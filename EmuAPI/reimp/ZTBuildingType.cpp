#include "ZTBuildingType.h"
#include <Windows.h> // must always be above detours.h

ZTBuildingType::ZTBuildingType(void* thisptr) {
    this->thisptr = thisptr;
}

int ZTBuildingType::ncolors() {
    return *(int*)((DWORD)this->thisptr + 0x038);
}

int ZTBuildingType::ncolors(int input) {
    *(int*)((DWORD)this->thisptr + 0x038) = input;
    return input;
}

bool ZTBuildingType::cIconZoom() {
    return *(bool*)((DWORD)this->thisptr + 0x050);
}

bool ZTBuildingType::cIconZoom(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x050) = input;
    return input;
}

bool ZTBuildingType::cExpansionID() {
    return *(bool*)((DWORD)this->thisptr + 0x054);
}

bool ZTBuildingType::cExpansionID(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x054) = input;
    return input;
}

bool ZTBuildingType::cMovable() {
    return *(bool*)((DWORD)this->thisptr + 0x055);
}

bool ZTBuildingType::cMovable(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x055) = input;
    return input;
}   

bool ZTBuildingType::walkable() {
    return *(bool*)((DWORD)this->thisptr + 0x056);
}

bool ZTBuildingType::walkable(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x056) = input;
    return input;
}

bool ZTBuildingType::walkableByTall() {
    return *(bool*)((DWORD)this->thisptr + 0x057);
}

bool ZTBuildingType::walkableByTall(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x057) = input;
    return input;
}

bool ZTBuildingType::cRubbleable() {
    return *(bool*)((DWORD)this->thisptr + 0x059);
}

bool ZTBuildingType::cRubbleable(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x059) = input;
    return input;
}

bool ZTBuildingType::cUseNumbersInName() {
    return *(bool*)((DWORD)this->thisptr + 0x05B);
}

bool ZTBuildingType::cUseNumbersInName(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x05B) = input;
    return input;
}

bool ZTBuildingType::cUsesRealShadows() {
    return *(bool*)((DWORD)this->thisptr + 0x05C);
}

bool ZTBuildingType::cUsesRealShadows(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x05C) = input;
    return input;
}

bool ZTBuildingType::cHasShadowImages() {
    return *(bool*)((DWORD)this->thisptr + 0x05D);
}

bool ZTBuildingType::cHasShadowImages(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x05D) = input;
    return input;
}

bool ZTBuildingType::cForceShadowBlack() {
    return *(bool*)((DWORD)this->thisptr + 0x05E);
}

bool ZTBuildingType::cForceShadowBlack(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x05E) = input;
    return input;
}

bool ZTBuildingType::cDrawsLate() {
    return *(bool*)((DWORD)this->thisptr + 0x060);
}

bool ZTBuildingType::cDrawsLate(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x060) = input;
    return input;
}

bool ZTBuildingType::cHeight() {
    return *(bool*)((DWORD)this->thisptr + 0x064);
}

bool ZTBuildingType::cHeight(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x064) = input;
    return input;
}

bool ZTBuildingType::cDepth() {
    return *(bool*)((DWORD)this->thisptr + 0x068);
}

bool ZTBuildingType::cDepth(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x068) = input;
    return input;
}

bool ZTBuildingType::cHasUnderwaterSection() {
    return *(bool*)((DWORD)this->thisptr + 0x06C);
}

bool ZTBuildingType::cHasUnderwaterSection(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x06C) = input;
    return input;
}

bool ZTBuildingType::cIsTransient() {
    return *(bool*)((DWORD)this->thisptr + 0x06D);
}

bool ZTBuildingType::cIsTransient(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x06D) = input;
    return input;
}

bool ZTBuildingType::cUsesPlacementCube() {
    return *(bool*)((DWORD)this->thisptr + 0x06E);
}

bool ZTBuildingType::cUsesPlacementCube(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x06E) = input;
    return input;
}




ZTBuildingType::~ZTBuildingType() {
    // destructor
}