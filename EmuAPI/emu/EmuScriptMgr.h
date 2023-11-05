#include <vector>
#include <string>
#include <ctime>
#include <Windows.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "lua.hpp"
#include <sstream>

class EmuScriptMgr
{
public:
    EmuScriptMgr();
    EmuScriptMgr(lua_State*, std::ofstream&); // overloaded constructor
    ~EmuScriptMgr();
    void findScripts();
    void serializeScripts();
    int executeScripts();
    
private:
    std::vector<std::string> files;
    std::vector<std::string> file_names;
    
    std::time_t* t;
    char* timestamp;

    lua_State *lua;
	std::ofstream& f;
};