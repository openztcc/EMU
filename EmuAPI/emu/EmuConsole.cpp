
#include "EmuConsole.h"
#include <iomanip>

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
    std::cout << "Welcome to the EMU command console. Please enter your command below.\n\n:::IMPORTANT::: Do not close this console window if you do not want to lose your zoo progress, this will effectively force quit the game. If you would like to exit the console safely, type in the 'exit' command and wait for the message. You can then close the command console." << std::endl << std::endl;
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
            ZooState::AddToZooBudget(static_cast<float>(::atof(tokens[1].c_str())));
        }
        else if (tokens[0] == "getbudget")
        {
            // return budget
            std::cout << std::fixed;  
            std::cout << "The current budget is: " << std::setprecision(2) << ZooState::GetZooBudget() << std::endl;
        }
        else if (tokens[0] == "setbudget")
        {
            // sets the budget
            ZooState::SetZooBudget(static_cast<float>(::atof(tokens[1].c_str())));
        }
		else if (tokens[0] == "pause")
		{
            // number of animals hook
			std::cout << "Pausing..." << std::endl;
            ZooState::PauseGame(true);
        }
        else if (tokens[0] == "resume")
		{
            // number of animals hook
			std::cout << "Resuming game..." << std::endl;
            ZooState::PauseGame(false);
        }
        else if (tokens[0] == "num-animals")
        {
            // return num of animals
            std::cout << "The current number of animals in the zoo: " << ZooState::NumAnimals() << std::endl;
        }
        else if (tokens[0] == "num-species")
        {
            // return num of animal species
            std::cout << "The current number of animal species in the zoo: " << ZooState::NumSpecies() << std::endl;
        }
        else if (tokens[0] == "num-guests")
        {
            // return num of guests
            std::cout << "The current number of guests in the zoo: " << ZooState::NumGuests() << std::endl;
        }
        else if (tokens[0] == "num-tiredguests")
        {
            // return num of tired guests
            std::cout << "The current number of tired guests in the zoo: " << ZooState::NumTiredGuests() << std::endl;
        }
        else if (tokens[0] == "num-hungryguests")
        {
            // return num of hungry guests
            std::cout << "The current number of hungry guests in the zoo: " << ZooState::NumHungryGuests() << std::endl;
        }
        else if (tokens[0] == "num-thirstyguests")
        {
            // return num of thirsty guests
            std::cout << "The current number of thirsty guests in the zoo: " << ZooState::NumThirstyGuests() << std::endl;
        }
        else if (tokens[0] == "num-rstrmguests")
        {
            // return num of guests that need to use the restroom
            std::cout << "The current number of guests that need restroom in the zoo: " << ZooState::NumGuestsNeedRestrm() << std::endl;
        }
        else if (tokens[0] == "num-guestsfilter")
        {
            // return num of guests in filter
            std::cout << "The current number of guests in the guest filter: " << ZooState::NumGuestsInFilter() << std::endl;
        }
        else if (tokens[0] == "getzooadmcost")
        {
            // return zoo admission cost
            std::cout << "Zoo admission cost: $" << ZooState::GetZooAdmissionCost() << std::endl;
        }
        else if (tokens[0] == "setzooadmcost")
        {
            // sets the admissions cost
            ZooState::SetZooAdmissionCost(static_cast<float>(::atof(tokens[1].c_str())));
        }

        else if (tokens[0] == "list-admissionsincome")
        {
            // return a full year list of admissions income by month
            ZooState::print_year_to_console(ZooState::AdmissionsIncomeByMonth(), "ADMISSIONS INCOME BY MONTH");
        }
        else if (tokens[0] == "list-concessionsbenefit")
        {
            // return a full year list of concessions benefits by month
            ZooState::print_year_to_console(ZooState::ConcessionsBenefitByMonth(), "CONCESSIONS BENEFIT BY MONTH");
        }
        // else if (tokens[0] == "list-recyclingbenefit")
        // {
        //     // return a full year list of recycling benefits by month
        //     ZooState::print_year_to_console(ZooState::RecyclingBenefitByMonth(), "RECYCLING BENEFIT BY MONTH");
        // }
        else if (tokens[0] == "list-zooprofits")
        {
            // return a full year list of zoo profits by month
            ZooState::print_year_to_console(ZooState::ZooProfitOverTime(), "ZOO PROFITS BY MONTH");
        }
        else if (tokens[0] == "list-privatedonations")
        {
            // return a full year list of private donations by month
            ZooState::print_year_to_console(ZooState::PrivateDonationsByMonth(), "PRIVATE DONATIONS BY MONTH");
        }
        else if (tokens[0] == "list-zoorating")
        {
            // return a full year list of zoo profits by month
            ZooState::print_year_to_console(ZooState::ZooRatingByMonth(), "ZOO RATING BY MONTH");
        }
        else if (tokens[0] == "list-constructioncosts")
        {
            // return a full year list of zoo profits by month
            ZooState::print_year_to_console(ZooState::ConstructionCostByMonth(), "CONSTRUCTION COSTS BY MONTH");
        }
        else if (tokens[0] == "list-animalpurchasecosts")
        {
            // return a full year list of animal purchase costs by month
            ZooState::print_year_to_console(ZooState::AnimalPurchaseCostsByMonth(), "ANIMAL PURCHASE COSTS BY MONTH");
        }
        else if (tokens[0] == "list-researchcosts")
        {
            // return a full year list of research costs by month
            ZooState::print_year_to_console(ZooState::ResearchCostsByMonth(), "RESEARCH COSTS BY MONTH");
        }
        else if (tokens[0] == "list-zoovalue")
        {
            // return a full year list of the zoo's value by month
            ZooState::print_year_to_console(ZooState::ZooValueByMonth(), "ZOO VALUE BY MONTH");
        }
        // else if (tokens[0] == "setmmcursor")
        // {
        //     if (tokens.size() > 2)
        //     {
        //         ZooMiniMap::SetMiniMapCursor(::atoi(tokens[1].c_str()), ::atoi(tokens[2].c_str()));
        //     }
        //     else if (tokens.size() == 2)
        //     {
        //         // set new mini map cursor size
        //         ZooMiniMap::SetMiniMapCursor(tokens[1]);
        //     }
            
        // }
        else
        {
            std::cout << "Err: No such command exists." << std::endl;
        }

        tokens.clear();
        std::cout << ">> ";
        this->tokenize();
    }
}