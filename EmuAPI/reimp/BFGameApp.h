#ifndef BFGameApp_h
#define BFGameApp_h

#include "EmuBase.h"

typedef void (__thiscall *_incSimSpeed)(void* thisptr);

class BFGameApp {
    public:
    void init();
    static DWORD instance(DWORD offset);
    static void incSimSpeed();
};

#endif