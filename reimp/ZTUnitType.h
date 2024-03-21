#ifndef ZTUNITTYPE_H
#define ZTUNITTYPE_H

#include "BFUnitType.h"

class ZTUnitType : public BFUnitType {
    public:
    char padding[76]; // 540
    ZTUnitType();
    ~ZTUnitType();
};

#endif // ZTUNITTYPE_H