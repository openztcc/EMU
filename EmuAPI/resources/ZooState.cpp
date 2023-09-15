#include "ZooState.h"

ZooState::ZooState()
{
    object_ptr = *((DWORD*)((LPVOID)0x638048));
}

ZooState::~ZooState(void)
{
}

/// @brief Pause the game.
/// @param input 
void ZooState::PauseGame(bool input)
{
    // game has it so pause = false. PauseGame is catchier so I like it this way :P
    if (input == true)
    {
        input = false;
    }
    else
    {
        input = true;
    }

    bool* p = ((bool*)(object_ptr + 0x4));
    *p = input;
}

/// @brief Add money to the zoo budget.
/// @param input 
void ZooState::AddToZooBudget(float input)
{
    float* budget = (float*)(object_ptr + 0x0C);
    *budget = (float)(*budget + input);
}

/// @brief Returns the zoo budget.
/// @return 
float ZooState::GetZooBudget()
{
    float* budget = (float*)(object_ptr + 0x0C);
    return *budget;
}

/// @brief Returns number of animals in zoo.
/// @return 
int ZooState::NumAnimals()
{
    int* p = ((int*)(object_ptr + 0x30));
    return *p;
}

/// @brief Returns number of animal species in zoo.
/// @return 
int ZooState::NumSpecies()
{
    int* p = ((int*)(object_ptr + 0x38));
    return *p;
}

/// @brief Returns number of guests in the zoo.
/// @return 
int ZooState::NumGuests()
{
    int* p = ((int*)(object_ptr + 0x54));
    return *p;
}

/// @brief Returns admissions income by month as a 12-member array.
/// @return 
float* ZooState::AdmissionsIncomeByMonth()
{
    float* p = ((float*)(object_ptr + 0x254));
    return p;
}

float* ZooState::ConcessionsBenefitByMonth()
{
    float* p = ((float*)(object_ptr + 0x29C));
    return p;
}

float* ZooState::RecyclingBenefitByMonth()
{
    float* p = ((float*)(object_ptr + 0x340));
    return p;
}

float* ZooState::ZooProfitOverTime()
{
    float* p = ((float*)(object_ptr + 0x404));
    return p;
}

float* ZooState::IncomeExpenseTotalsByMonth()
{
    float* p = ((float*)(object_ptr + 0x44C));
    return p;
}

float* ZooState::ZooRatingByMonth()
{
    float* p = ((float*)(object_ptr + 0x464));
    return p;
}

float* ZooState::ConstructionCostByMonth()
{
    float* p = ((float*)(object_ptr + 0x824));
    return p;
}

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