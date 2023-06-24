
#include "EmuConsole.h"


EmuConsole::EmuConsole(void)
{
}

EmuConsole::~EmuConsole(void)
{
}

/// <summary>
/// Tokenizes buffer stream
/// </summary>
void EmuConsole::tokenize()
{ 
    std::string token = "";
    std::getline(std::cin, token);

    if (token.size() > 100)
    {
		// this limit will be increased, it's just a pre-emptive measure
        std::cerr << "100 char limit in buffer. Please try again." << std::endl;
        throw;
    }

    std::istringstream iss(token);

    while (std::getline(iss, token, ' '))
    {
        tokens.push_back(token);
    }
}

/// <summary>
/// Delivers requested commands provided by user
/// </summary>
void EmuConsole::processInput()
{
    std::cout << ">> ";

    this->tokenize();
    // Process the input tokens
    while (!tokens.empty())
    {
        
		// Check for a special command to exit the program
		if (tokens[0] == "exit")
		{
            std::cout << "Closing console..." << std::endl;
            // close console
            FreeConsole();
			return;
		}
		
		else if (tokens[0] == "addtobudget")
		{
            // add to budget hook
            std::cout << "Budget has been updated. " << std::endl;
        }
		else if (tokens[0] == "numanimals")
		{
            // number of animals hook
			std::cout << "NumAnimals: 12 " << std::endl;
        }
        else
        {
            std::cout << "Err: No such command exists." << std::endl;
        }

        tokens.clear();
        std::cout << ">> ";
        this->tokenize();
    }
}