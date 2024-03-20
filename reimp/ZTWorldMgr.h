#ifndef ZTWORDLMGR_H
#define ZTWORDLMGR_H

#include "Windows.h"
#include <vector>
#include <sol/sol.hpp>

class ZTWorldMgr {
    public:
    // char padding[536];
    ZTWorldMgr() {};
    ~ZTWorldMgr() {};

    static void* getWorldMgr();
    static DWORD getOffset(DWORD);
    static bool isEntityNull(void*);


    static std::vector<DWORD*> GetAllEntitiesOfType(std::vector<int>);
    static void* getEntityTypeByID(int);
    static void SetVanishGuard(std::vector<DWORD*>, bool);
    static void ExportClassToLua(sol::state_view&);

};

#endif // ZTWORDLMGR_H
