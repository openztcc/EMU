#include "ZTGameMgr.h"



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
}

void ZTGameMgr::addCash(float amount) {
    // add cash to the game
    this->zoo_budget += amount;
}


void __fastcall ZTGameMgr::addCash_Detour(void* ptr, float amount) {
    // detour function for adding cash to the game
    ZTGameMgr::shared_instance().addCash(amount);
}

void ZTGameMgr::ZTUIMainSetMoneyText() {
    // set money text show in the UI
    float money = this->zoo_budget;
    DWORD uVar1; // local variable

    float money_to_display = (float)((int)money); // round down to nearest integer

}

ZTGameMgr::~ZTGameMgr() {
    // destructor
    // clean up detour function pointers
}