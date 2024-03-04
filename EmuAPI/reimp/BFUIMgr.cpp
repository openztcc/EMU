
#include "BFUIMgr.h"


BFUIMgr::BFUIMgr() {
    // constructor
}

BFUIMgr::~BFUIMgr() {
    // destructor
}

// int __cdecl BFUIMgr::__getElement(void* pThis, int param_1) {
     
//     _getElement _getElementAdd = (_getElement)0x0040157d;
//     return _getElementAdd(pThis, param_1);
// }

BFUIMgr* BFUIMgr::getElement(int param_1) {
    _getElement _oggetElement = (_getElement)0x0040157d;
    // DWORD ptr_ZTMapView = *((DWORD*)((LPVOID)0x00638de0));

    BFUIMgr *pBFUIMgr = reinterpret_cast<BFUIMgr*>((DWORD)0x00638de0);
    //BFUIMgr *pBFUIMgr = reinterpret_cast<BFUIMgr*>(0x00638de0);
    return _oggetElement((LPVOID)pBFUIMgr, param_1);
}

void BFUIMgr::clickSave() {
    //if (*(BFUIMgr::getElement(1502)) & 2 == 0) {
        // click save button
        if (ZTUI::gameopts::saveGame() != 0) {
            BFUIMgr::getElement(5);
        }
    //}
}

DWORD BFUIMgr::getUIMgr() {
    return *((DWORD*)((LPVOID)0x00638de0));
}

DWORD BFUIMgr::getOffset(DWORD offset) {
    return (*((DWORD*)((LPVOID)0x00638de0)) + offset);
}

void BFUIMgr::setControlForeColor(void* ptr, int param_1, DWORD color) {
    _setControlForeColor og_setControlForeColor = (_setControlForeColor)0x0040ee08;

    og_setControlForeColor(ptr, param_1, color);
}