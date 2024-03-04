#include "ZTUI.h"
#include "ZTGameMgr.h"
#include "bfinternat.h"
#include "EmuBase.h"
#include <ostream>
#include "Windows.h"
#include "detours.h"

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

ZTMapView* ZTUI::general::getMapView(void) {
    ZTMapView *ztmapview = reinterpret_cast<ZTMapView*>(0x00638068);
    if (ztmapview == 0) {
        ztmapview = (ZTMapView*)BFUIMgr::getElement(7000);
    }

    return ztmapview;
}

DWORD* ZTUI::general::getSelectedEntity(void) {
    ZTMapView *pZTMapView = (ZTUI::general::getMapView());
    unsigned char* baseAddr = reinterpret_cast<unsigned char*>(pZTMapView);    
    DWORD* addressAtOffset = reinterpret_cast<DWORD*>(baseAddr + (1084 * sizeof(DWORD)));
    if (pZTMapView == 0) {
        return 0;
    } else {
        return addressAtOffset;
    }
}

void ZTUI::main::setMoneyText() {
    // set money text show in the UI
    float money = ZTGameMgr::shared_instance().zoo_budget;

    // void* pBFUIMgr = *(void**)0x00638de0;
    //DWORD pBFUIMgr = *(DWORD*)((LPVOID)0x00638de0);
    //DWORD bfuimgr = *((DWORD*)((LPVOID)0x00638de0));
    BFUIMgr *pBFUIMgr = reinterpret_cast<BFUIMgr*>((DWORD)0x00638de0);
    // GXRGB color = {0, 0, 0}; // set color to black

    // float money_to_display = (float)((int)money); // round down to nearest integer
    BFUIMgr::setControlForeColor((LPVOID)pBFUIMgr, 0x3f8, 0x001ac5ff); // set control forecolor
    bfinternat::setMoneyText(0x3f8, (int)money, '\x01'); // set money text
}

void ZTUI::main::init() {
    // initialize the UI
    // setMoneyText();

    EmuBase::callHook(0x0040f02e, (DWORD)&ZTUI::main::setMoneyText_Detour); // from addCash
    EmuBase::callHook(0x0041d38d, (DWORD)&ZTUI::main::setMoneyText_Detour); // from updateSim
    EmuBase::callHook(0x0041ef7e, (DWORD)&ZTUI::main::setMoneyText_Detour); // from subtractCash
    EmuBase::callHook(0x00519c1c, (DWORD)&ZTUI::main::setMoneyText_Detour); // from init

    EmuBase::callHook(0x00485d9c, (DWORD)&ZTUI::gameopts::loadFile); // from clickContinue
    EmuBase::callHook(0x004c9a13, (DWORD)&ZTUI::gameopts::loadFile); // from beginScenario
    EmuBase::callHook(0x004cc462, (DWORD)&ZTUI::gameopts::loadFile); // from loadGame
    EmuBase::callHook(0x005c1d28, (DWORD)&ZTUI::gameopts::loadFile); // from ZTApp::iniInstance
}

void ZTUI::main::setMoneyText_Detour() {
    // detour function for setting money text in the UI
    ZTUI::main::setMoneyText();
}

void ZTUI::main::unpauseGame() {
    _unpauseGame _ogunpauseGame = (_unpauseGame)0x0059c7a9;
    _ogunpauseGame();
}

void ZTUI::main::pauseGame() {
    _pauseGame _ogpauseGame = (_pauseGame)0x0059c6b8;
    _ogpauseGame();
}

