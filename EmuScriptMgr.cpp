#include "EmuScriptMgr.h"
#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>

EmuScriptMgr::EmuScriptMgr()
{
}

EmuScriptMgr::~EmuScriptMgr()
{
}

void EmuScriptMgr::LoadScripts()
{
	std::vector<std::string> paths = KeepScriptPathsWithExt(".emu");
	std::string script;
	
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
	}
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

std::vector<std::string> EmuScriptMgr::FindAllFilePaths()
{
	std::string path = "scripts";
	std::vector<std::string> paths;
	if (!std::filesystem::is_directory(path)) {
		std::cout << "Directory does not exist: " << path << std::endl;
	}
	for (const auto& entry : std::filesystem::directory_iterator(path)) {
		paths.push_back(entry.path().string());
	}
	return paths;
}

std::vector<std::string> EmuScriptMgr::KeepScriptPathsWithExt(std::string ext)
{
	std::vector<std::string> paths = FindAllFilePaths();
	std::vector<std::string> ext_paths;
	for (auto& script : paths) {
		if (script.find(ext) != std::string::npos) {
			ext_paths.push_back(script);
		}
	}
	return ext_paths;
}