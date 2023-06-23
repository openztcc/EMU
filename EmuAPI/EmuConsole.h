#ifndef EMUCONSOLE_H
#define EMUCONSOLE_H

#include <cstring>
#include <iostream>
#include <sstream>

#include "TekUtilities.h"
#include "TekMemory.h"
#include <string>
#include <vector>

class EmuConsole
{
public:
	EmuConsole(void);
	void tokenize();

	std::vector<std::string> tokens;
	void processInput(Zoo::Process &p, Memory<float> w);
	~EmuConsole(void);
};

#endif