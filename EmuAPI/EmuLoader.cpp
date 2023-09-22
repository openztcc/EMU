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

bool IsConsoleRunning = false;
bool IsConsoleHiding = false;
bool HasConsoleOpenedOnce = false; // to avoid conflicts when console has not been opened yet
HWND consoleWindow; // contains console window handle

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

DWORD WINAPI RunEmu(LPVOID lpParameter) 
{
	bool ctrlMPressed = false;

	lua_State *lua = luaL_newstate();  // Open Lua
	int iErr = 0;
	if (!lua) 
	{
		std::cerr << "Failed to create Lua state." << std::endl;
		return 0;
	}

	RegZooState::register_zoo_state(lua);
	luaL_openlibs (lua);              // Load io library

	// main loop
	while (true)
	{
		// CTRL + J
		if (EmuBase::DoubleKey(0x11, 0x4A) == true && IsConsoleRunning == false && HasConsoleOpenedOnce == false)
		{
			IsConsoleRunning = true;
			HANDLE thread = CreateThread(NULL, 0, &ZooConsole, NULL, 0, NULL);
			CloseHandle(thread);
		}
		else if (EmuBase::DoubleKey(0x11, 0x4A) == true && IsConsoleHiding == true && HasConsoleOpenedOnce == true)
		{
			ShowWindow(consoleWindow, SW_SHOW);
			IsConsoleHiding = false;
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
		
		
		if ((((int)ZooState::object_ptr(0x0)) > 0) && (iErr = luaL_loadfile (lua, "playground.emu")) == 0)
		{
			if (ZooState::IsZooLoaded() == true)
			{
				// Call main...
				if ((iErr = lua_pcall (lua, 0, LUA_MULTRET, 0)) == 0)
				{ 
					lua_pcall(lua, 0, LUA_MULTRET, 0);
					
					// Push the function name onto the stack
					lua_getglobal(lua, "emu_run");
					
					lua_pcall(lua, 0, 0, 0);
					
				}
			}
			
		}
		

		Sleep(0);
	}
	lua_close (lua);
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