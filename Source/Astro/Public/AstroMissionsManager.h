#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AstroMissionActivatedDelegateDelegate.h"
#include "AstroMissionCompletedDelegateDelegate.h"
#include "AstroMissionData.h"
#include "AstroMissionObjectiveProgress.h"
#include "AstroMissionObjectiveUpdatedDelegateDelegate.h"
#include "AstroMissionReclaimableItem.h"
#include "AstroMissionRewardClaimedDelegateDelegate.h"
#include "AstroMissionState.h"
#include "EAstroMissionObjectiveType.h"
#include "EPlanetIdentifier.h"
#include "SignalDelegate.h"
#include "Templates/SubclassOf.h"
#include "AstroMissionsManager.generated.h"

class AAstroPlayerController;
class APhysicalItem;
class APlayerController;
class UItemType;
class UWorld;

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
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleEventsDebug(UWorld* World);
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestResetAllMissions(UWorld* World);
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestListMissions(UWorld* World) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestListCompletedMissions(UWorld* World) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestListActiveThemes(UWorld* World) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestListActiveMissions(UWorld* World) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestListActiveEvents(UWorld* World) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestCompleteMission(const FName missionId, UWorld* World);
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestCompleteAllMissions(UWorld* World);
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestBackdateMissionOneYear(const FName missionId, UWorld* World);
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestActivateMission(const FName missionId, UWorld* World);
    
    UFUNCTION(BlueprintCallable)
    bool PlayerHasReclaimReward(const TSubclassOf<UItemType> ItemType, const AAstroPlayerController* Controller);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_MissionsIntitialized(bool previousValue);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CompletedMissions();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ActiveMissions();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastNotifyRewardClamed(const FName missionId);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastNotifyObjectiveUpdated(const FName missionId, const FAstroMissionObjectiveProgress& objectiveProgress, int32 objectiveIndex, bool bShowUINotification, float valueToReport);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastNotifyMissionComplete(const FName missionId);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastNotifyMissionActive(const FName missionId);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool MissionsAreInitialized();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool MissionsAreDisabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool MissionHasUnclaimedReward(const FName missionId) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool MissionHasKeyItem(FName missionId) const;
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetPlayerId(const APlayerController* Player) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMissionStateBP(const FName missionId, FAstroMissionState& outMissionState) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APhysicalItem* GetMissionKeyItem(FName missionId);
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMissionIsComplete(const FName missionId) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMissionIsActive(const FName missionId) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMissionDataBP(const FName missionId, FAstroMissionData& outMissionData) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FAstroMissionState> GetCompletedMissions() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<FName, FAstroMissionData> GetAllMissions() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FAstroMissionState> GetActiveMissions() const;
    
private:
    UFUNCTION(BlueprintCallable)
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
    void AuthorityGrantResearchItemRewardMission(const FAstroMissionData& MissionData);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityGrantByteRewardMission(const FAstroMissionData& MissionData);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    AActor* AuthorityGetReclaimableRewardItem(const AAstroPlayerController* Controller, const TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityCompleteMission(const FName missionId);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityActivateMission(const FName missionId, const FString& EventName);
    
};

