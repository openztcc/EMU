#include "EmuControls.h"
#include "EmuMain.h"
#include "ZTWorldMgr.h"
#include "EmuMain.h"
#include "BFUIMgr.h"
#include "ZTGameMgr.h"

#define Main EmuMain::shared_instance()

void EmuControls::procControls()
{
	// if (EmuBase::DoubleKey(0x11, 0x54) == true)
	// {
	// 	// BFUIMgr::shared_instance().getElement(0x3f8);
	// 	//BFGameApp::incSimSpeed();

	// 	std::vector<int> ids = { 9313, 9314 };

	// 	std::vector<void*> entities = ZTWorldMgr::GetAllEntitiesOfType(ids);
	// 	ZTWorldMgr::SetVanishGuard(entities, ids, true);

	// 	// BFUIMgr::confirmDialog(BFUIMgr::getUIMgr(), 153, 0, 3, "ui/sharedui/question/question", '\x01', '\0', 0, 0);
	// 	// std::ofstream f;
	// 	// f.open("getelement.log", std::ios_base::app);
	// 	// f << "x: " << x << std::endl;
	// 	// f.close();
	// }


	//---- CTRL + J
	if (EmuBase::DoubleKey(0x11, 0x4A) == true && Main.IsConsoleRunning == false && Main.HasConsoleOpenedOnce == false) {
		// f << "[" << timestamp << "] " << "Opening console..." << std::endl;
		Main.IsConsoleRunning = true;
		HANDLE thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&EmuMain::ZooConsole, NULL, 0, NULL);
		// f << "[" << timestamp << "] " << "Console opened!" << std::endl;
		// if (thread != NULL)
		// {
		// 	// Wait for the thread to finish
		// 	WaitForSingleObject(thread, INFINITE);
		// 	// Close the thread handle
		// 	CloseHandle(thread);
		// }
		CloseHandle(thread);
	}

	//---- CTRL + M
	if (EmuBase::DoubleKey(0x11, 0x4D) == true && !Main.ctrlMPressed) {
		Main.ctrlMPressed = true; // Set the flag
		float mo_money = 1000000.00f;
		ZTGameMgr::addCash(mo_money);
	}
	else if (EmuBase::DoubleKey(0x11, 0x4D) == false) {
		Main.ctrlMPressed = false; // Reset the flag when the key is released
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
				}
				else if (isCtrlPressed && wheelDelta < 0) {
					// f << "Mouse wheel down!" << std::endl;
					ZTMapView::rotateCCW();
				}

			}
			else {
				if (wheelDelta > 0 && *currentZoom < 2) {
					// f << "Mouse wheel up!" << std::endl;
					ZTMapView::clickZoomIn();
				}
				else if (wheelDelta < 0 && *currentZoom > -2) {
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