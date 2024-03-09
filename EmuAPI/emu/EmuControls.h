#ifndef EMUCONTROLS_H
#define EMUCONTROLS_H

#include "BFUIMgr.h"
#include "EmuBase.h"
#include "ZooState.h"
#include "EmuConsole.h"
#include "EmuMain.h"

class EmuControls
{
    public:
    static void procControls(bool&, bool&);
    static LRESULT CALLBACK LowLevelMouseProc(int, WPARAM, LPARAM);
    static bool InitializeHook();
};

#endif // EMUCONTROLS_H