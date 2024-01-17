#ifndef EMUSCRIPTMGR_H
#define EMUSCRIPTMGR_H

#include <vector>
#include <string>
#include <ctime>
#include <Windows.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "lua.hpp"
#include <sstream>
#include <string.h>
#include "RegZooState.h"

class EmuScriptMgr
{
public:
    EmuScriptMgr(); // overloaded constructor
    ~EmuScriptMgr();
    void findScripts();
    void storeScripts();
    int executeScripts();
    
private:
    std::vector<std::string> files;
    std::vector<std::string> file_names;
    std::vector<lua_CFunction> compiled_scripts;
    std::vector<std::string> scripts;
    static int writer(const void*, size_t, void*);

    char* timestamp;
    lua_State *lua;
	std::ofstream& f;
};

#endif