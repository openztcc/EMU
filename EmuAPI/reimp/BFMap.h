#ifndef BFMAP_H
#define BFMAP_H

typedef void (__thiscall *ogGenerateMap)(void*, int, int, char);

class BFMap {
    public:
    static void init();
    static void generateMap(void*, int, int, char);
};

#endif // BFMAP_H