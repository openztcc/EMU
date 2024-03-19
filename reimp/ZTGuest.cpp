#include "ZTGuest.h"
#include "ZTUI.h"

std::string ZTGuest::GetSelectedGuestName() {
    void* selectedGuest = ZTUI::general::getSelectedEntity();

    if (!selectedGuest) {
        return "null";
    }

    char* startOfName = *reinterpret_cast<char**>(reinterpret_cast<DWORD>(selectedGuest) + 0x108);
    char* endOfName = *reinterpret_cast<char**>(reinterpret_cast<DWORD>(selectedGuest) + 0x10C);

    size_t nameLength = endOfName - startOfName;
    std::string name(startOfName, nameLength);

    return name;
}

void ZTGuest::ExportClassToLua(sol::state_view& lua) {
    lua.new_usertype<ZTGuest>("ZTGuest",
        "new", sol::constructors<ZTGuest(void*)>(),
        "GetSelectedGuestName", &ZTGuest::GetSelectedGuestName,
        sol::base_classes, sol::bases<ZTUnit, BFUnit, BFEntity>() );
}