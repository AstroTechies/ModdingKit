#include "AstroPSActivitiesDatabase.h"

UAstroPSActivitiesDatabase::UAstroPSActivitiesDatabase() {
}

bool UAstroPSActivitiesDatabase::HasCompletedMissionChain(const FName& CompletedMissionId, const TArray<FName>& CompletedMissionIds) const {
    return false;
}

TArray<FName> UAstroPSActivitiesDatabase::GetMissionIdsForChainByMissionId(const FName& missionId) const {
    return TArray<FName>();
}

TArray<FName> UAstroPSActivitiesDatabase::GetMissionIdsForChainByActivity(const EAstroPSActivity& Activity) const {
    return TArray<FName>();
}

TArray<FName> UAstroPSActivitiesDatabase::GetAllActivityNames() const {
    return TArray<FName>();
}

EAstroPSActivity UAstroPSActivitiesDatabase::GetActivityForMissionId(const FName& missionId) const {
    return EAstroPSActivity::None;
}

bool UAstroPSActivitiesDatabase::GetActivityAvalibility(const FName& ActivityName) const {
    return false;
}


