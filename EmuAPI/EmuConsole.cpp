
#include "EmuConsole.h"


EmuConsole::EmuConsole(void)
{
}

EmuConsole::~EmuConsole(void)
{
}

void EmuConsole::tokenize()
{
    
    std::string token = "";
    std::getline(std::cin, token);

    if (token.size() > 100)
    {
        std::cerr << "100 char limit in buffer. Please try again." << std::endl;
        throw;
    }

    std::istringstream iss(token);

    while (std::getline(iss, token, ' '))
    {
        tokens.push_back(token);
    }
}

void EmuConsole::processInput(Zoo::Process &p, Memory<float> w)
{
	float* flt_ctr;
	Memory<DWORD> r;
	DWORD oldProtection = r.protectMemory((LPVOID)(*(DWORD*)((LPVOID)(0x00638048))), PAGE_EXECUTE_READWRITE);
	DWORD ptr;
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
			FreeConsole();
			return;
		}
		
		if (command == "addToBudget")
		{
			float newbudget = std::atof(argument.c_str());
			float* b = w.pointMemory((LPVOID)ptr);
			flt_ctr = (float*)(ptr);
			ptr = *(DWORD*)((LPVOID)(0x00638048)) + 0x0C; // grab address to budget

			// string -> float
			*b = *flt_ctr + newbudget; // update budget
		}
		else if (command == "numanimals")
		{
			ptr = r.readMemory((void*)(0x00638048)) + 0x30; // grab address to numanimals
			int* numanimals = (int*)(ptr);
		
			std::cout << ">> " << numanimals << std::endl;
		}
    }

    
}