#include "EmuScriptMgr.h"
#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "ZTUI.h"
#include "EmuConsole.h"
#include "ZTWorldMgr.h"
#include "ZTGuest.h"
#include "ZTTankWallType.h"
#include "ZTFoodType.h"
#include "ZTGameMgr.h"
#include "ZTAnimal.h"
#include "ZTFence.h"

EmuScriptMgr::EmuScriptMgr()
{
}

EmuScriptMgr::~EmuScriptMgr()
{
}

// Initialize the Emu API
void EmuScriptMgr::InitEmuAPI() 
{
	this->lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::io);
	ZTUI::general::ExportClassToLua(this->lua);
	BFEntity::ExportClassToLua(this->lua);
	BFEntityType::ExportClassToLua(this->lua);
	EmuConsole::ExportToLua(this->lua);
	ZTSceneryType::ExportClassToLua(this->lua);
	ZTWorldMgr::ExportClassToLua(this->lua);
	ZTGuest::ExportClassToLua(this->lua);
	ZTFenceType::ExportClassToLua(this->lua);
	ZTTankWallType::ExportClassToLua(this->lua);
	ZTFoodType::ExportClassToLua(this->lua);
	ZTGameMgr::ExportClassToLua(this->lua);
	ZTAnimal::ExportClassToLua(this->lua);
	EmuBase::ExportClassToLua(this->lua);
	ZTFence::ExportClassToLua(this->lua);
}

// Initialize global variables, tables, etc
void EmuScriptMgr::InitGlobalState()
{
	this->lua["emu"] = this->lua.create_table();
} 

// Load all the scripts from the scripts directory into memory
// name is the name of the function to be called in the script
void EmuScriptMgr::LoadScripts(std::string name)
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
		LoadScript(script, name);
	}
}

void EmuScriptMgr::LoadScript(const std::string& script, std::string name) {
	// Load the script into the Lua state
	lua.script(script);

	// Increment the function counter for naming
	++s_counter;

	// Rename 'run_fun' to a number
	std::string newFunctionName = std::to_string(s_counter);
	lua[newFunctionName] = lua[name];
	lua[name] = sol::nil; // Remove the original 'run_fun' to avoid conflicts
}

void EmuScriptMgr::ExecuteScripts() {
	for (int i = 1; i <= s_counter; ++i) {
		std::string functionName = std::to_string(i);
		sol::protected_function func = lua[functionName];
		if (func.valid()) {
			auto result = func();
			if (!result.valid()) {
				sol::error err = result;
				std::cerr << "Error executing function " << functionName << ": " << err.what() << std::endl;
			}
		}
	}
}

void EmuScriptMgr::ConvertToBytecode(const std::string& script)
{
	this->lua.open_libraries(sol::lib::base, sol::lib::package);
	sol::load_result result = this->lua.load_file(script);
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

// Transfer the state of one table to another lua state
void EmuScriptMgr::TransferTableState(sol::state& to, std::string name)
{
	// does table exist in the from table?
	sol::optional<sol::table> opt = this->lua[name];
	if (opt == sol::nullopt) {
		std::cout << "Table does not exist in the from table!" << std::endl;
		return;
	}

	// create a new table
	sol::table curr_table = opt.value();
	sol::table new_table = to.create_table(name);

	// iterate through the table and copy the contents to the new state
	curr_table.for_each([&new_table](const sol::object& key, const sol::object& value) {
		new_table[key] = value;
	});

	// set the new table to the global table
	to[name] = new_table;
}