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
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach((PVOID*)&addCashAddress, (PVOID)&ZTGameMgr::addCash_Detour);
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

}

void ZTGameMgr::addCash(float amount) {
    // add cash to the game
    this->zoo_budget += amount;
    ZTUI::main::setMoneyText(); // update money text in the UI
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