#ifndef ZTWORDLMGR_H
#define ZTWORDLMGR_H

#include "Windows.h"
#include <vector>
#include <sol/sol.hpp>

class ZTWorldMgr {
    public:
    // char padding[536];
    ZTWorldMgr();
    ~ZTWorldMgr() {};

    static void* getWorldMgr();
    static DWORD getOffset(DWORD);
    static bool isEntityNull(void*);


    static std::vector<void*> GetAllEntitiesOfType(std::vector<int>);
    static void* getEntityTypeByID(int);
    static void* getEntityType(void*);
    static void SetVanishGuard(std::vector<void*>, std::vector<int>, bool);
    static void ExportClassToLua(sol::state_view&);
    static void ReinforceFences();

    static ZTWorldMgr& instance() {
        static ZTWorldMgr instance;
        return instance;
    }

    int cached_month;
    int cached_cHeight;
    bool cached_cSeeThrough;
    bool cached_cIsJumpable;
    bool cached_cIsClimbable;
    bool cached_cIndestructable;
    int cached_cLife;
    int cached_cStrength;
    int cached_cDecayedLife;
    int cached_cDecayedDelta;

    std::vector<void*> cached_entities;
};

#endif // ZTWORDLMGR_H
