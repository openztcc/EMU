<h1 align="center">EMU | Extensible Modding Utility</h1>

<h3 align="center"> A Zoo Tycoon Complete Collection API Utility for Modders</h3>

Zoo Tycoon initially offered limited modding tools, leading modders to heavily depend on the game's INI configuration for modifications. This project aims to enhance modding accessibility by introducing embedded Lua scripting and expanded access to game resources that were previously unavailable.

### Compatibility

This API requires the Zoo Tycoon Complete Collection, including both expansions, and a Windows XP or newer operating system with the Microsoft Visual C++ 2008 Redistributable installed.

If you do not own the Complete Collection but own the base game and have the two expansions installed, that should work as well.

### Build from Source

The .sln file has been included for the option to build from source. This requires Microsoft Visual C++ 2008 in order to compile. Express Edition should be fine.

### Installation

Drop the res-EMU.dll binary directly into your `C:\Program Files (x86)\Microsoft Games\Zoo Tycoon` game directory.

### Command Console

The API includes a command console not originally available in the vanilla game. It can be accessed via `CTRL + J`. Commands will not run unless a zoo is loaded.

Console limitations to consider as of **EMU v1.0.0-alpha.5**:
- The console is only visible in windowed mode and will not be accessible if you are full screen.
- Safety checks are not yet implemented so be careful to stray too far from the expected input.
- Console stays ontop of the main game window (in windowed mode) and will stay ontop of other windows if game is minized. If it's obtrusive, close the console with `exit`.
- This API makes use of multi-threading to run EMU and the console simultaneously with the game. On slower hardware you might see propagation of resources take longer between what you see in the game and what you see in a function return value. For example: `num-tiredguests` might say 10, but the game says 11 for a few milliseconds longer.
- `list-privatedonations` has different values than what the game displays. The array is accurate down to the second that the month changes, but then the game adds an unknown value to the final recorded value on-screen. It is not known if this is a bug or if it is adding other donations like benefactor contributions. We keep it for analysis in the future.

#### Console Commands

| Command  | Description |
| ------------- | ------------- |
| exit  | Safely close the console window. |
| addtobudget \<float deposit\> | Deposit a discrete amount of cash into your zoo budget. |
| getbudget | Returns the current budget. |
| setbudget \<float new_budget\> | Set your current budget to a new amount. |
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
| setzooadmcost \<float new_adm\> | Set the current admission cost to your zoo. See the above limitation about child ticket prices. |
| list-admissionsincome | Return a calendar listing of admissions income. |
| list-concessionsbenefit | Return a calendar listing of concessions benefits. |
| list-zoovalue | Return a calendar listing of zoo value changes over the year. |
| list-privatedonations | Return a calendar listing of private donations. |
| list-zoorating | Return a calendar listing of zoo ratings. |
| list-constructioncosts | Return a calendar listing with construction costs. |
| list-animalpurchasecosts | Return a calendar listing of animal adoption costs. |

### Lua Scripting

Introduced as of **EMU v1.0.0-alpha.3**.

EMU adds scripting support to Zoo Tycoon 1. Currently scripting is limited to the following commands:

| Command  | Description |
| ------------- | ------------- |
| AddToZooBudget(float deposit) | Deposit a discrete amount of cash into your zoo budget. Takes a float as an argument. |
| GetZooBudget() | Returns the current budget as a float. |
| SetZooBudget(float new_budget) | Set your current budget to a new amount. Takes a float as an argument. |
| IsZooLoaded() | Is a zoo currently open? Returns a boolean value. |
| PauseGame() | Pause the game. |
| IsGamePaused() | Is the game currently paused? Returns a boolean value. |
| NumAnimals() | Return the current number of animals in your zoo. Returns an integer. |
| NumSpecies() | Return the current number of animal species in your zoo. Returns an integer. |
| NumGuests() | Return the current number of guests in your zoo. Returns an integer. |
| NumTiredGuests() | Return the current number of tired guests in your zoo. Returns an integer. |
| NumHungryGuests() | Return the current number of hungry guests in your zoo. Returns an integer. |
| NumThirstyGuests() | Return the current number of thirsty guests in your zoo. Returns an integer. |
| NumGuestsNeedRestrm() | Return the current number of guests that need to use the restroom. Returns an integer. |
| NumGuestsInFilter() | Return the current number of guests in the guest filter. Returns an integer. |
| GetZooAdmissionCost() | Return the current admission cost to your zoo. Note: this is the adult ticket value. The child ticket value is not stored in memory as it is automatically calculated from the adult price divided by 2. Returns a float. |
| SetZooAdmissionCost(float new_adm) | Set the current admission cost to your zoo. See the above limitation about child ticket prices. Takes one float as an argument. |
| AdmissionsIncomeByMonth() | Retrieve an array containing 12 elements, each representing admissions income for a specific month. |
| ConcessionsBenefitByMonth() | Retrieve an array containing 12 elements, each representing the concessions benefit for a specific month. |
| ZooValueByMonth() | Retrieve an array containing 12 elements, each representing the zoo value for a specific month. |
| PrivateDonationsByMonth() | Retrieve an array containing 12 elements, each representing the private donations for a specific month. |
| ZooRatingByMonth() | Retrieve an array containing 12 elements, each representing the zoo rating for a specific month. |
| ConstructionCostByMonth() | Retrieve an array containing 12 elements, each representing the construction costs for a specific month. |
| AnimalPurchaseCostsByMonth() | Retrieve an array containing 12 elements, each representing the animal adoption costs for a specific month. |

Scripting info:
- All Lua standard libraries as of Lua 5.3 are made available for your use.
- Lua scripts must have the `.emu` extension.
- As of the latest **EMU v1.0.0-alpha.4**, EMU can load any lua scripts inside of a `/scripts` folder inside of the root Zoo Tycoon 1 folder.
- Lua support is designed for modders to take control of the game logic by having individual scripts run on the main EMU loop. If/then statements are obviously encouraged, but be conservative with your own loops unless they are predictable and efficient. Global variables might not be effective.
- All executing code must live inside of an `emu_run` function.

**Example Lua Script:**
_playground.emu_
```Lua
function emu_run()
    -- pause the game if the budget goes above $400,000
    if GetZooBudget() > 400000 and IsGamePaused() == false then
        io.write("Pausing the game")
        PauseGame(true)
    -- resume game if budget dips below $400,000 (maybe the console can save us here?)
    elseif GetZooBudget() <= 400000 and IsGamePaused() == true then
        io.write("Resuming the game")
        PauseGame(false)
    end
end
```
