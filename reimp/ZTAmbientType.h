#ifndef ZTAMBIENTTYPE_H
#define ZTAMBIENTTYPE_H

#include "BFOverlayType.h"

class ZTAmbientType : public BFOverlayType {
    public:
    char padding[12]; // 300
    ZTAmbientType();
    ~ZTAmbientType();
};

#endif // ZTAMBIENTTYPE_H