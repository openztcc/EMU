#ifndef ZTUI_H
#define ZTUI_H

#include "ZTMapView.h"
#include <sol/sol.hpp>

typedef unsigned int (*_saveGame)(void); // define original saveGame function
typedef void (*_unpauseGame)(void); // define original unpauseGame function
typedef void (*_pauseGame)(void); // define original pauseGame function
typedef unsigned int (__cdecl *_loadFile)(char **filename); // define original loadFile function
// typedef ZTMapView (*_getMapView)(void); // define original getMapView function
typedef void* (*_getSelectedEntity)(void); // define original getSelectedEntity function

namespace ZTUI {
    class gameopts {
        public:
        static unsigned int saveGame();
        static unsigned int loadFile(char **filename);
    };

    class general {
        public:
        static void* getMapView();
        static void* getSelectedEntity();
        static void* getSelectedEntityType();
        static void makeSelectableByType(int);
        static void makeSelectable(std::vector<DWORD*>);
        static void ExportClassToLua(sol::state& lua);
    };

    class main {
        public:

        main();
        struct rgb {
            unsigned short c;
            unsigned short r;
        };
        rgb color;
        static main &shared_instance() {
            static main instance;
            return instance;
        }
        static void setMoneyText(rgb);
        static void init();
        static void unpauseGame(); // hook
        static void pauseGame(); // hook
        static void __cdecl setMoneyText_Detour();
    };
};

#endif /* ZTUI_H */