#include "EmuControls.h"
#include "BFUIMgr.h"
#include "EmuBase.h"
#include "ZooState.h"
#include "EmuConsole.h"
#include "EmuMain.h"

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