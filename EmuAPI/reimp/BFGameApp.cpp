#include "BFGameApp.h" 


void BFGameApp::init() {
    // initialize instance of BFGameApp
    // initialize detour function pointers
    // EmuBase::callHook(0x0062075b, (DWORD)&); // from addCash
}

DWORD BFGameApp::instance(DWORD offset) {
    // return instance of BFGameApp
    return (*((DWORD*)((LPVOID)0x00638148)) + offset);
}

// not functional
void BFGameApp::incSimSpeed() {
    // detour function for increasing simulation speed
    // ZTGameMgr::shared_instance().incSimSpeed();
    // 0063088c
    void* _thisptr = (void*)0x00638148;

    // char *cVar1 = (char*)(instance(0x442));
    // float *fVar2 = (float*)(instance(0x4e0));

    // if (*cVar1 != '\0') {
    //     *fVar2 = *fVar2 + 0.1;
    // }

    _incSimSpeed _ogincSimSpeed = (_incSimSpeed)0x00620745;
    _ogincSimSpeed(_thisptr);
}