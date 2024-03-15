// Author: Eric "Goosifer" Galvan
// Github: https://github.com/GoosiferIO/EMU
// Description: EMU (Extensible Modding Utility) is a Zoo Tycoon Complete Collection API


#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <string>
#include <iomanip>
#include <mmsystem.h>
#include <winnt.h>
#include <cstdio>
#include "RegZooState.h"
#include "ZooModels.h"
#include "ZTGameMgr.h"
#include "BFUIMgr.h"
#include "ZTUI.h"
#include "BFMap.h"	
#include "ZTWorldMgr.h"
#include "EmuMain.h"

//------ Global variables
int consoleW = 400; // console window width
int consoleH = 200; // console window height

//------ ZooModels object
extern ZooModels* zoo_models;

// ------ DllMain

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	// Get the thread ID of the current thread
	// DWORD mainThreadId = GetCurrentThreadId();
	// f << std::endl << std::endl << "[" << timestamp << "] " << "\nMain thread ID: " << mainThreadId << "\nCurrent thread ID: " << std::setfill('0') << std::setw(8) << std::hex << B::base << std::endl;

	// dll attachment status
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		//------ Find/load scrpt file directories with script manager
		EmuMain::shared_instance().emu_run.LoadScripts();
		EmuMain::shared_instance().emu_gawk.LoadScripts();
		EmuMain::init();
		// ZTGameMgr::init();
		ZTUI::main::init();
		// ZTMapView::init();
		// BFMap::init();
		
		break;
	case DLL_PROCESS_DETACH:
		// f << "[" << timestamp << "] " << "DLL detached!\n";
		break;
	case DLL_THREAD_ATTACH:
		//f << "[" << timestamp << "] " << "Thread attached!\n";
		break;

	case DLL_THREAD_DETACH:
		//f << "[" << timestamp << "] " << "Thread detached!\n";
		break;
	default:
		//f << "[" << timestamp << "] " << "DLL was not attached to thread or process!\n";
		return FALSE;
	}
	
	return TRUE;
}