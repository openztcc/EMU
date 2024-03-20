#ifndef ZTFENCETYPE_H
#define ZTFENCETYPE_H

#include "ZTSceneryType.h"
#include <sol/sol.hpp>

class ZTFenceType : public ZTSceneryType {
    public:
    // char padding[32]; // 324
    bool cIsShowFence(); // 0x06F
    bool cIsShowFence(bool); // 0x06F
    int cStrength(); // 0x168
    int cStrength(int); // 0x168
    int cLife(); // 0x16C
    int cLife(int); // 0x16C
    int cDecayedLife(); // 0x170
    int cDecayedLife(int); // 0x170
    int cDecayedDelta(); // 0x174
    int cDecayedDelta(int); // 0x174
    int cBreakSoundAtten(); // 0x178
    int cBreakSoundAtten(int); // 0x178
    int cOpenSoundAtten(); // 0x17C
    int cOpenSoundAtten(int); // 0x17C
    std::string cBreakSound(); // 0x184
    std::string cBreakSound(std::string); // 0x184
    std::string cOpenSound(); // 0x188
    std::string cOpenSound(std::string); // 0x188
    bool cSeeThrough(); // 0x194
    bool cSeeThrough(bool); // 0x194
    bool cIsJumpable(); // 0x195
    bool cIsJumpable(bool); // 0x195
    bool cIsClimbable(); // 0x196
    bool cIsClimbable(bool); // 0x196
    bool cIndestructable(); // 0x197
    bool cIndestructable(bool); // 0x197
    bool cIsElectrified(); // 0x198
    bool cIsElectrified(bool); // 0x198
    bool cNoDrawWater(); // 0x199
    bool cNoDrawWater(bool); // 0x199
    ZTFenceType(void* ptr) : ZTSceneryType(ptr) {};
    static void ExportClassToLua(sol::state_view&);
    ~ZTFenceType();
};

#endif // ZTFENCETYPE_H