#include "ZTCheats.h"
#include "ZTWorldMgr.h"
#include "ZTGuest.h"
#include "ZTUI.h"

void ZTCheats::InvisibleInvincibleCheat() {
    if (ZTUI::general::getSelectedEntity() == 0) {
        return;
    }
    if (ZTGuest::GetSelectedGuestName() == "Mrs. Invis") {
        std::vector<int> ids = {9313, 9314 };
        std::vector<DWORD*> entities = ZTWorldMgr::GetAllEntitiesOfType(ids);
        ZTWorldMgr::MakeInvisible(entities, false);
    } else if (ZTGuest::GetSelectedGuestName() == "Mr. Show") {
        std::vector<int> ids = {9313, 9314 };
        std::vector<DWORD*> entities = ZTWorldMgr::GetAllEntitiesOfType(ids);
        ZTWorldMgr::MakeInvisible(entities, true);
    }
}