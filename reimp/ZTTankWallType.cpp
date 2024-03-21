#include "ZTTankWallType.h"
#include "Windows.h"

bool ZTTankWallType::cPortalOpenSoundAtten() {
    return *(bool*)((DWORD)this->thisptr + 0x180);
}

bool ZTTankWallType::cPortalOpenSoundAtten(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x180) = input;
    return input;
}

bool ZTTankWallType::cPortalCloseSoundAtten() {
    return *(bool*)((DWORD)this->thisptr + 0x184);
}

bool ZTTankWallType::cPortalCloseSoundAtten(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x184) = input;
    return input;
}

void ZTTankWallType::ExportClassToLua(sol::state_view& lua) {
    lua.new_usertype<ZTTankWallType>("ZTTankWallType",
        sol::constructors<ZTTankWallType(void*)>(),
        "cPortalOpenSoundAtten", sol::overload(
            sol::resolve<bool()>(static_cast<bool(ZTTankWallType::*)()>(&ZTTankWallType::cPortalOpenSoundAtten)),
            sol::resolve<bool(bool)>(static_cast<bool(ZTTankWallType::*)(bool)>(&ZTTankWallType::cPortalOpenSoundAtten))
        ),
        "cPortalCloseSoundAtten", sol::overload(
            sol::resolve<bool()>(static_cast<bool(ZTTankWallType::*)()>(&ZTTankWallType::cPortalCloseSoundAtten)),
            sol::resolve<bool(bool)>(static_cast<bool(ZTTankWallType::*)(bool)>(&ZTTankWallType::cPortalCloseSoundAtten))
        ),
        sol::base_classes, sol::bases<BFEntityType, ZTSceneryType>()
    );
}