// Author: Eric "Goosifer" Galvan
// Github: https://github.com/GoosiferIO/EMU
// Description: EMU (Extensible Modding Utility) is a Zoo Tycoon Complete Collection API


#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <string>
#include "TekUtilities.h"
#include "TekMemory.h"
#include <iomanip>

// declare addToBudget
DWORD __fastcall addToBudget(DWORD, float);

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved) {

	std::ofstream f;
	Zoo::Process p;
	f.open("out.log");

	// Get the thread ID of the current thread
	DWORD mainThreadId = GetCurrentThreadId();
	f << mainThreadId << "\nCurrent thread ID: " << std::setfill('0') << std::setw(8) << std::hex << p.base << "\n";

	// dll attachment status
	f << "Status: ";
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		f << "DLL attached!\n";
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

void game_loop() {
    // 
}

extern "C" __declspec(dllexport) void start_game_loop() 
{
    // new thread
    std::thread game_thread(game_loop);

    // wait for the game loop thread to finish before exiting the function
    game_thread.join();
}

// utility function for near hooking
DWORD callHook(DWORD hookAt, DWORD newFunc)
{
	Memory<DWORD> m;
	Zoo::Process process;
	DWORD newOffset = newFunc - hookAt - 5;
	DWORD oldProtection = m.protectMemory((LPVOID)(hookAt + 1), PAGE_EXECUTE_READWRITE);
	DWORD originalOffset = m.readMemory((LPVOID)(hookAt + 1));
	m.writeMemory((LPVOID)(hookAt + 1), newOffset);
	m.protectMemory((LPVOID)(hookAt + 1), oldProtection);
	return originalOffset + hookAt + 5;
}

// reroute old function to new function
typedef DWORD(__fastcall _origFunc)(DWORD arg1, float transaction);
_origFunc* __addToBudget = (_origFunc*)callHook(0x0050A245, (DWORD)&addToBudget);

// deposit = admission fee paid by guest 
DWORD __fastcall addToBudget(DWORD tclass, float transaction)
{
	transaction = 10000; // final release won't see this line. also the idea will be to call this function
	                     // from a VF table to use other class members
	return __addToBudget(tclass, transaction); // return to location in zoo.exe
}