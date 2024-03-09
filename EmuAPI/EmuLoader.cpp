// Author: Eric "Goosifer" Galvan
// Github: https://github.com/GoosiferIO/EMU
// Description: EMU (Extensible Modding Utility) is a Zoo Tycoon Complete Collection API


#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <string>
#include "EmuConsole.h"
#include "EmuBase.h"
#include <iomanip>
#include <mmsystem.h>
#include <winnt.h>
#include <cstdio>
#include "ZooState.h"
#include "RegZooState.h"
#include "EmuScriptMgr.h"
#include <detours.h>
#include "ZooModels.h"
#include "ZTGameMgr.h"
#include "BFUIMgr.h"
#include "ZTUI.h"
#include "BFMap.h"	
#include "ZTWorldMgr.h"
#include "ZTMapView.h"

//------ Flags for console
bool IsConsoleRunning = false;
bool CommandIsProcessing = false;
bool HasConsoleOpenedOnce = false; // to avoid conflicts when console has not been opened yet

//------ Flags for keypresses
bool ctrlMPressed = false;

// ------ Function prototypes
DWORD WINAPI ZooConsole(LPVOID lpParameter);
BOOL InitializeHook();

//------ Function pointers 
DWORD updateAddress = 0x41a16b; // 0x00401644; // address of update function in game
typedef void (__thiscall *_origUpdate)(void* thisptr); // define original update function


// DWORD exitBuildingAddress = 0x4a75bb; // address of exit building function in the game
// typedef void* (__thiscall *_origexitBuildingAddress)(void* thisptr, int *param_1); // define original update function

//------ Namespace and class aliases
#define fs std::filesystem

//------ Global variables
HHOOK hMsgHook = NULL;
int consoleW = 400; // console window width
int consoleH = 200; // console window height
EmuScriptMgr sm; // script manager object
std::vector<std::string> tokens; // contains tokens from console input
EmuConsole console(tokens); // console object


//------ ZooModels object
extern ZooModels* zoo_models;
ZooModels* zoo_models = new ZooModels();

DWORD setAnimalRatingAddress = 0x0041D08B;
DWORD setZooRatingAddress = 0x0041D22F;
DWORD setGuestRatingAddress = 0x0041D15D;
bool hasHooked = false;

// ------ Detours

typedef void (__cdecl *_setAnimalRating)(int); // define original setAnimalRating function
typedef void (__cdecl *_setZooRating)(int); // define original setZooRating function
typedef void (__cdecl *_setGuestRating)(int); // define original setGuestRating function


void __cdecl SetGuestRating(int rating) {
	_setGuestRating ogSetGuestRating = (_setGuestRating)setGuestRatingAddress;
	if (zoo_models->_emuGuestRatingSet == true) {
		rating = zoo_models->_guestRating;
	}
	ogSetGuestRating(rating);
}

void __cdecl SetZooRating(int rating) {
	_setZooRating ogSetZooRating = (_setZooRating)setZooRatingAddress;
	if (zoo_models->_emuZooRatingSet == true) {
		rating = zoo_models->_zooRating;
	}
	ogSetZooRating(rating);
}

void __cdecl SetAnimalRating(int rating) {
	_setAnimalRating ogSetAnimalRating = (_setAnimalRating)setAnimalRatingAddress;
	if (zoo_models->_emuAnimalRatingSet == true) {
    	rating = zoo_models->_animalRating;
	}
	ogSetAnimalRating(rating);
}

// void* __fastcall exitBuilding(void* thisptr, unsigned int edx, int *param_1) {
// 	// std::ofstream f;
// 	// f.open("emu.log", std::ios_base::app);
// 	// f << "Exit building called!" << std::endl;
// 	// f << "thisptr: " << thisptr << std::endl;
// 	// f << "param_1: " << param_1 << std::endl;
// 	// f.close();
// 	_origexitBuildingAddress ogexitBuilding = (_origexitBuildingAddress)exitBuildingAddress;
// 	return ogexitBuilding(thisptr, param_1);
// }

LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
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

BOOL InitializeHook()
{
    // call SetWindowsHookEx here
	HHOOK hHook = SetWindowsHookEx(WH_MOUSE_LL, LowLevelMouseProc, GetModuleHandle(NULL), 0);
    if (hHook == NULL) {
        // handle error
        return false;
    }
    return true;
}

// ------ DllMain

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {


	// Get the thread ID of the current thread
	// DWORD mainThreadId = GetCurrentThreadId();
	// f << std::endl << std::endl << "[" << timestamp << "] " << "\nMain thread ID: " << mainThreadId << "\nCurrent thread ID: " << std::setfill('0') << std::setw(8) << std::hex << B::base << std::endl;

	// dll attachment status
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		//------ Find/load script file directories with script manager
		sm.findScripts();
		sm.storeScripts();



		//------ Detour update function to run emu and sync with main game thread
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		
		DetourAttach((PVOID*)&updateAddress, (PVOID)&RunEmu);
		DetourAttach((PVOID*)&setAnimalRatingAddress, (PVOID)&SetAnimalRating);
		DetourAttach((PVOID*)&setZooRatingAddress, (PVOID)&SetZooRating);
		DetourAttach((PVOID*)&setGuestRatingAddress, (PVOID)&SetGuestRating);

		DetourTransactionCommit();
		ZTGameMgr::init();
		ZTUI::main::init();
		ZTMapView::init();
		// EmuBase::callHook(0x00452ea5, (DWORD)&generateMap);
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