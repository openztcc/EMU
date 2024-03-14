
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

void* BFUIMgr::getElement(int param_1) {
    _getElement _oggetElement = (_getElement)0x0040157d;

    return _oggetElement(BFUIMgr::getUIMgr(), param_1);
}

int BFUIMgr::confirmDialog(void* pThis, char param_1, int param_2, int param_3, std::string param_4, char param_5, char param_6, int param_7, int param_8) {
    _confirmDialog _ogconfirmDialog = (_confirmDialog)0x004fff2c;
    return _ogconfirmDialog(pThis, param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}

void BFUIMgr::clickSave() {
    //if (*(BFUIMgr::getElement(1502)) & 2 == 0) {
        // click save button
        if (ZTUI::gameopts::saveGame() != 0) {
            BFUIMgr::getElement(5);
        }
    //}
}

void* BFUIMgr::getUIMgr() {
    return (void*)0x00638de0;;
}

DWORD BFUIMgr::getOffset(DWORD offset) {
    return (*((DWORD*)((LPVOID)0x00638de0)) + offset);
}

void BFUIMgr::setControlForeColor(void* ptr, int param_1, ZTUI::main::rgb color) {
    _setControlForeColor og_setControlForeColor = (_setControlForeColor)0x0040ee08;

    og_setControlForeColor(ptr, param_1, color);
}