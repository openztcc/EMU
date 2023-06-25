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
    // float* zoo_budget_;
    // int* num_animals_;
    // int*  num_exhibits_;
    // int* num_guests_;
    // float* admissions_income_by_month_;
    // float* concessions_benefit_by_month_;
    // float* recycling_benefit_by_month_;
    // float* zoo_profit_over_time_;
    // float* income_expense_totals_by_month_;
    // float* zoo_rating_by_month_;
    // float* construction_cost_by_month_;

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
