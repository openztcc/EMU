#ifndef ZTHELICOPTERTYPE_H
#define ZTHELICOPTERTYPE_H

#include "ZTStaffType.h"

class ZTHelicopterType : public ZTStaffType {
    public:
    char padding[24]; // 624
    ZTHelicopterType();
    ~ZTHelicopterType();
};

#endif // ZTHELICOPTERTYPE_H