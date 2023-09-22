#include "ZooState.h"

//using LuaFunction = std::function<void(lua_State*)>;

ZooState::ZooState()
{
    
}

ZooState::~ZooState(void)
{
}

DWORD ZooState::object_ptr(DWORD offset)
{
    return (*((DWORD*)((LPVOID)0x638048)) + offset);
}

/// @brief Pause the game.
/// @param input 
void ZooState::PauseGame(bool input)
{
    bool* p = (bool*)(*((DWORD*)((LPVOID)0x638588)));
    *p = input;
}


/// @brief Overload: allows a user to set
/// @param input 
void ZooState::FreezeGameState(bool is_loaded)
{
    bool* p = ((bool*)object_ptr(0x4));
    *p = is_loaded;
}


/// @brief Pause the game.
/// @param input 
bool ZooState::IsZooLoaded()
{
    bool* p = ((bool*)object_ptr(0x4));
    return *p;
}

/// @brief Add money to the zoo budget.
/// @param input 
void ZooState::AddToZooBudget(float input)
{
    float* budget = (float*)object_ptr(0x0C);
    *budget = (float)(*budget + input);
}

/// @brief Returns the zoo budget.
/// @return 
float ZooState::GetZooBudget()
{
    float* budget = (float*)object_ptr(0x0C);
    return *budget;
}

/// @brief Sets the zoo budget.
/// @return 
void ZooState::SetZooBudget(float new_budget)
{
    float* budget = (float*)object_ptr(0x0C);
    *budget = new_budget;
}

/// @brief Returns number of animals in zoo.
/// @return 
int ZooState::NumAnimals()
{
    int* p = ((int*)object_ptr(0x30));
    return *p;
}

/// @brief Returns number of animal species in zoo.
/// @return 
int ZooState::NumSpecies()
{
    int* p = ((int*)object_ptr(0x38));
    return *p;
}

/// @brief Returns number of guests in the zoo.
/// @return 
int ZooState::NumGuests()
{
    int* p = ((int*)object_ptr(0x54));
    return *p;
}

/// @brief Returns the number of tired guests.
/// @return 
int ZooState::NumTiredGuests()
{
    int* p = ((int*)object_ptr(0x3C));
    return *p;
}

/// @brief Returns the number of hungry guests.
/// @return 
int ZooState::NumHungryGuests()
{
    int* p = ((int*)object_ptr(0x40));
    return *p;
}

/// @brief Returns the number of thirsty guests.
/// @return 
int ZooState::NumThirstyGuests()
{
    int* p = ((int*)object_ptr(0x44));
    return *p;
}

/// @brief Returns the number of guests that need the restroom.
/// @return 
int ZooState::NumGuestsNeedRestrm()
{
    int* p = ((int*)object_ptr(0x48));
    return *p;
}

int ZooState::NumGuestsInFilter()
{
    int* p = ((int*)object_ptr(0x54));
    return *p;
}

float ZooState::GetZooAdmissionCost()
{
    float* p = ((float*)object_ptr(0x1160));
    return *p;
}

void ZooState::SetZooAdmissionCost(float new_cost)
{
    float* p = ((float*)object_ptr(0x1160));
    *p = new_cost;
}

/// LISTS

/// @brief Returns admissions income by month as a 12-member array.
/// @return 
float* ZooState::AdmissionsIncomeByMonth()
{
    float* p = ((float*)object_ptr(0x254));
    return p;
}

float* ZooState::ConcessionsBenefitByMonth()
{
    float* p = ((float*)object_ptr(0x284));
    return p;
}

// Offset is incorrect
// float* ZooState::RecyclingBenefitByMonth()
// {
//     float* p = ((float*)object_ptr(0x314));
//     return p;
// }

float* ZooState::ZooProfitOverTime()
{
    float* p = ((float*)object_ptr(0x404));
    return p;
}

float* ZooState::PrivateDonationsByMonth()
{
    float* p = ((float*)object_ptr(0x2E4));
    return p;
}

float* ZooState::ZooRatingByMonth()
{
    float* p = ((float*)object_ptr(0x464));
    return p;
}

float* ZooState::ConstructionCostByMonth()
{
    float* p = ((float*)object_ptr(0x1F4));
    return p;
}

float* ZooState::AnimalPurchaseCostsByMonth()
{
    float* p = ((float*)object_ptr(0x1C4));
    return p;
}

// needs another look
float* ZooState::ResearchCostsByMonth()
{
    float* p = ((float*)object_ptr(0xD10));
    return p;
}

float* ZooState::ZooValueByMonth()
{
    float* p = ((float*)object_ptr(0x434));
    return p;
}

// float* ZooState::ZooValueByMonth()
// {
//     float* p = ((float*)object_ptr(0x434));
//     return p;
// }

/// @brief Print a human-readable list of one of the year-long arrays.
/// @param p 12-member float
/// @param msg message to display
void ZooState::print_year_to_console(float* p, std::string msg)
{
    std::cout << std::endl;
    std::string calendar[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    std::cout << msg << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 12; i++)
    {
        std::cout << calendar[i] << ": ";
        int val = (int)p[i];
        if (val < -1000000000)
        {
            std::cout << "[Value too low/not available]" << std::endl;
        }
        else
        {
            std::cout << val << std::endl;
        }
        
    }

    std::cout << std::endl;
}