
#include "EmuConsole.h"


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

void EmuConsole::processInput(Zoo::Process p, Memory<float> w)
{
	float* budget;
	Memory<DWORD> r;
	DWORD oldProtection = r.protectMemory((LPVOID)(*(DWORD*)((LPVOID)(0x00638048))), PAGE_EXECUTE_READWRITE);
	DWORD ptr = *(DWORD*)((LPVOID)(0x00638048)) + 0x0C; // grab address to budget
	budget = (float*)(ptr);
	Memory<DWORD> m;

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
			float* b = w.pointMemory((LPVOID)ptr);


			// string -> float
			*b = *budget + newbudget; // update budget
			r.protectMemory((LPVOID)(ptr), oldProtection);

		}
    }

    
}