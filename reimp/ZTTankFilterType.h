#ifndef ZTTANKFILTERTYPE_H
#define ZTTANKFILTERTYPE_H

#include "ZTSceneryType.h"
#include <sol/sol.hpp>

class ZTTankFilterType : public ZTSceneryType {
    public:
    
    ZTTankFilterType(void* ptr) : ZTSceneryType(ptr) {};
    static void ExportClassToLua(sol::state_view&);
    ~ZTTankFilterType() {};
};

#endif // ZTTANKFILTERTYPE_H