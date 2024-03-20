#include "ZTGameMgr.h"
#include <ostream>

void* ZTGameMgr::instance() {
    return (void*)0x00638048;
}

DWORD ZTGameMgr::instance(DWORD offset) {
    return (*((DWORD*)((LPVOID)0x00638048)) + offset);
}

// ZTGameMgr::ZTGameMgr() {
//     // constructor
//     this->zoo_budget = 0.0;
//     this->num_animals = 0;
//     this->num_species = 0;
//     this->guest_count = 0;
// }

void ZTGameMgr::init() {
    // initialize instance of ZTGameMgr
    // initialize detour function pointers
    DWORD addCashAddress = 0x40f018; // address of addCash function in the game
    DWORD getDateAddress = 0x0040e7e0; // address of getDate function in the game
    DWORD getStartMenuMusicAddress = 0x004bded9; // address of startMenuMusic function in the game
    DWORD setAnimalRatingAddress = 0x0041D08B;
	DWORD setZooRatingAddress = 0x0041D22F;
	DWORD setGuestRatingAddress = 0x0041D15D;
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    // DetourAttach((PVOID*)&addCashAddress, (PVOID)&ZTGameMgr::addCash_Detour);
        //------ Detour update function to run emu and sync with main game thread
    // DetourAttach((PVOID*)&setAnimalRatingAddress, (PVOID)&SetAnimalRating);
    // DetourAttach((PVOID*)&setZooRatingAddress, (PVOID)&SetZooRating);
    // DetourAttach((PVOID*)&setGuestRatingAddress, (PVOID)&SetGuestRating);
    DetourTransactionCommit();
}

void ZTGameMgr::addCash(float amount) {
    // add cash to the game
    // this->zoo_budget += amount;
    // ZTUI::main::setMoneyText(); // update money text in the UI
    _addCash _ogaddCash = (_addCash)0x0040f018;
    _ogaddCash(ZTGameMgr::instance(), amount);
}

void ZTGameMgr::setCash(int amount) {
    // set cash in the game
    // this->zoo_budget = amount;
    // ZTUI::main::setMoneyText(); // update money text in the UI
    float new_amount = (float)amount - ZTGameMgr::getCash();
    ZTGameMgr::addCash(new_amount);
}

float ZTGameMgr::getCash() {
    // get cash from the game
    // return this->zoo_budget;
    float* p = ((float*)instance(0x0C));
    return *p;
}

void ZTGameMgr::subtractCash(float amount) {
    // subtract cash from the game
    // this->zoo_budget -= amount;
    // ZTUI::main::setMoneyText(); // update money text in the UI
    ZTGameMgr::addCash(-amount);
}

// void ZTGameMgr::subtractCash(float amount) {
//     // subtract cash from the game
//     this->zoo_budget -= amount;
//     ZTUI::main::setMoneyText(); // update money text in the UI
// }

// void ZTGameMgr::startMenuMusic() {
//     // start the menu music
//     _startMenuMusic _ogstartMenuMusic = (_startMenuMusic)0x004bded9;
//     _ogstartMenuMusic(pZTGameMgr);
// }

// ZTGameMgr::~ZTGameMgr() {
//     // destructor
//     // clean up detour function pointers
// }

// // address: 0x0040e7e0. _FILETIME* return value likely incorrect.
// // game has it as a long long, which would have been the same number of bytes as a FILETIME
// _FILETIME* ZTGameMgr::getDate(_FILETIME* date) {
//     SystemTimeToFileTime(&current_date, date);
//     return date;
// }

typedef void (__cdecl *_setAnimalRating)(int); // define original setAnimalRating function
typedef void (__cdecl *_setZooRating)(int); // define original setZooRating function
typedef void (__cdecl *_setGuestRating)(int); // define original setGuestRating function


// void __cdecl SetGuestRating(int rating) {
// 	_setGuestRating ogSetGuestRating = (_setGuestRating)0x0041D15D;
// 	if (zoo_models->_emuGuestRatingSet == true) {
// 		rating = zoo_models->_guestRating;
// 	}
// 	ogSetGuestRating(rating);
// }

// void __cdecl SetZooRating(int rating) {
// 	_setZooRating ogSetZooRating = (_setZooRating)0x0041D22F;
// 	if (zoo_models->_emuZooRatingSet == true) {
// 		rating = zoo_models->_zooRating;
// 	}
// 	ogSetZooRating(rating);
// }

// void __cdecl SetAnimalRating(int rating) {
// 	_setAnimalRating ogSetAnimalRating = (_setAnimalRating)0x0041D08B;
// 	if (zoo_models->_emuAnimalRatingSet == true) {
//     	rating = zoo_models->_animalRating;
// 	}
// 	ogSetAnimalRating(rating);
// }

/// @brief Pause the game.
/// @param input 
void ZTGameMgr::pauseGame(bool input)
{
    DWORD ptr = (((DWORD)((LPVOID)0x638588)));
    bool* p = (bool*)ptr;
    *p = input;
}

/// @brief Is the game paused through the UI?
bool ZTGameMgr::isGamePaused()
{
    DWORD ptr = (((DWORD)((LPVOID)0x638588)));
    bool* p = (bool*)ptr;
    return *p;
}

/// @brief Overload: allows a user to set
/// @param input 
void ZTGameMgr::freezeGameState(bool is_loaded)
{
    bool* p = ((bool*)instance(0x4));
    *p = is_loaded;
}


/// @brief Is a zoo loaded currently loaded
/// @param input 
bool ZTGameMgr::isZooLoaded()
{
    bool* p = ((bool*)instance(0x4));
    return *p;
}

// /// @brief Add money to the zoo budget.
// /// @param input 
// void ZTGameMgr::AddToZooBudget(float input)
// {
//     float* budget = (float*)instance(0x0C);
//     *budget = (float)(*budget + input);
// }

// /// @brief Returns the zoo budget.
// /// @return 
// float ZTGameMgr::GetZooBudget()
// {
//     float* budget = (float*)instance(0x0C);
//     return *budget;
// }

// /// @brief Sets the zoo budget.
// /// @return 
// void ZTGameMgr::SetZooBudget(float new_budget)
// {
//     float* budget = (float*)instance(0x0C);
//     *budget = new_budget;
// }

/// @brief Returns number of animals in zoo.
/// @return 
int ZTGameMgr::numAnimals()
{
    int* p = ((int*)instance(0x30));
    return *p;
}

/// @brief Returns number of animal species in zoo.
/// @return 
int ZTGameMgr::numSpecies()
{
    int* p = ((int*)instance(0x38));
    return *p;
}

/// @brief Returns number of guests in the zoo.
/// @return 
int ZTGameMgr::numGuests()
{
    int* p = ((int*)instance(0x54));
    return *p;
}

/// @brief Returns the number of tired guests.
/// @return 
int ZTGameMgr::numTiredGuests()
{
    int* p = ((int*)instance(0x3C));
    return *p;
}

/// @brief Returns the number of hungry guests.
/// @return 
int ZTGameMgr::numHungryGuests()
{
    int* p = ((int*)instance(0x40));
    return *p;
}

/// @brief Returns the number of thirsty guests.
/// @return 
int ZTGameMgr::numThirstyGuests()
{
    int* p = ((int*)instance(0x44));
    return *p;
}

/// @brief Returns the number of guests that need the restroom.
/// @return 
int ZTGameMgr::numGuestsNeedRestrm()
{
    int* p = ((int*)instance(0x48));
    return *p;
}

int ZTGameMgr::numGuestsInFilter()
{
    int* p = ((int*)instance(0x54));
    return *p;
}

float ZTGameMgr::getZooAdmissionCost()
{
    float* p = ((float*)instance(0x1160));
    return *p;
}

void ZTGameMgr::setZooAdmissionCost(float new_cost)
{
    float* p = ((float*)instance(0x1160));
    *p = new_cost;
}

/// LISTS

/// @brief Returns admissions income by month as a 12-member array.
/// @return 
float* ZTGameMgr::admissionsIncomeByMonth()
{
    float* p = ((float*)instance(0x254));
    return p;
}

float* ZTGameMgr::concessionsBenefitByMonth()
{
    float* p = ((float*)instance(0x284));
    return p;
}

// Offset is incorrect
// float* ZTGameMgr::RecyclingBenefitByMonth()
// {
//     float* p = ((float*)instance(0x314));
//     return p;
// }

float* ZTGameMgr::zooProfitOverTime()
{
    float* p = ((float*)instance(0x404));
    return p;
}

float* ZTGameMgr::privateDonationsByMonth()
{
    float* p = ((float*)instance(0x2E4));
    return p;
}

float* ZTGameMgr::zooRatingByMonth()
{
    float* p = ((float*)instance(0x464));
    return p;
}

float* ZTGameMgr::constructionCostByMonth()
{
    float* p = ((float*)instance(0x1F4));
    return p;
}

float* ZTGameMgr::animalPurchaseCostsByMonth()
{
    float* p = ((float*)instance(0x1C4));
    return p;
}

// needs another look
float* ZTGameMgr::researchCostsByMonth()
{
    float* p = ((float*)instance(0xD10));
    return p;
}

float* ZTGameMgr::zooValueByMonth()
{
    float* p = ((float*)instance(0x434));
    return p;
}

void ZTGameMgr::enableDevMode(bool input)
{
    DWORD ptr = (((DWORD)((LPVOID)0x63858A)));
    bool* p = (bool*)ptr;
    *p = input;
}

bool ZTGameMgr::isDevModeEnabled()
{
    DWORD ptr = (((DWORD)((LPVOID)0x63858A)));
    bool* p = (bool*)ptr;
    return *p;
}

void ZTGameMgr::ExportClassToLua(sol::state_view& lua)
{
    lua.new_usertype<ZTGameMgr>("ztGameMgr",
        "new", sol::no_constructor,
        "addCash", &ZTGameMgr::addCash,
        "setCash", &ZTGameMgr::setCash,
        "getCash", &ZTGameMgr::getCash,
        "subtractCash", &ZTGameMgr::subtractCash,
        "pauseGame", &ZTGameMgr::pauseGame,
        "isGamePaused", &ZTGameMgr::isGamePaused,
        "freezeGameState", &ZTGameMgr::freezeGameState,
        "isZooLoaded", &ZTGameMgr::isZooLoaded,
        "numAnimals", &ZTGameMgr::numAnimals,
        "numSpecies", &ZTGameMgr::numSpecies,
        "numGuests", &ZTGameMgr::numGuests,
        "admissionsIncomeByMonth", &ZTGameMgr::admissionsIncomeByMonth,
        "concessionsBenefitByMonth", &ZTGameMgr::concessionsBenefitByMonth,
        "zooProfitOverTime", &ZTGameMgr::zooProfitOverTime,
        "privateDonationsByMonth", &ZTGameMgr::privateDonationsByMonth,
        "zooRatingByMonth", &ZTGameMgr::zooRatingByMonth,
        "constructionCostByMonth", &ZTGameMgr::constructionCostByMonth,
        "animalPurchaseCostsByMonth", &ZTGameMgr::animalPurchaseCostsByMonth,
        "researchCostsByMonth", &ZTGameMgr::researchCostsByMonth,
        "zooValueByMonth", &ZTGameMgr::zooValueByMonth,
        "enableDevMode", &ZTGameMgr::enableDevMode,
        "isDevModeEnabled", &ZTGameMgr::isDevModeEnabled
    );
}