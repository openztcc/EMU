#ifndef ZTMAINTYPE_H
#define ZTMAINTYPE_H

#include "ZTUnitType.h"

class ZTMainType : public ZTUnitType {
    public:
    char padding[40]; // 640
    ZTMainType();
    ~ZTMainType();
};

#endif // ZTMAINTYPE_H