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
    DetourAttach((PVOID*)&addCashAddress, (PVOID)&ZTGameMgr::addCash_Detour);
        //------ Detour update function to run emu and sync with main game thread
    DetourAttach((PVOID*)&setAnimalRatingAddress, (PVOID)&SetAnimalRating);
    DetourAttach((PVOID*)&setZooRatingAddress, (PVOID)&SetZooRating);
    DetourAttach((PVOID*)&setGuestRatingAddress, (PVOID)&SetGuestRating);
    DetourTransactionCommit();
    // DWORD _ztGameMgr = *(DWORD*)((LPVOID)0x00638048);
    // ZTGameMgr::shared_instance() = *(ZTGameMgr*)(_ztGameMgr);

    EmuBase::callHook(0x0050A245, (DWORD)&ZTGameMgr::addCash_Detour); // from removeEntityFromMap
    EmuBase::callHook(0x00613f61, (DWORD)&ZTGameMgr::addCash_Detour); // from ZooStatus::fGrantDonation
    EmuBase::callHook(0x0060d9d3, (DWORD)&ZTGameMgr::addCash_Detour); // from unknown fn at 0060d8e3
    EmuBase::callHook(0x0060cccd, (DWORD)&ZTGameMgr::addCash_Detour); // from unknown fn at 433ae0
    EmuBase::callHook(0x00613f61, (DWORD)&ZTGameMgr::addCash_Detour); // from unknown fn at 433b00
    EmuBase::callHook(0x006089fc, (DWORD)&ZTGameMgr::addCash_Detour); // from unknown fn at cls_0x40f018::meth_0x6089e8
    EmuBase::callHook(0x00607299, (DWORD)&ZTGameMgr::addCash_Detour); // from georgeW
    EmuBase::callHook(0x0060d9d3, (DWORD)&ZTGameMgr::addCash_Detour); // from unknown fn at 0060d8e3
    EmuBase::callHook(0x005b0f2d, (DWORD)&ZTGameMgr::addCash_Detour); // from unknown fn at 005b0f17
    EmuBase::callHook(0x005a1679, (DWORD)&ZTGameMgr::addCash_Detour); // from ZTScenarioSimpleGoal::trigger03
    EmuBase::callHook(0x004f7031, (DWORD)&ZTGameMgr::addCash_Detour); // from unknown fn at cls_0x41f881::meth_0x4f6e3c
    EmuBase::callHook(0x004d920f , (DWORD)&ZTGameMgr::addCash_Detour); // from ZTMapView::placeEntityOnMap
    EmuBase::callHook(0x004a2f97, (DWORD)&ZTGameMgr::addCash_Detour); // from ZTGameMgr::removedZooDoo
    EmuBase::callHook(0x00484047, (DWORD)&ZTGameMgr::addCash_Detour); // from ZooStatus::financeChecks
    EmuBase::callHook(0x0042ec81, (DWORD)&ZTGameMgr::addCash_Detour); // from ZTHabitat::acceptDonation
    EmuBase::callHook(0x0042d93f, (DWORD)&ZTGameMgr::addCash_Detour); // from ZTBuilding::removeUser
    EmuBase::callHook(0x005a981c, (DWORD)&ZTGameMgr::addCash_Detour); // from ZTBuilding::addUser

    EmuBase::callHook(0x004cb64f, (DWORD)&ZTGameMgr::setCash_Detour); // from showMapSelect
    EmuBase::callHook(0x006163ab, (DWORD)&ZTGameMgr::setCash_Detour); // from clickCashUp
    EmuBase::callHook(0x0061640d, (DWORD)&ZTGameMgr::setCash_Detour); // from clickCashDown
    EmuBase::callHook(0x006165ce, (DWORD)&ZTGameMgr::setCash_Detour); // from editStartingCash



    // EmuBase::callHook(0x0041f284, (DWORD)&ZTGameMgr::subtractCash_Detour); // from ZTResearchBranch::update <--- crashes, not sure why
    // EmuBase::callHook(0x0041f304, (DWORD)&ZTGameMgr::subtractCash_Detour); // from unknown fn at 0041f304 <--- crashes, not sure why
    // // EmuBase::callHook(0x00469281, (DWORD)&ZTGameMgr::subtractCash_Detour); // from unknown fn at 00469281
    // // EmuBase::callHook(0x0046944c, (DWORD)&ZTGameMgr::subtractCash_Detour); // from unknown fn at 0046944c
    // // EmuBase::callHook(0x004702e3, (DWORD)&ZTGameMgr::subtractCash_Detour); // from unknown fn at 004702e3
    // // EmuBase::callHook(0x0047c043, (DWORD)&ZTGameMgr::subtractCash_Detour); // from unknown fn at 0047c043
    // // EmuBase::callHook(0x004841a3, (DWORD)&ZTGameMgr::subtractCash_Detour); // from financeChecks
    // // EmuBase::callHook(0x00484230, (DWORD)&ZTGameMgr::subtractCash_Detour); // from financeChecks
    // // EmuBase::callHook(0x00488e9d, (DWORD)&ZTGameMgr::subtractCash_Detour); // from fn at virt_meth_0x4da252:00488e9d
    // // EmuBase::callHook(0x0048a021, (DWORD)&ZTGameMgr::subtractCash_Detour); // from virt_meth_0x489fcd
    // // EmuBase::callHook(0x0048f76c, (DWORD)&ZTGameMgr::subtractCash_Detour); // from virt_meth_0x48f624
    // // EmuBase::callHook(0x0049befe, (DWORD)&ZTGameMgr::subtractCash_Detour); // from meth_0x49bec7
    // // EmuBase::callHook(0x004a099a, (DWORD)&ZTGameMgr::subtractCash_Detour); // from removeEntityFromMap
    // // EmuBase::callHook(0x004d8eda, (DWORD)&ZTGameMgr::subtractCash_Detour); // from placeEntityOnMap
    // // EmuBase::callHook(0x004deb1b, (DWORD)&ZTGameMgr::subtractCash_Detour); // from FUN_005b6710
    // // EmuBase::callHook(0x004efd66, (DWORD)&ZTGameMgr::subtractCash_Detour); // from removeEntityFromMap
    // // EmuBase::callHook(0x005ce004, (DWORD)&ZTGameMgr::subtractCash_Detour); // from removeEntityFromMap
    // // EmuBase::callHook(0x005ce042, (DWORD)&ZTGameMgr::subtractCash_Detour); // from removeEntityFromMap
    // // EmuBase::callHook(0x005ce068, (DWORD)&ZTGameMgr::subtractCash_Detour); // from removeEntityFromMap
    // // EmuBase::callHook(0x00611666, (DWORD)&ZTGameMgr::subtractCash_Detour); // from FUN_006115f2


}

void ZTGameMgr::addCash(float amount) {
    // add cash to the game
    this->zoo_budget += amount;
    ZTUI::main::setMoneyText(); // update money text in the UI
}

void ZTGameMgr::subtractCash(float amount) {
    // subtract cash from the game
    this->zoo_budget -= amount;
    ZTUI::main::setMoneyText(); // update money text in the UI
}

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

_FILETIME* ZTGameMgr::getDate_Detour(void* ptr, _FILETIME* date) {
    // detour function for getting the current date from the game
    return ZTGameMgr::shared_instance().getDate(date);
}

void ZTGameMgr::subtractCash_Detour(void* ptr, float amount) {
    // detour function for subtracting cash from the game
    ZTGameMgr::shared_instance().subtractCash(amount);
}

void ZTGameMgr::setCash_Detour(int amount) {
    // detour function for setting cash in the game
    // Log the amount of cash being set
    std::ofstream logfile("cash.txt", std::ios::app);
    if (logfile.is_open()) {
        logfile << "Setting cash to: " << amount << std::endl;
        logfile.close();
    }

    ZTGameMgr::shared_instance().setCash(amount);
}

void ZTGameMgr::setCash(int amount) {
    _setCash _ogsetCash = (_setCash)0x004cb384;
    _ogsetCash(amount);
}

void __fastcall ZTGameMgr::addCash_Detour(void* ptr, float amount) {
    // detour function for adding cash to the game
    ZTGameMgr::shared_instance().addCash(amount);
}


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


void __cdecl SetGuestRating(int rating) {
	_setGuestRating ogSetGuestRating = (_setGuestRating)0x0041D15D;
	if (zoo_models->_emuGuestRatingSet == true) {
		rating = zoo_models->_guestRating;
	}
	ogSetGuestRating(rating);
}

void __cdecl SetZooRating(int rating) {
	_setZooRating ogSetZooRating = (_setZooRating)0x0041D22F;
	if (zoo_models->_emuZooRatingSet == true) {
		rating = zoo_models->_zooRating;
	}
	ogSetZooRating(rating);
}

void __cdecl SetAnimalRating(int rating) {
	_setAnimalRating ogSetAnimalRating = (_setAnimalRating)0x0041D08B;
	if (zoo_models->_emuAnimalRatingSet == true) {
    	rating = zoo_models->_animalRating;
	}
	ogSetAnimalRating(rating);
}
