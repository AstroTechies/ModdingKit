#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Actor.h"
#include "AstroMissionData.h"
#include "AstroMissionState.h"
#include "AstroMissionReclaimableItem.h"
#include "SignalDelegate.h"
#include "AstroMissionObjectiveUpdatedDelegateDelegate.h"
#include "AstroMissionActivatedDelegateDelegate.h"
#include "AstroMissionCompletedDelegateDelegate.h"
#include "AstroMissionRewardClaimedDelegateDelegate.h"
#include "AstroMissionObjectiveProgress.h"
#include "EAstroMissionObjectiveType.h"
#include "EPlanetIdentifier.h"
#include "AstroMissionsManager.generated.h"

class UWorld;
class APlayerController;
class UItemType;
class AAstroPlayerController;
class APhysicalItem;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AAstroMissionsManager : public AActor
{
    GENERATED_BODY()
public:
private:
    UPROPERTY()
    TMap<FName, FAstroMissionData> AllMissions;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_CompletedMissions)
    TArray<FAstroMissionState> CompletedMissions;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_ActiveMissions)
    TArray<FAstroMissionState> ActiveMissions;

    UPROPERTY(Replicated, SaveGame)
    TArray<FString> CompletedCustomTags;

    UPROPERTY(Replicated, SaveGame)
    TArray<FAstroMissionReclaimableItem> ReclaimableRewards;

    UPROPERTY(Replicated, SaveGame)
    uint8 bMissionsDisabled : 1;

    UPROPERTY(ReplicatedUsing = OnRep_MissionsIntitialized)
    uint8 bMissionsIntitialized : 1;

public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnMissionsInitialized;

    UPROPERTY(BlueprintAssignable)
    FAstroMissionActivatedDelegate OnMissionActivated;

    UPROPERTY(BlueprintAssignable)
    FAstroMissionObjectiveUpdatedDelegate OnMissionObjectiveUpdated;

    UPROPERTY(BlueprintAssignable)
    FAstroMissionCompletedDelegate OnMissionCompleted;

    UPROPERTY(BlueprintAssignable)
    FAstroMissionRewardClaimedDelegate OnMissionRewardClaimed;

    AAstroMissionsManager();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(Exec)
    void TestResetAllMissions(UWorld *World);

    UFUNCTION(Exec)
    void TestListMissions(UWorld *World) const;

    UFUNCTION(Exec)
    void TestListCompletedMissions(UWorld *World) const;

    UFUNCTION(Exec)
    void TestListActiveMissions(UWorld *World) const;

    UFUNCTION(Exec)
    void TestCompleteMission(const FName missionId, UWorld *World);

    UFUNCTION(Exec)
    void TestCompleteAllMissions(UWorld *World);

    UFUNCTION(Exec)
    void TestActivateMission(const FName missionId, UWorld *World);

    UFUNCTION(BlueprintCallable)
    bool PlayerHasReclaimReward(const TSubclassOf<UItemType> ItemType, const AAstroPlayerController *Controller);

private:
    UFUNCTION()
    void OnRep_MissionsIntitialized(bool previousValue);

    UFUNCTION()
    void OnRep_CompletedMissions();

    UFUNCTION()
    void OnRep_ActiveMissions();

    UFUNCTION(NetMulticast, Reliable)
    void MulticastNotifyRewardClamed(const FName missionId);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastNotifyObjectiveUpdated(const FName missionId, const FAstroMissionObjectiveProgress &objectiveProgress, int32 objectiveIndex, bool bShowUINotification, float valueToReport);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastNotifyMissionComplete(const FName missionId);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastNotifyMissionActive(const FName missionId);

public:
    UFUNCTION(BlueprintPure)
    bool MissionsAreInitialized();

    UFUNCTION(BlueprintPure)
    bool MissionsAreDisabled();

    UFUNCTION(BlueprintPure)
    bool MissionHasUnclaimedReward(const FName missionId) const;

    UFUNCTION(BlueprintPure)
    bool MissionHasKeyItem(FName missionId) const;

private:
    UFUNCTION(BlueprintPure)
    FString GetPlayerId(const APlayerController *Player) const;

    UFUNCTION(BlueprintPure)
    bool GetMissionStateBP(const FName missionId, FAstroMissionState &outMissionState) const;

public:
    UFUNCTION(BlueprintPure)
    APhysicalItem *GetMissionKeyItem(FName missionId);

private:
    UFUNCTION(BlueprintPure)
    bool GetMissionIsComplete(const FName missionId) const;

    UFUNCTION(BlueprintPure)
    bool GetMissionIsActive(const FName missionId) const;

    UFUNCTION(BlueprintPure)
    bool GetMissionDataBP(const FName missionId, FAstroMissionData &outMissionData) const;

public:
    UFUNCTION(BlueprintPure)
    TArray<FAstroMissionState> GetCompletedMissions() const;

    UFUNCTION(BlueprintPure)
    TMap<FName, FAstroMissionData> GetAllMissions() const;

    UFUNCTION(BlueprintPure)
    TArray<FAstroMissionState> GetActiveMissions() const;

private:
    UFUNCTION()
    void DelayedTryActivateNavpointGroup(FName missionId);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetRewardClaimedMission(const FName missionId);

    UFUNCTION(BlueprintCallable)
    void AuthoritySetReclaimableRewardUnclaimed(AAstroPlayerController *Controller, APhysicalItem *Item);

    UFUNCTION(BlueprintCallable)
    void AuthoritySetReclaimableRewardClaimed(AAstroPlayerController *Controller, APhysicalItem *Item);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityRaiseMissionEvent(const EAstroMissionObjectiveType ObjectiveType, const TSubclassOf<UItemType> TargetType, const TSubclassOf<UItemType> SecondaryTargetType, const float Count, const EPlanetIdentifier Planet, const FString &CustomTag);

    UFUNCTION(BlueprintCallable)
    void AuthorityNotifyKeyItemCreated(FName missionId, APhysicalItem *Item);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityGrantResearchItemRewardMission(const FName missionId);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityGrantByteRewardMission(const FName missionId);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    AActor *AuthorityGetReclaimableRewardItem(const AAstroPlayerController *Controller, const TSubclassOf<UItemType> ItemType);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityCompleteMission(const FName missionId);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityActivateMission(const FName missionId);
};
