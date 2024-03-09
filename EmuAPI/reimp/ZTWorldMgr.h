#ifndef ZTWORDLMGR_H
#define ZTWORDLMGR_H

#include "Windows.h"
#include <vector>

class ZTWorldMgr {
    public:
    char padding[536];
    ZTWorldMgr();
    ~ZTWorldMgr();

    static void* getWorldMgr();
    static DWORD getOffset(DWORD);

    static std::vector<DWORD*> getAllEntitiesOfType(DWORD*, DWORD*, int ids[]);
    static void makeInvisible(std::vector<DWORD*>);
};

#endif // ZTWORDLMGR_H
