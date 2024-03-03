#ifndef ZTFENCETYPE_H
#define ZTFENCETYPE_H

#include "ZTSceneryType.h"

class ZTFenceType : public ZTSceneryType {
    public:
    char padding[32]; // 324
    ZTFenceType();
    ~ZTFenceType();
};

#endif // ZTFENCETYPE_H