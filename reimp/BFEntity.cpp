#include "BFEntity.h"
#include "Windows.h"
#include "ZTUI.h"

bool BFEntity::visible() {
    return *(bool*)((DWORD)this->thisptr + 0x13F);
}

bool BFEntity::visible(bool input) {
    *(bool*)((DWORD)this->thisptr + 0x13F) = input;
    return input;
}

std::string BFEntity::name() {
    char* startOfName = *reinterpret_cast<char**>(reinterpret_cast<DWORD>(thisptr) + 0x108);
    char* endOfName = *reinterpret_cast<char**>(reinterpret_cast<DWORD>(thisptr) + 0x10C);

    size_t nameLength = endOfName - startOfName;
    std::string name(startOfName, nameLength);

    return name;
}


void BFEntity::ExportClassToLua(sol::state& lua) {
    lua.open_libraries(sol::lib::base);

    lua.new_usertype<BFEntity>("BFEntity",
        "new", sol::constructors<BFEntity(void*)>(),
        "name", &BFEntity::name,
        "visible", sol::overload(
            static_cast<bool (BFEntity::*)()>(&BFEntity::visible),
            static_cast<bool (BFEntity::*)(bool)>(&BFEntity::visible)
        )
    );
}
