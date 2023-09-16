<h1 align="center">EMU | Extensible Modding Utility</h1>

<h3 align="center"> A Zoo Tycoon Complete Collection API Utility for Modders</h3>

Zoo Tycoon initially offered limited modding tools, leading modders to heavily depend on the game's INI configuration for modifications. This project aims to enhance modding accessibility by introducing embedded Lua scripting and expanded access to game resources that were previously unavailable.

### Compatibility

This API requires the Zoo Tycoon Complete Collection, including both expansions, and a Windows XP or newer operating system with the Microsoft Visual C++ 2008 Redistributable installed.

If you do not own the Complete Collection but own the base game and have the two expansions installed, that should work as well.

### Build from Source

The .sln file has been included for the option to build from source. This requires Microsoft Visual C++ 2008 in order to compile. Express Edition should be fine.

### Command Console

The API includes a command console not originally available in the vanilla game. It can be accessed via `CTRL + J`. It is currently not advisable to run any commands unless a zoo file has been loaded as it depends on the resources to have been allocated in memory.

Important limitations to consider as of **EMU v1.0.0-alpha.1**:
- The console is only visible in windowed mode and will not be accessible if you are full screen.
- Do not immediately exit the console by hitting 'X' on the window as this will close your game without prompt to save your zoo. First enter the `exit` command in order to detach the console thread from the game thread. This will now let you close the window safely and allow you to keep playing your game without issue.
- Safety checks are not yet implemented so be careful to stray too far from the expected input.

List of all available commands:

| Command  | Description |
| ------------- | ------------- |
| exit  | Safely close the console thread. |
| addtobudget <float deposit> | Deposit a discrete amount of cash into your zoo budget. |
| getbudget | Returns the current budget. |
| setbudget <float new_budget> | Set your current budget to a new amount. |
| pause | Pause your game from the console. |
| resume | Resume your game from the console. |
| num-animals | Return the current number of animals in your zoo. |
| num-species | Return the current number of animal species in your zoo. |
| num-guests | Return the current number of guests in your zoo. |
| num-tiredguests | Return the current number of tired guests in your zoo. |
| num-hungryguests | Return the current number of hungry guests in your zoo. |
| num-thirstyguests | Return the current number of thirsty guests in your zoo. |
| num-rstrmguests | Return the current number of guests that need to use the restroom. |
| getzooadmcost | Return the current admission cost to your zoo. Note: this is the adult ticket value. The child ticket value is not stored in memory as it is automatically calculated from the adult price divided by 2. |
| setzooadmcost <float new_adm> | Set the current admission cost to your zoo. See the above limitation about child ticket prices. |
| list-admissionsincome | Return a calendar listing of admissions income. |
| list-concessionsbenefit | Return a calendar listing of concessions benefits. |
| list-recyclingbenefit | Return a calendar listing of recycling benefits. |
| list-zooprofits | Return a calendar listing of zoo profits. |
| list-privatedonations | Return a calendar listing of private donations. |
| list-zoorating | Return a calendar listing of zoo ratings. |
| list-constructioncosts | Return a calendar listing with construction costs. |
| list-animalpurchasecosts | Return a calendar listing of animal purchase costs. |
