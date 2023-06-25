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