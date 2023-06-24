#ifndef ZTGAMEMGR_H
#define ZTGAMEMGR_H

#include "EmuBase.h"

class ZTGameMgr : public EmuBase
{
public:
	ZTGameMgr();
	~ZTGameMgr();
    float* ZooBudget;
    int* NumAnimals;
    int*  NumExhibits;
    int* NumGuests;
    float* AdmissionsIncomeByMonth;
    float* ConcessionsBenefitByMonth;
    float* RecyclingBenefitByMonth;
    float* ZooProfitOverTime;
    float* IncomeExpenseTotalsByMonth;
    float* ZooRatingByMonth;
    float* ConstructionCostByMonth;

    // verify
    int* NumAngryGuests;
    int* NumTiredGuests;
    int* NumHungryGuests;
    int* NumThirstyGuests;
    int* NumGuestsNeedRestrm;
    int* NumGuestsInFilter;
    float* ZooAdmissionCost;
    float* ZooValueOverTime;
};

#endif
