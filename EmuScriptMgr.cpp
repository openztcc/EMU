#include "EmuScriptMgr.h"
#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

EmuScriptMgr::EmuScriptMgr()
{
}

EmuScriptMgr::~EmuScriptMgr()
{
}

// Load all the scripts from the scripts directory into memory
sol::state EmuScriptMgr::LoadScripts()
{
	std::vector<std::string> paths = KeepScriptPathsWithExt(".emu");
	std::string script;
	sol::state lua;
	
	for (auto& path : paths) {
		std::ifstream file(path);
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				script += line + "\n";
			}
			
		}
		else {
			std::cout << "Failed to open file: " << path << std::endl;
		}
		file.close();
		s_scripts.push_back(script);
		lua.script(script);
	}

	return lua;
}

// Execute all the scripts in memory
void EmuScriptMgr::ExecuteScripts(std::string lua_function)
{
	sol::state lua = LoadScripts();
	lua.open_libraries(sol::lib::base, sol::lib::package);
	for (auto& script : s_scripts) {
		sol::protected_function function_driver = lua["emu_run"];

		if (function_driver.valid()) {
			auto result = function_driver(script);
			if (!result.valid()) {
				sol::error err = result;
				std::cout << "Failed to execute function: " << lua_function << std::endl;
				std::cout << "Error: " << err.what() << std::endl;
			}
		}
		else {
			std::cout << "Failed to execute function: " << lua_function << std::endl;
		}
	}

	//sol::function script_func = lua[lua_function];
	//if (script_func.valid()) {
	//	script_func();
	//}
	//else {
	//	std::cout << "Failed to execute function: " << lua_function << std::endl;
	//}

}

void EmuScriptMgr::ConvertToBytecode(const std::string& script)
{
	sol::state lua;
	lua.open_libraries(sol::lib::base, sol::lib::package);
	sol::load_result result = lua.load_file(script);
	assert(result.valid(), "Failed to load script: %s", script.c_str());
	sol::protected_function target = result.get<sol::protected_function>();

	if (result.valid()) {
		sol::bytecode bc = target.dump();
		c_scripts.push_back(bc);
	}

	sol::function script_func = result;
}	

// Find all files in the scripts directory
std::vector<std::string> EmuScriptMgr::FindAllFilePaths() {
	std::string path = "scripts";
	std::vector<std::string> paths;
	if (std::filesystem::is_directory(path)) { // It's a good practice to check this
		for (const auto& entry : std::filesystem::directory_iterator(path)) {
			paths.push_back(entry.path().string());
		}
	}
	return paths;
}

// Keep only the files with the specified extension
std::vector<std::string> EmuScriptMgr::KeepScriptPathsWithExt(std::string ext)
{
	std::vector<std::string> paths = FindAllFilePaths();

	for (auto it = paths.begin(); it != paths.end();) {
		if (it->find(ext) == std::string::npos) {
			it = paths.erase(it);
		}
		else {
			++it;
		}
	}
	return paths;
}

// Prints contents of scripts found
void EmuScriptMgr::PrintFoundScripts()
{
	for (auto& script : s_scripts) {
		std::cout << script << std::endl;
	}
}