#include "AstroMissionsManager.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

AAstroMissionsManager::AAstroMissionsManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
//    this->bSaveGameRelevant = true;
    this->bAlwaysRelevant = true;
    this->bReplicates = true;
//    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
//    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->bMissionsDisabled = false;
    this->bMissionsIntitialized = false;
}

void AAstroMissionsManager::ToggleEventsDebug(UWorld* World) {
}

void AAstroMissionsManager::TestResetAllMissions(UWorld* World) {
}

void AAstroMissionsManager::TestListMissions(UWorld* World) const {
}

void AAstroMissionsManager::TestListCompletedMissions(UWorld* World) const {
}

void AAstroMissionsManager::TestListActiveThemes(UWorld* World) const {
}

void AAstroMissionsManager::TestListActiveMissions(UWorld* World) const {
}

void AAstroMissionsManager::TestListActiveEvents(UWorld* World) const {
}

void AAstroMissionsManager::TestCompleteMission(const FName missionId, UWorld* World) {
}

void AAstroMissionsManager::TestCompleteAllMissions(UWorld* World) {
}

void AAstroMissionsManager::TestBackdateMissionOneYear(const FName missionId, UWorld* World) {
}

void AAstroMissionsManager::TestActivateMission(const FName missionId, UWorld* World) {
}

bool AAstroMissionsManager::PlayerHasReclaimReward(const TSubclassOf<UItemType> ItemType, const AAstroPlayerController* Controller) {
    return false;
}

void AAstroMissionsManager::OnRep_MissionsIntitialized(bool previousValue) {
}

void AAstroMissionsManager::OnRep_CompletedMissions() {
}

void AAstroMissionsManager::OnRep_ActiveMissions() {
}

void AAstroMissionsManager::OnDLCLicenseUpdated() {
}

void AAstroMissionsManager::OnDLCLicenseAdded(EAstroDlcName Name) {
}

void AAstroMissionsManager::MulticastNotifyRewardClamed_Implementation(const FName missionId) {
}

void AAstroMissionsManager::MulticastNotifyObjectiveUpdated_Implementation(const FName missionId, const FAstroMissionObjectiveProgress& objectiveProgress, int32 objectiveIndex, bool bShowUINotification, float valueToReport) {
}

void AAstroMissionsManager::MulticastNotifyMissionComplete_Implementation(const FName missionId) {
}

void AAstroMissionsManager::MulticastNotifyMissionActive_Implementation(const FName missionId) {
}

bool AAstroMissionsManager::MissionsAreInitialized() {
    return false;
}

bool AAstroMissionsManager::MissionsAreDisabled() {
    return false;
}

bool AAstroMissionsManager::MissionHasUnclaimedReward(const FName missionId) const {
    return false;
}

bool AAstroMissionsManager::MissionHasKeyItem(FName missionId) const {
    return false;
}

FString AAstroMissionsManager::GetPlayerId(const APlayerController* Player) const {
    return TEXT("");
}

bool AAstroMissionsManager::GetMissionStateBP(const FName missionId, FAstroMissionState& outMissionState) const {
    return false;
}

APhysicalItem* AAstroMissionsManager::GetMissionKeyItem(FName missionId) {
    return NULL;
}

bool AAstroMissionsManager::GetMissionIsComplete(const FName missionId) const {
    return false;
}

bool AAstroMissionsManager::GetMissionIsActive(const FName missionId) const {
    return false;
}

bool AAstroMissionsManager::GetMissionDataBP(const FName missionId, FAstroMissionData& outMissionData) const {
    return false;
}

TArray<FAstroMissionState> AAstroMissionsManager::GetCompletedMissions() const {
    return TArray<FAstroMissionState>();
}

TMap<FName, FAstroMissionData> AAstroMissionsManager::GetAllMissions() const {
    return TMap<FName, FAstroMissionData>();
}

TArray<FAstroMissionState> AAstroMissionsManager::GetActiveMissions() const {
    return TArray<FAstroMissionState>();
}

void AAstroMissionsManager::DelayedTryActivateNavpointGroup(FName missionId) {
}

bool AAstroMissionsManager::AuthoritySetRewardClaimedMission(const FName missionId) {
    return false;
}

void AAstroMissionsManager::AuthoritySetReclaimableRewardUnclaimed(AAstroPlayerController* Controller, APhysicalItem* Item) {
}

void AAstroMissionsManager::AuthoritySetReclaimableRewardClaimed(AAstroPlayerController* Controller, APhysicalItem* Item) {
}

void AAstroMissionsManager::AuthorityRaiseMissionEvent(const EAstroMissionObjectiveType ObjectiveType, const TSubclassOf<UItemType> TargetType, const TSubclassOf<UItemType> SecondaryTargetType, const float Count, const EPlanetIdentifier Planet, const FString& CustomTag) {
}

void AAstroMissionsManager::AuthorityNotifyKeyItemCreated(FName missionId, APhysicalItem* Item) {
}

void AAstroMissionsManager::AuthorityGrantResearchItemRewardMission(const FAstroMissionData& MissionData) {
}

void AAstroMissionsManager::AuthorityGrantPlayFabReward(const FAstroMissionData& MissionData) {
}

void AAstroMissionsManager::AuthorityGrantByteRewardMission(const FAstroMissionData& MissionData) {
}

AActor* AAstroMissionsManager::AuthorityGetReclaimableRewardItem(const AAstroPlayerController* Controller, const TSubclassOf<UItemType> ItemType) {
    return NULL;
}

void AAstroMissionsManager::AuthorityCompleteMission(const FName missionId) {
}

void AAstroMissionsManager::AuthorityActivateMission(const FName missionId, const FString& EventName, bool ignorePrerequisites) {
}

void AAstroMissionsManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAstroMissionsManager, CompletedMissions);
    DOREPLIFETIME(AAstroMissionsManager, ActiveMissions);
    DOREPLIFETIME(AAstroMissionsManager, CompletedCustomTags);
    DOREPLIFETIME(AAstroMissionsManager, ReclaimableRewards);
    DOREPLIFETIME(AAstroMissionsManager, bMissionsDisabled);
    DOREPLIFETIME(AAstroMissionsManager, bMissionsIntitialized);
}


