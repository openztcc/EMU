#ifndef ZTGUIDETYPE_H
#define ZTGUIDETYPE_H

#include "ZTStaffType.h"

class ZTGuideType : public ZTStaffType {
    public:
    char padding[24]; // 624
    ZTGuideType();
    ~ZTGuideType();
};

#endif // ZTGUIDETYPE_H