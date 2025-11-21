#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ELogisticsComplexChannel.h"
#include "EPlanetIdentifier.h"
#include "EShuttleAutomationRule.h"
#include "EShuttleSequenceState.h"
#include "EShuttleSlotOrgRule.h"
#include "SignalDelegate.h"
#include "ShuttleAutomationComponent.generated.h"

class APhysicalItem;
class UStorageChassisComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UShuttleAutomationComponent : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsAutomatedShuttle: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsShuttleLost: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EPlanetIdentifier DestinationPlanetID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ELogisticsComplexChannel DestinationPadChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EShuttleSequenceState ShuttleSequenceState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EShuttleAutomationRule ShuttleAutomationRule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EShuttleSlotOrgRule ShuttleSlotOrgRule;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnLostShuttleRecalled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LaunchShuttleTimerDelay;
    
public:
    UShuttleAutomationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetShuttleSlotOrgRule(const EShuttleSlotOrgRule InAutomationRule);
    
    UFUNCTION(BlueprintCallable)
    void SetIsAutomatedShuttle(const bool bInIsAutomatedShuttle);
    
    UFUNCTION(BlueprintCallable)
    void SetDestination(const EPlanetIdentifier inPlanetId, const ELogisticsComplexChannel InPadChannel);
    
    UFUNCTION(BlueprintCallable)
    void SetAutomationRule(const EShuttleAutomationRule InAutomationRule);
    
    UFUNCTION(BlueprintCallable)
    void OnShuttleUnslotted();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnShuttleArrivedAtDestination();
    
    UFUNCTION(BlueprintCallable)
    void OnReleaseItem(APhysicalItem* inItem);
    
public:
    UFUNCTION(BlueprintCallable)
    void MarkShuttleLost();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EShuttleSlotOrgRule GetShuttleSlotOrgRule() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EShuttleAutomationRule GetShuttleAutomationRule() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsShuttleLost() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsAutomatedShuttle() const;
    
    UFUNCTION(BlueprintCallable)
    void BeginAutomationSequence();
    
    UFUNCTION(BlueprintCallable)
    void AuthoritySetParentStorageChassisOverride(UStorageChassisComponent* InParentStorageChassisComponent, const bool bInCanNest);
    
};

