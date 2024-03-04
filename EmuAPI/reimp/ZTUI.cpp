#include "ZTUI.h"
#include "ZTGameMgr.h"
#include "bfinternat.h"

unsigned int ZTUI::gameopts::saveGame(void) {
    _saveGame _ogsaveGame = (_saveGame)0x004769ac;
    return _ogsaveGame();
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
    BFUIMgr::setControlForeColor((LPVOID)pBFUIMgr, 0x3f8, 0xf44bda); // set control forecolor
    bfinternat::setMoneyText(0x3f8, (int)money, '\x01'); // set money text
}

