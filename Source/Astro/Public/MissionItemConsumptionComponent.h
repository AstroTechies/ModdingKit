#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EMissionItemRequestState.h"
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "SlotReference.h"
#include "RequestMissionList.h"
#include "AstroMissionObjectiveProgress.h"
#include "MissionItemConsumptionComponent.generated.h"

class UDynamicWhitelistOrganizationRule;
class UItemType;
class APhysicalItem;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UMissionItemConsumptionComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ConsumptionSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConsumptionRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConsumptionSlotEjectionForce;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnRequestsStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnConsumptionProgressChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSlotReference ConsumptionSlotRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDynamicWhitelistOrganizationRule* ConsumptionSlotOrganizationRule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FName> requestMissionIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UItemType>, FRequestMissionList> ActiveMissionRequests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_RequestsState, meta=(AllowPrivateAccess=true))
    EMissionItemRequestState RequestState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ConsumptionProgress, meta=(AllowPrivateAccess=true))
    float ConsumptionProgress;
    
public:
    UMissionItemConsumptionComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
private:
    UFUNCTION()
    void OnRep_RequestsState(EMissionItemRequestState prevState);
    
    UFUNCTION()
    void OnRep_ConsumptionProgress(float prevProgress);
    
    UFUNCTION()
    void InitializeMissionRequests_Internal();
    
    UFUNCTION()
    void HandleRequestObjectiveUpdated(FName missionId, const FAstroMissionObjectiveProgress& objectiveProgress, int32 objectiveIndex);
    
    UFUNCTION()
    void HandleRequestMissionCompleted(FName missionId);
    
    UFUNCTION()
    void HandleRequestMissionActivated(FName missionId);
    
    UFUNCTION()
    void HandleOnSetItem(APhysicalItem* Item);
    
    UFUNCTION()
    void HandleOnReleaseItem(APhysicalItem* Item);
    
public:
    UFUNCTION(BlueprintPure)
    EMissionItemRequestState GetRequestState();
    
    UFUNCTION(BlueprintPure)
    float GetCurrentConsumptionProgress();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityInitializeMissionRequests(const TArray<FName>& NewRequestMissionIDs);
    
};

