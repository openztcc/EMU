#ifndef ZTMAPVIEW_H
#define ZTMAPVIEW_H

#include "ZTWorldMgr.h"
#include "EmuBase.h"


typedef void (__thiscall *_zoomMap)(void*, int); // define original zoomMap function

class ZTMapView {
    public:
    char padding[1444];
    static ZTMapView &shared_instance() {
        ZTMapView *ztmapview = reinterpret_cast<ZTMapView*>(0x00511054);
        static ZTMapView instance = *ztmapview;
        return instance;
    }
    static void* getMapView();
    static void zoomMap(int);
    static void clickZoomOut();
};

#endif // ZTMAPVIEW_H