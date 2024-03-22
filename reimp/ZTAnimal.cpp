#include "ZTAnimal.h"

void ZTAnimal::hatchEgg()
{
    _hatchegg original = (_hatchegg)0x00613ca6;
    original(this->thisptr);
}

void ZTAnimal::ExportClassToLua(sol::state_view& lua)
{
    lua.new_usertype<ZTAnimal>("ZTAnimal",
        "new", sol::constructors<sol::types<void*>>(),
        "hatchEgg", &ZTAnimal::hatchEgg,
        sol::base_classes, sol::bases<BFUnit, ZTUnit>()
    );
}