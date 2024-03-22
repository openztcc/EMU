#include "ZTAnimal.h"
#include "Windows.h"

void ZTAnimal::hatchEgg()
{
    _hatchegg original = (_hatchegg)0x00613ca6;
    original(this->thisptr);
}

bool ZTAnimal::hasHatched()
{
    return *(bool*)((DWORD)this->thisptr + 0x070);
}

void ZTAnimal::ExportClassToLua(sol::state_view& lua)
{
    lua.new_usertype<ZTAnimal>("ZTAnimal",
        "new", sol::constructors<sol::types<void*>>(),
        "hatchEgg", &ZTAnimal::hatchEgg,
        "hasHatched", &ZTAnimal::hasHatched,
        sol::base_classes, sol::bases<ZTUnit, BFUnit, BFEntity>()
    );
}