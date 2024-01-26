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
#include <ctime>
#include "EmuScriptMgr.h"
#include <detours.h>
#include "ZooModels.h"

//------ Flags for console
bool IsConsoleRunning = false;
bool CommandIsProcessing = false;
bool HasConsoleOpenedOnce = false; // to avoid conflicts when console has not been opened yet

//------ Flags for keypresses
bool ctrlMPressed = false;

// ------ Function prototypes
DWORD WINAPI ZooConsole(LPVOID lpParameter);

//------ Function pointers 
DWORD updateAddress = 0x41a16b; // 0x00401644; // address of update function in game
typedef void (__thiscall *_origUpdate)(void* thisptr); // define original update function

//------ Namespace and class aliases
#define fs std::filesystem

//------ Global variables
HHOOK hHook = NULL;
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

//------ Function definitions

void __fastcall RunEmu(void* thisptr) { 

	// main loop


	// f << "[" << timestamp << "] " << "EMU loop running..." << std::endl;

	//---- CTRL + J
	if (EmuBase::DoubleKey(0x11, 0x4A) == true && IsConsoleRunning == false && HasConsoleOpenedOnce == false) {
		// f << "[" << timestamp << "] " << "Opening console..." << std::endl;
		IsConsoleRunning = true;
		HANDLE thread = CreateThread(NULL, 0, &ZooConsole, NULL, 0, NULL);
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

	// only run scripts while zoo is loaded and not in main menu
	if ((int)ZooState::object_ptr(0x0) > 0) {
		// f << "[" << timestamp << "] " << "Is no longer in main menu!" << std::endl;
		if (ZooState::IsZooLoaded() == true) {
			// f << "[" << timestamp << "] " << "Zoo is loaded!" << std::endl;
			*zoo_models = sm.executeScripts();
			int x = 0;
			// f << "[" << timestamp << "] " << "Scripts executed!" << std::endl;
		}
		
	}

	//---- Process the input tokens while console is running
	if (!tokens.empty() && IsConsoleRunning == true)
	{
		console.processInput(IsConsoleRunning);
		tokens.clear();
		CommandIsProcessing = false; // reset flag to allow another command to be tokenized
	}

	//---- return to original update function
	_origUpdate ogUpdate = (_origUpdate)updateAddress;
	// f << "[" << timestamp << "] " << "EMU loop finished!" << std::endl;
	
	ogUpdate(thisptr);

	// f << "[" << timestamp << "] " << "ogUpdate(thisptr) called!" << std::endl;
	
}

DWORD WINAPI ZooConsole(LPVOID lpParameter)
{
	
	

	HasConsoleOpenedOnce = true;

	HWND consoleWindow = EmuConsole::createConsole();
	
	while (IsConsoleRunning)
	{
		// ------ Tokenize the input
		if (!CommandIsProcessing)
		{
			std::cout << ">> ";
			CommandIsProcessing = true; // set flag to true to avoid multiple commands being processed at once
			console.tokenize(CommandIsProcessing);
		}
		Sleep(10);

	}

	// ------ Close the console window
	HasConsoleOpenedOnce = false;
	IsConsoleRunning = false;
	FreeConsole();
	Sleep(100);
	PostMessage(consoleWindow, WM_CLOSE, 0, 0);
	return 1;
}

// ------ Detours

typedef void (__cdecl *_setAnimalRating)(int); // define original setAnimalRating function
typedef void (__cdecl *_setZooRating)(int); // define original setZooRating function
typedef void (__cdecl *_setGuestRating)(int); // define original setGuestRating function

void __cdecl SetGuestRating(int rating) {
	_setGuestRating ogSetGuestRating = (_setGuestRating)setGuestRatingAddress;
    rating = zoo_models->_guestRating;
	ogSetGuestRating(rating);
}

void __cdecl SetZooRating(int rating) {
	_setZooRating ogSetZooRating = (_setZooRating)setZooRatingAddress;
    rating = zoo_models->_zooRating;
	ogSetZooRating(rating);
}

void __cdecl SetAnimalRating(int rating) {
	_setAnimalRating ogSetAnimalRating = (_setAnimalRating)setAnimalRatingAddress;
    rating = zoo_models->_animalRating;
	ogSetAnimalRating(rating);
}


// ------ DllMain

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved) {


	// Get the thread ID of the current thread
	// DWORD mainThreadId = GetCurrentThreadId();
	// f << std::endl << std::endl << "[" << timestamp << "] " << "\nMain thread ID: " << mainThreadId << "\nCurrent thread ID: " << std::setfill('0') << std::setw(8) << std::hex << B::base << std::endl;

	// dll attachment status
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		{
		// f << "[" << timestamp << "] " << "DLL attached!\n";
		// HANDLE thread = CreateThread(NULL, 0, &RunEmu, NULL, 0, NULL);
		 // CloseHandle(thread);
		}
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