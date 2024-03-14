#ifndef ZTPATHTYPE_H
#define ZTPATHTYPE_H

#include "ZTSceneryType.h"

// size: 296
// no difference from ZTSceneryType in byte space

class ZTPathType : public ZTSceneryType {
    public:
    ZTPathType(void* ptr) : ZTSceneryType(ptr) {};
    ~ZTPathType();

    
};

#endif // ZTPATHTYPE_H