#ifndef ZTTANKFILTERTYPE_H
#define ZTTANKFILTERTYPE_H

#include "ZTSceneryType.h"

class ZTTankFilterType : public ZTSceneryType {
    public:
    char padding[72]; // 368
    ZTTankFilterType();
    ~ZTTankFilterType();
};

#endif // ZTTANKFILTERTYPE_H