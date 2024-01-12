#ifndef ZUTILITIES_H
#define ZUTILITIES_H

#include "EmuBase.h"
#include <string>
#include <iostream>
#include "lua.hpp"
#include <map>
#include <functional>
#include <ctime>
#include <sstream>
#include <fstream>

class ZUtilities
{
    public:
    ZUtilities();
    ~ZUtilities();
    static DWORD SetIAT(const char*, DWORD);
    static void DetourFunction(DWORD, DWORD);
};

#endif