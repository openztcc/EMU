#ifndef ZTWORDLMGR_H
#define ZTWORDLMGR_H

#include "Windows.h"
#include <vector>
#include <sol/sol.hpp>

struct cache {
    int cHeight;
    bool cSeeThrough;
    bool cIsJumpable;
    bool cIsClimbable;
    bool cIndestructable;
    int cLife;
    int cStrength;
    int cDecayedLife;
    int cDecayedDelta;
};

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
    cache cached_FenceType;

    std::vector<void*> cached_entities;
};

#endif // ZTWORDLMGR_H
