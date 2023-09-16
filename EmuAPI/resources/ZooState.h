#ifndef ZOOSTATE_H
#define ZOOSTATE_H

#include "EmuBase.h"
#include <string>
#include <iostream>

class ZooState : public EmuBase
{

public:
	ZooState();
	~ZooState();

    static void PauseGame(bool);
    static void SetZooBudget(float);
    static float GetZooBudget();
    static void AddToZooBudget(float);
    static int NumAnimals();
    static int  NumSpecies();
    static int NumGuests();
    static float* AdmissionsIncomeByMonth();
    static float* ConcessionsBenefitByMonth();
    static float* RecyclingBenefitByMonth();
    static float* ZooProfitOverTime();
    static float* ZooRatingByMonth();
    static float* ConstructionCostByMonth();
    static float* PrivateDonationsByMonth();
    static float* AnimalPurchaseCostsByMonth();
    static float* ResearchCostsByMonth();
    // verify
    static int NumAngryGuests();
    static int NumTiredGuests();
    static int NumHungryGuests();
    static int NumThirstyGuests();
    static int NumGuestsNeedRestrm();
    static int NumGuestsInFilter();
    static float GetZooAdmissionCost();
    static void SetZooAdmissionCost(float);
    static float* ZooValueByMonth();

    static void print_year_to_console(float*, std::string);

private:
        
    static DWORD object_ptr;
};

#endif
