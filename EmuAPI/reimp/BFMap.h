#ifndef BFMAP_H
#define BFMAP_H

typedef int (__thiscall *ogGenerateMap)(void*, int, int);

class BFMap {
    public:
    static void init();
    static int __fastcall generateMap(void*, int, int);
};

#endif // BFMAP_H