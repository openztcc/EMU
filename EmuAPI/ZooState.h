#ifndef ZOOSTATE_H
#define ZOOSTATE_H

#include "EmuBase.h"

class ZooState : public EmuBase
{
    union ptr 
    {
        bool* bl;
        ptr() : bl(NULL) {};
    };

public:
	ZooState();
	~ZooState();

    void PauseGame(bool);
    void SetZooBudget(float);
    float GetZooBudget(float);
    void AddToZooBudget(float);
    int NumAnimals();
    int  NumExhibits();
    int NumGuests();
    float AdmissionsIncomeByMonth();
    float ConcessionsBenefitByMonth();
    float RecyclingBenefitByMonth();
    float ZooProfitOverTime();
    float IncomeExpenseTotalsByMonth();
    float ZooRatingByMonth();
    float ConstructionCostByMonth();

    // verify
    // int* NumAngryGuests;
    // int* NumTiredGuests;
    // int* NumHungryGuests;
    // int* NumThirstyGuests;
    // int* NumGuestsNeedRestrm;
    // int* NumGuestsInFilter;
    // float* ZooAdmissionCost;
    // float* ZooValueOverTime;
};

#endif
