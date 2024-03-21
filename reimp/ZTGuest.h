#ifndef ZTGUEST_H
#define ZTGUEST_H

#include <string>
#include "ZTUnit.h"

class ZTGuest : public ZTUnit
{
    public:
    ZTGuest(void* _thisptr) : ZTUnit(_thisptr) {};
    static void init();
    static void ExportClassToLua(sol::state_view&);
};

#endif // ZTGUEST_H