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

DWORD ZTUI::general::getSelectedEntity(void) {
    ZTMapView *pZTMapView = ZTUI::general::getMapView();
    if (pZTMapView == 0) {
        return 0;
    } else {
        return reinterpret_cast<DWORD>(pZTMapView[1084]);
    }
}

