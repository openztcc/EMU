#include "ZTMapView.h"
#include "ZTUI.h"

// ZTMapView::ZTMapView() {
//     // constructor
// }

// ZTMapView::~ZTMapView() {
//     // destructor
// }

void ZTMapView::zoomMap(int param_2) {
    // zoom map
    // void *pZTMapView = reinterpret_cast<void*>(0x00638068);
    DWORD ptr_ZTMapView = *((DWORD*)((LPVOID)0x00638068));
    // 004b072d
    _zoomMap _ogzoomMap = (_zoomMap)0x004b072d;
    _ogzoomMap((LPVOID)ptr_ZTMapView, param_2);
}

DWORD getOffset(DWORD offset)
{
    return (*((DWORD*)((LPVOID)0x00638068)) + offset);
}

// Live version of the ZTMapView state
DWORD ZTMapView::getMapView() {
    return *((DWORD*)((LPVOID)0x00638068));
}

void ZTMapView::clickZoomOut() {
    int* currentZoom = (int*)ZTWorldMgr::getOffset(0x14);
    int* uiElem;

    if (getMapView() != 0 && ZTWorldMgr::getWorldMgr() != 0 && *currentZoom != -2) {
        zoomMap(*currentZoom - 2);
        uiElem = BFUIMgr::getElement(1007);
    }
	if (*currentZoom == -2) {
        uiElem = BFUIMgr::getElement(1023);
    }
}
