#include "RegZooState.h"

void RegZooState::register_zoo_state(lua_State* lua)
{
    // create a new RegZooState object
    lua_register(lua, "GetZooBudget", RegZooState::lua_ZooState_GetZooBudget);
    lua_register(lua, "IsZooLoaded", RegZooState::lua_ZooState_IsZooLoaded);
    lua_register(lua, "PauseGame", RegZooState::lua_ZooState_PauseGame);
    lua_register(lua, "IsGamePaused", RegZooState::lua_ZooState_IsGamePaused);
    lua_register(lua, "SetZooBudget", RegZooState::lua_ZooState_SetZooBudget);
    lua_register(lua, "AddToZooBudget", RegZooState::lua_ZooState_AddToZooBudget);
    lua_register(lua, "NumAnimals", RegZooState::lua_ZooState_NumAnimals);
    lua_register(lua, "NumSpecies", RegZooState::lua_ZooState_NumSpecies);
    lua_register(lua, "NumGuests", RegZooState::lua_ZooState_NumGuests);
    lua_register(lua, "AdmissionsIncomeByMonth", RegZooState::lua_ZooState_AdmissionsIncomeByMonth);
    lua_register(lua, "ConcessionsBenefitByMonth", RegZooState::lua_ZooState_ConcessionsBenefitByMonth);
    lua_register(lua, "ZooProfitOverTime", RegZooState::lua_ZooState_ZooProfitOverTime);
    lua_register(lua, "ZooRatingByMonth", RegZooState::lua_ZooState_ZooRatingByMonth);
    lua_register(lua, "ConstructionCostByMonth", RegZooState::lua_ZooState_ConstructionCostByMonth);
    lua_register(lua, "PrivateDonationsByMonth", RegZooState::lua_ZooState_PrivateDonationsByMonth);
    lua_register(lua, "AnimalPurchaseCostsByMonth", RegZooState::lua_ZooState_AnimalPurchaseCostsByMonth);
    lua_register(lua, "ResearchCostsByMonth", RegZooState::lua_ZooState_ResearchCostsByMonth);
    //lua_register(lua, "NumAngryGuests", RegZooState::lua_ZooState_NumAngryGuests);
    lua_register(lua, "NumTiredGuests", RegZooState::lua_ZooState_NumTiredGuests);
    lua_register(lua, "NumHungryGuests", RegZooState::lua_ZooState_NumHungryGuests);
    lua_register(lua, "NumThirstyGuests", RegZooState::lua_ZooState_NumThirstyGuests);
    lua_register(lua, "NumGuestsNeedRestrm", RegZooState::lua_ZooState_NumGuestsNeedRestrm);
    lua_register(lua, "NumGuestsInFilter", RegZooState::lua_ZooState_NumGuestsInFilter);
    lua_register(lua, "GetZooAdmissionCost", RegZooState::lua_ZooState_GetZooAdmissionCost);
    lua_register(lua, "SetZooAdmissionCost", RegZooState::lua_ZooState_SetZooAdmissionCost);
    lua_register(lua, "ZooValueByMonth", RegZooState::lua_ZooState_ZooValueByMonth);
    lua_register(lua, "SetZooRating", RegZooState::lua_ZooState_SetZooRating);
    lua_register(lua, "SetGuestRating", RegZooState::lua_ZooState_SetGuestRating);
    lua_register(lua, "SetAnimalRating", RegZooState::lua_ZooState_SetAnimalRating);
    lua_register(lua, "EnableDevMode", RegZooState::lua_ZooState_EnableDevMode);
    lua_register(lua, "IsDevModeEnabled", RegZooState::lua_ZooState_IsDevModeEnabled);
}

int RegZooState::lua_ZooState_GetZooBudget(lua_State* lua)
{
    lua_pushnumber(lua, ZooState::GetZooBudget());
    return 1;
}

int RegZooState::lua_ZooState_IsZooLoaded(lua_State* lua)
{
    lua_pushboolean(lua, ZooState::IsZooLoaded());
    return 1;
}

int RegZooState::lua_ZooState_PauseGame(lua_State* lua)
{
        // obtain num of args taken from lua
    int numArgs = lua_gettop(lua);
    
    // only one arg required
    if (numArgs == 1)
    {
        // parameter is at Lua stack 1
        #pragma warning(disable : 4800)
        bool pause_state = lua_toboolean(lua, 1);
        #pragma warning(default : 4800)

        // set new value
        ZooState::PauseGame(pause_state);
    }
    else
    {
        return luaL_error(lua, "Missing argument: pause state (true or false)");
    }

    // ret num of values to ret to lua (0 in this case)
    return 0;
}

int RegZooState::lua_ZooState_IsGamePaused(lua_State* lua)
{
    lua_pushboolean(lua, ZooState::IsGamePaused());
    return 1;
}

int RegZooState::lua_ZooState_SetZooBudget(lua_State* lua)
{
    // obtain num of args taken from lua
    int numArgs = lua_gettop(lua);
    
    // only one arg required
    if (numArgs == 1)
    {
        // parameter is at Lua stack 1
        float newBudget = (float)lua_tonumber(lua, 1);

        // set new value
        ZooState::SetZooBudget(newBudget);
    }
    else
    {
        return luaL_error(lua, "Missing argument: new budget value");
    }

    // ret num of values to ret to lua (0 in this case)
    return 0;
}


int RegZooState::lua_ZooState_AddToZooBudget(lua_State* lua)
{
    // obtain num of args taken from lua
    int numArgs = lua_gettop(lua);
    
    // only one arg required
    if (numArgs == 1)
    {
        // parameter is at Lua stack 1
        float deposit = (float)lua_tonumber(lua, 1);

        // set new value
        ZooState::AddToZooBudget(deposit);
    }
    else
    {
        return luaL_error(lua, "Missing argument: deposit value");
    }

    // ret num of values to ret to lua (0 in this case)
    return 0;
}

int RegZooState::lua_ZooState_NumAnimals(lua_State* lua)
{
    lua_pushnumber(lua, ZooState::NumAnimals());
    return 1;
}

int RegZooState::lua_ZooState_NumSpecies(lua_State* lua)
{
    lua_pushnumber(lua, ZooState::NumSpecies());
    return 1;
}

int RegZooState::lua_ZooState_NumGuests(lua_State* lua)
{
    lua_pushnumber(lua, ZooState::NumGuests());
    return 1;
}

int RegZooState::lua_ZooState_AdmissionsIncomeByMonth(lua_State* lua)
{
    float* incomeArray = ZooState::AdmissionsIncomeByMonth();

    // new lua table to hold the float array
    lua_newtable(lua);

    // push each element of array onto lua table
    for (int i = 0; i < 12; i++) {
        lua_pushnumber(lua, incomeArray[i]);
        lua_rawseti(lua, -2, i + 1); // -2 refers to the table, i + 1 is the Lua array index
    }

    // return the Lua table (it's on top of the stack)
    return 1;
}

int RegZooState::lua_ZooState_ConcessionsBenefitByMonth(lua_State* lua)
{
    float* incomeArray = ZooState::ConcessionsBenefitByMonth();

    // new lua table to hold the float array
    lua_newtable(lua);

    // push each element of array onto lua table
    for (int i = 0; i < 12; i++) {
        lua_pushnumber(lua, incomeArray[i]);
        lua_rawseti(lua, -2, i + 1); // -2 refers to the table, i + 1 is the Lua array index
    }

    // return the Lua table (it's on top of the stack)
    return 1;
}

int RegZooState::lua_ZooState_ZooProfitOverTime(lua_State* lua)
{
    float* incomeArray = ZooState::ZooProfitOverTime();

    // new lua table to hold the float array
    lua_newtable(lua);

    // push each element of array onto lua table
    for (int i = 0; i < 12; i++) {
        lua_pushnumber(lua, incomeArray[i]);
        lua_rawseti(lua, -2, i + 1); // -2 refers to the table, i + 1 is the Lua array index
    }

    // return the Lua table (it's on top of the stack)
    return 1;
}

int RegZooState::lua_ZooState_ZooRatingByMonth(lua_State* lua)
{
    float* incomeArray = ZooState::ZooRatingByMonth();

    // new lua table to hold the float array
    lua_newtable(lua);

    // push each element of array onto lua table
    for (int i = 0; i < 12; i++) {
        lua_pushnumber(lua, incomeArray[i]);
        lua_rawseti(lua, -2, i + 1); // -2 refers to the table, i + 1 is the Lua array index
    }

    // return the Lua table (it's on top of the stack)
    return 1;
}

int RegZooState::lua_ZooState_ConstructionCostByMonth(lua_State* lua)
{
    float* incomeArray = ZooState::ConstructionCostByMonth();

    // new lua table to hold the float array
    lua_newtable(lua);

    // push each element of array onto lua table
    for (int i = 0; i < 12; i++) {
        lua_pushnumber(lua, incomeArray[i]);
        lua_rawseti(lua, -2, i + 1); // -2 refers to the table, i + 1 is the Lua array index
    }

    // return the Lua table (it's on top of the stack)
    return 1;
}

int RegZooState::lua_ZooState_PrivateDonationsByMonth(lua_State* lua)
{
    float* incomeArray = ZooState::PrivateDonationsByMonth();

    // new lua table to hold the float array
    lua_newtable(lua);

    // push each element of array onto lua table
    for (int i = 0; i < 12; i++) {
        lua_pushnumber(lua, incomeArray[i]);
        lua_rawseti(lua, -2, i + 1); // -2 refers to the table, i + 1 is the Lua array index
    }

    // return the Lua table (it's on top of the stack)
    return 1;
}

int RegZooState::lua_ZooState_AnimalPurchaseCostsByMonth(lua_State* lua)
{
    float* incomeArray = ZooState::AnimalPurchaseCostsByMonth();

    // new lua table to hold the float array
    lua_newtable(lua);

    // push each element of array onto lua table
    for (int i = 0; i < 12; i++) {
        lua_pushnumber(lua, incomeArray[i]);
        lua_rawseti(lua, -2, i + 1); // -2 refers to the table, i + 1 is the Lua array index
    }

    // return the Lua table (it's on top of the stack)
    return 1;
}

int RegZooState::lua_ZooState_ResearchCostsByMonth(lua_State* lua)
{
    float* incomeArray = ZooState::ResearchCostsByMonth();

    // new lua table to hold the float array
    lua_newtable(lua);

    // push each element of array onto lua table
    for (int i = 0; i < 12; i++) {
        lua_pushnumber(lua, incomeArray[i]);
        lua_rawseti(lua, -2, i + 1); // -2 refers to the table, i + 1 is the Lua array index
    }

    // return the Lua table (it's on top of the stack)
    return 1;
}

// int RegZooState::lua_ZooState_NumAngryGuests(lua_State* lua)
// {
//     lua_pushnumber(lua, ZooState::NumAngryGuests());
//     return 1;
// }

int RegZooState::lua_ZooState_NumTiredGuests(lua_State* lua)
{
    lua_pushnumber(lua, ZooState::NumTiredGuests());
    return 1;
}

int RegZooState::lua_ZooState_NumHungryGuests(lua_State* lua)
{
    lua_pushnumber(lua, ZooState::NumHungryGuests());
    return 1;
}

int RegZooState::lua_ZooState_NumThirstyGuests(lua_State* lua)
{
    lua_pushnumber(lua, ZooState::NumThirstyGuests());
    return 1;
}

int RegZooState::lua_ZooState_NumGuestsNeedRestrm(lua_State* lua)
{
    lua_pushnumber(lua, ZooState::NumGuestsNeedRestrm());
    return 1;
}

int RegZooState::lua_ZooState_NumGuestsInFilter(lua_State* lua)
{
    lua_pushnumber(lua, ZooState::NumGuestsInFilter());
    return 1;
}

int RegZooState::lua_ZooState_GetZooAdmissionCost(lua_State* lua)
{
    lua_pushnumber(lua, ZooState::GetZooAdmissionCost());
    return 1;
}

int RegZooState::lua_ZooState_SetZooAdmissionCost(lua_State* lua)
{
    // obtain num of args taken from lua
    int numArgs = lua_gettop(lua);
    
    // only one arg required
    if (numArgs == 1)
    {
        // parameter is at Lua stack 1
        float adm_cost = (float)lua_tonumber(lua, 1);

        // set new value
        ZooState::SetZooAdmissionCost(adm_cost);
    }
    else
    {
        return luaL_error(lua, "Missing argument: new admission cost");
    }

    // ret num of values to ret to lua (0 in this case)
    return 0;
}

int RegZooState::lua_ZooState_ZooValueByMonth(lua_State* lua)
{
    float* incomeArray = ZooState::ZooValueByMonth();

    // new lua table to hold the float array
    lua_newtable(lua);

    // push each element of array onto lua table
    for (int i = 0; i < 12; i++) {
        lua_pushnumber(lua, incomeArray[i]);
        lua_rawseti(lua, -2, i + 1); // -2 refers to the table, i + 1 is the Lua array index
    }

    // return the Lua table (it's on top of the stack)
    return 1;
}

int RegZooState::lua_ZooState_SetAnimalRating(lua_State* lua)
{
    // obtain num of args taken from lua
    int numArgs = lua_gettop(lua);
    
    // only one arg required
    if (numArgs == 1)
    {
        ZooModels* instance = static_cast<ZooModels*>(lua_touserdata(lua, lua_upvalueindex(1)));
        // parameter is at Lua stack 1
        int rating = (int)lua_tonumber(lua, 1);
        instance->_animalRating = rating;

        return 1;
    }
    else
    {
        return luaL_error(lua, "Missing argument: new animal rating");
    }

    // ret num of values to ret to lua (0 in this case)
    return 0;
}

int RegZooState::lua_ZooState_SetGuestRating(lua_State* lua)
{
    // obtain num of args taken from lua
    int numArgs = lua_gettop(lua);
    
    // only one arg required
    if (numArgs == 1)
    {
        ZooModels* instance = static_cast<ZooModels*>(lua_touserdata(lua, lua_upvalueindex(1)));
        // parameter is at Lua stack 1
        int rating = (int)lua_tonumber(lua, 1);
        instance->_guestRating = rating;

        // set new value
        // ZooState::SetGuestRating(rating);
    }
    else
    {
        return luaL_error(lua, "Missing argument: new guest rating");
    }

    // ret num of values to ret to lua (0 in this case)
    return 0;
}

int RegZooState::lua_ZooState_SetZooRating(lua_State* lua)
{
    // obtain num of args taken from lua
    int numArgs = lua_gettop(lua);
    
    // only one arg required
    if (numArgs == 1)
    {
        ZooModels* instance = static_cast<ZooModels*>(lua_touserdata(lua, lua_upvalueindex(1)));
        // parameter is at Lua stack 1
        int rating = (int)lua_tonumber(lua, 1);
        instance->_zooRating = rating;

        // set new value
        // ZooState::SetZooRating(rating);
    }
    else
    {
        return luaL_error(lua, "Missing argument: new zoo rating");
    }

    // ret num of values to ret to lua (0 in this case)
    return 0;
}

int RegZooState::lua_ZooState_EnableDevMode(lua_State* lua)
{
    // obtain num of args taken from lua
    int numArgs = lua_gettop(lua);
    
    // only one arg required
    if (numArgs == 1)
    {
        // parameter is at Lua stack 1
        #pragma warning(disable : 4800)
        bool dev_mode = lua_toboolean(lua, 1);
        #pragma warning(default : 4800)

        // set new value
        ZooState::EnableDevMode(dev_mode);
    }
    else
    {
        return luaL_error(lua, "Missing argument: dev mode state (true or false)");
    }

    // ret num of values to ret to lua (0 in this case)
    return 0;
}

int RegZooState::lua_ZooState_IsDevModeEnabled(lua_State* lua)
{
    lua_pushboolean(lua, ZooState::IsDevModeEnabled());
    return 1;
}

