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

DWORD WINAPI RunEmu(LPVOID lpParameter) 
{
	bool ctrlMPressed = false;
	std::time_t t = std::time(0);
	char timestamp[80]; // timestamp buffer
	std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&t));

	std::ofstream f;
	f.open("out.log", std::ios_base::app);

	lua_State *lua = luaL_newstate();  // Open Lua
	int iErr = 0;
	if (!lua) 
	{
		f << "[" << timestamp << "] " << "Failed to create Lua state." << std::endl;
		return 0;
	}

	std::vector<lua_CFunction> script_functions; // store the lua scripts
	RegZooState::register_zoo_state(lua);
	luaL_openlibs (lua);              // Load io library
	wchar_t buffer[MAX_PATH];
	DWORD len = GetCurrentDirectory(MAX_PATH, buffer); // TODO: add error handling for this

	// directory path
	// std::string path = "/scripts";
	std::wstring wpath(buffer, len);//std::wstring(buffer.begin(), buffer.end()); // conv path to wide string (project uses multi-byte char set)
	wpath += L"\\scripts";
	std::string path(wpath.begin(), wpath.end());
	std::string ext = ".emu";

	// while ((((int)ZooState::object_ptr(0x0)) == 0) || (iErr = lua_pcall (lua, 0, LUA_MULTRET, 0)) > 0)
	// {
	// 	iErr = lua_pcall (lua, 0, LUA_MULTRET, 0);
	// 	Sleep(100);
	// }

	// iterate through directory
	//if ((iErr = lua_pcall (lua, 0, LUA_MULTRET, 0)) == 0)
	//{
		WIN32_FIND_DATA find_emu_file;
		HANDLE hFind = FindFirstFile((wpath + L"\\*.emu").c_str(), &find_emu_file); // wide string used here

		wpath = find_emu_file.cFileName;
		std::string file_found(wpath.begin(), wpath.end());
		
		if  (hFind == INVALID_HANDLE_VALUE)
		{
			f << "[" << timestamp << "] " << "Error finding path: " << file_found << std::endl;
		}
		else
		{
			f << "[" << timestamp << "] " << "Path found: " << file_found << std::endl;
			do
			{
				if (find_emu_file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					// skip directories (for now)
				}
				else // we only care about files (for now)
				{
					std::wstring nFound = find_emu_file.cFileName; // conv file found back to narrow string
					std::string file_name(nFound.begin(), nFound.end());
					std::string file = path + "\\" + file_name;
					
					// look for .emu files
					if (file_name.size() > ext.size() && file_name.compare(file_name.size() - ext.size(), ext.size(), ext) == 0)
					{
						f << "[" << timestamp << "] " << "Loading script: " << file_name << std::endl;

						if ((iErr = luaL_loadfile(lua, file.c_str())) == 0)
						{
							if ((iErr = lua_pcall(lua, 0, 0, 0)) == 0)
    						{
								lua_getglobal(lua, "emu_run");

								if (lua_isfunction(lua, -1))
        						{
									lua_CFunction script_fun = lua_tocfunction(lua, -1); // conv to c funct
									if (script_fun != NULL)
									{
										lua_pop(lua, 1); // remove from lua stack
										script_functions.push_back(script_fun); // add to vector
									}
									else
									{
										f << "[" << timestamp << "] " << "Error loading script: <" << file_name << "> null function" << std::endl;
									}
									// if ((iErr = lua_pcall (lua, 0, LUA_MULTRET, 0)) == 0)
									// { 
									// 	// lua_pcall(lua, 0, LUA_MULTRET, 0);
									// 	// // Push the function name onto the stack
									// 	// lua_getglobal(lua, "emu_run");
									// 	// lua_pcall(lua, 0, 0, 0);
									// }
								}
							}
							else
							{
								const char* error_message = lua_tostring(lua, -1);
								if (error_message != NULL)
								{
									f << "[" << timestamp << "] " << "Error loading script: <" << file_name << "> " << error_message << std::endl;
								}
								else
								{
									f << "[" << timestamp << "] " << "Error loading script: <" << file_name << std::endl;
								}
							}
						}
						else
						{
							const char* error_message = lua_tostring(lua, -1);
							if (error_message != NULL)
							{
								f << "[" << timestamp << "] " << "Error loading script: <" << file_name << "> " << error_message << std::endl;
							}
							else
							{
								f << "[" << timestamp << "] " << "Error loading script: <" << file_name << std::endl;
							}
							
						}
					}
				}
			} while (FindNextFile(hFind, &find_emu_file) != 0);
			FindClose(hFind);
		}
		
	//}
	// else
	// {
	// 	const char* err = lua_tostring(lua, -1);
	// 	f << "[" << timestamp << "] Error loading lua state: " << err << std::endl;
	// 	lua_pop(lua, 1);
	// }

		// if ((((int)ZS::object_ptr(0x0)) > 0) && (iErr = luaL_loadfile (lua, "playground.emu")) == 0)
		// {
		// 	if (ZS::IsZooLoaded() == true)
		// 	{
		// 		// Call main...
		// 		if ((iErr = lua_pcall (lua, 0, LUA_MULTRET, 0)) == 0)
		// 		{ 
		// 			lua_pcall(lua, 0, LUA_MULTRET, 0);
					
		// 			// Push the function name onto the stack
		// 			lua_getglobal(lua, "emu_run");
					
		// 			lua_pcall(lua, 0, 0, 0);
					
		// 		}
		// 	}
			
		// }

	// main loop
	while (true)
	{
		// CTRL + J
		if (B::DoubleKey(0x11, 0x4A) == true && IsConsoleRunning == false && HasConsoleOpenedOnce == false)
		{
			IsConsoleRunning = true;
			HANDLE thread = CreateThread(NULL, 0, &ZooConsole, NULL, 0, NULL);
			CloseHandle(thread);
		}
		else if (B::DoubleKey(0x11, 0x4A) == true && IsConsoleHiding == true && HasConsoleOpenedOnce == true)
		{
			ShowWindow(consoleWindow, SW_SHOW);
			IsConsoleHiding = false;
		}
		
		
		// CTRL + M
        if (B::DoubleKey(0x11, 0x4D) == true && !ctrlMPressed)
        {
            ctrlMPressed = true; // Set the flag
            float mo_money = 1000000.00f;
            ZS::AddToZooBudget(mo_money);
        }
        else if (B::DoubleKey(0x11, 0x4D) == false)
        {
            ctrlMPressed = false; // Reset the flag when the key is released
        }

		// only run scripts while zoo is loaded and not in main menu
		if ((int)ZS::object_ptr(0x0) > 0 && script_functions.size() > 0)
		{
			if (ZS::IsZooLoaded() == true)
			{
				for (size_t i = 0; i < script_functions.size(); ++i)
				{
					lua_CFunction script_fun = script_functions[i];
					//script_fun(lua);
				// 	lua_getglobal(lua, "emu_run"); // call emu_run from script
				// 	if (lua_isfunction(lua, -1))
				// 	{
				// 		lua_pcall(lua, 0, 0, 0);
				// 	}
				// 	lua_pop(lua, 1);  // remov emu_run from stack
					lua_pushcfunction(lua, script_fun);
					lua_pcall(lua, 0, 0, 0);
				}
				// }
				
			}
			
		}
			
		Sleep(0);
	}
	lua_close (lua);
	f.close();
	return 1;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved) 
{
	std::ofstream f;
	f.open("out.log", std::ios_base::app);
	std::time_t t = std::time(0);
	char timestamp[80]; // timestamp buffer
	std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&t));

	// Get the thread ID of the current thread
	DWORD mainThreadId = GetCurrentThreadId();
	f << std::endl << std::endl << "[" << timestamp << "] " << "\nMain thread ID: " << mainThreadId << "\nCurrent thread ID: " << std::setfill('0') << std::setw(8) << std::hex << B::base << std::endl;

	// dll attachment status
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		{
		f << "[" << timestamp << "] " << "DLL attached!\n";
		HANDLE thread = CreateThread(NULL, 0, &RunEmu, NULL, 0, NULL);
		CloseHandle(thread);
		}
		break;
	case DLL_PROCESS_DETACH:
		f << "[" << timestamp << "] " << "DLL detached!\n";
		break;
	case DLL_THREAD_ATTACH:
		f << "[" << timestamp << "] " << "Thread attached!\n";
		break;

	case DLL_THREAD_DETACH:
		f << "[" << timestamp << "] " << "Thread detached!\n";
		break;
	default:
		f << "[" << timestamp << "] " << "DLL was not attached to thread or process!\n";
		return FALSE;
	}
	
	f.close();
	return TRUE;
}