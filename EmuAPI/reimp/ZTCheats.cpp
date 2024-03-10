#include "ZTCheats.h"
#include "ZTWorldMgr.h"
#include "ZTGuest.h"
#include "ZTUI.h"

void ZTCheats::InvisibleInvincibleCheat() {
    if (ZTUI::general::getSelectedEntity() == 0) {
        return;
    }
    if (ZTGuest::getSelectedGuestName() == "Mrs. Invis") {
        int ids[] = {9313, 9314, NULL};
        std::vector<DWORD*> entities = ZTWorldMgr::getAllEntitiesOfType(ids);
        ZTWorldMgr::makeInvisible(entities, false);
    } else if (ZTGuest::getSelectedGuestName() == "Mr. Show") {
        int ids[] = {9313, 9314, NULL};
        std::vector<DWORD*> entities = ZTWorldMgr::getAllEntitiesOfType(ids);
        ZTWorldMgr::makeInvisible(entities, true);
    }
}