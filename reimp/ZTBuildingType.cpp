#include "ZTBuildingType.h"
#include <Windows.h> // must always be above detours.h
#include "sol/sol.hpp"
#include "EmuMain.h"

int ZTBuildingType::cCapacity() {
    return *(int*)((DWORD)this->thisptr + 0x16C);
}

int ZTBuildingType::cCapacity(int value) {
    return *(int*)((DWORD)this->thisptr + 0x16C) = value;
}

int ZTBuildingType::cToySatisfaction() {
    return *(int*)((DWORD)this->thisptr + 0x170);
}

int ZTBuildingType::cToySatisfaction(int value) {
    return *(int*)((DWORD)this->thisptr + 0x170) = value;
}

int ZTBuildingType::cTimeInside() {
    return *(int*)((DWORD)this->thisptr + 0x174);
}

int ZTBuildingType::cTimeInside(int value) {
    return *(int*)((DWORD)this->thisptr + 0x174) = value;
}

int ZTBuildingType::cDefaultCost() {
    return *(int*)((DWORD)this->thisptr + 0x178);
}

int ZTBuildingType::cDefaultCost(int value) {
    return *(int*)((DWORD)this->thisptr + 0x178) = value;
}

int ZTBuildingType::cLowCost() {
    return *(int*)((DWORD)this->thisptr + 0x17C);
}

int ZTBuildingType::cLowCost(int value) {
    return *(int*)((DWORD)this->thisptr + 0x17C) = value;
}

int ZTBuildingType::cMedCost() {
    return *(int*)((DWORD)this->thisptr + 0x180);
}

int ZTBuildingType::cMedCost(int value) {
    return *(int*)((DWORD)this->thisptr + 0x180) = value;
}

int ZTBuildingType::cHighCost() {
    return *(int*)((DWORD)this->thisptr + 0x184);
}

int ZTBuildingType::cHighCost(int value) {
    return *(int*)((DWORD)this->thisptr + 0x184) = value;
}

int ZTBuildingType::cPriceFactor() {
    return *(int*)((DWORD)this->thisptr + 0x188);
}

int ZTBuildingType::cPriceFactor(int value) {
    return *(int*)((DWORD)this->thisptr + 0x188) = value;
}

int ZTBuildingType::cUpkeep() {
    return *(int*)((DWORD)this->thisptr + 0x18C);
}

int ZTBuildingType::cUpkeep(int value) {
    return *(int*)((DWORD)this->thisptr + 0x18C) = value;
}

bool ZTBuildingType::cHideUser() {
    return *(bool*)((DWORD)this->thisptr + 0x194);
}

bool ZTBuildingType::cHideUser(bool value) {
    return *(bool*)((DWORD)this->thisptr + 0x194) = value;
}

bool ZTBuildingType::cSetLetterFacing() {
    return *(bool*)((DWORD)this->thisptr + 0x195);
}

bool ZTBuildingType::cSetLetterFacing(bool value) {
    return *(bool*)((DWORD)this->thisptr + 0x195) = value;
}

bool ZTBuildingType::cDrawUser() {
    return *(bool*)((DWORD)this->thisptr + 0x196);
}

bool ZTBuildingType::cDrawUser(bool value) {
    return *(bool*)((DWORD)this->thisptr + 0x196) = value;
}

bool ZTBuildingType::cHideCostChange() {
    return *(bool*)((DWORD)this->thisptr + 0x197);
}

bool ZTBuildingType::cHideCostChange(bool value) {
    return *(bool*)((DWORD)this->thisptr + 0x197) = value;
}

bool ZTBuildingType::cHideCommerceInfo() {
    return *(bool*)((DWORD)this->thisptr + 0x198);
}

bool ZTBuildingType::cHideCommerceInfo(bool value) {
    return *(bool*)((DWORD)this->thisptr + 0x198) = value;
}

bool ZTBuildingType::cHideRegularInfo() {
    return *(bool*)((DWORD)this->thisptr + 0x199);
}

bool ZTBuildingType::cHideRegularInfo(bool value) {
    return *(bool*)((DWORD)this->thisptr + 0x199) = value;
}

bool ZTBuildingType::cHoldsOntoUser() {
    return *(bool*)((DWORD)this->thisptr + 0x19A);
}

bool ZTBuildingType::cHoldsOntoUser(bool value) {
    return *(bool*)((DWORD)this->thisptr + 0x19A) = value;
}

bool ZTBuildingType::cUserTracker() {
    return *(bool*)((DWORD)this->thisptr + 0x19B);
}

bool ZTBuildingType::cUserTracker(bool value) {
    return *(bool*)((DWORD)this->thisptr + 0x19B) = value;
}

bool ZTBuildingType::cIdler() {
    return *(bool*)((DWORD)this->thisptr + 0x19C);
}

bool ZTBuildingType::cIdler(bool value) {
    return *(bool*)((DWORD)this->thisptr + 0x19C) = value;
}

bool ZTBuildingType::cExhibitViewer() {
    return *(bool*)((DWORD)this->thisptr + 0x19D);
}

bool ZTBuildingType::cExhibitViewer(bool value) {
    return *(bool*)((DWORD)this->thisptr + 0x19D) = value;
}

int ZTBuildingType::cAlternatePanelTitle() {
    return *(int*)((DWORD)this->thisptr + 0x1A0);
}

int ZTBuildingType::cAlternatePanelTitle(int value) {
    return *(int*)((DWORD)this->thisptr + 0x1A0) = value;
}

bool ZTBuildingType::cDirectEntrance() {
    return *(bool*)((DWORD)this->thisptr + 0x1A4);
}

bool ZTBuildingType::cDirectEntrance(bool value) {
    return *(bool*)((DWORD)this->thisptr + 0x1A4) = value;
}

bool ZTBuildingType::cHideBuilding() {
    return *(bool*)((DWORD)this->thisptr + 0x1A5);
}

bool ZTBuildingType::cHideBuilding(bool value) {
    return *(bool*)((DWORD)this->thisptr + 0x1A5) = value;
}

bool ZTBuildingType::cUserStaysOutside() {
    return *(bool*)((DWORD)this->thisptr + 0x1A6);
}

bool ZTBuildingType::cUserStaysOutside(bool value) {
    return *(bool*)((DWORD)this->thisptr + 0x1A6) = value;
}

bool ZTBuildingType::cUserTeleportsInside() {
    return *(bool*)((DWORD)this->thisptr + 0x1A7);
}

bool ZTBuildingType::cUserTeleportsInside(bool value) {
    return *(bool*)((DWORD)this->thisptr + 0x1A7) = value;
}

bool ZTBuildingType::cUserUsesExit() {
    return *(bool*)((DWORD)this->thisptr + 0x1A8);
}

bool ZTBuildingType::cUserUsesExit(bool value) {
    return *(bool*)((DWORD)this->thisptr + 0x1A8) = value;
}

bool ZTBuildingType::cUserUsesEntranceAsEmergencyExit() {
    return *(bool*)((DWORD)this->thisptr + 0x1A9);
}

bool ZTBuildingType::cUserUsesEntranceAsEmergencyExit(bool value) {
    return *(bool*)((DWORD)this->thisptr + 0x1A9) = value;
}

int ZTBuildingType::cAdultChange() {
    return *(int*)((DWORD)this->thisptr + 0x1B8);
}

int ZTBuildingType::cAdultChange(int value) {
    return *(int*)((DWORD)this->thisptr + 0x1B8) = value;
}

int ZTBuildingType::cChildChange() {
    return *(int*)((DWORD)this->thisptr + 0x1BC);
}

int ZTBuildingType::cChildChange(int value) {
    return *(int*)((DWORD)this->thisptr + 0x1BC) = value;
}

int ZTBuildingType::cHungerChange() {
    return *(int*)((DWORD)this->thisptr + 0x1C0);
}

int ZTBuildingType::cHungerChange(int value) {
    return *(int*)((DWORD)this->thisptr + 0x1C0) = value;
}

int ZTBuildingType::cThirstChange() {
    return *(int*)((DWORD)this->thisptr + 0x1C4);
}

int ZTBuildingType::cThirstChange(int value) {
    return *(int*)((DWORD)this->thisptr + 0x1C4) = value;
}

int ZTBuildingType::cBathroomChange() {
    return *(int*)((DWORD)this->thisptr + 0x1C8);
}

int ZTBuildingType::cBathroomChange(int value) {
    return *(int*)((DWORD)this->thisptr + 0x1C8) = value;
}

int ZTBuildingType::cEnergyChange() {
    return *(int*)((DWORD)this->thisptr + 0x1CC);
}

int ZTBuildingType::cEnergyChange(int value) {
    return *(int*)((DWORD)this->thisptr + 0x1CC) = value;
}

void ZTBuildingType::ExportClassToLua() {
    sol::state lua;
    lua.open_libraries(sol::lib::base);
    lua_State* L = lua.lua_state();
    sol::state_view _lua(L);

    _lua.new_usertype<ZTBuildingType>("ZTBuildingType",
        // Constructors
        sol::constructors<ZTBuildingType(void*)>(),
        "cCapacity", sol::overload(
            static_cast<int (ZTBuildingType::*)()>(&ZTBuildingType::cCapacity),
            static_cast<int (ZTBuildingType::*)(int)>(&ZTBuildingType::cCapacity)
        ),
        "cToySatisfaction", sol::overload(
			static_cast<int (ZTBuildingType::*)()>(&ZTBuildingType::cToySatisfaction),
			static_cast<int (ZTBuildingType::*)(int)>(&ZTBuildingType::cToySatisfaction)
		),
        "cTimeInside", sol::overload(
            static_cast<int (ZTBuildingType::*)()>(&ZTBuildingType::cTimeInside),
            static_cast<int (ZTBuildingType::*)(int)>(&ZTBuildingType::cTimeInside)
        ),
        "cDefaultCost", sol::overload(
            static_cast<int (ZTBuildingType::*)()>(&ZTBuildingType::cDefaultCost),
            static_cast<int (ZTBuildingType::*)(int)>(&ZTBuildingType::cDefaultCost)
        ),
        "cLowCost", sol::overload(
            static_cast<int (ZTBuildingType::*)()>(&ZTBuildingType::cLowCost),
            static_cast<int (ZTBuildingType::*)(int)>(&ZTBuildingType::cLowCost)
        ),
        "cMedCost", sol::overload(
            static_cast<int (ZTBuildingType::*)()>(&ZTBuildingType::cMedCost),
            static_cast<int (ZTBuildingType::*)(int)>(&ZTBuildingType::cMedCost)
        ),
        "cHighCost", sol::overload(
            static_cast<int (ZTBuildingType::*)()>(&ZTBuildingType::cHighCost),
            static_cast<int (ZTBuildingType::*)(int)>(&ZTBuildingType::cHighCost)
        ),
        "cPriceFactor", sol::overload(
            static_cast<int (ZTBuildingType::*)()>(&ZTBuildingType::cPriceFactor),
            static_cast<int (ZTBuildingType::*)(int)>(&ZTBuildingType::cPriceFactor)
        ),
        "cUpkeep", sol::overload(
            static_cast<int (ZTBuildingType::*)()>(&ZTBuildingType::cUpkeep),
            static_cast<int (ZTBuildingType::*)(int)>(&ZTBuildingType::cUpkeep)
        ),
        "cHideUser", sol::overload(
            static_cast<bool (ZTBuildingType::*)()>(&ZTBuildingType::cHideUser),
            static_cast<bool (ZTBuildingType::*)(bool)>(&ZTBuildingType::cHideUser)
        ),
        "cSetLetterFacing", sol::overload(
            static_cast<bool (ZTBuildingType::*)()>(&ZTBuildingType::cSetLetterFacing),
            static_cast<bool (ZTBuildingType::*)(bool)>(&ZTBuildingType::cSetLetterFacing)
        ),
        "cDrawUser", sol::overload(
            static_cast<bool (ZTBuildingType::*)()>(&ZTBuildingType::cDrawUser),
            static_cast<bool (ZTBuildingType::*)(bool)>(&ZTBuildingType::cDrawUser)
        ),
        "cHideCostChange", sol::overload(
            static_cast<bool (ZTBuildingType::*)()>(&ZTBuildingType::cHideCostChange),
            static_cast<bool (ZTBuildingType::*)(bool)>(&ZTBuildingType::cHideCostChange)
        ),
        "cHideCommerceInfo", sol::overload(
            static_cast<bool (ZTBuildingType::*)()>(&ZTBuildingType::cHideCommerceInfo),
            static_cast<bool (ZTBuildingType::*)(bool)>(&ZTBuildingType::cHideCommerceInfo)
        ),
        "cHideRegularInfo", sol::overload(
            static_cast<bool (ZTBuildingType::*)()>(&ZTBuildingType::cHideRegularInfo),
            static_cast<bool (ZTBuildingType::*)(bool)>(&ZTBuildingType::cHideRegularInfo)
        ),
        "cHoldsOntoUser", sol::overload(
            static_cast<bool (ZTBuildingType::*)()>(&ZTBuildingType::cHoldsOntoUser),
            static_cast<bool (ZTBuildingType::*)(bool)>(&ZTBuildingType::cHoldsOntoUser)
        ),
        "cUserTracker", sol::overload(
            static_cast<bool (ZTBuildingType::*)()>(&ZTBuildingType::cUserTracker),
            static_cast<bool (ZTBuildingType::*)(bool)>(&ZTBuildingType::cUserTracker)
        ),
        "cIdler", sol::overload(
            static_cast<bool (ZTBuildingType::*)()>(&ZTBuildingType::cIdler),
            static_cast<bool (ZTBuildingType::*)(bool)>(&ZTBuildingType::cIdler)
        ),
        "cExhibitViewer", sol::overload(
            static_cast<bool (ZTBuildingType::*)()>(&ZTBuildingType::cExhibitViewer),
            static_cast<bool (ZTBuildingType::*)(bool)>(&ZTBuildingType::cExhibitViewer)
        ),
        "cAlternatePanelTitle", sol::overload(
            static_cast<int (ZTBuildingType::*)()>(&ZTBuildingType::cAlternatePanelTitle),
            static_cast<int (ZTBuildingType::*)(int)>(&ZTBuildingType::cAlternatePanelTitle)
        ),
        "cDirectEntrance", sol::overload(
            static_cast<bool (ZTBuildingType::*)()>(&ZTBuildingType::cDirectEntrance),
            static_cast<bool (ZTBuildingType::*)(bool)>(&ZTBuildingType::cDirectEntrance)
        ),
        "cHideBuilding", sol::overload(
            static_cast<bool (ZTBuildingType::*)()>(&ZTBuildingType::cHideBuilding),
            static_cast<bool (ZTBuildingType::*)(bool)>(&ZTBuildingType::cHideBuilding)
        ),
        "cUserStaysOutside", sol::overload(
            static_cast<bool (ZTBuildingType::*)()>(&ZTBuildingType::cUserStaysOutside),
            static_cast<bool (ZTBuildingType::*)(bool)>(&ZTBuildingType::cUserStaysOutside)
        ),
        "cUserTeleportsInside", sol::overload(
            static_cast<bool (ZTBuildingType::*)()>(&ZTBuildingType::cUserTeleportsInside),
            static_cast<bool (ZTBuildingType::*)(bool)>(&ZTBuildingType::cUserTeleportsInside)
        ),
        "cUserUsesExit", sol::overload(
            static_cast<bool (ZTBuildingType::*)()>(&ZTBuildingType::cUserUsesExit),
            static_cast<bool (ZTBuildingType::*)(bool)>(&ZTBuildingType::cUserUsesExit)
        ),
        "cUserUsesEntranceAsEmergencyExit", sol::overload(
            static_cast<bool (ZTBuildingType::*)()>(&ZTBuildingType::cUserUsesEntranceAsEmergencyExit),
            static_cast<bool (ZTBuildingType::*)(bool)>(&ZTBuildingType::cUserUsesEntranceAsEmergencyExit)
        ),
        "cAdultChange", sol::overload(
            static_cast<int (ZTBuildingType::*)()>(&ZTBuildingType::cAdultChange),
            static_cast<int (ZTBuildingType::*)(int)>(&ZTBuildingType::cAdultChange)
        ),
        "cChildChange", sol::overload(
            static_cast<int (ZTBuildingType::*)()>(&ZTBuildingType::cChildChange),
            static_cast<int (ZTBuildingType::*)(int)>(&ZTBuildingType::cChildChange)
        ),
        "cHungerChange", sol::overload(
            static_cast<int (ZTBuildingType::*)()>(&ZTBuildingType::cHungerChange),
            static_cast<int (ZTBuildingType::*)(int)>(&ZTBuildingType::cHungerChange)
        ),
        "cThirstChange", sol::overload(
            static_cast<int (ZTBuildingType::*)()>(&ZTBuildingType::cThirstChange),
            static_cast<int (ZTBuildingType::*)(int)>(&ZTBuildingType::cThirstChange)
        ),
        "cBathroomChange", sol::overload(
            static_cast<int (ZTBuildingType::*)()>(&ZTBuildingType::cBathroomChange),
            static_cast<int (ZTBuildingType::*)(int)>(&ZTBuildingType::cBathroomChange)
        ),
        "cEnergyChange", sol::overload(
            static_cast<int (ZTBuildingType::*)()>(&ZTBuildingType::cEnergyChange),
            static_cast<int (ZTBuildingType::*)(int)>(&ZTBuildingType::cEnergyChange)
        ),
        sol::base_classes, sol::bases<BFEntityType, ZTSceneryType>()
    );
}