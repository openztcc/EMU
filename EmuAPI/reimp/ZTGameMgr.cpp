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
    // DetourAttach((PVOID*)&BFUIMgrSetControlForeColorAddress, (PVOID)&ZTGameMgr::BFUIMgrSetControlForeColor_Detour);
    DetourTransactionCommit();
}

void ZTGameMgr::addCash(float amount) {
    // add cash to the game
    this->zoo_budget += amount;
    ZTUIMainSetMoneyText(); // update money text in the UI
}


void __fastcall ZTGameMgr::addCash_Detour(void* ptr, float amount) {
    // detour function for adding cash to the game
    ZTGameMgr::shared_instance().addCash(amount);
}

void __fastcall ZTGameMgr::BFUIMgrSetControlForeColor_Detour(void* ptr, int param_1, DWORD color) {
    // detour function for setting control forecolor
    // set control forecolor
    _BFUIMgrSetControlForeColor og_BFUIMgrSetControlForeColor = (_BFUIMgrSetControlForeColor)0x0040ee08;

    // void* deref_ptr = *(void**)ptr;

    og_BFUIMgrSetControlForeColor(ptr, param_1, color);
}

void __cdecl ZTGameMgr::BFInternatSetMoneyText_Detour(int param_1, float param_2, char param_3) {
    // detour function for setting money text
    // set money text
    _BFInternatSetMoneyText og_BFInternatSetMoneyText = (_BFInternatSetMoneyText)0x0040ed88;

    og_BFInternatSetMoneyText(param_1, param_2, param_3);
}

void ZTGameMgr::ZTUIMainSetMoneyText() {
    // set money text show in the UI
    float money = this->zoo_budget;
    DWORD uVar1; // local variable

    void* pBFUIMgr = *(void**)0x00638de0;

    // GXRGB color = {0, 0, 0}; // set color to black
    DWORD color = 0x638fbc; // set color to black
    DWORD BFInternatSetMoneyText_DetourAddress = 0x0040ed88; // address of BFUIMgrSetControlForeColor function in the game
    DWORD BFUIMgrSetControlForeColorAddress = 0x0040ee08; // address of BFUIMgrSetControlForeColor function in the game
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach((PVOID*)&BFUIMgrSetControlForeColorAddress, (PVOID)&ZTGameMgr::BFUIMgrSetControlForeColor_Detour);
    DetourAttach((PVOID*)&BFInternatSetMoneyText_DetourAddress, (PVOID)&ZTGameMgr::BFInternatSetMoneyText_Detour);


    float money_to_display = (float)((int)money); // round down to nearest integer
    BFUIMgrSetControlForeColor_Detour(pBFUIMgr, 0x3f8, color); // set control forecolor   
    BFInternatSetMoneyText_Detour(0x3f8, money_to_display, '\x01'); // set money text

    DetourTransactionCommit();
}

ZTGameMgr::~ZTGameMgr() {
    // destructor
    // clean up detour function pointers
}