#include "EmuMain.h"
#include "EmuConsole.h"
#include "detours.h"

#define instance EmuMain::shared_instance()

//------ Function pointers 
DWORD updateAddress = 0x41a16b; // 0x00401644; // address of update function in game
typedef void (__thiscall *_origUpdate)(void* thisptr); // define original update function


EmuMain::EmuMain()
{
	IsConsoleRunning = false;
	CommandIsProcessing = false;
	HasConsoleOpenedOnce = false;
	console = new EmuConsole(tokens);
}

void EmuMain::init()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach((PVOID*)&updateAddress, (PVOID)&RunEmu);
	DetourTransactionCommit();
}

DWORD WINAPI EmuMain::ZooConsole()
{
	instance.HasConsoleOpenedOnce = true;

	HWND consoleWindow = EmuConsole::createConsole();
	
	while (instance.IsConsoleRunning)
	{
		// ------ Tokenize the input
		if (!instance.CommandIsProcessing)
		{
			std::cout << ">> ";
			instance.CommandIsProcessing = true; // set flag to true to avoid multiple commands being processed at once
			instance.console->tokenize(instance.CommandIsProcessing);
		}
		Sleep(10);
	}

	// ------ Close the console window
	instance.HasConsoleOpenedOnce = false;
	instance.IsConsoleRunning = false;
	FreeConsole();
	Sleep(100);
	PostMessage(consoleWindow, WM_CLOSE, 0, 0);
	return 1;
}

void __fastcall RunEmu(void* thisptr) { 

	// main loop

	if (!hasHooked) {
		InitializeHook(); // initialize mouse hook

		hasHooked = true;
	}

	// only run scripts while zoo is loaded and not in main menu
	if ((int)ZooState::object_ptr(0x0) > 0) {
		// f << "[" << timestamp << "] " << "Is no longer in main menu!" << std::endl;
		if (ZooState::IsZooLoaded() == true) {
			// f << "[" << timestamp << "] " << "Zoo is loaded!" << std::endl;
			*zoo_models = sm.executeScripts();
			// f << "[" << timestamp << "] " << "Scripts executed!" << std::endl;
		}
	}

	//---- Process the input tokens while console is running
	if (!instance.tokens.empty() && EmuMain::shared_instance().IsConsoleRunning == true)
	{
		instance.console->processInput(EmuMain::shared_instance().IsConsoleRunning);
		instance.tokens.clear();
		EmuMain::shared_instance().CommandIsProcessing = false; // reset flag to allow another command to be tokenized
	}

	//---- return to original update function
	_origUpdate ogUpdate = (_origUpdate)updateAddress;
	// f << "[" << timestamp << "] " << "EMU loop finished!" << std::endl;
	
	ogUpdate(thisptr);

	// f << "[" << timestamp << "] " << "ogUpdate(thisptr) called!" << std::endl;
}
