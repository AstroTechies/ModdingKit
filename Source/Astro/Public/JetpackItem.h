#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Chaos/ChaosEngineInterface.h"
#include "ERemainingFuelState.h"
#include "PhysicalItem.h"
#include "Templates/SubclassOf.h"
#include "JetpackItem.generated.h"

class AAstroCharacter;
class ABackpack;
class UFuelConsumerComponent;
class UItemType;
class UJetpackMovementOverrideComponent;

UCLASS(Blueprintable)
class ASTRO_API AJetpackItem : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFuelConsumerComponent* FuelConsumerComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UJetpackMovementOverrideComponent* JetpackMovementOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAstroCharacter* AstroCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ABackpack* Backpack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_NozzleDirection, meta=(AllowPrivateAccess=true))
    FVector NozzleDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_FuelPortionAmount, meta=(AllowPrivateAccess=true))
    float FuelPortionAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float JumpActivationTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    FGuid Guid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_RemainingFuelState, meta=(AllowPrivateAccess=true))
    ERemainingFuelState RemainingFuelStateReplicated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_JetpackActive, meta=(AllowPrivateAccess=true))
    uint8 bJetpackActive: 1;
    
public:
    AJetpackItem(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable)
    void SendStateTelemetry();
    
    UFUNCTION(BlueprintCallable)
    void SendPostRateLimitTelemetry();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUpdateNozzleDirection(FVector NewNozzleDirection);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSlottedItemsChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_RemainingFuelState();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_NozzleDirection();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_JetpackActive();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_FuelPortionAmount();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPortionDepleted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPortionChanged(float portionUsed);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnMovementOverrideTick(float DeltaTime);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnLanded(TEnumAsByte<EPhysicalSurface> GroundSurface);
    
    UFUNCTION(BlueprintCallable)
    void OnJumpStopped();
    
    UFUNCTION(BlueprintCallable)
    void OnJumpStarted();
    
    UFUNCTION(BlueprintCallable)
    void OnJumpingTick(float DeltaTime);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnJetpackStowed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnJetpackDeployed(FVector NeutralPosition, bool bMirrored);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnJetpackActived(bool Activated);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnItemSelectionChanged(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnItemDrained(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    void OnFuelRecipeAmountChanged(float Amount);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFuelIsLow(bool bIsLow);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnEndOperation();
    
    UFUNCTION(BlueprintCallable)
    void OnCreativeFreeFuelChanged(bool State);
    
    UFUNCTION(BlueprintCallable)
    void OnClientActionReleased();
    
    UFUNCTION(BlueprintCallable)
    void OnClientActionPressed();
    
    UFUNCTION(BlueprintCallable)
    void OnBackpackCracked();
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityOverrideRemoved();
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityOverrideAdded();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAttemptedActivationNoFuel();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAllFuelDepleted();
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleRemovedFromSlot(bool NewOwner);
    
    UFUNCTION(BlueprintCallable)
    void HandlePlacedInSlot();
    
    UFUNCTION(BlueprintCallable)
    void HandleOnSpawnedInSlot();
    
    UFUNCTION(BlueprintCallable)
    void HandleFullyEmplaced();
    
};

