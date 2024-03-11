#ifndef ZTBUILDINGTYPE_H
#define ZTBUILDINGTYPE_H

#include "ZTSceneryType.h"

class ZTBuildingType : public ZTSceneryType {
    public:
    ZTBuildingType(void*);
    int ncolors(); // 0x038
    int ncolors(int); // 0x038
    bool cIconZoom(); // 0x050
    bool cIconZoom(bool); // 0x050
    bool cExpansionID(); // 0x054 maybe int?
    bool cExpansionID(bool); // 0x054
    bool cMovable(); // 0x055
    bool cMovable(bool); // 0x055
    bool walkable(); // 0x056
    bool walkable(bool); // 0x056
    bool walkableByTall(); // 0x057
    bool walkableByTall(bool); // 0x057
    bool cRubbleable(); // 0x059
    bool cRubbleable(bool); // 0x059
    bool cUseNumbersInName(); // 0x05B
    bool cUseNumbersInName(bool); // 0x05B
    bool cUsesRealShadows(); // 0x05C
    bool cUsesRealShadows(bool); // 0x05C
    bool cHasShadowImages(); // 0x05D
    bool cHasShadowImages(bool); // 0x05D
    bool cForceShadowBlack(); // 0x05E
    bool cForceShadowBlack(bool); // 0x05E
    bool cDrawsLate(); // 0x060
    bool cDrawsLate(bool); // 0x060
    bool cHeight(); // 0x064
    bool cHeight(bool); // 0x064
    bool cDepth(); // 0x068
    bool cDepth(bool); // 0x068
    bool cHasUnderwaterSection(); // 0x06C
    bool cHasUnderwaterSection(bool); // 0x06C
    bool cIsTransient(); // 0x06D
    bool cIsTransient(bool); // 0x06D
    bool cUsesPlacementCube(); // 0x06E
    bool cUsesPlacementCube(bool); // 0x06E



    ~ZTBuildingType();

    private:
    void* thisptr;
};

#endif // ZTBUILDINGTYPE_H