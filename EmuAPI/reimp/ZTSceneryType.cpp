#include "ZTSceneryType.h"
#include <Windows.h> // must always be above detours.h

int ZTSceneryType::ncolors() {
    return *(int*)((DWORD)thisptr + 0x038);
}

int ZTSceneryType::ncolors(int input) {
    *(int*)((DWORD)this->thisptr + 0x038) = input;
    return input;
}

bool ZTSceneryType::cIconZoom() {
    return *(bool*)((DWORD)this->thisptr + 0x050);
}

bool ZTSceneryType::cIconZoom(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x050) = input;
    return input;
}

bool ZTSceneryType::cExpansionID() {
    return *(bool*)((DWORD)this->thisptr + 0x054);
}

bool ZTSceneryType::cExpansionID(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x054) = input;
    return input;
}

bool ZTSceneryType::cMovable() {
    return *(bool*)((DWORD)this->thisptr + 0x055);
}

bool ZTSceneryType::cMovable(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x055) = input;
    return input;
}   

bool ZTSceneryType::walkable() {
    return *(bool*)((DWORD)this->thisptr + 0x056);
}

bool ZTSceneryType::walkable(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x056) = input;
    return input;
}

bool ZTSceneryType::walkableByTall() {
    return *(bool*)((DWORD)this->thisptr + 0x057);
}

bool ZTSceneryType::walkableByTall(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x057) = input;
    return input;
}

bool ZTSceneryType::cRubbleable() {
    return *(bool*)((DWORD)this->thisptr + 0x059);
}

bool ZTSceneryType::cRubbleable(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x059) = input;
    return input;
}

bool ZTSceneryType::cUseNumbersInName() {
    return *(bool*)((DWORD)this->thisptr + 0x05B);
}

bool ZTSceneryType::cUseNumbersInName(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x05B) = input;
    return input;
}

bool ZTSceneryType::cUsesRealShadows() {
    return *(bool*)((DWORD)this->thisptr + 0x05C);
}

bool ZTSceneryType::cUsesRealShadows(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x05C) = input;
    return input;
}

bool ZTSceneryType::cHasShadowImages() {
    return *(bool*)((DWORD)this->thisptr + 0x05D);
}

bool ZTSceneryType::cHasShadowImages(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x05D) = input;
    return input;
}

bool ZTSceneryType::cForceShadowBlack() {
    return *(bool*)((DWORD)this->thisptr + 0x05E);
}

bool ZTSceneryType::cForceShadowBlack(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x05E) = input;
    return input;
}

bool ZTSceneryType::cDrawsLate() {
    return *(bool*)((DWORD)this->thisptr + 0x060);
}

bool ZTSceneryType::cDrawsLate(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x060) = input;
    return input;
}

bool ZTSceneryType::cHeight() {
    return *(bool*)((DWORD)this->thisptr + 0x064);
}

bool ZTSceneryType::cHeight(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x064) = input;
    return input;
}

bool ZTSceneryType::cDepth() {
    return *(bool*)((DWORD)this->thisptr + 0x068);
}

bool ZTSceneryType::cDepth(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x068) = input;
    return input;
}

bool ZTSceneryType::cHasUnderwaterSection() {
    return *(bool*)((DWORD)this->thisptr + 0x06C);
}

bool ZTSceneryType::cHasUnderwaterSection(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x06C) = input;
    return input;
}

bool ZTSceneryType::cIsTransient() {
    return *(bool*)((DWORD)this->thisptr + 0x06D);
}

bool ZTSceneryType::cIsTransient(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x06D) = input;
    return input;
}

bool ZTSceneryType::cUsesPlacementCube() {
    return *(bool*)((DWORD)this->thisptr + 0x06E);
}

bool ZTSceneryType::cUsesPlacementCube(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x06E) = input;
    return input;
}

bool ZTSceneryType::cShow() {
    return *(bool*)((DWORD)this->thisptr + 0x06F);
}

bool ZTSceneryType::cShow(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x06F) = input;
    return input;
}

int ZTSceneryType::cHitThreshold() {
    return *(int*)((DWORD)this->thisptr + 0x070);
}

int ZTSceneryType::cHitThreshold(int input) {
    *(int*)((DWORD)this->thisptr + 0x070) = input;
    return input;
}

bool ZTSceneryType::cAvoidEdges() {
    return *(bool*)((DWORD)this->thisptr + 0x074);
}

bool ZTSceneryType::cAvoidEdges(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x074) = input;
    return input;
}

int ZTSceneryType::cFootprintX() {
    return *(int*)((DWORD)this->thisptr + 0x0B4);
}

int ZTSceneryType::cFootprintX(int input) {
    *(int*)((DWORD)this->thisptr + 0x0B4) = input;
    return input;
}

int ZTSceneryType::cFootprintY() {
    return *(int*)((DWORD)this->thisptr + 0x0B8);
}

int ZTSceneryType::cFootprintY(int input) {
    *(int*)((DWORD)this->thisptr + 0x0B8) = input;
    return input;
}


int ZTSceneryType::cFootprintZ() {
    return *(int*)((DWORD)this->thisptr + 0x0BC);
}

int ZTSceneryType::cFootprintZ(int input) {
    *(int*)((DWORD)this->thisptr + 0x0BC) = input;
    return input;
}

int ZTSceneryType::cPlacementFootprintX() {
    return *(int*)((DWORD)this->thisptr + 0x0C0);
}

int ZTSceneryType::cPlacementFootprintX(int input) {
    *(int*)((DWORD)this->thisptr + 0x0C0) = input;
    return input;
}

int ZTSceneryType::cPlacementFootprintY() {
    return *(int*)((DWORD)this->thisptr + 0x0C4);
}

int ZTSceneryType::cPlacementFootprintY(int input) {
    *(int*)((DWORD)this->thisptr + 0x0C4) = input;
    return input;
}

int ZTSceneryType::cPlacementFootprintZ() {
    return *(int*)((DWORD)this->thisptr + 0x0C8);
}


int ZTSceneryType::cPlacementFootprintZ(int input) {
    *(int*)((DWORD)this->thisptr + 0x0C8) = input;
    return input;
}

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

std::string ZTSceneryType::typeName() {
    return *(std::string*)((DWORD)this->thisptr + 0x098);
}

std::string ZTSceneryType::typeName(std::string input) {
    *(std::string*)((DWORD)this->thisptr + 0x098) = input;
    return input;
}

std::string ZTSceneryType::codename() {
    return *(std::string*)((DWORD)this->thisptr + 0x0A4);
}

std::string ZTSceneryType::codename(std::string input) {
    *(std::string*)((DWORD)this->thisptr + 0x0A4) = input;
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