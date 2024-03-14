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

	sol::state LoadScripts();
	void ExecuteScripts(std::string);
	void ConvertToBytecode(const std::string& script);
	std::vector<std::string> FindAllFilePaths();
	std::vector<std::string> KeepScriptPathsWithExt(std::string);
	void PrintFoundScripts();
private:
	std::vector<std::string> s_scripts;
	std::vector<sol::bytecode> c_scripts;
};

#endif // EMUSCRIPTMGR_H