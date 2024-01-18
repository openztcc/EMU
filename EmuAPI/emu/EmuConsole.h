#ifndef EMUCONSOLE_H
#define EMUCONSOLE_H

#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "ZooState.h"
#include "ZooMiniMap.h"

class EmuConsole
{
public:
	EmuConsole(std::vector<std::string>&);
	void processInput(bool&);
	~EmuConsole();
	void tokenize();
	static HWND& createConsole();
private:
	std::vector<std::string>& tokens;
};

#endif