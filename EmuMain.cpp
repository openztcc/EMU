#include "EmuMain.h"
#include "detours.h"
#include "EmuControls.h"
#include "ZTCheats.h"
#include "ZooState.h"

// #define instance 

//------ Function pointers 
DWORD updateAddress = 0x41a16b; // 0x00401644; // address of update function in game
typedef void(__thiscall* _origUpdate)(void* thisptr); // define original update function


EmuMain::EmuMain()
{
	this->IsConsoleRunning = false;
	this->CommandIsProcessing = false;
	this->HasConsoleOpenedOnce = false;
	this->ctrlMPressed = false;
	this->hasHooked = false;
	this->zoo_models = new ZooModels();
	this->console = new EmuConsole(tokens);
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
	EmuMain::shared_instance().HasConsoleOpenedOnce = true;

	HWND consoleWindow = EmuConsole::createConsole();

	while (EmuMain::shared_instance().IsConsoleRunning)
	{
		// ------ Tokenize the input
		if (!EmuMain::shared_instance().CommandIsProcessing)
		{
			std::cout << ">> ";
			EmuMain::shared_instance().CommandIsProcessing = true; // set flag to true to avoid multiple commands being processed at once
			EmuMain::shared_instance().console->tokenize(EmuMain::shared_instance().CommandIsProcessing);
		}
		Sleep(10);
	}

	// ------ Close the console window
	EmuMain::shared_instance().HasConsoleOpenedOnce = false;
	EmuMain::shared_instance().IsConsoleRunning = false;
	FreeConsole();
	Sleep(100);
	PostMessage(consoleWindow, WM_CLOSE, 0, 0);
	return 1;
}

void __fastcall EmuMain::RunEmu(void* thisptr) {

	// main loop

	EmuControls::procControls(); // process controls

	// if (!EmuMain::shared_instance().hasHooked) {
	// 	EmuControls::InitializeHook(); // initialize mouse hook

	// 	EmuMain::shared_instance().hasHooked = true;
	// }

	ZTCheats::InvisibleInvincibleCheat(); // run cheats

	// only run scripts while zoo is loaded and not in main menu
	if ((int)ZooState::object_ptr(0x0) > 0) {
		// f << "[" << timestamp << "] " << "Is no longer in main menu!" << std::endl;
		if (ZooState::IsZooLoaded() == true) {
			// f << "[" << timestamp << "] " << "Zoo is loaded!" << std::endl;
			if (!EmuMain::shared_instance().hasEmuRunOnce) {
				// f << "[" << timestamp << "] " << "Running emu_run scripts..." << std::endl;
				EmuMain::shared_instance().sm.ExecuteScripts("emu_gawk");
				EmuMain::shared_instance().hasEmuRunOnce = true;
				EmuMain::shared_instance().sm = EmuScriptMgr(); // TODO: create dumpScripts function for graceful cleanup
				// f << "[" << timestamp << "] " << "Scripts executed!" << std::endl;
			}
			*(EmuMain::shared_instance().zoo_models) = EmuMain::shared_instance().sm.ExecuteScripts("emu_run");
			// f << "[" << timestamp << "] " << "Scripts executed!" << std::endl;
		}
	}

	if (ZooState::IsZooLoaded() == false) {
		EmuMain::shared_instance().hasEmuRunOnce = false;

	}

	//---- Process the input tokens while console is running
	if (!EmuMain::shared_instance().tokens.empty() && EmuMain::shared_instance().IsConsoleRunning == true)
	{
		EmuMain::shared_instance().console->processInput(EmuMain::shared_instance().IsConsoleRunning);
		EmuMain::shared_instance().tokens.clear();
		EmuMain::shared_instance().CommandIsProcessing = false; // reset flag to allow another command to be tokenized
	}

	//---- return to original update function
	_origUpdate ogUpdate = (_origUpdate)updateAddress;
	// f << "[" << timestamp << "] " << "EMU loop finished!" << std::endl;

	ogUpdate(thisptr);

	// f << "[" << timestamp << "] " << "ogUpdate(thisptr) called!" << std::endl;
}