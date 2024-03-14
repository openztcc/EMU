#ifndef EMUCONSOLE_H
#define EMUCONSOLE_H

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

#include <windows.h>
#include <vector>
#include <string>

class EmuConsole
{
public:
	EmuConsole(std::vector<std::string>&);
	void processInput(bool&);
	~EmuConsole();
	void tokenize(bool&);
	static HWND createConsole();
private:
	std::vector<std::string>& tokens;
	std::string HelpDefinition(std::string, std::string);
};

#endif