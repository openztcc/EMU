#ifndef ZTFOODTYPE_H
#define ZTFOODTYPE_H

#include "ZTSceneryType.h"
#include <sol/sol.hpp>

class ZTFoodType : public ZTSceneryType {
    public:
    int cKeeperFoodType(); // 0x168
    int cKeeperFoodType(int); // 0x168
    ZTFoodType(void* ptr) : ZTSceneryType(ptr) {};
    static void ExportClassToLua(sol::state_view&);
    ~ZTFoodType();
};

#endif // ZTFOODTYPE_H