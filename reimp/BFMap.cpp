#include "BFMap.h"
#include "EmuBase.h"
#include "detours.h"

DWORD originalGenerateMapAdd = 0x00452e13;
DWORD setMapDimensionsAdd = 0x004c84d3;
DWORD computeTilesAdd = 0x004af165;

void BFMap::init() {
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    // DetourAttach((PVOID*)generateMapAdd, (PVOID)&BFMap::generateMap);
    // DetourAttach((PVOID*)&originalGenerateMapAdd, (PVOID)BFMap::generateMap);
    // DetourAttach((PVOID*)&setMapDimensionsAdd, (PVOID)&BFMap::setMapDimensions);
    DetourAttach((PVOID*)&computeTilesAdd, (PVOID)&BFMap::computeTiles);
    DetourTransactionCommit();

    EmuBase::callHook(0x005bc4b4, (DWORD)&BFMap::computeTiles);

}

// not working
void BFMap::generateMap(void* a2, int a3, int a4, char a5) {
    ogGenerateMap original = (ogGenerateMap)originalGenerateMapAdd;
    return original(a2, a3, a4, a5);
}

void BFMap::setMapDimensions(void* a2, int a3, int a4, bool a5) {
    ogSetMapDimensions original = (ogSetMapDimensions)setMapDimensionsAdd;
    // a3 = 200;
    // a4 = 200;
    original(a2, a3, a4, a5);
}

void __fastcall BFMap::computeTiles(void* a2) {
    ogComputeTiles original = (ogComputeTiles)computeTilesAdd;
    original(a2);
}