#ifndef ZTTANKWALLTYPE_H
#define ZTTANKWALLTYPE_H

#include "ZTFenceType.h"

class ZTTankWallType : public ZTFenceType {
    public:
    bool cPortalOpenSoundAtten(); // 0x1BC
    bool cPortalOpenSoundAtten(bool); // 0x1BC
    bool cPortalCloseSoundAtten(); // 0x1C0
    bool cPortalCloseSoundAtten(bool); // 0x1C0
    ZTTankWallType(void* ptr) : ZTFenceType(ptr) {};
    static void ExportClassToLua(sol::state_view&);
    ~ZTTankWallType() {};
};

#endif // ZTTANKWALLTYPE_H