#include "ZooState.h"

ZooState::ZooState()
{
}

ZooState::~ZooState(void)
{
}

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

void ZooState::AddToZooBudget(float input)
{
    Memory<float> w;
    DWORD ptr = *((DWORD*)((LPVOID)0x638048)) + 0x0C;
    float* budget = (float*)ptr;
    w.writeMemory((void*)ptr, (float)(*budget + input));;
}

float GetZooBudget()
{
    DWORD ptr = *((DWORD*)((LPVOID)0x638048)) + 0x0C;
    float* budget = (float*)ptr;
    return *budget;
}



int NumAnimals()
{
    DWORD ptr = *((DWORD*)((LPVOID)0x638048)) + 0x30;
    int* p = ((int*)ptr);
    return *p;
}