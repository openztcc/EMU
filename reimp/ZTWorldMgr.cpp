
#include "ZTWorldMgr.h"
#include "ZTMapView.h"

void* ZTWorldMgr::getWorldMgr() {
    return (void*)0x00638040;
}

DWORD ZTWorldMgr::getOffset(DWORD offset) {
    return (*(DWORD*)0x00638040) + offset;
}

std::vector<DWORD*> ZTWorldMgr::getAllEntitiesOfType(int ids[]) {
    // store the begin and end pointers of the entity list

    DWORD* begin = *reinterpret_cast<DWORD**>(ZTWorldMgr::getOffset(0x80));
    DWORD* end = *reinterpret_cast<DWORD**>(ZTWorldMgr::getOffset(0x84));
    std::vector<DWORD*> entities;

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

        for (size_t i = 0; ids[i] != NULL; i++) {
            if (entityID == ids[i]) {
                // store the pointer to the entity
                entities.push_back(firstLevelPtr);
            }
        }
    }

    return entities;
}

void ZTWorldMgr::makeInvisible(std::vector<DWORD*> entities, bool isInvisible) {
    for (size_t i = 0; i < entities.size(); i++) {
        // Correctly calculate the pointer to the visibility flag
        bool* visibilityFlag = reinterpret_cast<bool*>(reinterpret_cast<char*>(entities[i]) + 0x13f);
        *visibilityFlag = isInvisible;
    }
}
