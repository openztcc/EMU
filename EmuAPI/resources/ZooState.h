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

    void PauseGame(bool);
    void SetZooBudget(float);
    float GetZooBudget();
    void AddToZooBudget(float);
    int NumAnimals();
    int  NumSpecies();
    int NumGuests();
    float* AdmissionsIncomeByMonth();
    float* ConcessionsBenefitByMonth();
    float* RecyclingBenefitByMonth();
    float* ZooProfitOverTime();
    float* ZooRatingByMonth();
    float* ConstructionCostByMonth();
    float* PrivateDonationsByMonth();
    float* AnimalPurchaseCostsByMonth();
    float* ResearchCostsByMonth();
    // verify
    int NumAngryGuests();
    int NumTiredGuests();
    int NumHungryGuests();
    int NumThirstyGuests();
    int NumGuestsNeedRestrm();
    int NumGuestsInFilter();
    float GetZooAdmissionCost();
    void SetZooAdmissionCost(float);
    float* ZooValueByMonth();

    void print_year_to_console(float*, std::string);

private:
        
    DWORD object_ptr;
};

#endif
