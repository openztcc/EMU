#ifndef ZTBUILDINGTYPE_H
#define ZTBUILDINGTYPE_H

#include "ZTSceneryType.h"

#include <string>
#include <sol/sol.hpp>

class ZTBuildingType : public ZTSceneryType {
    public:
    ZTBuildingType(void* ptr) : ZTSceneryType(ptr) {};
    int cCapacity(); // 0x16C
    int cCapacity(int); // 0x16C
    int cToySatisfaction(); // 0x170
    int cToySatisfaction(int); // 0x170
    int cTimeInside(); // 0x174
    int cTimeInside(int); // 0x174
    int cDefaultCost(); // 0x178
    int cDefaultCost(int); // 0x178
    int cLowCost(); // 0x17C
    int cLowCost(int); // 0x17C
    int cMedCost(); // 0x180
    int cMedCost(int); // 0x180
    int cHighCost(); // 0x184
    int cHighCost(int); // 0x184
    int cPriceFactor(); // 0x188
    int cPriceFactor(int); // 0x188
    int cUpkeep(); // 0x18C
    int cUpkeep(int); // 0x18C
    bool cHideUser(); // 0x194
    bool cHideUser(bool); // 0x194
    bool cSetLetterFacing(); // 0x195
    bool cSetLetterFacing(bool); // 0x195
    bool cDrawUser(); // 0x196
    bool cDrawUser(bool); // 0x196
    bool cHideCostChange(); // 0x197
    bool cHideCostChange(bool); // 0x197
    bool cHideCommerceInfo(); // 0x198
    bool cHideCommerceInfo(bool); // 0x198
    bool cHideRegularInfo(); // 0x199
    bool cHideRegularInfo(bool); // 0x199
    bool cHoldsOntoUser(); // 0x19A
    bool cHoldsOntoUser(bool); // 0x19A
    bool cUserTracker(); // 0x19B
    bool cUserTracker(bool); // 0x19B
    bool cIdler(); // 0x19C
    bool cIdler(bool); // 0x19C
    bool cExhibitViewer(); // 0x19D
    bool cExhibitViewer(bool); // 0x19D
    int cAlternatePanelTitle(); // 0x1A0 ---> probably a string
    int cAlternatePanelTitle(int); // 0x1A0
    bool cDirectEntrance(); // 0x1A4
    bool cDirectEntrance(bool); // 0x1A4
    bool cHideBuilding(); // 0x1A5
    bool cHideBuilding(bool); // 0x1A5
    bool cUserStaysOutside(); // 0x1A6
    bool cUserStaysOutside(bool); // 0x1A6
    bool cUserTeleportsInside(); // 0x1A7
    bool cUserTeleportsInside(bool); // 0x1A7
    bool cUserUsesExit(); // 0x1A8
    bool cUserUsesExit(bool); // 0x1A8
    bool cUserUsesEntranceAsEmergencyExit(); // 0x1A9
    bool cUserUsesEntranceAsEmergencyExit(bool); // 0x1A9
    // TODO: slots will go here
    int cAdultChange(); // 0x1B8
    int cAdultChange(int); // 0x1B8
    int cChildChange(); // 0x1BC
    int cChildChange(int); // 0x1BC
    int cHungerChange(); // 0x1C0
    int cHungerChange(int); // 0x1C0
    int cThirstChange(); // 0x1C4
    int cThirstChange(int); // 0x1C4
    int cBathroomChange(); // 0x1C8
    int cBathroomChange(int); // 0x1C8
    int cEnergyChange(); // 0x1CC
    int cEnergyChange(int); // 0x1CC
    // TODO: string pointers

    void ExportClassToLua(sol::state&);
};

#endif // ZTBUILDINGTYPE_H