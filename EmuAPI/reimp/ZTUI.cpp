#include "ZTUI.h"

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

