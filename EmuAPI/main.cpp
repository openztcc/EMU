// Author: Eric "Goosifer" Galvan
// Github: https://github.com/GoosiferIO/EMU
// Description: EMU (Extensible Modding Utility) is a Zoo Tycoon Complete Collection API


#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <string>
#include "EmuConsole.h"
#include <iomanip>
#include <mmsystem.h>
#include <winnt.h>

// declare addToBudget
DWORD __fastcall addToBudget(DWORD, float);

DWORD WINAPI game_loop(LPVOID lpParameter) 
{
	EmuConsole console;
	EmuConsole::Memory<float> w;
	EmuConsole::Memory<DWORD> r;
	
	// Create a console window
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);
	system("pause");

	// main loop
	while (true)
	{
		// Process the input tokens
		console.processInput();
		
		// Free the console and wait for user input
		std::cout << ">> ";
		Sleep(0);
	}

	return 1;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved) 
{
	EmuBase p;
	std::ofstream f;
	f.open("out.log");

	// Get the thread ID of the current thread
	DWORD mainThreadId = GetCurrentThreadId();
	f << mainThreadId << "\nCurrent thread ID: " << std::setfill('0') << std::setw(8) << std::hex << p.base << std::endl;

	// dll attachment status
	f << "Status: ";
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		{
		f << "DLL attached!\n";
		HANDLE thread = CreateThread(NULL, 0, &game_loop, NULL, 0, NULL);
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

// reroute old function to new function
typedef DWORD(__fastcall _origFunc)(DWORD arg1, float transaction);
_origFunc* __addToBudget = (_origFunc*)callHook(0x0050A245, (DWORD)&addToBudget);

// deposit = admission fee paid by guest 
DWORD __fastcall addToBudget(DWORD tclass, float transaction)
{
	//transaction = 10000; // final release won't see this line. also the idea will be to call this function
	                     // from a VF table to use other class members
	return __addToBudget(tclass, transaction); // return to location in zoo.exe
}