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

bool IsConsoleRunning = false;
bool IsConsoleHiding = false;
bool HasConsoleOpenedOnce = false; // to avoid conflicts when console has not been opened yet
HWND consoleWindow; // contains console window handle

#define fs std::filesystem
#define B EmuBase
#define ZS ZooState

DWORD WINAPI ZooConsole(LPVOID lpParameter)
{
	EmuConsole console; // new console object. needed to keep token state persistent.
	FILE* file_s;
	

	HasConsoleOpenedOnce = true;

	// Create a console window
    AllocConsole();
    if (freopen_s(&file_s, "CONOUT$", "w", stdout) != 0)
	{
		perror("freeopen_s");
		return 1;
	}
	if (freopen_s(&file_s, "CONIN$", "r", stdin) != 0)
	{
		perror("freeopen_s");
		return 1;
	}

	consoleWindow = GetConsoleWindow();
	// SetWindowLongPtr(consoleWindow, GWL_EXSTYLE, GetWindowLongPtr(consoleWindow, GWL_EXSTYLE) | WS_EX_NOACTIVATE);
    // SetWindowPos(consoleWindow, HWND_TOPMOST, 100, 100, 400, 200, SWP_SHOWWINDOW);

	std::cout << "Welcome to the EMU command console. Please enter your command below.\n\n:::IMPORTANT::: Do not close this console window if you do not want to lose your zoo progress, this will effectively force quit the game. If you would like to exit the console safely, type in the 'exit' command and wait for the message. You can then close the command console." << std::endl << std::endl;
	
	while (IsConsoleRunning)
	{
		// Process the input tokens
		console.processInput(IsConsoleRunning);
		
		if (IsConsoleHiding == false)
		{
			ShowWindow(consoleWindow, SW_HIDE);
			IsConsoleHiding = true;
		}
		
		Sleep(10);
	}
	FreeConsole();
	return 1;
}

DWORD WINAPI RunEmu(LPVOID lpParameter) {
	//------ Variable and object initialization
	bool ctrlMPressed = false;

	//------ Timestamp for logging
	std::time_t t = std::time(0);
	char timestamp[80]; // timestamp buffer
	std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&t));

	//------ Open log file in append mode
	std::ofstream f;
	f.open("out.log", std::ios_base::app);

	//------ Find/load script file directories with script manager
	EmuScriptMgr sm(f, timestamp);
	sm.findScripts();
	sm.storeScripts();

	// main loop

	bool renaming_done = false;
	while (true) {
		// CTRL + J
		if (B::DoubleKey(0x11, 0x4A) == true && IsConsoleRunning == false && HasConsoleOpenedOnce == false) {
			IsConsoleRunning = true;
			HANDLE thread = CreateThread(NULL, 0, &ZooConsole, NULL, 0, NULL);
			CloseHandle(thread);
		} else if (B::DoubleKey(0x11, 0x4A) == true && IsConsoleHiding == true && HasConsoleOpenedOnce == true) {
			ShowWindow(consoleWindow, SW_SHOW);
			IsConsoleHiding = false;
		}
		
		
		// CTRL + M
        if (B::DoubleKey(0x11, 0x4D) == true && !ctrlMPressed) {
            ctrlMPressed = true; // Set the flag
            float mo_money = 1000000.00f;
            ZS::AddToZooBudget(mo_money);
        }
        else if (B::DoubleKey(0x11, 0x4D) == false) {
            ctrlMPressed = false; // Reset the flag when the key is released
        }

		

		// only run scripts while zoo is loaded and not in main menu
		if ((int)ZS::object_ptr(0x0) > 0) {
			if (ZS::IsZooLoaded() == true) {
				sm.executeScripts();
			}
			
		}
			
		Sleep(0);
	}
	f.close();
	return 1;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved) {
	// std::ofstream f;
	// f.open("out.log", std::ios_base::app);
	// std::time_t t = std::time(0);
	// char timestamp[80]; // timestamp buffer
	// std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&t));

	// Get the thread ID of the current thread
	// DWORD mainThreadId = GetCurrentThreadId();
	// f << std::endl << std::endl << "[" << timestamp << "] " << "\nMain thread ID: " << mainThreadId << "\nCurrent thread ID: " << std::setfill('0') << std::setw(8) << std::hex << B::base << std::endl;

	// dll attachment status
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		{
		//f << "[" << timestamp << "] " << "DLL attached!\n";
		HANDLE thread = CreateThread(NULL, 0, &RunEmu, NULL, 0, NULL);
		CloseHandle(thread);
		}
		break;
	case DLL_PROCESS_DETACH:
		//f << "[" << timestamp << "] " << "DLL detached!\n";
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
	
	// f.close();
	return TRUE;
}