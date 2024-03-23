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

	void LoadScripts(std::string name);
	void LoadScript(const std::string& script, const std::string);
	void ExecuteScripts();
	void ConvertToBytecode(const std::string& script);
	std::vector<std::string> FindAllFilePaths();
	std::vector<std::string> KeepScriptPathsWithExt(std::string);
	void PrintFoundScripts();
	void InitEmuAPI();
	void InitGlobalState();
	void TransferTableState(sol::state& to, std::string name);\
	sol::state lua;
private:
	std::vector<std::string> s_scripts;
	std::vector<sol::bytecode> c_scripts;
	int s_counter;
	sol::table global_vars;
};

#endif // EMUSCRIPTMGR_H