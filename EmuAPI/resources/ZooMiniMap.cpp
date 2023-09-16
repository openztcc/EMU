#include "ZooMiniMap.h"

ZooMiniMap::ZooMiniMap()
{
    dflt_set = false;
}

ZooMiniMap::~ZooMiniMap()
{

}

bool ZooMiniMap::dflt_set = false;
int ZooMiniMap::min_map_x = 800;
int ZooMiniMap::min_map_y = 600;

void ZooMiniMap::SetMiniMapCursor(int mapx, int mapy)
{
    DWORD ptr = *((DWORD*)((LPVOID)0x638068)) + 0x4C;
    int* x = ((int*)ptr);

    DWORD ptr2 = *((DWORD*)((LPVOID)0x638068)) + 0x50;
    int* y = ((int*)ptr2);

    if (dflt_set == false)
    {
        dflt_set = true;
        min_map_x = *x;
        min_map_y = *y;  
    }

    *x = mapx;
    *y = mapy;
}

void ZooMiniMap::SetMiniMapCursor(std::string size)
{
    DWORD ptr = *((DWORD*)((LPVOID)0x638068)) + 0x4C;
    int* x = ((int*)ptr);

    DWORD ptr2 = *((DWORD*)((LPVOID)0x638068)) + 0x50;
    int* y = ((int*)ptr2);

    if (dflt_set == false)
    {
        dflt_set = true;
        min_map_x = *x;
        min_map_y = *y;  
    }

    if (size == "small")
    {
        *x = 512;
        *y = 384;
    }
    else if (size == "default")
    {
        *x = 1024;
        *y = 768;
    }
    else if (size == "large")
    {
        *x = 2048;
        *y = 1536;
    }
}

void ZooMiniMap::RestoreMiniMapCursor()
{
    DWORD ptr = *((DWORD*)((LPVOID)0x638068)) + 0x4C;
    int* x = ((int*)ptr);

    DWORD ptr2 = *((DWORD*)((LPVOID)0x638068)) + 0x50;
    int* y = ((int*)ptr2);
    
    if (dflt_set == true)
    {
        *x = min_map_x;
        *y = min_map_y;
    }
    else 
    {
        std::cout << "Err: Mini Map cursor size is already the default." << std::endl << std::endl;
    }
}

int ZooMiniMap::GetMiniMapCursorX()
{
    return 0;
}

int ZooMiniMap::GetMiniMapCursorY()
{
    return 0;
}