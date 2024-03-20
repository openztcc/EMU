#include "ZTUI.h"
#include "ZTGameMgr.h"
#include "bfinternat.h"
#include "EmuBase.h"
#include <ostream>
#include "Windows.h"
#include "detours.h"
#include "ZTWorldMgr.h"
#include "ZTGameMgr.h"

unsigned int ZTUI::gameopts::saveGame(void) {
    _saveGame _ogsaveGame = (_saveGame)0x004769ac;
    return _ogsaveGame();
}

// hooked but filestr is not readable yet
unsigned int ZTUI::gameopts::loadFile(char **filestr) {
    _loadFile _ogloadFile = (_loadFile)0x00453000;
    // std::ofstream logFile("filename.txt");
    // if (logFile.is_open()) {
    //     logFile << *filename << std::endl;
    //     logFile.close();
    // }
    return _ogloadFile(filestr);
}

void* ZTUI::general::getMapView(void) {
    void* ztmapview = (void*)(0x00638068);
    if (ztmapview == 0) {
        ztmapview = (void*)BFUIMgr::getElement(7000);
    }

    return ztmapview;
}

void* ZTUI::general::getSelectedEntity(void) {
    _getSelectedEntity _oggetSelectedEntity = (_getSelectedEntity)0x00410f84;
    return _oggetSelectedEntity();
}

void* ZTUI::general::getSelectedEntityType(void) {
    if (getSelectedEntity() == 0) {
        return 0;
    }
    void* entity = getSelectedEntity();
    void* entitytype = *(void**)((DWORD)entity + 0x128);
    return (void*)entitytype;
}

void ZTUI::general::makeSelectableByType(int type) {
    if (type == 0) {
        return;
    }
    std::vector<int> id;
    id.push_back(type);
    std::vector<DWORD*> entities = ZTWorldMgr::GetAllEntitiesOfType(id);
    makeSelectable(entities);
}

void ZTUI::general::makeSelectable(std::vector<DWORD*> entities) {
    if (entities.size() == 0) {
        return;
    }
    for (size_t i = 0; i < entities.size(); i++) {
        void* entity = (void*)entities[i];
        void* entitytype = *(void**)((DWORD)entity + 0x128);
        // selectable offset is 0x128
        void* selectable = (void*)((DWORD)entitytype + 0x128);
        *(bool*)selectable = true;
    }
}

void ZTUI::general::ExportClassToLua(sol::state& lua) {
    lua.open_libraries(sol::lib::base);
    lua_State* L = lua.lua_state();
    sol::state_view _lua(L);

    lua.new_usertype<ZTUI::general>("ztUIGeneral",
        "new", sol::no_constructor,
        "getSelectedEntity", &ZTUI::general::getSelectedEntity,
        "getSelectedEntityType", &ZTUI::general::getSelectedEntityType,
        "makeSelectableByType", &ZTUI::general::makeSelectableByType,
        "makeSelectable", &ZTUI::general::makeSelectable
    );
}

void ZTUI::main::setMoneyText(rgb color) {
    // set money text show in the UI
    float money = ZTGameMgr::getCash();

    // void* pBFUIMgr = *(void**)0x00638de0;
    //DWORD pBFUIMgr = *(DWORD*)((LPVOID)0x00638de0);
    //DWORD bfuimgr = *((DWORD*)((LPVOID)0x00638de0));
    void *pBFUIMgr = reinterpret_cast<void*>(0x00638de0);
    // GXRGB color = {0, 0, 0}; // set color to black

    // float money_to_display = (float)((int)money); // round down to nearest integer
    BFUIMgr::setControlForeColor(pBFUIMgr, 0x3f8, color); // set control forecolor
    bfinternat::setMoneyText(0x3f8, (int)money, '\x01'); // set money text
}

void ZTUI::main::init() {
    // initialize the UI
    // setMoneyText();
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DWORD setMoneyTextAdd = 0x0040ee3d;
    DetourAttach((PVOID*)&setMoneyTextAdd, (PVOID)&ZTUI::main::setMoneyText);
    DetourTransactionCommit();
    // EmuBase::callHook(0x0040f02e, (DWORD)&ZTUI::main::setMoneyText_Detour); // from addCash
    // EmuBase::callHook(0x0041d38d, (DWORD)&ZTUI::main::setMoneyText_Detour); // from updateSim
    // EmuBase::callHook(0x0041ef7e, (DWORD)&ZTUI::main::setMoneyText_Detour); // from subtractCash
    // EmuBase::callHook(0x00519c1c, (DWORD)&ZTUI::main::setMoneyText_Detour); // from init

    EmuBase::callHook(0x00485d9c, (DWORD)&ZTUI::gameopts::loadFile); // from clickContinue
    EmuBase::callHook(0x004c9a13, (DWORD)&ZTUI::gameopts::loadFile); // from beginScenario
    EmuBase::callHook(0x004cc462, (DWORD)&ZTUI::gameopts::loadFile); // from loadGame
    EmuBase::callHook(0x005c1d28, (DWORD)&ZTUI::gameopts::loadFile); // from ZTApp::iniInstance
}

ZTUI::main::main() {
    // constructor
    color.c = 0;
    color.r = 0;
}

void ZTUI::main::setMoneyText_Detour() {
    // detour function for setting money text in the UI
    ZTUI::main::setMoneyText(ZTUI::main::shared_instance().color);
}

void ZTUI::main::unpauseGame() {
    _unpauseGame _ogunpauseGame = (_unpauseGame)0x0059c7a9;
    _ogunpauseGame();
}

void ZTUI::main::pauseGame() {
    _pauseGame _ogpauseGame = (_pauseGame)0x0059c6b8;
    _ogpauseGame();
}

