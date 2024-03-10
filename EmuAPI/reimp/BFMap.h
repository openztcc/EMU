#ifndef BFMAP_H
#define BFMAP_H

typedef void (__thiscall *ogGenerateMap)(void*, int, int, char);
typedef void (*ogSetMapDimensions)(void*, int, int, bool);
typedef void (__thiscall *ogComputeTiles)(void*);

class BFMap {
    public:
    static void init();
    static void generateMap(void*, int, int, char);
    static void setMapDimensions(void*, int, int, bool);
    static void __fastcall computeTiles(void*);
};

#endif // BFMAP_H