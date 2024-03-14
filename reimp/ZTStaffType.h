#ifndef ZTSTAFFTYPE_H
#define ZTSTAFFTYPE_H

#include "ZTUnitType.h"

class ZTStaffType : public ZTUnitType {
    public:
    char padding[60]; // 600
    ZTStaffType();
    ~ZTStaffType();
};

#endif // ZTSTAFFTYPE_H