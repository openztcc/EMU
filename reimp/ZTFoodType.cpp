#include "ZTFoodType.h"
#include "Windows.h"

int ZTFoodType::cKeeperFoodType() {
    return *(int*)((DWORD)this->thisptr + 0x168);
}

int ZTFoodType::cKeeperFoodType(int input) {
    *(int*)((DWORD)this->thisptr + 0x168) = input;
    return input;
}

void ZTFoodType::ExportClassToLua(sol::state_view& lua) {
    lua.new_usertype<ZTFoodType>("ZTFoodType",
        sol::constructors<ZTFoodType(void*)>(),
        "cKeeperFoodType", sol::overload(
            sol::resolve<int()>(static_cast<int(ZTFoodType::*)()>(&ZTFoodType::cKeeperFoodType)),
            sol::resolve<int(int)>(static_cast<int(ZTFoodType::*)(int)>(&ZTFoodType::cKeeperFoodType))
        ),
        sol::base_classes, sol::bases<ZTSceneryType, BFEntityType>()
    );
}
