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
#include "lua.hpp"

bool IsConsoleRunning = false;

DWORD WINAPI ZooConsole(LPVOID lpParameter)
{
	EmuConsole console;
	FILE* file_s;

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
	
	system("pause");

	while (IsConsoleRunning)
	{
		// Process the input tokens
		console.processInput(IsConsoleRunning);
		Sleep(10);
	}

	return 1;
}

DWORD WINAPI RunEmu(LPVOID lpParameter) 
{
	//EmuBase b;
	bool ctrlMPressed = false;

	// main loop
	while (true)
	{
		// CTRL + J
		if (EmuBase::DoubleKey(0x11, 0x4A) == true && !IsConsoleRunning)
		{
			IsConsoleRunning = true;
			HANDLE thread = CreateThread(NULL, 0, &ZooConsole, NULL, 0, NULL);
			CloseHandle(thread);
		}
		
		
		// CTRL + M
        if (EmuBase::DoubleKey(0x11, 0x4D) == true && !ctrlMPressed)
        {
            ctrlMPressed = true; // Set the flag
            float mo_money = 1000000.00f;
            ZooState::AddToZooBudget(mo_money);
        }
        else if (EmuBase::DoubleKey(0x11, 0x4D) == false)
        {
            ctrlMPressed = false; // Reset the flag when the key is released
        }


		Sleep(0);
	}
	
	return 1;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved) 
{
	std::ofstream f;
	f.open("out.log");

	// Get the thread ID of the current thread
	DWORD mainThreadId = GetCurrentThreadId();
	f << mainThreadId << "\nCurrent thread ID: " << std::setfill('0') << std::setw(8) << std::hex << EmuBase::base << std::endl;

	// dll attachment status
	f << "Status: ";
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		{
		f << "DLL attached!\n";
		HANDLE thread = CreateThread(NULL, 0, &RunEmu, NULL, 0, NULL);
		CloseHandle(thread);
		}
		break;
	case DLL_PROCESS_DETACH:
		f << "DLL detached!\n";
		break;
	case DLL_THREAD_ATTACH:
		f << "Thread attached!\n";
		break;

	case DLL_THREAD_DETACH:
		f << "Thread detached!\n";
		break;
	default:
		f << "DLL was not attached to thread or process!\n";
		return FALSE;
	}
	
	f.close();
	return TRUE;
}