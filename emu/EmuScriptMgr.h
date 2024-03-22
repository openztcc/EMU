#ifndef EMUSCRIPTMGR_H
#define EMUSCRIPTMGR_H

#include <vector>
#include "sol/sol.hpp"
#include "sol/assert.hpp"
#define _WIN32_WINNT 0x0601
#include <cassert>

class EmuScriptMgr
{
public:
	EmuScriptMgr();
	~EmuScriptMgr();

	void LoadScripts();
	void LoadScript(const std::string& script);
	void ExecuteScripts();
	void ConvertToBytecode(const std::string& script);
	std::vector<std::string> FindAllFilePaths();
	std::vector<std::string> KeepScriptPathsWithExt(std::string);
	void PrintFoundScripts();
	void InitEmuAPI();
private:
	std::vector<std::string> s_scripts;
	std::vector<sol::bytecode> c_scripts;
	sol::state lua;
	int s_counter;
};

#endif // EMUSCRIPTMGR_H