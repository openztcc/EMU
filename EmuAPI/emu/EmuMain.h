#ifndef EMUMAIN_H
#define EMUMAIN_H

#include "EmuBase.h"

class EmuMain
{
    public:
    static DWORD WINAPI ZooConsole(LPVOID, bool&, bool&, bool&);

    static EmuMain &shared_instance() {
        static EmuMain instance;
        return instance;
    }

    

};

#endif // EMUMAIN_H