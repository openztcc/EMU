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
#include "EmuConsole.h"
#include <iomanip>
#include <mmsystem.h>
#include <winnt.h>

// declare addToBudget
DWORD __fastcall addToBudget(DWORD, float);
VOID WINAPI newSleepFunction(DWORD ms, DWORD b, DWORD c, DWORD d, DWORD e);

DWORD WINAPI game_loop(LPVOID lpParameter) 
{

	Zoo::Process p;
	Memory<float> w;
	
	// Create a console window
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
	
	freopen("CONIN$", "r", stdin);
	
	system("pause");
	std::cout << ">> ";
	std::string input;
	// main loop
	while (true)
	{
		float* budget;
		Memory<DWORD> r;
		DWORD ptr = r.readMemory((void*)(p.base + 0x00238048)) + 0x0C; // grab address to budget
		budget = (float*)(ptr);

		std::string input;
		std::string argument;
		std::cin >> input >> argument;

		// Split the input into tokens based on space delimiter
		//std::istringstream iss(input);
		//std::vector<std::string> tokens;
		std::string token;
		/*while (iss >> token)
		{
			tokens.push_back(token);
		}*/

		// Process the input tokens
		if (!input.empty())
		{
			// The first token is the command
			std::string command = input;

			// The remaining tokens are arguments
			// std::vector<std::string> arguments(tokens.begin() + 1, tokens.end());
	        
			// Check for a special command to exit the program
			if (command == "exit")
			{
				FreeConsole();
				return 0;
			}
			
			if (command == "addtobudget")
			{
				float newbudget = std::atof(argument.c_str());

				// string -> float
				w.writeMemory((void*)ptr, (float)(*budget + newbudget)); // update budget

			}
		}
		// Free the console and wait for user input
		std::cout << ">> ";
		Sleep(0);
	}
	FreeConsole();
	return 1;
}

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

// Modified IAT hook from Nick Cano's book. Needs a lot of fixing.
//DWORD hookIAT(const char* funcName, DWORD newFunc)
//{
//    HMODULE hModule = GetModuleHandle(NULL);
//    IMAGE_DOS_HEADER* dosHeader = (IMAGE_DOS_HEADER*)hModule;
//
//    if (dosHeader->e_magic != IMAGE_DOS_SIGNATURE)
//    {
//        return 0;
//    }
//
//    IMAGE_NT_HEADERS* ntHeaders = (IMAGE_NT_HEADERS*)((BYTE*)hModule + dosHeader->e_lfanew);
//
//    if (ntHeaders->Signature != IMAGE_NT_SIGNATURE)
//    {
//        return 0;
//    }
//
//    IMAGE_DATA_DIRECTORY* iatDirectory = &(ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT]);
//    IMAGE_IMPORT_DESCRIPTOR* importDescriptor = (IMAGE_IMPORT_DESCRIPTOR*)((BYTE*)hModule + iatDirectory->VirtualAddress);
//
//    while (importDescriptor->Name != 0)
//    {
//        char* moduleName = (char*)((BYTE*)hModule + importDescriptor->Name);
//        if (strcmp(moduleName, "kernel32.dll") == 0) // Replace "target_module.dll" with the actual module name
//        {
//            IMAGE_THUNK_DATA* thunkData = (IMAGE_THUNK_DATA*)((BYTE*)hModule + importDescriptor->FirstThunk);
//
//            while (thunkData->u1.Function != 0)
//            {
//                if (!(thunkData->u1.Ordinal & IMAGE_ORDINAL_FLAG))
//                {
//                    IMAGE_IMPORT_BY_NAME* importByName = (IMAGE_IMPORT_BY_NAME*)((BYTE*)hModule + thunkData->u1.AddressOfData);
//                    if (strcmp(reinterpret_cast<const char*>(importByName->Name), funcName) == 0)
//                    {
//                        DWORD oldProtection;
//                        VirtualProtect(&(thunkData->u1.Function), sizeof(DWORD), PAGE_EXECUTE_READWRITE, &oldProtection);
//                        DWORD original = thunkData->u1.Function;
//                        thunkData->u1.Function = newFunc;
//                        VirtualProtect(&(thunkData->u1.Function), sizeof(DWORD), oldProtection, &oldProtection);
//                        return original;
//                    }
//                }
//                thunkData++;
//            }
//        }
//        importDescriptor++;
//    }
//
//    return 0;
//}

typedef VOID (WINAPI _origSleep)(DWORD ms, DWORD b, DWORD c, DWORD d, DWORD e);
_origSleep* originalSleep =
(_origSleep*)hookIAT("PeekMessageA", (DWORD)&newSleepFunction);
VOID WINAPI newSleepFunction(DWORD ms, DWORD b, DWORD c, DWORD d, DWORD e)
{
	std::cout << "new sleep works\n";
	originalSleep(ms, b, c, d, e);
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
	//transaction = 10000; // final release won't see this line. also the idea will be to call this function
	                     // from a VF table to use other class members
	return __addToBudget(tclass, transaction); // return to location in zoo.exe
}