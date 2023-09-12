#include "ZooState.h"

ZooState::ZooState()
{
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

    DWORD ptr = *((DWORD*)((LPVOID)0x638048)) + 0x4;
    bool* p = ((bool*)ptr);
    *p = input;
}

/// @brief Add money to the zoo budget.
/// @param input 
void ZooState::AddToZooBudget(float input)
{
    Memory<float> w;
    DWORD ptr = *((DWORD*)((LPVOID)0x638048)) + 0x0C;
    float* budget = (float*)ptr;
    w.writeMemory((void*)ptr, (float)(*budget + input));;
}

/// @brief Returns the zoo budget.
/// @return 
float ZooState::GetZooBudget()
{
    DWORD ptr = *((DWORD*)((LPVOID)0x638048)) + 0x0C;
    float* budget = (float*)ptr;
    return *budget;
}

/// @brief Returns number of animals in zoo.
/// @return 
int ZooState::NumAnimals()
{
    DWORD ptr = *((DWORD*)((LPVOID)0x638048)) + 0x30;
    int* p = ((int*)ptr);
    return *p;
}

/// @brief Returns number of exhibits in zoo.
/// @return 
int ZooState::NumExhibits()
{
    DWORD ptr = *((DWORD*)((LPVOID)0x638048)) + 0x38;
    int* p = ((int*)ptr);
    return *p;
}

/// @brief Returns number of guests in the zoo.
/// @return 
int ZooState::NumGuests()
{
    DWORD ptr = *((DWORD*)((LPVOID)0x638048)) + 0x54;
    int* p = ((int*)ptr);
    return *p;
}

/// @brief Returns admissions income by month as a 12-member array.
/// @return 
float* ZooState::AdmissionsIncomeByMonth()
{
    DWORD ptr = *((DWORD*)((LPVOID)0x638048)) + 0x54;
    float* p = ((float*)ptr);
    return p;
}

/// @brief Print a human-readable list of one of the year-long arrays.
/// @param p 12-member float
/// @param msg message to display
void ZooState::print_year_to_console(float* p, std::string msg)
{
    std::string calendar[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    std::cout << msg << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 12; i++)
    {
        std::cout << calendar[i] << ": " << p[i] << std::endl;
    }
}