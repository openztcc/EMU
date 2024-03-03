
#include "BFUIMgr.h"


BFUIMgr::BFUIMgr() {
    // constructor
}

BFUIMgr::~BFUIMgr() {
    // destructor
}

int __cdecl BFUIMgr::__getElement(void* pThis, int param_1) {
     
    _getElement _getElementAdd = (_getElement)0x0040157d;
    return _getElementAdd(pThis, param_1);
}

int BFUIMgr::getElement(int param_1) {
    // _getElement _oggetElement = (_getElement)0x0040147d;
    // BFUIMgr *pBFUIMgr = reinterpret_cast<BFUIMgr*>((DWORD)0x00638de0);
    BFUIMgr *pBFUIMgr = reinterpret_cast<BFUIMgr*>(0x00638de0);
    return __getElement(pBFUIMgr, param_1);
}

void BFUIMgr::clickSave() {
    if (BFUIMgr::getElement(1502) == 0) {
        // click save button
        if (ZTUI::gameopts::saveGame() != 0) {
            BFUIMgr::getElement(5);
        }
    }
}

