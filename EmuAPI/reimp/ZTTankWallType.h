#ifndef ZTTANKWALLTYPE_H
#define ZTTANKWALLTYPE_H

#include "ZTFenceType.h"

class ZTTankWallType : public ZTFenceType {
    public:
    char padding[652]; // 976
    ZTTankWallType();
    ~ZTTankWallType();
};

#endif // ZTTANKWALLTYPE_H