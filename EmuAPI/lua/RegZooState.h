#ifndef REGZOOSTATE_H
#define REGZOOSTATE_H

#include "lua.hpp"
#include "ZooState.h"

class RegZooState
{
    public:
        RegZooState(lua_State*);
        static void register_zoo_state(lua_State*);
        static int lua_ZooState_GetZooBudget(lua_State*);
        static int lua_ZooState_IsZooLoaded(lua_State*);
        static int lua_ZooState_PauseGame(lua_State*);
        static int lua_ZooState_IsGamePaused(lua_State*);
        static int lua_ZooState_SetZooBudget(lua_State*);
        static int lua_ZooState_AddToZooBudget(lua_State*);
        static int lua_ZooState_NumAnimals(lua_State*);
        static int  lua_ZooState_NumSpecies(lua_State*);
        static int lua_ZooState_NumGuests(lua_State*);
        static int lua_ZooState_AdmissionsIncomeByMonth(lua_State*);
        static int lua_ZooState_ConcessionsBenefitByMonth(lua_State*);
        static int lua_ZooState_ZooProfitOverTime(lua_State*);
        static int lua_ZooState_ZooRatingByMonth(lua_State*);
        static int lua_ZooState_ConstructionCostByMonth(lua_State*);
        static int lua_ZooState_PrivateDonationsByMonth(lua_State*);
        static int lua_ZooState_AnimalPurchaseCostsByMonth(lua_State*);
        static int lua_ZooState_ResearchCostsByMonth(lua_State*);
        //static int lua_ZooState_NumAngryGuests(lua_State*);
        static int lua_ZooState_NumTiredGuests(lua_State*);
        static int lua_ZooState_NumHungryGuests(lua_State*);
        static int lua_ZooState_NumThirstyGuests(lua_State*);
        static int lua_ZooState_NumGuestsNeedRestrm(lua_State*);
        static int lua_ZooState_NumGuestsInFilter(lua_State*);
        static int lua_ZooState_GetZooAdmissionCost(lua_State*);
        static int lua_ZooState_SetZooAdmissionCost(lua_State*);
        static int lua_ZooState_ZooValueByMonth(lua_State*);
};

#endif