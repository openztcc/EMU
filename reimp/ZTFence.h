#ifndef ZTFENCE_H
#define ZTFENCE_H

#include "ZTScenery.h"

class ZTFence : public ZTScenery {
    public:
    ZTFence(void* ptr) : ZTScenery(ptr) {};
    int cStrength(); // 0x15C
    int cStrength(int); // 0x15C
    int cLife(); // 0x160
    int cLife(int); // 0x160
};

#endif // ZTFENCE_H