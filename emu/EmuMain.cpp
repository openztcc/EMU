#include "EmuMain.h"
#include "detours.h"
#include "EmuControls.h"
#include "ZTCheats.h"
#include "ZTGameMgr.h"

#define singleton EmuMain::shared_instance()

// #define instance 

//------ Function pointers 
DWORD updateAddress = 0x41a16b; // 0x00401644; // address of update function in game
typedef void(__thiscall* _origUpdate)(void* thisptr); // define original update function


EmuMain::EmuMain()
{
	this->IsConsoleRunning = false;
	this->hasEmuRunOnce = false;
	this->CommandIsProcessing = false;
	this->HasConsoleOpenedOnce = false;
	this->ctrlMPressed = false;
	this->hasHooked = false;
	this->console = new EmuConsole(this->tokens);
	this->cached_month = 0;
	this->vanishGuardCheck = false;
}

void EmuMain::init()
{
	singleton.emu_run.InitEmuAPI();
	singleton.emu_gawk.InitEmuAPI();
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach((PVOID*)&updateAddress, (PVOID)&RunEmu);
	DetourTransactionCommit();
	singleton.hasEmuRunOnce = false;
}

DWORD WINAPI EmuMain::ZooConsole()
{
	singleton.HasConsoleOpenedOnce = true;

	HWND consoleWindow = EmuConsole::createConsole();

	while (singleton.IsConsoleRunning)
	{
		// ------ Tokenize the input
		if (!singleton.CommandIsProcessing)
		{
			singleton.console->WriteToConsole(">> ");
			singleton.CommandIsProcessing = true; // set flag to true to avoid multiple commands being processed at once
			singleton.console->tokenize(singleton.CommandIsProcessing);
		}
		Sleep(10);
	}

	// ------ Close the console window
	singleton.HasConsoleOpenedOnce = false;
	singleton.IsConsoleRunning = false;
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

	// ZTCheats::InvisibleInvincibleCheat(); // run cheats

	// only run scripts while zoo is loaded and not in main menu
	if ((int)ZTGameMgr::instance(0x0) > 0) {
		// f << "[" << timestamp << "] " << "Is no longer in main menu!" << std::endl;
		if (ZTGameMgr::isZooLoaded() == true) {
			// f << "[" << timestamp << "] " << "Zoo is loaded!" << std::endl;
			if (singleton.hasEmuRunOnce == false) {
				// f << "[" << timestamp << "] " << "Running emu_run scripts..." << std::endl;
				singleton.emu_gawk.ExecuteScripts();
				singleton.emu_gawk.TransferTableState(singleton.emu_run.lua, "emu");
				singleton.cached_month = ZTGameMgr::getMonth();
				singleton.hasEmuRunOnce = true;
				// f << "[" << timestamp << "] " << "Scripts executed!" << std::endl;
			}
			singleton.emu_run.ExecuteScripts();
			// f << "[" << timestamp << "] " << "Scripts executed!" << std::endl;
		}
	}

	if (ZTGameMgr::isZooLoaded() == false) {
		EmuMain::shared_instance().hasEmuRunOnce = false;

	}

	//---- Process the input tokens while console is running
	if (!EmuMain::shared_instance().tokens.empty() && EmuMain::shared_instance().IsConsoleRunning == true)
	{
		EmuMain::shared_instance().console->processInput(EmuMain::shared_instance().IsConsoleRunning);
		EmuMain::shared_instance().tokens.clear();
		EmuMain::shared_instance().CommandIsProcessing = false; // reset flag to allow another command to be tokenized
	}

	// ---- vanishGuard check: reinforce fences every 4 months
	if (singleton.vanishGuardCheck)
	{
		// if the current month is different from the cached month, increment the month count
		if (singleton.cached_month != ZTGameMgr::getMonth() && singleton.monthCount < 4)
		{
			singleton.cached_month = ZTGameMgr::getMonth();
			singleton.monthCount++;
		}
		// if the month count is 4, reinforce the fences and reset the month count
		else if (singleton.monthCount == 4)
		{
			ZTWorldMgr::ReinforceFences();
			singleton.monthCount = 0;
		}
	}

	//---- return to original update function
	_origUpdate ogUpdate = (_origUpdate)updateAddress;
	// f << "[" << timestamp << "] " << "EMU loop finished!" << std::endl;

	ogUpdate(thisptr);

	// f << "[" << timestamp << "] " << "ogUpdate(thisptr) called!" << std::endl;
}