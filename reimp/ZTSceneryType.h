#ifndef ZTSCENERYTYPE_H
#define ZTSCENERYTYPE_H

#include "BFEntityType.h"
#include <string>
#include <sol/sol.hpp>


class ZTSceneryType : public BFEntityType {
    public:
    // char padding[4]; // 292
    int cPurchaseCost(); //0x100
    int cPurchaseCost(int); //0x100
    int cNameID(); //0x104
    int cNameID(int); //0x104
    int cHelpID(); //0x108
    int cHelpID(int); //0x108
    int cHabitat(); //0x10C
    int cHabitat(int); //0x10C
    int cLocation(); //0x110
    int cLocation(int); //0x110
    int cEra(); //0x114
    int cEra(int); //0x114
    int cMaxFoodUnits(); //0x118
    int cMaxFoodUnits(int); //0x118
    bool cDeletable(); //0x119
    bool cDeletable(bool); //0x119
    bool cStink(); //0x11C
    bool cStink(bool); //0x11C
    int cEstheticWeight(); //0x120
    int cEstheticWeight(int); //0x120
    bool cSelectable(); //0x128
    bool cSelectable(bool); //0x128
    // bool cDeletable(); //0x129
    // bool cDeletable(bool); //0x129
    bool cFoliage(); //0x12A
    bool cFoliage(bool); //0x12A
    bool cAutoRotate(); //0x12D
    bool cAutoRotate(bool); //0x12D
    bool cLand(); //0x12E
    bool cLand(bool); //0x12E
    bool cSwims(); //0x12F
    bool cSwims(bool); //0x12F
    bool cUnderwater(); //0x130
    bool cUnderwater(bool); //0x130
    bool cSurface(); //0x131
    bool cSurface(bool); //0x131
    bool cSubmerge(); //0x132
    bool cSubmerge(bool); //0x132
    bool cOnlySwims(); //0x133
    bool cOnlySwims(bool); //0x133
    bool cNeedsConfirm(); //0x134
    bool cNeedsConfirm(bool); //0x134
    bool cGawkOnlyFromFront(); //0x135
    bool cGawkOnlyFromFront(bool); //0x135
    bool cDeadOnLand(); //0x136
    bool cDeadOnLand(bool); //0x136
    bool cDeadOnFlatWater(); //0x137
    bool cDeadOnFlatWater(bool); //0x137
    bool cDeadUnderwater(); //0x138
    bool cDeadUnderwater(bool); //0x138
    bool cUsesTreeRubble(); //0x139
    bool cUsesTreeRubble(bool); //0x139
    bool cForcesSceneryRubble(); //0x13A
    bool cForcesSceneryRubble(bool); //0x13A
    bool cBlocksLOS(); //0x13B
    bool cBlocksLOS(bool); //0x13B
    std::string cInfoImageName(); //0x14C
    std::string cInfoImageName(std::string); //0x14C
    ZTSceneryType(void* ptr) : BFEntityType(ptr) {};
    ~ZTSceneryType() {};
    static void ExportClassToLua(sol::state& lua);

};

#endif // ZTSCENERYTYPE_H