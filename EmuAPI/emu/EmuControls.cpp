#include "EmuControls.h"


void EmuControls::procControls(bool &IsConsoleRunning, bool &HasConsoleOpenedOnce, bool &ctrlMPressed)
{
    	if (EmuBase::DoubleKey(0x11, 0x54) == true) {
		// BFUIMgr::shared_instance().getElement(0x3f8);
		// BFGameApp::incSimSpeed();
		// DWORD* begin = *reinterpret_cast<DWORD**>(ZTWorldMgr::getOffset(0x80));
    	// DWORD* end = *reinterpret_cast<DWORD**>(ZTWorldMgr::getOffset(0x84));
		// int ids[] = {6101, 6111, NULL};

		// std::vector<DWORD*> entities = ZTWorldMgr::getAllEntitiesOfType(begin, end, ids);
		// ZTWorldMgr::makeInvisible(entities);

		BFUIMgr::confirmDialog(BFUIMgr::getUIMgr(), 153, 0, 3, "ui/sharedui/question/question", '\x01', '\0', 0, 0);
		// std::ofstream f;
		// f.open("getelement.log", std::ios_base::app);
		// f << "x: " << x << std::endl;
		// f.close();
	}
	

	//---- CTRL + J
	if (EmuBase::DoubleKey(0x11, 0x4A) == true && IsConsoleRunning == false && HasConsoleOpenedOnce == false) {
		// f << "[" << timestamp << "] " << "Opening console..." << std::endl;
		IsConsoleRunning = true;
		HANDLE thread = CreateThread(NULL, 0, &EmuMain::ZooConsole(), NULL, 0, NULL);
		// f << "[" << timestamp << "] " << "Console opened!" << std::endl;
		CloseHandle(thread);
	} 
	
	//---- CTRL + M
	if (EmuBase::DoubleKey(0x11, 0x4D) == true && !ctrlMPressed) {
		ctrlMPressed = true; // Set the flag
		float mo_money = 1000000.00f;
		ZooState::AddToZooBudget(mo_money);
	} else if (EmuBase::DoubleKey(0x11, 0x4D) == false) {
		ctrlMPressed = false; // Reset the flag when the key is released
	}

}

LRESULT CALLBACK EmuControls::LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
		MSLLHOOKSTRUCT* pMouseStruct = (MSLLHOOKSTRUCT*)lParam;
		if (wParam == WM_MOUSEWHEEL) {
			int wheelDelta = GET_WHEEL_DELTA_WPARAM(pMouseStruct->mouseData);
			bool isCtrlPressed = GetAsyncKeyState(VK_CONTROL) & 0x8000;
			int* currentZoom = (int*)ZTWorldMgr::getOffset(0x14);
			if (isCtrlPressed) {
				if (isCtrlPressed && wheelDelta > 0) {
				// f << "Mouse wheel up!" << std::endl;
				ZTMapView::rotateCW();
				} else if (isCtrlPressed && wheelDelta < 0) {
					// f << "Mouse wheel down!" << std::endl;
					ZTMapView::rotateCCW();
				} 
				
			} else {
				if (wheelDelta > 0 && *currentZoom < 2) {
					// f << "Mouse wheel up!" << std::endl;
					ZTMapView::clickZoomIn();
				} else if (wheelDelta < 0 && *currentZoom > -2) {
					// f << "Mouse wheel down!" << std::endl;
					ZTMapView::clickZoomOut();
				}
			}
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}
}

bool EmuControls::InitializeHook()
{
    // call SetWindowsHookEx here
	HHOOK hHook = SetWindowsHookEx(WH_MOUSE_LL, EmuControls::LowLevelMouseProc, GetModuleHandle(NULL), 0);
    if (hHook == NULL) {
        // handle error
        return false;
    }
    return true;
}
