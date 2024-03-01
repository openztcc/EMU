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
    // DetourAttach((PVOID*)&addCashAddress, (PVOID)&ZTGameMgr::addCash_Detour);
}

void ZTGameMgr::addCash(float amount) {
    // add cash to the game
    this->zoo_budget += amount;
}

ZTGameMgr::~ZTGameMgr() {
    // destructor
    // clean up detour function pointers
}