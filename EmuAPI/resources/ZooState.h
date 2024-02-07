#ifndef ZOOSTATE_H
#define ZOOSTATE_H

#ifndef EMU_EXPORTS
#define EMU_API __declspec(dllexport)
#else
#define EMU_API __declspec(dllimport)
#endif

#include "EmuBase.h"
#include <string>
#include <iostream>
#include "lua.hpp"
#include <map>
#include <functional>
#include <fstream>
#include "detours.h"
#include "ZooModels.h"

extern "C" {
    EMU_API void FreezeGameState(bool);
    EMU_API void PauseGame(bool);
    EMU_API bool IsGamePaused();
    EMU_API void SetZooBudget(float);
    EMU_API float GetZooBudget();
    EMU_API void AddToZooBudget(float);
    EMU_API void EnableDevMode(bool);
    EMU_API bool IsDevModeEnabled();
}

class ZooState
{

public:
	/// Lua Managers
    static void register_zoo_state(lua_State*);
    static int lua_ZooState_GetZooBudget(lua_State*);

	/// Zoo State
	ZooState();
	~ZooState();
    void FreezeGameState(bool);
    static bool IsZooLoaded();
    static void PauseGame(bool);
    static bool IsGamePaused();
    static void SetZooBudget(float);
    static float GetZooBudget();
    static void AddToZooBudget(float);
    static int NumAnimals();
    static int  NumSpecies();
    static int NumGuests();
    static float* AdmissionsIncomeByMonth();
    static float* ConcessionsBenefitByMonth();
    // static float* RecyclingBenefitByMonth();
    static float* ZooProfitOverTime();
    static float* ZooRatingByMonth();
    static float* ConstructionCostByMonth();
    static float* PrivateDonationsByMonth();
    static float* AnimalPurchaseCostsByMonth();
    static float* ResearchCostsByMonth();
    // verify
    //static int NumAngryGuests();
    static int NumTiredGuests();
    static int NumHungryGuests();
    static int NumThirstyGuests();
    static int NumGuestsNeedRestrm();
    static int NumGuestsInFilter();
    static float GetZooAdmissionCost();
    static void SetZooAdmissionCost(float);
    static float* ZooValueByMonth();

    static int SetZooRating(int);
    static void SetGuestRating(int);
    static void SetAnimalRating(int);
    static void EnableDevMode(bool);
    static bool IsDevModeEnabled();

    static void print_month_to_console(float*, std::string);

    static void print_year_to_console(float*, std::string);
    static DWORD object_ptr(DWORD);

    ZooModels zoo_models;
    }; 

#endif
