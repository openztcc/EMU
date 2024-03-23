
#include "ZTWorldMgr.h"
#include "ZTMapView.h"
#include <vector>
#include "ZTUI.h"
#include "ZTGameMgr.h"
#include "EmuMain.h"
#include "ZTFenceType.h"
#include "ZTFence.h"

#define instance ZTWorldMgr::instance()

ZTWorldMgr::ZTWorldMgr() {
    this->cached_month = ZTGameMgr::getMonth();
}

void* ZTWorldMgr::getWorldMgr() {
    return (void*)0x00638040;
}

DWORD ZTWorldMgr::getOffset(DWORD offset) {
    return (*(DWORD*)0x00638040) + offset;
}

// gets only entity types whose entities are currently loaded in the game
std::vector<void*> ZTWorldMgr::GetAllEntitiesOfType(std::vector<int> ids) {
    // store the begin and end pointers of the entity list

    DWORD* begin = *reinterpret_cast<DWORD**>(ZTWorldMgr::getOffset(0x80));
    DWORD* end = *reinterpret_cast<DWORD**>(ZTWorldMgr::getOffset(0x84));
    std::vector<void*> entities;

    // iterate through the entity list
    for (DWORD** current = reinterpret_cast<DWORD**>(begin); current < reinterpret_cast<DWORD**>(end); ++current) {
        // get the first level pointer
        DWORD* firstLevelPtr = *current;
        if (!firstLevelPtr) continue;

        // get the second level pointer
        DWORD* secondLevelPtr = *reinterpret_cast<DWORD**>(reinterpret_cast<char*>(firstLevelPtr) + 0x128);
        if (!secondLevelPtr) continue;

        // get second level pointer's entity ID
        int entityID = *reinterpret_cast<int*>(reinterpret_cast<char*>(secondLevelPtr) + 0x104);

        for (size_t i = 0; i < ids.size(); i++) {
            if (entityID == ids[i]) {
                // store the pointer to the entity
                entities.push_back(reinterpret_cast<void*>(firstLevelPtr));
            }
        }
    }

    return entities;
}

bool ZTWorldMgr::isEntityNull(void* entity) {
    if (entity == 0) {
        return true;
    }
    return false;
}

// gets ALL entity types loaded in the game
void* ZTWorldMgr::getEntityTypeByID(int id) {
    DWORD* begin = *reinterpret_cast<DWORD**>(ZTWorldMgr::getOffset(0x98));
    DWORD* end = *reinterpret_cast<DWORD**>(ZTWorldMgr::getOffset(0x9C));

    // iterate through the entity list
    for (DWORD** current = reinterpret_cast<DWORD**>(begin); current < reinterpret_cast<DWORD**>(end); ++current) {
        // get the first level pointer
        DWORD* firstLevelPtr = *current;
        if (!firstLevelPtr) continue;

        // get second level pointer's entity ID
        int entityID = *reinterpret_cast<int*>(reinterpret_cast<char*>(firstLevelPtr) + 0x104);
        int animalID = *reinterpret_cast<int*>(reinterpret_cast<char*>(firstLevelPtr) + 0x130);

        if (entityID == id || animalID == id) {
            // store the pointer to the entity
            return firstLevelPtr;
        } 
    }

    return nullptr;
}

void* ZTWorldMgr::getEntityType(void* entity) {
    return *reinterpret_cast<void**>((DWORD)entity + 0x128);
}

//  
void ZTWorldMgr::SetVanishGuard(std::vector<void*> entities, std::vector<int> ids, bool visible) {
    if (entities.size() == 0 || ids.size() == 0) {
        return;
    }

        
    for (size_t x = 0; x < ids.size(); x++) {
        // -- set entity type properties
        if (!visible) {
            void* type = ZTWorldMgr::getEntityTypeByID(ids[x]);
            ZTFenceType fence_type(type);

            // save the entity type properties

            instance.cached_FenceType.cDecayedDelta = fence_type.cDecayedDelta();
            instance.cached_FenceType.cDecayedLife = fence_type.cDecayedLife();
            instance.cached_FenceType.cHeight = fence_type.cHeight();
            instance.cached_FenceType.cIndestructable = fence_type.cIndestructable();
            instance.cached_FenceType.cIsClimbable = fence_type.cIsClimbable();
            instance.cached_FenceType.cIsJumpable = fence_type.cIsJumpable();
            instance.cached_FenceType.cLife = fence_type.cLife();
            instance.cached_FenceType.cSeeThrough = fence_type.cSeeThrough();
            instance.cached_FenceType.cStrength = fence_type.cStrength();

            // set entity type properties
            fence_type.cStrength(500);
            fence_type.cLife(12);
            fence_type.cIsClimbable(false);
            fence_type.cIsJumpable(false);
            fence_type.cIndestructable(true);
            fence_type.cSeeThrough(true);
            fence_type.cHeight(5);
            fence_type.cDecayedLife(1);
            fence_type.cDecayedDelta(20);
        }
        else 
        {
            void* type = ZTWorldMgr::getEntityTypeByID(ids[x]);
            ZTFenceType fence_type(type);

            // restore the entity type properties
            fence_type.cDecayedDelta(instance.cached_FenceType.cDecayedDelta);
            fence_type.cDecayedLife(instance.cached_FenceType.cDecayedLife);
            fence_type.cHeight(instance.cached_FenceType.cHeight);
            fence_type.cIndestructable(instance.cached_FenceType.cIndestructable);
            fence_type.cIsClimbable(instance.cached_FenceType.cIsClimbable);
            fence_type.cIsJumpable(instance.cached_FenceType.cIsJumpable);
            fence_type.cLife(instance.cached_FenceType.cLife);
            fence_type.cSeeThrough(instance.cached_FenceType.cSeeThrough);
            fence_type.cStrength(instance.cached_FenceType.cStrength);
        }
    }

    for (size_t i = 0; i < entities.size(); i++) {
        // set the entity to be invisible
        void* type = ZTWorldMgr::getEntityType(entities[i]);
        ZTFenceType fence_type(type);
        if (fence_type.codename() != "stickfen")
        {
            entities.erase(entities.begin() + i);
            continue;
        }
        ZTFence fence(entities[i]);
        fence.visible(visible);
        fence.setHealthy();
        
    }

    if (!visible) {
        EmuMain::shared_instance().vanishGuardCheck = true;
        instance.cached_entities = entities;
    } else {
        EmuMain::shared_instance().vanishGuardCheck = false;
        instance.cached_entities.clear();
    }
}

void ZTWorldMgr::ReinforceFences() {
    int size = instance.cached_entities.size();
    for (int i = 0; i < size; i++) {
        void* entity = instance.cached_entities[i];
        ZTFence fence(entity);
        fence.setHealthy();
    }
}

void ZTWorldMgr::ExportClassToLua(sol::state_view& lua) {
    lua.new_usertype<ZTWorldMgr>("ztWorldMgr",
        "new", sol::no_constructor,
        "getAllEntitiesOfType", &ZTWorldMgr::GetAllEntitiesOfType,
        "getEntityTypeByID", &ZTWorldMgr::getEntityTypeByID,
        "setVanishGuard", &ZTWorldMgr::SetVanishGuard,
        "isEntityNull", &ZTWorldMgr::isEntityNull
    );
}

void* ZTWorldMgr::trimReturnedEntitiesByID(std::vector<void*> entities, int id) {
    for (size_t i = 0; i < entities.size(); i++) {
        void* type = ZTWorldMgr::getEntityType(entities[i]);
        //  look through associated entity types to find the one with the matching ID
        void* secondLevelPtr = *reinterpret_cast<void**>((DWORD)type + 0x128);
        int entityID = *reinterpret_cast<int*>((DWORD)secondLevelPtr + 0x104);
        if (entityID == id) {
            return entities[i];
        }
    }
    return nullptr;
}