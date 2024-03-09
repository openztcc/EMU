#include "EmuMain.h"
#include "EmuConsole.h"

DWORD WINAPI EmuMain::ZooConsole(LPVOID lpParameter, EmuConsole console, bool &IsConsoleRunning, bool &CommandIsProcessing, bool &HasConsoleOpenedOnce)
{
	HasConsoleOpenedOnce = true;

	HWND consoleWindow = EmuConsole::createConsole();

    EmuConsole 
	
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
