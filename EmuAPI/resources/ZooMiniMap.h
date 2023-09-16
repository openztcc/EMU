#ifndef ZOOMINIMAP_H
#define ZOOMINIMAP_H

#include "EmuBase.h"
#include <string>
#include <iostream>
#include "lua.h"

class ZooMiniMap : public EmuBase
{
    public:
        ZooMiniMap();
        ~ZooMiniMap();
    
        lua_State* L;
        static void SetMiniMapCursor(int, int);
        static void SetMiniMapCursor(std::string);
        static void RestoreMiniMapCursor();
        static int GetMiniMapCursorX();
        static int GetMiniMapCursorY();
    private:
        static bool dflt_set;
        static int min_map_x;
        static int min_map_y;
};

#endif