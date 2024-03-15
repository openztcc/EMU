#include "BFEntity.h"
#include "Windows.h"

bool BFEntity::visible() {
    return *(bool*)((DWORD)this->thisptr + 0x13F);
}

bool BFEntity::visible(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x13F) = input;
    return input;
}

void BFEntity::ExportClassToLua(sol::state& lua) {
    lua.open_libraries(sol::lib::base);
    lua_State* L = lua.lua_state();
    sol::state_view _lua(L);

    lua.new_usertype<BFEntity>("BFEntity",
        "new", sol::constructors<BFEntity(void*)>(),
        "visible", sol::overload(
			static_cast<bool (BFEntity::*)()>(&BFEntity::visible),
			static_cast<bool (BFEntity::*)(bool)>(&BFEntity::visible)
		)
    );
}