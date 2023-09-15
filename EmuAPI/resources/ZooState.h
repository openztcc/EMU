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
    float* IncomeExpenseTotalsByMonth();
    float* ZooRatingByMonth();
    float* ConstructionCostByMonth();
    // verify
    int NumAngryGuests();
    int NumTiredGuests();
    int NumHungryGuests();
    int NumThirstyGuests();
    int NumGuestsNeedRestrm();
    int NumGuestsInFilter();
    float ZooAdmissionCost();
    float* ZooValueOverTime();

    void print_year_to_console(float*, std::string);

private:
        
    DWORD object_ptr;
};

#endif
