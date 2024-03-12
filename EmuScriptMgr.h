#ifndef EMUSCRIPTMGR_H
#define EMUSCRIPTMGR_H

#include <vector>
#include "sol/sol.hpp"
#include "sol/assert.hpp"
#include <cassert>

class EmuScriptMgr
{
public:
	EmuScriptMgr();
	~EmuScriptMgr();

	void LoadScript(const std::string& script);
	void ConvertToBytecode(const std::string& script);
private:
	std::vector<sol::bytecode> c_scripts;
};

#endif // EMUSCRIPTMGR_H