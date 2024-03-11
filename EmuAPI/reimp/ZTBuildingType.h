#ifndef ZTBUILDINGTYPE_H
#define ZTBUILDINGTYPE_H

#include "ZTSceneryType.h"
#include <string>

class ZTBuildingType : public ZTSceneryType {
    public:
    ZTBuildingType(void* ptr) : ZTSceneryType(ptr) {};
};

#endif // ZTBUILDINGTYPE_H