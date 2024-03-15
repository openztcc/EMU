#include "BFEntityType.h"
#include <Windows.h> // must always be above detours.h
#include <string>
#include "sol/sol.hpp"

int BFEntityType::ncolors() {
    return *(int*)((DWORD)thisptr + 0x038);
}

int BFEntityType::ncolors(int input) {
    *(int*)((DWORD)this->thisptr + 0x038) = input;
    return input;
}

bool BFEntityType::cIconZoom() {
    return *(bool*)((DWORD)this->thisptr + 0x050);
}

bool BFEntityType::cIconZoom(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x050) = input;
    return input;
}

bool BFEntityType::cExpansionID() {
    return *(bool*)((DWORD)this->thisptr + 0x054);
}

bool BFEntityType::cExpansionID(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x054) = input;
    return input;
}

bool BFEntityType::cMovable() {
    return *(bool*)((DWORD)this->thisptr + 0x055);
}

bool BFEntityType::cMovable(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x055) = input;
    return input;
}   

bool BFEntityType::walkable() {
    return *(bool*)((DWORD)this->thisptr + 0x056);
}

bool BFEntityType::walkable(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x056) = input;
    return input;
}

bool BFEntityType::walkableByTall() {
    return *(bool*)((DWORD)this->thisptr + 0x057);
}

bool BFEntityType::walkableByTall(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x057) = input;
    return input;
}

bool BFEntityType::cRubbleable() {
    return *(bool*)((DWORD)this->thisptr + 0x059);
}

bool BFEntityType::cRubbleable(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x059) = input;
    return input;
}

bool BFEntityType::cUseNumbersInName() {
    return *(bool*)((DWORD)this->thisptr + 0x05B);
}

bool BFEntityType::cUseNumbersInName(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x05B) = input;
    return input;
}

bool BFEntityType::cUsesRealShadows() {
    return *(bool*)((DWORD)this->thisptr + 0x05C);
}

bool BFEntityType::cUsesRealShadows(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x05C) = input;
    return input;
}

bool BFEntityType::cHasShadowImages() {
    return *(bool*)((DWORD)this->thisptr + 0x05D);
}

bool BFEntityType::cHasShadowImages(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x05D) = input;
    return input;
}

bool BFEntityType::cForceShadowBlack() {
    return *(bool*)((DWORD)this->thisptr + 0x05E);
}

bool BFEntityType::cForceShadowBlack(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x05E) = input;
    return input;
}

bool BFEntityType::cDrawsLate() {
    return *(bool*)((DWORD)this->thisptr + 0x060);
}

bool BFEntityType::cDrawsLate(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x060) = input;
    return input;
}

bool BFEntityType::cHeight() {
    return *(bool*)((DWORD)this->thisptr + 0x064);
}

bool BFEntityType::cHeight(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x064) = input;
    return input;
}

bool BFEntityType::cDepth() {
    return *(bool*)((DWORD)this->thisptr + 0x068);
}

bool BFEntityType::cDepth(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x068) = input;
    return input;
}

bool BFEntityType::cHasUnderwaterSection() {
    return *(bool*)((DWORD)this->thisptr + 0x06C);
}

bool BFEntityType::cHasUnderwaterSection(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x06C) = input;
    return input;
}

bool BFEntityType::cIsTransient() {
    return *(bool*)((DWORD)this->thisptr + 0x06D);
}

bool BFEntityType::cIsTransient(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x06D) = input;
    return input;
}

bool BFEntityType::cUsesPlacementCube() {
    return *(bool*)((DWORD)this->thisptr + 0x06E);
}

bool BFEntityType::cUsesPlacementCube(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x06E) = input;
    return input;
}

bool BFEntityType::cShow() {
    return *(bool*)((DWORD)this->thisptr + 0x06F);
}

bool BFEntityType::cShow(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x06F) = input;
    return input;
}

int BFEntityType::cHitThreshold() {
    return *(int*)((DWORD)this->thisptr + 0x070);
}

int BFEntityType::cHitThreshold(int input) {
    *(int*)((DWORD)this->thisptr + 0x070) = input;
    return input;
}

bool BFEntityType::cAvoidEdges() {
    return *(bool*)((DWORD)this->thisptr + 0x074);
}

bool BFEntityType::cAvoidEdges(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x074) = input;
    return input;
}

std::string BFEntityType::typeName() {
    return *(std::string*)((DWORD)this->thisptr + 0x098);
}

std::string BFEntityType::typeName(std::string input) {
    *(std::string*)((DWORD)this->thisptr + 0x098) = input;
    return input;
}

std::string BFEntityType::codename() {
    return *(std::string*)((DWORD)this->thisptr + 0x0A4);
}

std::string BFEntityType::codename(std::string input) {
    *(std::string*)((DWORD)this->thisptr + 0x0A4) = input;
    return input;
}


int BFEntityType::cFootprintX() {
    return *(int*)((DWORD)this->thisptr + 0x0B4);
}

int BFEntityType::cFootprintX(int input) {
    *(int*)((DWORD)this->thisptr + 0x0B4) = input;
    return input;
}

int BFEntityType::cFootprintY() {
    return *(int*)((DWORD)this->thisptr + 0x0B8);
}

int BFEntityType::cFootprintY(int input) {
    *(int*)((DWORD)this->thisptr + 0x0B8) = input;
    return input;
}


int BFEntityType::cFootprintZ() {
    return *(int*)((DWORD)this->thisptr + 0x0BC);
}

int BFEntityType::cFootprintZ(int input) {
    *(int*)((DWORD)this->thisptr + 0x0BC) = input;
    return input;
}

int BFEntityType::cPlacementFootprintX() {
    return *(int*)((DWORD)this->thisptr + 0x0C0);
}

int BFEntityType::cPlacementFootprintX(int input) {
    *(int*)((DWORD)this->thisptr + 0x0C0) = input;
    return input;
}

int BFEntityType::cPlacementFootprintY() {
    return *(int*)((DWORD)this->thisptr + 0x0C4);
}

int BFEntityType::cPlacementFootprintY(int input) {
    *(int*)((DWORD)this->thisptr + 0x0C4) = input;
    return input;
}

int BFEntityType::cPlacementFootprintZ() {
    return *(int*)((DWORD)this->thisptr + 0x0C8);
}


int BFEntityType::cPlacementFootprintZ(int input) {
    *(int*)((DWORD)this->thisptr + 0x0C8) = input;
    return input;
}

bool BFEntityType::availableAtStartup() {
    return *(bool*)((DWORD)this->thisptr + 0x0CC);
}

bool BFEntityType::availableAtStartup(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x0CC) = input;
    return input;
}
