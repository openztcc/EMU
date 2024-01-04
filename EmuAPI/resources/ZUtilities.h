#ifndef ZUTILITIES_H
#define ZUTILITIES_H

#include "EmuBase.h"
#include <string>
#include <iostream>
#include "lua.hpp"
#include <map>
#include <functional>

class ZUtilities
{
    public:
    ZUtilities();
    ~ZUtilities();
    static DWORD SetIAT(const char*, DWORD);
};

#endif