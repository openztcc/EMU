#include "ZTFence.h"
#include "ZTScenery.h"

int ZTFence::strength() {
    return *(int*)((char*)this->thisptr + 0x15C);
}

int ZTFence::life(int value) {
    return *(int*)((char*)this->thisptr + 0x160) = value;
}

int ZTFence::life() {
    return *(int*)((char*)this->thisptr + 0x160);
}  

int ZTFence::strength(int value) {
    return *(int*)((char*)this->thisptr + 0x15C) = value;
}

void ZTFence::setHealthy() {
    _setHealthy original = (_setHealthy)0x005B391C;
    original(this->thisptr);
}

void ZTFence::ExportClassToLua(sol::state_view& lua) {
    lua.new_usertype<ZTFence>("ZTFence",
        "new", sol::constructors<sol::types<void*>>(),
        "strength", sol::overload(
            sol::resolve<int()>(static_cast<int(ZTFence::*)()>(&ZTFence::strength)),
            sol::resolve<int(int)>(static_cast<int(ZTFence::*)(int)>(&ZTFence::strength))
        ),
        "life", sol::overload(
            sol::resolve<int()>(static_cast<int(ZTFence::*)()>(&ZTFence::life)),
            sol::resolve<int(int)>(static_cast<int(ZTFence::*)(int)>(&ZTFence::life))
        ),
        "setHealthy", &ZTFence::setHealthy,
        sol::base_classes, sol::bases<ZTScenery, BFEntity>()
    );
}