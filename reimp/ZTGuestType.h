#ifndef ZTGUESTTYPE_H
#define ZTGUESTTYPE_H

#include "ZTUnitType.h"

class ZTGuestType : public ZTUnitType {
    public:
    char padding[216]; // 756
    ZTGuestType();
    ~ZTGuestType();
};

#endif // ZTGUESTTYPE_H