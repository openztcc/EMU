#ifndef ZTGUEST_H
#define ZTGUEST_H

#include <string>
#include "sol/sol.hpp"
#include "ZTUnit.h"

class ZTGuest : public ZTUnit
{
    public:
    ZTGuest(void* _thisptr) : ZTUnit(_thisptr) {};
    static void init();
    static std::string GetSelectedGuestName();
    static void ExportClassToLua(sol::state_view& lua);
};

#endif // ZTGUEST_H