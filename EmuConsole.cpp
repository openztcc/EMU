#include "EmuConsole.h"
#include <iomanip>
#include <sstream>
#include <iostream>

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

HWND EmuConsole::createConsole()
{
    HWND consoleWindow; // contains console window handle

    FILE* file_s;

    // ------ Create a console window
    AllocConsole();
    if (freopen_s(&file_s, "CONOUT$", "w", stdout) != 0)
    {
        perror("freeopen_s");
    }
    if (freopen_s(&file_s, "CONIN$", "r", stdin) != 0)
    {
        perror("freeopen_s");
    }

    // ------ Set the console window title and position
    consoleWindow = GetConsoleWindow();
    SetConsoleTitle(TEXT("EMU Console")); // console title

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

    std::cout << "Welcome to the EMU command console.\nAuthor: Eric \"Goosifer\" Galvan.\nSpecial thanks to: Finn, wowjinxy, Jay\n\nPlease enter your command below. Enter 'help' for a list of commands, or 'exit' to exit." << std::endl << std::endl;
    std::cout << ""; // reset color
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
        std::cout << "Err: Command too long." << std::endl;
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
    }
    //else if (ZooState::IsZooLoaded())
    //{
    //}
    else
    {
        std::cout << "Err: Not able to execute command until zoo has been loaded." << std::endl;
    }
}