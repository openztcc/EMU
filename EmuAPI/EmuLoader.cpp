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

//------ Flags for console
bool IsConsoleRunning = false;
bool IsConsoleHiding = false;
bool HasConsoleOpenedOnce = false; // to avoid conflicts when console has not been opened yet

//------ Flags for keypresses
bool ctrlMPressed = false;

// ------ Function prototypes
DWORD WINAPI ZooConsole(LPVOID lpParameter);

//------ Function pointers 
DWORD updateAddress = 0x00401644; // address of update function in game
typedef void (__cdecl *_origUpdate)(unsigned int); // define original update function

//------ Namespace and class aliases
#define fs std::filesystem
#define B EmuBase
#define ZS ZooState

//------ Global variables
HHOOK hHook = NULL;
int consoleW = 400; // console window width
int consoleH = 200; // console window height
EmuScriptMgr sm; // script manager object
std::vector<std::string> tokens; // contains tokens from console input
EmuConsole console(tokens); // console object

void RunEmu(unsigned int arg1) {


	// main loop

	std::ofstream f;
	f.open("out.log", std::ios_base::app);
	std::time_t t = std::time(0);
	char timestamp[80]; // timestamp buffer
	std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&t));

	// f << "[" << timestamp << "] " << "EMU loop running..." << std::endl;

	//---- CTRL + J
	if (B::DoubleKey(0x11, 0x4A) == true && IsConsoleRunning == false && HasConsoleOpenedOnce == false) {
		// f << "[" << timestamp << "] " << "Opening console..." << std::endl;
		IsConsoleRunning = true;
		HANDLE thread = CreateThread(NULL, 0, &ZooConsole, NULL, 0, NULL);
		// f << "[" << timestamp << "] " << "Console opened!" << std::endl;
		CloseHandle(thread);
	} 
	
	//---- CTRL + M
	if (B::DoubleKey(0x11, 0x4D) == true && !ctrlMPressed) {
		ctrlMPressed = true; // Set the flag
		float mo_money = 1000000.00f;
		ZS::AddToZooBudget(mo_money);
	} else if (B::DoubleKey(0x11, 0x4D) == false) {
		ctrlMPressed = false; // Reset the flag when the key is released
	}

	// only run scripts while zoo is loaded and not in main menu
	if ((int)ZS::object_ptr(0x0) > 0) {
		// f << "[" << timestamp << "] " << "Is no longer in main menu!" << std::endl;
		if (ZS::IsZooLoaded() == true) {
			f << "[" << timestamp << "] " << "Zoo is loaded!" << std::endl;
			sm.executeScripts();
			f << "[" << timestamp << "] " << "Scripts executed!" << std::endl;
		}
		
	}

	if (tokens.empty() != true)
	{
		// ------ Process the input tokens while console is running
		console.processInput(IsConsoleRunning);
	}

	// ------ Check for CTRL + J to close the console
	if (B::DoubleKey(0x11, 0x4A) == true) {
	}


	//---- return to original update function
	_origUpdate ogUpdate = (_origUpdate)updateAddress;
	// f << "[" << timestamp << "] " << "EMU loop finished!" << std::endl;
	f.close();
	return ogUpdate(arg1);
}

DWORD WINAPI ZooConsole(LPVOID lpParameter)
{
	
	
	std::ofstream f;
	f.open("out.log", std::ios_base::app);
	std::time_t t = std::time(0);
	char timestamp[80]; // timestamp buffer
	std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&t));

	HasConsoleOpenedOnce = true;

	HWND& consoleWindow = EmuConsole::createConsole();
	
	while (IsConsoleRunning)
	{
		// ------ Tokenize the input
		tokens.clear();
		std::cout << ">> ";
		console.tokenize();
		
		Sleep(10);
	}

	// ------ Close the console window
	HasConsoleOpenedOnce = false;
	IsConsoleRunning = false;
	FreeConsole();
	Sleep(100);
	PostMessage(consoleWindow, WM_CLOSE, 0, 0);
	return 1;

	f.close();
}


BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved) {


	std::ofstream f;
	f.open("out.log", std::ios_base::app);
	std::time_t t = std::time(0);
	char timestamp[80]; // timestamp buffer
	std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&t));

	// Get the thread ID of the current thread
	// DWORD mainThreadId = GetCurrentThreadId();
	// f << std::endl << std::endl << "[" << timestamp << "] " << "\nMain thread ID: " << mainThreadId << "\nCurrent thread ID: " << std::setfill('0') << std::setw(8) << std::hex << B::base << std::endl;

	// dll attachment status
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		{
		f << "[" << timestamp << "] " << "DLL attached!\n";
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
		DetourTransactionCommit();
		
		break;
	case DLL_PROCESS_DETACH:
		f << "[" << timestamp << "] " << "DLL detached!\n";
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
	
	f.close();
	return TRUE;
}