#ifndef ZTUI_H
#define ZTUI_H

#include "ZTMapView.h"
#include "BFUIMgr.h"

typedef unsigned int (*_saveGame)(void); // define original saveGame function
typedef ZTMapView (*_getMapView)(void); // define original getMapView function
typedef void* (*_getSelectedEntity)(void); // define original getSelectedEntity function

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
};

#endif /* ZTUI_H */