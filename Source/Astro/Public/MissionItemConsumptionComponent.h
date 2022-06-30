#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroMissionObjectiveProgress.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "EMissionItemRequestState.h"
#include "RequestMissionList.h"
#include "MissionItemConsumptionComponent.generated.h"

class UDynamicWhitelistOrganizationRule;
class UItemType;
class APhysicalItem;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UMissionItemConsumptionComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FName ConsumptionSlotName;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float ConsumptionRate;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float ConsumptionSlotEjectionForce;

    UPROPERTY(BlueprintAssignable)
    FSignal OnRequestsStateChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnConsumptionProgressChanged;

private:
    UPROPERTY(Transient)
    FSlotReference ConsumptionSlotRef;

    UPROPERTY(Transient)
    UDynamicWhitelistOrganizationRule *ConsumptionSlotOrganizationRule;

    UPROPERTY(SaveGame)
    TArray<FName> requestMissionIDs;

    UPROPERTY(Transient)
    TMap<TSubclassOf<UItemType>, FRequestMissionList> ActiveMissionRequests;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_RequestsState)
    EMissionItemRequestState RequestState;

    UPROPERTY(Transient, ReplicatedUsing = OnRep_ConsumptionProgress)
    float ConsumptionProgress;

public:
    UMissionItemConsumptionComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

private:
    UFUNCTION()
    void OnRep_RequestsState(EMissionItemRequestState prevState);

    UFUNCTION()
    void OnRep_ConsumptionProgress(float prevProgress);

    UFUNCTION()
    void InitializeMissionRequests_Internal();

    UFUNCTION()
    void HandleRequestObjectiveUpdated(FName missionId, const FAstroMissionObjectiveProgress &objectiveProgress, int32 objectiveIndex);

    UFUNCTION()
    void HandleRequestMissionCompleted(FName missionId);

    UFUNCTION()
    void HandleRequestMissionActivated(FName missionId);

    UFUNCTION()
    void HandleOnSetItem(APhysicalItem *Item);

    UFUNCTION()
    void HandleOnReleaseItem(APhysicalItem *Item);

public:
    UFUNCTION(BlueprintPure)
    EMissionItemRequestState GetRequestState();

    UFUNCTION(BlueprintPure)
    float GetCurrentConsumptionProgress();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityInitializeMissionRequests(const TArray<FName> &NewRequestMissionIDs);
};
