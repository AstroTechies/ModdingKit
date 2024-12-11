#include "AstroMissionState.h"

FAstroMissionState::FAstroMissionState() {
    this->MissionVersion = 0;
    this->MissionLogPriority = 0;
    this->bPendingReward = false;
    this->bReclaimableReward = false;
    this->bRemoveAfterReward = false;
    this->ReclaimedCount = 0;
    this->bHasKeyItem = false;
}

