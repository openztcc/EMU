#ifndef ZTWORDLMGR_H
#define ZTWORDLMGR_H

#include "Windows.h"


class ZTWorldMgr {
    public:
    char padding[536];
    ZTWorldMgr();
    ~ZTWorldMgr();

    static DWORD getWorldMgr();
    static DWORD getOffset(DWORD);
};

#endif // ZTWORDLMGR_H
