#ifndef EMUCONSOLE_H
#define EMUCONSOLE_H

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "ZooState.h"
#include "ZooMiniMap.h"
#include <windows.h>
#include "ZTUI.h"
#include "ZTMapView.h"

class EmuConsole
{
public:
	EmuConsole(std::vector<std::string>&);
	void processInput(bool&);
	~EmuConsole();
	void tokenize(bool&);
	static HWND createConsole();
	static DWORD WINAPI ZooConsole(LPVOID, bool&, bool&, bool&); 
private:
	std::vector<std::string>& tokens;
	static void EnableVirtualTerminalProcessing();
	std::string HelpDefinition(std::string, std::string);
};

#endif