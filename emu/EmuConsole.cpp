#include "EmuConsole.h"
#include <iomanip>
#include <sstream>
#include <iostream>
#include "stdio.h"
#include "SimpleIni.h"
#include "ZTUI.h"
#include "ZTSceneryType.h"
#include "ZTGameMgr.h"
#include "ZTAnimal.h"

//#include "ZTGameMgr.h"
//#include "BFGameApp.h"
//#include "EmuControls.h"
//#include "ZTMapView.h"
//#include "ZTGuest.h"
//#include "ZTBuildingType.h"
//#include "ZTUI.h"

EmuConsole::EmuConsole(std::vector<std::string>& tokes) : tokens(tokes)
{
}

EmuConsole::~EmuConsole(void)
{
}

// ---- Enables ANSI escape sequences for console
void EmuConsole::EnableVirtualTerminalProcessing() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) {
        return;
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) {
        return;
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

// ---- Writes to console
void EmuConsole::WriteToConsole(const std::string& utf8String) {
    std::string nlUtf8String = "\n" + utf8String + "\n>> ";
    int wchars_num = MultiByteToWideChar(CP_UTF8, 0, utf8String.c_str(), -1, NULL, 0);
    std::vector<wchar_t> wstr(wchars_num);
    MultiByteToWideChar(CP_UTF8, 0, utf8String.c_str(), -1, &wstr[0], wchars_num);
    WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), wstr.data(), wchars_num - 1, NULL, NULL);
}

// ---- Exports to Lua
void EmuConsole::ExportToLua(sol::state& lua) {
    lua_State* L = lua.lua_state();
    sol::state_view _lua(L);
    lua.new_usertype<EmuConsole>("emuConsole",
        "new", sol::no_constructor,
        "print", &EmuConsole::WriteToConsole
    );
}

HWND EmuConsole::createConsole()
{
    HWND consoleWindow; // contains console window handle

    FILE* file_s = nullptr;

    // ------ Create a console window
    AllocConsole();
    if (freopen_s(&file_s, "CONOUT$", "w", stdout) != 0)
    {
        perror("freopen_s");
    } else {
        setvbuf(stdout, NULL, _IONBF, 0);
    }
    if (freopen_s(&file_s, "CONIN$", "r", stdin) != 0)
    {
        perror("freopen_s");
    } else {
        setvbuf(stdin, NULL, _IONBF, 0);
    }

    // ------ Set the console window title and position
    consoleWindow = GetConsoleWindow();
    // EnableVirtualTerminalProcessing();
    SetConsoleTitle(TEXT("EMU Console")); // console title
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::locale::global(std::locale("en_US.UTF-8"));

    if (consoleWindow != NULL)
    {
        RECT mainWindowRect;
        HWND mainGameWindow = FindWindow(NULL, TEXT("Zoo Tycoon")); // find the main game window
        GetWindowRect(mainGameWindow, &mainWindowRect);

        // ------ Get screen dimensions
        int screenWidth = GetSystemMetrics(SM_CXSCREEN);
        int screenHeight = GetSystemMetrics(SM_CYSCREEN);
        int windowWidth = 400;
        int windowHeight = 200;

        // ------ Remove close, minimize and maximize buttons
        LONG lStyle = GetWindowLong(consoleWindow, GWL_STYLE);
        lStyle &= ~(WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU);
        SetWindowLong(consoleWindow, GWL_STYLE, lStyle);

        // ------ Remove from taskbar
        LONG lExStyle = GetWindowLong(consoleWindow, GWL_EXSTYLE);
        lExStyle = (lExStyle | WS_EX_TOOLWINDOW) & ~WS_EX_APPWINDOW;
        SetWindowLong(consoleWindow, GWL_EXSTYLE, lExStyle);

        // ------ Set the window position
        if (mainGameWindow != NULL)
        {
            // ------ Set the console window position
            RECT mainGameWindowRect;
            GetWindowRect(mainGameWindow, &mainGameWindowRect);
            int windowWidth = 400;
            int windowHeight = 200;

            // ------ Calculate new position
            int newWindowX = mainWindowRect.right - windowWidth;
            int newWindowY = mainWindowRect.top + 30;

            // SetWindowPos(consoleWindow, HWND_TOPMOST, mainGameWindowRect.left + 100, mainGameWindowRect.top + 100, windowWidth, windowHeight, SWP_SHOWWINDOW);
            SetWindowPos(consoleWindow, HWND_TOPMOST, newWindowX, newWindowY, windowWidth, windowHeight, SWP_SHOWWINDOW);
        }
    }

    WriteToConsole("Welcome to the EMU command console.\nAuthor: Eric \"Goosifer\" Galvan.\nSpecial thanks to: Finn, wowjinxy, Jay\n\nPlease enter your command below. Enter 'help' for a list of commands, or 'exit' to exit.\n\n");
    return consoleWindow;
}

/// <summary>
/// Tokenizes buffer stream
/// </summary>
void EmuConsole::tokenize(bool& CommandIsProcessing)
{
    std::string token = "";
    // TODO: fix try/catch. Crashes if error found.
    if (!std::getline(std::cin, token)) {
        return;
    }

    if (token.size() > 100)
    {
        // this limit will be increased, it's just a pre-emptive measure
        WriteToConsole("Err: Command too long.\n");
        CommandIsProcessing = false;
        // std::cin.ignore(32767, '\n');
    }
    else {
        std::istringstream iss(token);

        while (std::getline(iss, token, ' '))
        {
            tokens.push_back(token);
        }
    }


}

std::string EmuConsole::HelpDefinition(std::string command, std::string definition)
{
    std::string help = command + " - " + definition;
    return help;
}

/// <summary>
/// Delivers requested commands provided by user
/// </summary>
void EmuConsole::processInput(bool& IsConsoleRunning)
{
    // tokens.clear();

    // Process the input tokens

    // Check for a special command to exit the program
    if (tokens[0] == "exit")
    {
        IsConsoleRunning = false;
        return;
    }
    if (tokens[0] == "help")
    {
        std::cout << "==== Commands ====" << std::endl << std::endl;
        std::cout << HelpDefinition("exit", "Exits the console.") << std::endl;
        std::cout << HelpDefinition("help", "Displays this help menu.") << std::endl;

        std::cout << "";

    }
    else if (ZTGameMgr::isZooLoaded())
    {
        // ----- Test commands (devs only)
        // else if (tokens[0] == "pefound") {
        //     // ----- Test command to check if PE header is valid or found
        //     if (ZUtilities::FoundIAT() == 0)
        //     {
        //         std::cout << "PE header not found." << std::endl;
        //     }
        //     else if (ZUtilities::FoundIAT() == 2)
        //     {
        //         std::cout << "Optional header in PE Header not found." << std::endl;
        //     }
        //     else if (ZUtilities::FoundIAT() == 3)
        //     {
        //         std::cout << "Import Address Table in PE Header not found." << std::endl;
        //     }
        //     else
        //     {
        //         std::cout << "PE header found and valid." << std::endl;
        //     }

        // }
        if (tokens[0] == "addcash")
        {
            if (tokens.size() < 2)
            {
                std::cout << "Err: Command <" << tokens[0] << "> requires an amount." << std::endl;
                return;
            }
            // ----- Adds cash to the zoo budget
            ZTGameMgr::addCash(::atof(tokens[1].c_str()));
        }
        else if (tokens[0] == "setcash")
        {
            if (tokens.size() < 2)
            {
                std::cout << "Err: Command <" << tokens[0] << "> requires an amount." << std::endl;
                return;
            }
            // ----- Adds cash to the zoo budget
            ZTGameMgr::setCash(::atoi(tokens[1].c_str()));

        }
        else if (tokens[0] == "setzoorating")
        {
            if (tokens.size() < 2)
            {
                std::cout << "Err: Command <" << tokens[0] << "> requires a rating." << std::endl;
                return;
            }
            // sets the zoo rating
            // ZooState::SetZooRating(::atoi(tokens[1].c_str()));
        }
        else if (tokens[0] == "setguestrating")
        {
            if (tokens.size() < 2)
            {
                std::cout << "Err: Command <" << tokens[0] << "> requires a rating." << std::endl;
                return;
            }
            // sets the guest rating
            // ZooState::SetGuestRating(::atoi(tokens[1].c_str()));
        }
        else if (tokens[0] == "setanimalrating")
        {
            if (tokens.size() < 2)
            {
                std::cout << "Err: Command <" << tokens[0] << "> requires a rating." << std::endl;
                return;
            }
            // sets the animal rating
            // ZooState::SetAnimalRating(::atoi(tokens[1].c_str()));
        }
        else if (tokens[0] == "devmode")
        {
            if (tokens.size() < 2)
            {
                
                WriteToConsole("Err: Command <" + tokens[0] + "> requires a boolean.\n");
                return;
            }
            // enable dev mode
            if (tokens[1] == "true")
            {
                ZTGameMgr::enableDevMode(true);
            }
            else if (tokens[1] == "false")
            {
                ZTGameMgr::enableDevMode(false);
            }
            else
            {
                
                WriteToConsole("Err: Command <" + tokens[0] + "> requires a boolean.\n");
            }
        }
        else if (tokens[0] == "loadconfig")
        {
            void* entity = 0;
            if (tokens.size() < 2)
            {
                
                WriteToConsole("Err: Command <" + tokens[0] + "> requires a filename.\n");
                return;
            }
            if (tokens[1] == "-s")
            {
                entity = ZTUI::general::getSelectedEntity();
                if (entity == 0)
                {
                    
                    WriteToConsole("Err: No entity selected.\n");
                    return;
                }
            } else if (tokens[1] == "-id")
            {
                entity = ZTWorldMgr::getEntityTypeByID(::atoi(tokens[2].c_str()));
                if (entity == 0)
                {
                    
                    WriteToConsole("Err: Entity with ID <" + tokens[2] + "> not found.\n");
                    return;
                }
                ZTSceneryType sceneryType(entity);
                sceneryType.LoadConfiguration();
                WriteToConsole("Loading configuration file for entity with codename: " + sceneryType.codename() + "\n");
                WriteToConsole("Configuration file loaded.\n");

            }
            else
            {
                
                WriteToConsole("Err: Command <" + tokens[0] + "> requires a subcommand.\n");
                WriteToConsole("Usage: -s (selected entity), -id (entity by id)\n");
                return;
            }
        }
        else if (tokens[0] == "enttype")
        {
            if (tokens.size() < 2)
            {
                
                WriteToConsole("Err: Command <" + tokens[0] + "> requires a subcommand.\n");
                WriteToConsole("-id (entity by id)\n");
                return;
            }
            if (tokens[1] == "-id")
            {
                void* entity = ZTWorldMgr::getEntityTypeByID(::atoi(tokens[2].c_str()));
                if (entity == 0)
                {
                    
                    WriteToConsole("Err: Entity with ID <" + tokens[2] + "> not found.\n");
                    return;
                }
                std::string entitytype_str = EmuBase::ptrToHexStr(entity);
                WriteToConsole("Entity type: " +  entitytype_str + "\n");
            }
            else
            {
                
                WriteToConsole("Err: Command <" + tokens[0] + "> requires a subcommand.\n");
                WriteToConsole("-id (entity by id)\n");
                return;
            }
        }
        else if (tokens[0] == "selent")
        {
            void* entity = ZTUI::general::getSelectedEntity();
            
            if (entity == 0)
            {
                
                WriteToConsole("Err: No entity selected.\n");
                return;
            }
            std::string entity_str = EmuBase::ptrToHexStr(entity);
            WriteToConsole("Selected entity: " + entity_str + "\n");
            if (tokens.size() > 1 && tokens[1] == "-b")
            {
                void* entityType = ZTUI::general::getSelectedEntityType();
                std::string entityType_str = EmuBase::ptrToHexStr(entityType);
                WriteToConsole("Selected entity type: " + entityType_str + "\n");
            }
        }
        else if (tokens[0] == "date")
        {
            std::string date = ZTGameMgr::retStrDate();
            WriteToConsole("Current date: " + date + "\n");

        }
        else if (tokens[0] == "month")
        {
            int month = ZTGameMgr::getMonth();
            WriteToConsole("Current month: " + std::to_string(month) + "\n");
        }
        else if (tokens[0] == "day")
        {
            int day = ZTGameMgr::getDay();
            WriteToConsole("Current day: " + std::to_string(day) + "\n");
        }
        else if (tokens[0] == "makesel")
        {
            if (tokens.size() < 2)
            {
                
                WriteToConsole("Err: Command <" + tokens[0] + "> requires a subcommand.\n");
                WriteToConsole("-id (entity by id)\n");
                return;
            }
            ZTUI::general::makeSelectableByType(::atoi(tokens[1].c_str()));
        }
        else if (tokens[0] == "hatch")
        {
            void* entity = ZTUI::general::getSelectedEntity();
            if (entity == 0)
            {
                
                WriteToConsole("Err: No entity selected.\n");
                return;
            }
            ZTAnimal animal(entity);
            animal.hatchEgg();
        }
        else
        {
            
            WriteToConsole("Err: Command <" + tokens[0] + "> does not exist.\n");
        }
    }
    else
    {
        
        WriteToConsole("Err: Not able to execute command until zoo has been loaded.\n");
    }

    // tokens.clear();
    // std::cout << ">> ";
    // this->tokenize();
}