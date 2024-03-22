#ifndef ZTANIMAL_H
#define ZTANIMAL_H

#include "ZTUnit.h"

typedef void (__thiscall *_hatchegg)(void* thisptr); // define original hatchEgg function

class ZTAnimal : public ZTUnit
{
public:
    ZTAnimal(void* ptr) : ZTUnit(ptr) {};
    static void ExportClassToLua(sol::state_view&);
    void hatchEgg(); // 0x00613ca6
    bool hasHatched(); // 0x070
};

#endif // ZTANIMAL_H