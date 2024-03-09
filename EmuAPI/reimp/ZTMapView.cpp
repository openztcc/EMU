#include "ZTMapView.h"
#include "ZTUI.h"
#include "BFUIMgr.h"

typedef void (__thiscall *_zoomMapWidgetCall)(void*);

// ZTMapView::ZTMapView() {
//     // constructor
// }

// ZTMapView::~ZTMapView() {
//     // destructor
// }

void ZTMapView::zoomMap(int param_2) {
    // zoom map
    _zoomMap _ogzoomMap = (_zoomMap)0x004c85c0;
    _ogzoomMap(getMapView(), param_2);
}

DWORD getOffset(DWORD offset)
{
    return (*((DWORD*)((LPVOID)0x00638068)) + offset);
}

// Live version of the ZTMapView state
void* ZTMapView::getMapView() {
    return (void*)0x00638068;
}

// doesn't do anything yet
void ZTMapView::clickZoomOut() {
    int* currentZoom = (int*)ZTWorldMgr::getOffset(0x14);
    void* uiElem;
    uiElem = BFUIMgr::getElement(1023);
    _zoomMapWidgetCall func1 = (_zoomMapWidgetCall)0x0041914B;
    func1(uiElem);
    if (ZTMapView::getMapView() != 0 && ZTWorldMgr::getWorldMgr() != 0) {
        int zoom = *currentZoom - 2;
        ZTMapView::zoomMap(zoom);
        uiElem = BFUIMgr::getElement(1007);
        if (*currentZoom == -2) {
            uiElem = BFUIMgr::getElement(1023);
            _zoomMapWidgetCall func2 = (_zoomMapWidgetCall)0x00419191;
            func2(uiElem);
        }
    }

}
