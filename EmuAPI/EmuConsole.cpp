
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
void EmuConsole::processInput(bool& IsConsoleRunning)
{
    ZooState state;
    std::cout << "Welcome to the EMU command console. Please enter your command below.\n\n:::IMPORTANT::: Do not close this console window if you do not want to lose your zoo progress, this will effectively force quit the game. If you would like to exit the game, type in the 'exit' command and wait for the message. You can then close the command console." << std::endl << std::endl;
    std::cout << ">> ";

    this->tokenize();
    // Process the input tokens
    while (!tokens.empty())
    {
        
		// Check for a special command to exit the program
		if (tokens[0] == "exit")
		{
            std::cout << "You may now safely close the console window." << std::endl;
            // close console
            FreeConsole();
            IsConsoleRunning = false;
			return;
		}
		
		else if (tokens[0] == "addtobudget")
		{
            // add to budget hook
            std::cout << "Budget has been updated. " << std::endl;
            state.AddToZooBudget(::atof(tokens[1].c_str()));
        }
        else if (tokens[0] == "getbudget")
        {
            // return budget
            std::cout << "The current budget is: " << state.GetZooBudget() << std::endl;
        }
		else if (tokens[0] == "pause")
		{
            // number of animals hook
			std::cout << "Pausing..." << std::endl;
            state.PauseGame(true);
        }
        else if (tokens[0] == "resume")
		{
            // number of animals hook
			std::cout << "Resuming game..." << std::endl;
            state.PauseGame(false);
        }
        else if (tokens[0] == "numanimals")
        {
            // return num of animals
            std::cout << "The current number of animals in the zoo: " << state.NumAnimals() << std::endl;
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