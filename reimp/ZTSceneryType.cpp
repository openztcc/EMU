#include "ZTSceneryType.h"
#include <Windows.h> // must always be above detours.h
#include "SimpleIni.h"

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

bool ZTSceneryType::cDeletable() {
    return *(bool*)((DWORD)this->thisptr + 0x119);
}

bool ZTSceneryType::cDeletable(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x119) = input;
    return input;
}

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

void ZTSceneryType::ExportClassToLua(sol::state& lua) {
    lua.open_libraries(sol::lib::base);
    lua_State* L = lua.lua_state();
    sol::state_view _lua(L);

    lua.new_usertype<ZTSceneryType>("ZTSceneryType",
        "new", sol::constructors<ZTSceneryType(void*)>(),
        "cPurchaseCost", sol::overload(
            static_cast<int (ZTSceneryType::*)()>(&ZTSceneryType::cPurchaseCost),
            static_cast<int (ZTSceneryType::*)(int)>(&ZTSceneryType::cPurchaseCost)
        ),
        "cNameID", sol::overload(
            static_cast<int (ZTSceneryType::*)()>(&ZTSceneryType::cNameID),
            static_cast<int (ZTSceneryType::*)(int)>(&ZTSceneryType::cNameID)
        ),
        "cHelpID", sol::overload(
            static_cast<int (ZTSceneryType::*)()>(&ZTSceneryType::cHelpID),
            static_cast<int (ZTSceneryType::*)(int)>(&ZTSceneryType::cHelpID)
        ),
        "cHabitat", sol::overload(
            static_cast<int (ZTSceneryType::*)()>(&ZTSceneryType::cHabitat),
            static_cast<int (ZTSceneryType::*)(int)>(&ZTSceneryType::cHabitat)
        ),
        "cLocation", sol::overload(
            static_cast<int (ZTSceneryType::*)()>(&ZTSceneryType::cLocation),
            static_cast<int (ZTSceneryType::*)(int)>(&ZTSceneryType::cLocation)
        ),
        "cEra", sol::overload(
            static_cast<int (ZTSceneryType::*)()>(&ZTSceneryType::cEra),
            static_cast<int (ZTSceneryType::*)(int)>(&ZTSceneryType::cEra)
        ),
        "cMaxFoodUnits", sol::overload(
            static_cast<int (ZTSceneryType::*)()>(&ZTSceneryType::cMaxFoodUnits),
            static_cast<int (ZTSceneryType::*)(int)>(&ZTSceneryType::cMaxFoodUnits)
        ),
        "cDeletable", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cDeletable),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cDeletable)
        ),
        "cStink", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cStink),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cStink)
        ),
        "cEstheticWeight", sol::overload(
            static_cast<int (ZTSceneryType::*)()>(&ZTSceneryType::cEstheticWeight),
            static_cast<int (ZTSceneryType::*)(int)>(&ZTSceneryType::cEstheticWeight)
        ),
        "cSelectable", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cSelectable),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cSelectable)
        ),
        "cFoliage", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cFoliage),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cFoliage)
        ),
        "cAutoRotate", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cAutoRotate),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cAutoRotate)
        ),
        "cLand", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cLand),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cLand)
        ),
        "cSwims", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cSwims),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cSwims)
        ),
        "cUnderwater", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cUnderwater),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cUnderwater)
        ),
        "cSurface", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cSurface),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cSurface)
        ),
        "cSubmerge", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cSubmerge),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cSubmerge)
        ),
        "cOnlySwims", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cOnlySwims),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cOnlySwims)
        ),
        "cNeedsConfirm", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cNeedsConfirm),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cNeedsConfirm)
        ),
        "cGawkOnlyFromFront", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cGawkOnlyFromFront),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cGawkOnlyFromFront)
        ),
        "cDeadOnLand", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cDeadOnLand),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cDeadOnLand)
        ),
        "cDeadOnFlatWater", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cDeadOnFlatWater),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cDeadOnFlatWater)
        ),
        "cDeadUnderwater", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cDeadUnderwater),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cDeadUnderwater)
        ),
        "cUsesTreeRubble", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cUsesTreeRubble),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cUsesTreeRubble)
        ),
        "cForcesSceneryRubble", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cForcesSceneryRubble),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cForcesSceneryRubble)
        ),
        "cBlocksLOS", sol::overload(
            static_cast<bool (ZTSceneryType::*)()>(&ZTSceneryType::cBlocksLOS),
            static_cast<bool (ZTSceneryType::*)(bool)>(&ZTSceneryType::cBlocksLOS)
        ),
        "cInfoImageName", sol::overload(
            static_cast<std::string (ZTSceneryType::*)()>(&ZTSceneryType::cInfoImageName),
            static_cast<std::string (ZTSceneryType::*)(std::string)>(&ZTSceneryType::cInfoImageName)
        )
    );
}

void ZTSceneryType::LoadConfiguration() {
    BFEntityType::LoadConfiguration();
    CSimpleIniA ini;
    ini.SetUnicode();
    std::string file = this->codename() + ".ai";
    const char* filename = file.c_str();

    SI_Error result = ini.LoadFile("0.ai");
    if (result < 0) {
        return;
    }
    const char* integers = "Characteristics/Integers";
    const char* pVal = ini.GetValue(integers, "cPurchaseCost");
    if (pVal) {
        this->cPurchaseCost(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cNameID");
    if (pVal) {
        this->cNameID(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cHelpID");
    if (pVal) {
        this->cHelpID(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cHabitat");
    if (pVal) {
        this->cHabitat(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cLocation");
    if (pVal) {
        this->cLocation(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cEra");
    if (pVal) {
        this->cEra(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cMaxFoodUnits");
    if (pVal) {
        this->cMaxFoodUnits(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cDeletable");
    if (pVal) {
        this->cDeletable(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cStink");
    if (pVal) {
        this->cStink(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cEstheticWeight");
    if (pVal) {
        this->cEstheticWeight(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cSelectable");
    if (pVal) {
        this->cSelectable(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cFoliage");
    if (pVal) {
        this->cFoliage(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cAutoRotate");
    if (pVal) {
        this->cAutoRotate(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cLand");
    if (pVal) {
        this->cLand(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cSwims");
    if (pVal) {
        this->cSwims(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cUnderwater");
    if (pVal) {
        this->cUnderwater(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cSurface");
    if (pVal) {
        this->cSurface(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cSubmerge");
    if (pVal) {
        this->cSubmerge(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cOnlySwims");
    if (pVal) {
        this->cOnlySwims(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cNeedsConfirm");
    if (pVal) {
        this->cNeedsConfirm(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cGawkOnlyFromFront");
    if (pVal) {
        this->cGawkOnlyFromFront(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cDeadOnLand");
    if (pVal) {
        this->cDeadOnLand(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cDeadOnFlatWater");
    if (pVal) {
        this->cDeadOnFlatWater(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cDeadUnderwater");
    if (pVal) {
        this->cDeadUnderwater(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cUsesTreeRubble");
    if (pVal) {
        this->cUsesTreeRubble(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cForcesSceneryRubble");
    if (pVal) {
        this->cForcesSceneryRubble(atoi(pVal));
    }
    pVal = ini.GetValue(integers, "cBlocksLOS");
    if (pVal) {
        this->cBlocksLOS(atoi(pVal));
    }
    // const char* strings = "Characteristics/Strings";
    // pVal = ini.GetValue(strings, "cInfoImageName");
    // if (pVal) {
    //     this->cInfoImageName(pVal);
    // }

}