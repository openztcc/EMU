#include "ZTGuest.h"
#include "ZTUI.h"



void ZTGuest::ExportClassToLua(sol::state_view& lua) {
    lua.new_usertype<ZTGuest>("ZTGuest",
        "new", sol::constructors<ZTGuest(void*)>(),
        sol::base_classes, sol::bases<ZTUnit, BFUnit, BFEntity>() );
}