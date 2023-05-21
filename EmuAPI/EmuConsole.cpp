
#include "EmuConsole.h"
#include <cstring>
#include <iostream>
#include <sstream>

EmuConsole::EmuConsole(void)
{
}

EmuConsole::~EmuConsole(void)
{
}

std::string EmuConsole::tokenize(std::string a)
{
	
	return a;
}

void EmuConsole::processInput(Zoo::Process p, DWORD ptr, Memory<float> w)
{
	float* budget;
	budget = (float*)(ptr);

    std::string input;
	std::string argument;
	std::cin >> input >> argument;

    // Split the input into tokens based on space delimiter
    //std::istringstream iss(input);
    //std::vector<std::string> tokens;
    std::string token;
    /*while (iss >> token)
    {
        tokens.push_back(token);
    }*/

    // Process the input tokens
    if (!input.empty())
    {
        // The first token is the command
        std::string command = input;

        // The remaining tokens are arguments
        // std::vector<std::string> arguments(tokens.begin() + 1, tokens.end());
        
		// Check for a special command to exit the program
		if (command == "exit")
		{
			return;
		}
		
		if (command == "addToBudget")
		{
			float newbudget = std::atof(argument.c_str());
			// string -> float
			w.writeMemory((void*)ptr, (float)(*budget + newbudget)); // update budget
		}
    }

    
}