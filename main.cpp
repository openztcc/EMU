#include <iostream>
#include "sol/sol.hpp"
#include "EmuScriptMgr.h"

class Test {
public: 
	void print() {
		std::cout << "Hello, World!" << std::endl;
	}

	void print2() {
		std::cout << "Hello, World! 2" << std::endl;
	}
};

int main() {
	std::cout << "=== Opening Lua state ===" << std::endl;
	sol::state lua;
	std::cout << "=== Lua state opened ===" << std::endl;
	lua.open_libraries(sol::lib::base, sol::lib::package);

	sol::usertype<Test> test_type = lua.new_usertype<Test>("Test",
				"print", &Test::print,
				"print2", &Test::print2
		);

	lua.set("test", Test());

	lua.script("newtest = Test.new()");
	lua.script("newtest:print()");
	lua.script("newtest:print2()");

	EmuScriptMgr emu;
	emu.LoadScripts();
	emu.PrintFoundScripts();
	emu.ExecuteScripts("emu_run");


	return 0;
}
