#include "ZTMapView.h"
#include "ZTUI.h"
#include "BFUIMgr.h"
#include "detours.h"

typedef void (__thiscall *_zoomMapWidgetCall)(void*);

// ZTMapView::ZTMapView() {
//     // constructor
// }

// ZTMapView::~ZTMapView() {
//     // destructor
// }

void ZTMapView::init() {
    // DWORD _clickZoomOut = 0x004b0779;
    // DetourTransactionBegin();
    // DetourUpdateThread(GetCurrentThread());
    // DetourAttach((PVOID*)&_clickZoomOut, (PVOID)ZTMapView::clickZoomOut);
    // DetourTransactionCommit();
}

void ZTMapView::zoomMap(int param_2) {
    // zoom map
    _zoomMap _ogzoomMap = (_zoomMap)0x004b072d;
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

// // // doesn't do anything yet
// void ZTMapView::clickZoomOut() {
//     if (ZTMapView::getMapView() != 0 && ZTWorldMgr::getWorldMgr() != 0) {
//         int* currentZoom = (int*)ZTWorldMgr::getOffset(0x14);
//         int zoom = *currentZoom - 2;
//         ZTMapView::zoomMap(zoom);
//         void* uiElem = BFUIMgr::getElement(1007);
//         _zoomMapWidgetCall func1 = (_zoomMapWidgetCall)0x0041914B;
//         func1(uiElem);
//         if (*currentZoom == -2) {
//             uiElem = BFUIMgr::getElement(1023);
//             _zoomMapWidgetCall func2 = (_zoomMapWidgetCall)0x00419191;
//             func2(uiElem);
//         }
//     }

// }

void ZTMapView::clickZoomOut() {
    _clickZoomOut _ogclickZoomOut = (_clickZoomOut)0x004b0779;
    _ogclickZoomOut();
}

void ZTMapView::clickZoomIn() {
    _clickZoomOut _ogclickZoomIn = (_clickZoomOut)0x004b081b;
    _ogclickZoomIn();
}

void ZTMapView::rotateCW() {
    _rotateCW _ogrotateCW = (_rotateCW)0x004b071a;
    _ogrotateCW();
}

void ZTMapView::rotateCCW() {
    _rotateCCW _ogrotateCCW = (_rotateCCW)0x00416cb7;
    _ogrotateCCW();
}