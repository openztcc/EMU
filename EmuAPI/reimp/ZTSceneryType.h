#ifndef ZTSCENERYTYPE_H
#define ZTSCENERYTYPE_H

#include "BFEntityType.h"

class ZTSceneryType : public BFEntityType {
    public:
    char padding[4]; // 292
    ZTSceneryType();
    ~ZTSceneryType();
};

#endif // ZTSCENERYTYPE_H