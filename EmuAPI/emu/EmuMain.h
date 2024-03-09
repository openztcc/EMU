#ifndef EMUMAIN_H
#define EMUMAIN_H

#include "EmuBase.h"

class EmuMain
{
    public:
    static DWORD WINAPI ZooConsole();
    static void init();
    EmuMain();

    static EmuMain &shared_instance() {
        static EmuMain instance;
        return instance;
    }

    LPVOID lpParameter;

    //------ Flags for console
    bool IsConsoleRunning;
    bool CommandIsProcessing;
    bool HasConsoleOpenedOnce; // to avoid conflicts when console has not been opened yet

    std::vector<std::string> tokens; // contains tokens from console input
    EmuConsole *console; // console object

};

#endif // EMUMAIN_H