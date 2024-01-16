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
	EmuConsole();
	void processInput(bool&);
	~EmuConsole();
private:
	void tokenize();
	std::vector<std::string> tokens;
};

#endif