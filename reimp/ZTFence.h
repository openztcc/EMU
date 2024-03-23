#ifndef ZTFENCE_H
#define ZTFENCE_H

#include "ZTScenery.h"
#include "sol/sol.hpp"

typedef void (__thiscall *_setHealthy)(void*); // define original setHealthy function

class ZTFence : public ZTScenery {
    public:
    ZTFence(void* ptr) : ZTScenery(ptr) {};
    int strength(); // 0x15C
    int strength(int); // 0x15C
    int life(); // 0x160
    int life(int); // 0x160

    void setHealthy(); // 0x005B391C

    static void ExportClassToLua(sol::state_view&);
};

#endif // ZTFENCE_H