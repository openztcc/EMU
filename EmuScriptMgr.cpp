#include "EmuScriptMgr.h"

EmuScriptMgr::EmuScriptMgr()
{
}

EmuScriptMgr::~EmuScriptMgr()
{
}

void EmuScriptMgr::LoadScript(const std::string& script)
{
	sol::state lua;
	lua.open_libraries(sol::lib::base, sol::lib::package);

	lua.script_file(script);
}

void EmuScriptMgr::ConvertToBytecode(const std::string& script)
{
	sol::state lua;
	lua.open_libraries(sol::lib::base, sol::lib::package);

	lua.load_file(script);
	lua.
	assert(result.valid(), "Failed to load script: %s", script.c_str());
	sol::protected_function target = result.get<sol::protected_function>();

	if (result.valid()) {
		sol::bytecode bc = target.dump();
		c_scripts.push_back(bc);
	}
}	