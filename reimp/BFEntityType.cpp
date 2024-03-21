#include "BFEntityType.h"
#include <Windows.h> // must always be above detours.h
#include <string>
#include "sol/sol.hpp"
#include "SimpleIni.h"

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

int BFEntityType::cHeight() {
    return *(int*)((DWORD)this->thisptr + 0x064);
}

int BFEntityType::cHeight(int input) {
    *(int*)((DWORD)this->thisptr + 0x064) = input;
    return input;
}

int BFEntityType::cDepth() {
    return *(int*)((DWORD)this->thisptr + 0x068);
}

int BFEntityType::cDepth(int input) {
    *(int*)((DWORD)this->thisptr + 0x068) = input;
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
    char* startOfName = *reinterpret_cast<char**>(reinterpret_cast<DWORD>(thisptr) + 0x098);
    char* endOfName = *reinterpret_cast<char**>(reinterpret_cast<DWORD>(thisptr) + 0x09C);

    size_t nameLength = endOfName - startOfName;
    std::string name(startOfName, nameLength);

    return name;
}

// TODO: test this
std::string BFEntityType::codename(std::string input) {
    *(std::string*)((DWORD)this->thisptr + 0x098) = input;
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

void BFEntityType::ExportClassToLua(sol::state& lua) {
    lua.new_usertype<BFEntityType>("BFEntityType",
        "new", sol::constructors<BFEntityType(void*)>(),
        "ncolors", sol::overload(
			static_cast<int (BFEntityType::*)()>(&BFEntityType::ncolors),
			static_cast<int (BFEntityType::*)(int)>(&BFEntityType::ncolors)
		),
        "cIconZoom", sol::overload(
            static_cast<bool (BFEntityType::*)()>(&BFEntityType::cIconZoom),
            static_cast<bool (BFEntityType::*)(bool)>(&BFEntityType::cIconZoom)
        ),
        "cExpansionID", sol::overload(
            static_cast<bool (BFEntityType::*)()>(&BFEntityType::cExpansionID),
            static_cast<bool (BFEntityType::*)(bool)>(&BFEntityType::cExpansionID)
        ),
        "cMovable", sol::overload(
            static_cast<bool (BFEntityType::*)()>(&BFEntityType::cMovable),
            static_cast<bool (BFEntityType::*)(bool)>(&BFEntityType::cMovable)
        ),
        "walkable", sol::overload(
            static_cast<bool (BFEntityType::*)()>(&BFEntityType::walkable),
            static_cast<bool (BFEntityType::*)(bool)>(&BFEntityType::walkable)
        ),
        "walkableByTall", sol::overload(
            static_cast<bool (BFEntityType::*)()>(&BFEntityType::walkableByTall),
            static_cast<bool (BFEntityType::*)(bool)>(&BFEntityType::walkableByTall)
        ),
        "cRubbleable", sol::overload(
            static_cast<bool (BFEntityType::*)()>(&BFEntityType::cRubbleable),
            static_cast<bool (BFEntityType::*)(bool)>(&BFEntityType::cRubbleable)
        ),
        "cUseNumbersInName", sol::overload(
            static_cast<bool (BFEntityType::*)()>(&BFEntityType::cUseNumbersInName),
            static_cast<bool (BFEntityType::*)(bool)>(&BFEntityType::cUseNumbersInName)
        ),
        "cUsesRealShadows", sol::overload(
            static_cast<bool (BFEntityType::*)()>(&BFEntityType::cUsesRealShadows),
            static_cast<bool (BFEntityType::*)(bool)>(&BFEntityType::cUsesRealShadows)
        ),
        "cHasShadowImages", sol::overload(
            static_cast<bool (BFEntityType::*)()>(&BFEntityType::cHasShadowImages),
            static_cast<bool (BFEntityType::*)(bool)>(&BFEntityType::cHasShadowImages)
        ),
        "cForceShadowBlack", sol::overload(
            static_cast<bool (BFEntityType::*)()>(&BFEntityType::cForceShadowBlack),
            static_cast<bool (BFEntityType::*)(bool)>(&BFEntityType::cForceShadowBlack)
        ),
        "cDrawsLate", sol::overload(
            static_cast<bool (BFEntityType::*)()>(&BFEntityType::cDrawsLate),
            static_cast<bool (BFEntityType::*)(bool)>(&BFEntityType::cDrawsLate)
        ),
        "cHeight", sol::overload(
            static_cast<int (BFEntityType::*)()>(&BFEntityType::cHeight),
            static_cast<int (BFEntityType::*)(int)>(&BFEntityType::cHeight)
        ),
        "cDepth", sol::overload(
            static_cast<int (BFEntityType::*)()>(&BFEntityType::cDepth),
            static_cast<int (BFEntityType::*)(int)>(&BFEntityType::cDepth)
        ),
        "cHasUnderwaterSection", sol::overload(
            static_cast<bool (BFEntityType::*)()>(&BFEntityType::cHasUnderwaterSection),
            static_cast<bool (BFEntityType::*)(bool)>(&BFEntityType::cHasUnderwaterSection)
        ),
        "cIsTransient", sol::overload(
            static_cast<bool (BFEntityType::*)()>(&BFEntityType::cIsTransient),
            static_cast<bool (BFEntityType::*)(bool)>(&BFEntityType::cIsTransient)
        ),
        "cUsesPlacementCube", sol::overload(
            static_cast<bool (BFEntityType::*)()>(&BFEntityType::cUsesPlacementCube),
            static_cast<bool (BFEntityType::*)(bool)>(&BFEntityType::cUsesPlacementCube)
        ),
        "cShow", sol::overload(
            static_cast<bool (BFEntityType::*)()>(&BFEntityType::cShow),
            static_cast<bool (BFEntityType::*)(bool)>(&BFEntityType::cShow)
        ),
        "cHitThreshold", sol::overload(
            static_cast<int (BFEntityType::*)()>(&BFEntityType::cHitThreshold),
            static_cast<int (BFEntityType::*)(int)>(&BFEntityType::cHitThreshold)
        ),
        "cAvoidEdges", sol::overload(
            static_cast<bool (BFEntityType::*)()>(&BFEntityType::cAvoidEdges),
            static_cast<bool (BFEntityType::*)(bool)>(&BFEntityType::cAvoidEdges)
        ),
        "typeName", sol::overload(
            static_cast<std::string (BFEntityType::*)()>(&BFEntityType::typeName),
            static_cast<std::string (BFEntityType::*)(std::string)>(&BFEntityType::typeName)
        ),
        "codename", sol::overload(
            static_cast<std::string (BFEntityType::*)()>(&BFEntityType::codename),
            static_cast<std::string (BFEntityType::*)(std::string)>(&BFEntityType::codename)
        ),
        "cFootprintX", sol::overload(
            static_cast<int (BFEntityType::*)()>(&BFEntityType::cFootprintX),
            static_cast<int (BFEntityType::*)(int)>(&BFEntityType::cFootprintX)
        ),
        "cFootprintY", sol::overload(
            static_cast<int (BFEntityType::*)()>(&BFEntityType::cFootprintY),
            static_cast<int (BFEntityType::*)(int)>(&BFEntityType::cFootprintY)
        ),
        "cFootprintZ", sol::overload(
            static_cast<int (BFEntityType::*)()>(&BFEntityType::cFootprintZ),
            static_cast<int (BFEntityType::*)(int)>(&BFEntityType::cFootprintZ)
        ),
        "cPlacementFootprintX", sol::overload(
            static_cast<int (BFEntityType::*)()>(&BFEntityType::cPlacementFootprintX),
            static_cast<int (BFEntityType::*)(int)>(&BFEntityType::cPlacementFootprintX)
        ),
        "cPlacementFootprintY", sol::overload(
            static_cast<int (BFEntityType::*)()>(&BFEntityType::cPlacementFootprintY),
            static_cast<int (BFEntityType::*)(int)>(&BFEntityType::cPlacementFootprintY)
        ),
        "cPlacementFootprintZ", sol::overload(
            static_cast<int (BFEntityType::*)()>(&BFEntityType::cPlacementFootprintZ),
            static_cast<int (BFEntityType::*)(int)>(&BFEntityType::cPlacementFootprintZ)
        ),
        "availableAtStartup", sol::overload(
            static_cast<bool (BFEntityType::*)()>(&BFEntityType::availableAtStartup),
            static_cast<bool (BFEntityType::*)(bool)>(&BFEntityType::availableAtStartup)
        )
    );
}

void BFEntityType::LoadConfiguration() {
    CSimpleIniA ini;
    ini.SetUnicode();
    std::string file = this->codename() + ".ai";
    const char* filename = file.c_str();
    ini.LoadFile("0.ai");
    const char* integers = "Characteristics/Integers";
    const char* pVal = ini.GetValue(integers, "ncolors");
    if (pVal) {
        this->ncolors(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cIconZoom");
    if (pVal) {
        this->cIconZoom(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cExpansionID");
    if (pVal) {
        this->cExpansionID(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cMovable");
    if (pVal) {
        this->cMovable(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "walkable");
    if (pVal) {
        this->walkable(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "walkableByTall");
    if (pVal) {
        this->walkableByTall(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cRubbleable");
    if (pVal) {
        this->cRubbleable(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cUseNumbersInName");
    if (pVal) {
        this->cUseNumbersInName(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cUsesRealShadows");
    if (pVal) {
        this->cUsesRealShadows(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cHasShadowImages");
    if (pVal) {
        this->cHasShadowImages(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cForceShadowBlack");
    if (pVal) {
        this->cForceShadowBlack(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cDrawsLate");
    if (pVal) {
        this->cDrawsLate(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cHeight");
    if (pVal) {
        this->cHeight(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cDepth");
    if (pVal) {
        this->cDepth(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cHasUnderwaterSection");
    if (pVal) {
        this->cHasUnderwaterSection(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cIsTransient");
    if (pVal) {
        this->cIsTransient(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cUsesPlacementCube");
    if (pVal) {
        this->cUsesPlacementCube(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cShow");
    if (pVal) {
        this->cShow(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cHitThreshold");
    if (pVal) {
        this->cHitThreshold(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cAvoidEdges");
    if (pVal) {
        this->cAvoidEdges(atoi(pVal));
    }
    const char* strings = "Configuration/Strings";
    pVal = ini.GetValue(strings, "typeName");
    if (pVal) {
        this->typeName(pVal);
    }
    pVal = ini.GetValue(strings, "codename");
    if (pVal) {
        this->codename(pVal);
    }
    pVal = ini.GetValue(integers, "cFootprintX");
    if (pVal) {
        this->cFootprintX(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cFootprintY");
    if (pVal) {
        this->cFootprintY(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cFootprintZ");
    if (pVal) {
        this->cFootprintZ(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cPlacementFootprintX");
    if (pVal) {
        this->cPlacementFootprintX(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cPlacementFootprintY");
    if (pVal) {
        this->cPlacementFootprintY(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cPlacementFootprintZ");
    if (pVal) {
        this->cPlacementFootprintZ(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "availableAtStartup");
    if (pVal) {
        this->availableAtStartup(atoi(pVal));
    }
}
