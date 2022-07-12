#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "SignalDelegate.h"
#include "AstroMissionObjectiveUpdatedDelegateDelegate.h"
#include "AstroMissionData.h"
#include "AstroMissionState.h"
#include "AstroMissionCompletedDelegateDelegate.h"
#include "AstroMissionReclaimableItem.h"
#include "AstroMissionActivatedDelegateDelegate.h"
#include "AstroMissionRewardClaimedDelegateDelegate.h"
#include "AstroMissionObjectiveProgress.h"
#include "EAstroMissionObjectiveType.h"
#include "EPlanetIdentifier.h"
#include "AstroMissionsManager.generated.h"

class AAstroPlayerController;
class APlayerController;
class UWorld;
class UItemType;
class APhysicalItem;

UCLASS(Blueprintable)
class ASTRO_API AAstroMissionsManager : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FAstroMissionData> AllMissions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_CompletedMissions, meta=(AllowPrivateAccess=true))
    TArray<FAstroMissionState> CompletedMissions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_ActiveMissions, meta=(AllowPrivateAccess=true))
    TArray<FAstroMissionState> ActiveMissions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FString> CompletedCustomTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FAstroMissionReclaimableItem> ReclaimableRewards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bMissionsDisabled: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_MissionsIntitialized, meta=(AllowPrivateAccess=true))
    uint8 bMissionsIntitialized: 1;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnMissionsInitialized;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroMissionActivatedDelegate OnMissionActivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroMissionObjectiveUpdatedDelegate OnMissionObjectiveUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroMissionCompletedDelegate OnMissionCompleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroMissionRewardClaimedDelegate OnMissionRewardClaimed;
    
    AAstroMissionsManager();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(Exec)
    void ToggleEventsDebug(UWorld* World);
    
    UFUNCTION(Exec)
    void TestResetAllMissions(UWorld* World);
    
    UFUNCTION(Exec)
    void TestListMissions(UWorld* World) const;
    
    UFUNCTION(Exec)
    void TestListCompletedMissions(UWorld* World) const;
    
    UFUNCTION(Exec)
    void TestListActiveMissions(UWorld* World) const;
    
    UFUNCTION(Exec)
    void TestCompleteMission(const FName missionId, UWorld* World);
    
    UFUNCTION(Exec)
    void TestCompleteAllMissions(UWorld* World);
    
    UFUNCTION(Exec)
    void TestActivateMission(const FName missionId, UWorld* World);
    
    UFUNCTION(BlueprintCallable)
    bool PlayerHasReclaimReward(const TSubclassOf<UItemType> ItemType, const AAstroPlayerController* Controller);
    
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
    void MulticastNotifyObjectiveUpdated(const FName missionId, const FAstroMissionObjectiveProgress& objectiveProgress, int32 objectiveIndex, bool bShowUINotification, float valueToReport);
    
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
    FString GetPlayerId(const APlayerController* Player) const;
    
    UFUNCTION(BlueprintPure)
    bool GetMissionStateBP(const FName missionId, FAstroMissionState& outMissionState) const;
    
public:
    UFUNCTION(BlueprintPure)
    APhysicalItem* GetMissionKeyItem(FName missionId);
    
private:
    UFUNCTION(BlueprintPure)
    bool GetMissionIsComplete(const FName missionId) const;
    
    UFUNCTION(BlueprintPure)
    bool GetMissionIsActive(const FName missionId) const;
    
    UFUNCTION(BlueprintPure)
    bool GetMissionDataBP(const FName missionId, FAstroMissionData& outMissionData) const;
    
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
    void AuthoritySetReclaimableRewardUnclaimed(AAstroPlayerController* Controller, APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void AuthoritySetReclaimableRewardClaimed(AAstroPlayerController* Controller, APhysicalItem* Item);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityRaiseMissionEvent(const EAstroMissionObjectiveType ObjectiveType, const TSubclassOf<UItemType> TargetType, const TSubclassOf<UItemType> SecondaryTargetType, const float Count, const EPlanetIdentifier Planet, const FString& CustomTag);
    
    UFUNCTION(BlueprintCallable)
    void AuthorityNotifyKeyItemCreated(FName missionId, APhysicalItem* Item);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityGrantResearchItemRewardMission(const FName missionId);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityGrantByteRewardMission(const FName missionId);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    AActor* AuthorityGetReclaimableRewardItem(const AAstroPlayerController* Controller, const TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityCompleteMission(const FName missionId);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityActivateMission(const FName missionId);
    
};

