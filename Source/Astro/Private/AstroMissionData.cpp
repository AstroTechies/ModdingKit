#include "AstroMissionData.h"

FAstroMissionData::FAstroMissionData() {
    this->IsEventMission = false;
    this->NotificationColor = EAstroColor::None;
    this->NotificationIcon = NULL;
    this->KeyItemType = NULL;
    this->KeyItemDeliveryType = EAstroMissionRewardDeliveryType::SupplyDrop;
    this->AchievementReward = EAstroAchievementKeys::TutorialDone;
    this->MissionVersion = 0;
    this->MissionLogPriority = 0;
    this->ByteRewardValue = 0;
    this->bAutoActivate = false;
    this->bAutoCompleteOnExistingGames = false;
    this->bSuppressActivationNotification = false;
    this->bReclaimableReward = false;
    this->bDestroyKeyItemOnMissionComplete = false;
    this->DeliveryType = EAstroMissionRewardDeliveryType::SupplyDrop;
    this->RequiresGlitchWalkersEntitlement = false;
    this->RequiresMegatechEntitlement = false;
//    this->EngagementStateToSetOnActivation = FAstroGWExpansionEngagementState::GW_NotEngaged;
}

