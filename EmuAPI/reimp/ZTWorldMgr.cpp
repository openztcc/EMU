
#include "ZTWorldMgr.h"
#include "ZTMapView.h"


DWORD ZTWorldMgr::getWorldMgr() {
    return *(DWORD*)((LPVOID)0x00638040);
}

DWORD ZTWorldMgr::getOffset(DWORD offset) {
    return (*((DWORD*)((LPVOID)0x00638040)) + offset);
}