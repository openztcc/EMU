#ifndef ZTUI_H
#define ZTUI_H

#include "ZTMapView.h"
#include "BFUIMgr.h"

typedef unsigned int (*_saveGame)(void); // define original saveGame function
typedef void (*_unpauseGame)(void); // define original unpauseGame function
typedef void (*_pauseGame)(void); // define original pauseGame function
// typedef ZTMapView (*_getMapView)(void); // define original getMapView function
// typedef void* (*_getSelectedEntity)(void); // define original getSelectedEntity function

namespace ZTUI {
    class gameopts {
        public:
        static unsigned int saveGame();
    };

    class general {
        public:
        static ZTMapView* getMapView();
        static DWORD* getSelectedEntity();
    };

    class main {
        public:
        static void setMoneyText();
        static void init();
        static void unpauseGame(); // hook
        static void pauseGame(); // hook
        static void __cdecl setMoneyText_Detour();
    };
};

#endif /* ZTUI_H */