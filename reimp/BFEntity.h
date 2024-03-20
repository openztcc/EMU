#ifndef BFENTITY_H
#define BFENTITY_H

#include "sol/sol.hpp"

class BFEntity {
    public:
    BFEntity(void* ptr) : thisptr(ptr) {};
    void* thisptr;

    std::string name(); // 0x108, 0x10C
    bool visible(); // 0x13F
    bool visible(bool); // 0x13F


    static void ExportClassToLua(sol::state& lua);
};

#endif 