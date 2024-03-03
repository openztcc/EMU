#include "ZTUI.h"

unsigned int ZTUI::gameopts::saveGame(void) {
    // call BFUIMgr::clickSave();
    _saveGame _ogsaveGame = (_saveGame)0x004769ac;
    return _ogsaveGame();
}