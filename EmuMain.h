#ifndef EMUMAIN_H
#define EMUMAIN_H

#include "EmuScriptMgr.h"
#include "ZooModels.h"
#include "windows.h"
#include "EmuConsole.h"

class EmuMain
{
public:
    static DWORD WINAPI ZooConsole();
    static void __fastcall RunEmu(void*);
    static void init();
    EmuMain();

    LPVOID lpParameter;
    ZooModels* zoo_models;

    //------ Flags for console
    bool IsConsoleRunning;
    bool CommandIsProcessing;
    bool HasConsoleOpenedOnce; // to avoid conflicts when console has not been opened yet

    //------ Flags for keypresses
    bool ctrlMPressed;

    //------ Flags for hooks
    bool hasHooked;

    //------ Flags for script manager
    bool hasEmuRunOnce;

    EmuScriptMgr emu_run; // script manager object
    EmuScriptMgr emu_gawk;

    std::vector<std::string> tokens; // contains tokens from console input
    EmuConsole* console; // console object

    static EmuMain& shared_instance() {
        static EmuMain instance;
        return instance;
    }

};

#endif // EMUMAIN_H