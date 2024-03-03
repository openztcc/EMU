#ifndef ZTMAPVIEW_H
#define ZTMAPVIEW_H

class ZTMapView {
    public:
    char padding[1444];
    static ZTMapView &shared_instance() {
        ZTMapView *ztmapview = reinterpret_cast<ZTMapView*>(0x00511054);
        static ZTMapView instance = *ztmapview;
        return instance;
    }
};

#endif // ZTMAPVIEW_H