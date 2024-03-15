#ifndef ZTANIMALTYPE_H
#define ZTANIMALTYPE_H

#include "ZTUnitType.h"

class ZTAnimalType : public ZTUnitType {
    public:
    char padding[324]; // 864
    ZTAnimalType();
    ~ZTAnimalType();
};

#endif // ZTANIMALTYPE_H