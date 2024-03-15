#include "ZTGuest.h"
#include "ZTUI.h"

std::string ZTGuest::getSelectedGuestName() {
    void* selectedGuest = ZTUI::general::getSelectedEntity();

    if (!selectedGuest) {
        return "null";
    }

    char* startOfName = *reinterpret_cast<char**>(reinterpret_cast<DWORD>(selectedGuest) + 0x108);
    char* endOfName = *reinterpret_cast<char**>(reinterpret_cast<DWORD>(selectedGuest) + 0x10C);

    size_t nameLength = endOfName - startOfName;

    return std::string(startOfName, nameLength);
}