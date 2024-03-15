#ifndef EMUCONTROLS_H
#define EMUCONTROLS_H

#include "EmuBase.h"

#include "EmuConsole.h"


class BFUIMgr;
class ZooState;
class EmuMain;

class EmuControls
{
public:
    static void procControls();
    static LRESULT CALLBACK LowLevelMouseProc(int, WPARAM, LPARAM);
    static bool InitializeHook();
};

#endif // EMUCONTROLS_H