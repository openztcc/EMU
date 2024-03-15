#include "ZTApp.h"
#include "EmuBase.h"
#include "BFUIMgr.h"

void ZTApp::init() {
    EmuBase::callHook(0x004f0b72, (DWORD)&ZTApp::handleKeyDown); // from addCash
}

void ZTApp::handleKeyDown(int key) {
    // handle key down event
    _handleKeyDown _oghandleKeyDown = (_handleKeyDown)0x004f0b72;
    _oghandleKeyDown(key);
}

void ZTApp::emuKeysHandleKeyDown(int key) {
    
    // if (key == 0x11) {
    //     EmuBase::setCtrlPressed(true);
    // }
    // // CTRL + T - for testing
    // if (EmuBase::DoubleKey(0x11, 0x54) == true) {
    // // BFUIMgr::shared_instance().getElement(0x3f8);
    //     BFUIMgr::clickSave();

    // // std::ofstream f;
    // // f.open("getelement.log", std::ios_base::app);
    // // f << "x: " << x << std::endl;
    // // f.close();
	// }
	

	// //---- CTRL + J
	// if (EmuBase::DoubleKey(0x11, 0x4A) == true && IsConsoleRunning == false && HasConsoleOpenedOnce == false) {
	// 	// f << "[" << timestamp << "] " << "Opening console..." << std::endl;
	// 	IsConsoleRunning = true;
	// 	HANDLE thread = CreateThread(NULL, 0, &ZooConsole, NULL, 0, NULL);
	// 	// f << "[" << timestamp << "] " << "Console opened!" << std::endl;
	// 	CloseHandle(thread);
	// } 
	
	// //---- CTRL + M
	// if (EmuBase::DoubleKey(0x11, 0x4D) == true && !ctrlMPressed) {
	// 	ctrlMPressed = true; // Set the flag
	// 	float mo_money = 1000000.00f;
	// 	ZooState::AddToZooBudget(mo_money);
	// } else if (EmuBase::DoubleKey(0x11, 0x4D) == false) {
	// 	ctrlMPressed = false; // Reset the flag when the key is released
	// }

}