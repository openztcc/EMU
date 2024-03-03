#ifndef ZTBUILDINGTYPE_H
#define ZTBUILDINGTYPE_H

#include "ZTSceneryType.h"

class ZTBuildingType : public ZTSceneryType {
    public:
    char padding[112]; // 404
    ZTBuildingType();
    ~ZTBuildingType();
};

#endif // ZTBUILDINGTYPE_H