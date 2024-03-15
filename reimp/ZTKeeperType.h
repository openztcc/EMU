#ifndef ZTKEEPERTYPE_H
#define ZTKEEPERTYPE_H

#include "ZTStaffType.h"

class ZTKeeperType : public ZTStaffType {
    public:
    char padding[24]; // 624
    ZTKeeperType();
    ~ZTKeeperType();
};

#endif // ZTKEEPERTYPE_H