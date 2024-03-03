#ifndef ZTRUBBLETYPE_H
#define ZTRUBBLETYPE_H

#include "ZTSceneryType.h"

class ZTRubbleType : public ZTSceneryType {
    public:
    char padding[12]; // 304
    ZTRubbleType();
    ~ZTRubbleType();
};

#endif // ZTRUBBLETYPE_H