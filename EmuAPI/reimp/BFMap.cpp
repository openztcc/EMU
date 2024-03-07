#include "BFMap.h"
#include "EmuBase.h"
#include "detours.h"

DWORD originalGenerateMapAdd = 0x00452e13;

void BFMap::init() {
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    // DetourAttach((PVOID*)generateMapAdd, (PVOID)&BFMap::generateMap);
    DetourAttach((PVOID*)&originalGenerateMapAdd, (PVOID)BFMap::generateMap);
    DetourTransactionCommit();

    // EmuBase::callHook(0x00630ce8, (DWORD)&BFMap::generateMap);

}

// not working
int __fastcall BFMap::generateMap(void* a2, int a3, int a4) {
    ogGenerateMap original = (ogGenerateMap)originalGenerateMapAdd;
    return original(a2, a3, a4);
}