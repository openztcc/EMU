#include "ZTSceneryType.h"
#include <Windows.h> // must always be above detours.h


int ZTSceneryType::cPurchaseCost() {
    return *(int*)((DWORD)this->thisptr + 0x100);
}

int ZTSceneryType::cPurchaseCost(int input) {
    *(int*)((DWORD)this->thisptr + 0x100) = input;
    return input;
}

int ZTSceneryType::cNameID() {
    return *(int*)((DWORD)this->thisptr + 0x104);
}

int ZTSceneryType::cNameID(int input) {
    *(int*)((DWORD)this->thisptr + 0x104) = input;
    return input;
}

int ZTSceneryType::cHelpID() {
    return *(int*)((DWORD)this->thisptr + 0x108);
}

int ZTSceneryType::cHelpID(int input) {
    *(int*)((DWORD)this->thisptr + 0x108) = input;
    return input;
}

int ZTSceneryType::cHabitat() {
    return *(int*)((DWORD)this->thisptr + 0x10C);
}

int ZTSceneryType::cHabitat(int input) {
    *(int*)((DWORD)this->thisptr + 0x10C) = input;
    return input;
}

int ZTSceneryType::cLocation() {
    return *(int*)((DWORD)this->thisptr + 0x110);
}

int ZTSceneryType::cLocation(int input) {
    *(int*)((DWORD)this->thisptr + 0x110) = input;
    return input;
}

int ZTSceneryType::cEra() {
    return *(int*)((DWORD)this->thisptr + 0x114);
}

int ZTSceneryType::cEra(int input) {
    *(int*)((DWORD)this->thisptr + 0x114) = input;
    return input;
}

int ZTSceneryType::cMaxFoodUnits() {
    return *(int*)((DWORD)this->thisptr + 0x118);
}

int ZTSceneryType::cMaxFoodUnits(int input) {
    *(int*)((DWORD)this->thisptr + 0x118) = input;
    return input;
}

// bool ZTSceneryType::cDeletable() {
//     return *(bool*)((DWORD)this->thisptr + 0x119);
// }

// bool ZTSceneryType::cDeletable(bool input) {
//     *(bool*)((DWORD)this->thisptr + 0x119) = input;
//     return input;
// }

bool ZTSceneryType::cStink() {
    return *(bool*)((DWORD)this->thisptr + 0x11C);
}

bool ZTSceneryType::cStink(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x11C) = input;
    return input;
}

int ZTSceneryType::cEstheticWeight() {
    return *(int*)((DWORD)this->thisptr + 0x120);
}

int ZTSceneryType::cEstheticWeight(int input) {
    *(int*)((DWORD)this->thisptr + 0x120) = input;
    return input;
}

bool ZTSceneryType::cSelectable() {
    return *(bool*)((DWORD)this->thisptr + 0x128);
}

bool ZTSceneryType::cSelectable(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x128) = input;
    return input;
}

// bool ZTSceneryType::cDeletable() {
//     return *(bool*)((DWORD)this->thisptr + 0x129);
// }

// bool ZTSceneryType::cDeletable(bool input) {
//     *(bool*)((DWORD)this->thisptr + 0x129) = input;
//     return input;
// }

bool ZTSceneryType::cFoliage() {
    return *(bool*)((DWORD)this->thisptr + 0x12A);
}

bool ZTSceneryType::cFoliage(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x12A) = input;
    return input;
}

// bool ZTSceneryType::cAutoRotate() {
//     return *(bool*)((DWORD)this->thisptr + 0x12D);
// }

// bool ZTSceneryType::cAutoRotate(bool input) {
//     *(bool*)((DWORD)this->thisptr + 0x12D) = input;
//     return input;
// }

// bool ZTSceneryType::cLand() {
//     return *(bool*)((DWORD)this->thisptr + 0x12E);
// }

// bool ZTSceneryType::cLand(bool input) {
//     *(bool*)((DWORD)this->thisptr + 0x12E) = input;
//     return input;
// }

bool ZTSceneryType::cSwims() {
    return *(bool*)((DWORD)this->thisptr + 0x12F);
}

bool ZTSceneryType::cSwims(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x12F) = input;
    return input;
}

bool ZTSceneryType::cUnderwater() {
    return *(bool*)((DWORD)this->thisptr + 0x130);
}

bool ZTSceneryType::cUnderwater(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x130) = input;
    return input;
}

bool ZTSceneryType::cSurface() {
    return *(bool*)((DWORD)this->thisptr + 0x131);
}

bool ZTSceneryType::cSurface(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x131) = input;
    return input;
}


// bool ZTSceneryType::cSelectable() {
//     return *(bool*)((DWORD)this->thisptr + 0x128);
// }

// bool ZTSceneryType::cSelectable(bool input) {
//     *(bool*)((DWORD)this->thisptr + 0x128) = input;
//     return input;
// }

// bool ZTSceneryType::cDeletable() {
//     return *(bool*)((DWORD)this->thisptr + 0x129);
// }

// bool ZTSceneryType::cDeletable(bool input) {
//     *(bool*)((DWORD)this->thisptr + 0x129) = input;
//     return input;
// }

// bool ZTSceneryType::cFoliage() {
//     return *(bool*)((DWORD)this->thisptr + 0x12A);
// }

// bool ZTSceneryType::cFoliage(bool input) {
//     *(bool*)((DWORD)this->thisptr + 0x12A) = input;
//     return input;
// }

bool ZTSceneryType::cAutoRotate() {
    return *(bool*)((DWORD)this->thisptr + 0x12D);
}

bool ZTSceneryType::cAutoRotate(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x12D) = input;
    return input;
}

bool ZTSceneryType::cLand() {
    return *(bool*)((DWORD)this->thisptr + 0x12E);
}

bool ZTSceneryType::cLand(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x12E) = input;
    return input;
}

// bool ZTSceneryType::cSwims() {
//     return *(bool*)((DWORD)this->thisptr + 0x12F);
// }

// bool ZTSceneryType::cSwims(bool input) {
//     *(bool*)((DWORD)this->thisptr + 0x12F) = input;
//     return input;
// }

// bool ZTSceneryType::cUnderwater() {
//     return *(bool*)((DWORD)this->thisptr + 0x130);
// }

// bool ZTSceneryType::cUnderwater(bool input) {
//     *(bool*)((DWORD)this->thisptr + 0x130) = input;
//     return input;
// }

// bool ZTSceneryType::cSurface() {
//     return *(bool*)((DWORD)this->thisptr + 0x131);
// }

// bool ZTSceneryType::cSurface(bool input) {
//     *(bool*)((DWORD)this->thisptr + 0x131) = input;
//     return input;
// }

bool ZTSceneryType::cSubmerge() {
    return *(bool*)((DWORD)this->thisptr + 0x132);
}

bool ZTSceneryType::cSubmerge(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x132) = input;
    return input;
}

bool ZTSceneryType::cOnlySwims() {
    return *(bool*)((DWORD)this->thisptr + 0x133);
}

bool ZTSceneryType::cOnlySwims(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x133) = input;
    return input;
}

bool ZTSceneryType::cNeedsConfirm() {
    return *(bool*)((DWORD)this->thisptr + 0x134);
}

bool ZTSceneryType::cNeedsConfirm(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x134) = input;
    return input;
}

bool ZTSceneryType::cGawkOnlyFromFront() {
    return *(bool*)((DWORD)this->thisptr + 0x135);
}

bool ZTSceneryType::cGawkOnlyFromFront(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x135) = input;
    return input;
}

bool ZTSceneryType::cDeadOnLand() {
    return *(bool*)((DWORD)this->thisptr + 0x136);
}

bool ZTSceneryType::cDeadOnLand(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x136) = input;
    return input;
}

bool ZTSceneryType::cDeadOnFlatWater() {
    return *(bool*)((DWORD)this->thisptr + 0x137);
}

bool ZTSceneryType::cDeadOnFlatWater(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x137) = input;
    return input;
}

bool ZTSceneryType::cDeadUnderwater() {
    return *(bool*)((DWORD)this->thisptr + 0x138);
}

bool ZTSceneryType::cDeadUnderwater(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x138) = input;
    return input;
}

bool ZTSceneryType::cUsesTreeRubble() {
    return *(bool*)((DWORD)this->thisptr + 0x139);
}

bool ZTSceneryType::cUsesTreeRubble(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x139) = input;
    return input;
}

bool ZTSceneryType::cForcesSceneryRubble() {
    return *(bool*)((DWORD)this->thisptr + 0x13A);
}

bool ZTSceneryType::cForcesSceneryRubble(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x13A) = input;
    return input;
}

bool ZTSceneryType::cBlocksLOS() {
    return *(bool*)((DWORD)this->thisptr + 0x13B);
}

bool ZTSceneryType::cBlocksLOS(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x13B) = input;
    return input;
}

std::string ZTSceneryType::cInfoImageName() {
    return *(std::string*)((DWORD)this->thisptr + 0x14C);
}

std::string ZTSceneryType::cInfoImageName(std::string input) {
    *(std::string*)((DWORD)this->thisptr + 0x14C) = input;
    return input;
}