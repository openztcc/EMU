#include "ZTGameMgr.h"
#include <ostream>

ZTGameMgr::ZTGameMgr() {
    // constructor
    this->zoo_budget = 0.0;
    this->num_animals = 0;
    this->num_species = 0;
    this->guest_count = 0;

    // initialize detour function pointers

}

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

// void ZTGameMgr::addCash(float amount) {
//     // add cash to the game
//     this->zoo_budget += amount;
//     ZTUI::main::setMoneyText(); // update money text in the UI
// }

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

DWORD ZTGameMgr::getZTGameMgr() {
    // get the instance of ZTGameMgr
    DWORD _ztGameMgr = *(DWORD*)((LPVOID)0x00638048);
    return *(DWORD*)(_ztGameMgr);
}

// void __fastcall ZTGameMgr::addCash_Detour(void* ptr, float amount) {
//     // detour function for adding cash to the game
//     ZTGameMgr::shared_instance().addCash(amount);
// }


ZTGameMgr::~ZTGameMgr() {
    // destructor
    // clean up detour function pointers
}

// address: 0x0040e7e0. _FILETIME* return value likely incorrect.
// game has it as a long long, which would have been the same number of bytes as a FILETIME
_FILETIME* ZTGameMgr::getDate(_FILETIME* date) {
    SystemTimeToFileTime(&current_date, date);
    return date;
}

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
