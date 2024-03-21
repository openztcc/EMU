#include "ZTFenceType.h"
#include <string>
#include <Windows.h> // must always be above detours.h

bool ZTFenceType::cIsShowFence() {
    return *(bool*)((DWORD)this->thisptr + 0x06F);
}

bool ZTFenceType::cIsShowFence(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x06F) = input;
    return input;
}

int ZTFenceType::cStrength() {
    return *(int*)((DWORD)this->thisptr + 0x168);
}

int ZTFenceType::cStrength(int input) {
    *(int*)((DWORD)this->thisptr + 0x168) = input;
    return input;
}

int ZTFenceType::cLife() {
    return *(int*)((DWORD)this->thisptr + 0x16C);
}

int ZTFenceType::cLife(int input) {
    *(int*)((DWORD)this->thisptr + 0x16C) = input;
    return input;
}

int ZTFenceType::cDecayedLife() {
    return *(int*)((DWORD)this->thisptr + 0x170);
}

int ZTFenceType::cDecayedLife(int input) {
    *(int*)((DWORD)this->thisptr + 0x170) = input;
    return input;
}

int ZTFenceType::cDecayedDelta() {
    return *(int*)((DWORD)this->thisptr + 0x174);
}

int ZTFenceType::cDecayedDelta(int input) {
    *(int*)((DWORD)this->thisptr + 0x174) = input;
    return input;
}

int ZTFenceType::cBreakSoundAtten() {
    return *(int*)((DWORD)this->thisptr + 0x178);
}

int ZTFenceType::cBreakSoundAtten(int input) {
    *(int*)((DWORD)this->thisptr + 0x178) = input;
    return input;
}

int ZTFenceType::cOpenSoundAtten() {
    return *(int*)((DWORD)this->thisptr + 0x17C);
}

int ZTFenceType::cOpenSoundAtten(int input) {
    *(int*)((DWORD)this->thisptr + 0x17C) = input;
    return input;
}

std::string ZTFenceType::cBreakSound() {
    return *(std::string*)((DWORD)this->thisptr + 0x184);
}

std::string ZTFenceType::cBreakSound(std::string input) {
    *(std::string*)((DWORD)this->thisptr + 0x184) = input;
    return input;
}

std::string ZTFenceType::cOpenSound() {
    return *(std::string*)((DWORD)this->thisptr + 0x188);
}

std::string ZTFenceType::cOpenSound(std::string input) {
    *(std::string*)((DWORD)this->thisptr + 0x188) = input;
    return input;
}

bool ZTFenceType::cSeeThrough() {
    return *(bool*)((DWORD)this->thisptr + 0x194);
}

bool ZTFenceType::cSeeThrough(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x194) = input;
    return input;
}

bool ZTFenceType::cIsJumpable() {
    return *(bool*)((DWORD)this->thisptr + 0x195);
}

bool ZTFenceType::cIsJumpable(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x195) = input;
    return input;
}

bool ZTFenceType::cIsClimbable() {
    return *(bool*)((DWORD)this->thisptr + 0x196);
}

bool ZTFenceType::cIsClimbable(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x196) = input;
    return input;
}

bool ZTFenceType::cIndestructable() {
    return *(bool*)((DWORD)this->thisptr + 0x197);
}

bool ZTFenceType::cIndestructable(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x197) = input;
    return input;
}

bool ZTFenceType::cIsElectrified() {
    return *(bool*)((DWORD)this->thisptr + 0x198);
}

bool ZTFenceType::cIsElectrified(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x198) = input;
    return input;
}

bool ZTFenceType::cNoDrawWater() {
    return *(bool*)((DWORD)this->thisptr + 0x199);
}

bool ZTFenceType::cNoDrawWater(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x199) = input;
    return input;
}

void ZTFenceType::ExportClassToLua(sol::state_view& lua)
{
    lua.new_usertype<ZTFenceType>("ZTFenceType",
        sol::constructors<ZTFenceType(void*)>(),
        "cIsShowFence", sol::overload(
            sol::resolve<bool()>(static_cast<bool(ZTFenceType::*)()>(&ZTFenceType::cIsShowFence)),
            sol::resolve<bool(bool)>(static_cast<bool(ZTFenceType::*)(bool)>(&ZTFenceType::cIsShowFence))
        ),
        "cStrength", sol::overload(
            sol::resolve<int()>(static_cast<int(ZTFenceType::*)()>(&ZTFenceType::cStrength)),
            sol::resolve<int(int)>(static_cast<int(ZTFenceType::*)(int)>(&ZTFenceType::cStrength))
        ),
        "cLife", sol::overload(
            sol::resolve<int()>(static_cast<int(ZTFenceType::*)()>(&ZTFenceType::cLife)),
            sol::resolve<int(int)>(static_cast<int(ZTFenceType::*)(int)>(&ZTFenceType::cLife))
        ),
        "cDecayedLife", sol::overload(
            sol::resolve<int()>(static_cast<int(ZTFenceType::*)()>(&ZTFenceType::cDecayedLife)),
            sol::resolve<int(int)>(static_cast<int(ZTFenceType::*)(int)>(&ZTFenceType::cDecayedLife))
        ),
        "cDecayedDelta", sol::overload(
            sol::resolve<int()>(static_cast<int(ZTFenceType::*)()>(&ZTFenceType::cDecayedDelta)),
            sol::resolve<int(int)>(static_cast<int(ZTFenceType::*)(int)>(&ZTFenceType::cDecayedDelta))
        ),
        "cBreakSoundAtten", sol::overload(
            sol::resolve<int()>(static_cast<int(ZTFenceType::*)()>(&ZTFenceType::cBreakSoundAtten)),
            sol::resolve<int(int)>(static_cast<int(ZTFenceType::*)(int)>(&ZTFenceType::cBreakSoundAtten))
        ),
        "cOpenSoundAtten", sol::overload(
            sol::resolve<int()>(static_cast<int(ZTFenceType::*)()>(&ZTFenceType::cOpenSoundAtten)),
            sol::resolve<int(int)>(static_cast<int(ZTFenceType::*)(int)>(&ZTFenceType::cOpenSoundAtten))
        ),
        "cBreakSound", sol::overload(
            sol::resolve<std::string()>(static_cast<std::string(ZTFenceType::*)()>(&ZTFenceType::cBreakSound)),
            sol::resolve<std::string(std::string)>(static_cast<std::string(ZTFenceType::*)(std::string)>(&ZTFenceType::cBreakSound))
        ),
        "cOpenSound", sol::overload(
            sol::resolve<std::string()>(static_cast<std::string(ZTFenceType::*)()>(&ZTFenceType::cOpenSound)),
            sol::resolve<std::string(std::string)>(static_cast<std::string(ZTFenceType::*)(std::string)>(&ZTFenceType::cOpenSound))
        ),
        "cSeeThrough", sol::overload(
            sol::resolve<bool()>(static_cast<bool(ZTFenceType::*)()>(&ZTFenceType::cSeeThrough)),
            sol::resolve<bool(bool)>(static_cast<bool(ZTFenceType::*)(bool)>(&ZTFenceType::cSeeThrough))
        ),
        "cIsJumpable", sol::overload(
            sol::resolve<bool()>(static_cast<bool(ZTFenceType::*)()>(&ZTFenceType::cIsJumpable)),
            sol::resolve<bool(bool)>(static_cast<bool(ZTFenceType::*)(bool)>(&ZTFenceType::cIsJumpable))
        ),
        sol::base_classes, sol::bases<BFEntityType, ZTSceneryType>()
    );
}