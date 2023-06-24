#ifndef EMUCONSOLE_H
#define EMUCONSOLE_H

#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "EmuBase.h"

class EmuConsole : public EmuBase
{
public:
	EmuConsole(void);
	void processInput();
	~EmuConsole(void);
private:
	void tokenize();
	std::vector<std::string> tokens;
};

#endif