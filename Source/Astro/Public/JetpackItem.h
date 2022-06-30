#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ERemainingFuelState.h"
#include "Engine/EngineTypes.h"
#include "JetpackItem.generated.h"

class UJetpackMovementOverrideComponent;
class ABackpack;
class UFuelConsumerComponent;
class AAstroCharacter;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AJetpackItem : public APhysicalItem
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UFuelConsumerComponent *FuelConsumerComponent;

private:
    UPROPERTY(Export, VisibleAnywhere)
    UJetpackMovementOverrideComponent *JetpackMovementOverride;

    UPROPERTY(Transient)
    AAstroCharacter *AstroCharacter;

    UPROPERTY(Transient)
    ABackpack *Backpack;

    UPROPERTY(ReplicatedUsing = OnRep_NozzleDirection)
    FVector NozzleDirection;

    UPROPERTY(ReplicatedUsing = OnRep_FuelPortionAmount)
    float FuelPortionAmount;

    UPROPERTY(EditDefaultsOnly)
    float JumpActivationTime;

    UPROPERTY(Replicated, SaveGame)
    FGuid Guid;

    UPROPERTY(ReplicatedUsing = OnRep_RemainingFuelState)
    ERemainingFuelState RemainingFuelStateReplicated;

    UPROPERTY(ReplicatedUsing = OnRep_JetpackActive)
    uint8 bJetpackActive : 1;

public:
    AJetpackItem();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

private:
    UFUNCTION()
    void SendStateTelemetry();

    UFUNCTION()
    void SendPostRateLimitTelemetry();

public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnUpdateNozzleDirection(FVector NewNozzleDirection);

private:
    UFUNCTION()
    void OnSlottedItemsChanged();

    UFUNCTION()
    void OnRep_RemainingFuelState();

    UFUNCTION()
    void OnRep_NozzleDirection();

    UFUNCTION()
    void OnRep_JetpackActive();

    UFUNCTION()
    void OnRep_FuelPortionAmount();

public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnPortionDepleted();

    UFUNCTION(BlueprintImplementableEvent)
    void OnPortionChanged(float portionUsed);

private:
    UFUNCTION()
    void OnMovementOverrideTick(float DeltaTime);

public:
    UFUNCTION()
    void OnLanded(TEnumAsByte<EPhysicalSurface> GroundSurface);

    UFUNCTION()
    void OnJumpStopped();

    UFUNCTION()
    void OnJumpStarted();

    UFUNCTION()
    void OnJumpingTick(float DeltaTime);

    UFUNCTION(BlueprintImplementableEvent)
    void OnJetpackStowed();

    UFUNCTION(BlueprintImplementableEvent)
    void OnJetpackDeployed(FVector NeutralPosition, bool bMirrored);

    UFUNCTION(BlueprintImplementableEvent)
    void OnJetpackActived(bool Activated);

private:
    UFUNCTION()
    void OnItemSelectionChanged(APhysicalItem *Item);

    UFUNCTION()
    void OnItemDrained();

    UFUNCTION()
    void OnFuelRecipeAmountChanged(float Amount);

public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnFuelIsLow(bool bIsLow);

private:
    UFUNCTION()
    void OnEndOperation();

    UFUNCTION()
    void OnCreativeFreeFuelChanged(bool State);

    UFUNCTION()
    void OnClientActionReleased();

    UFUNCTION()
    void OnClientActionPressed();

    UFUNCTION()
    void OnBackpackCracked();

    UFUNCTION()
    void OnAuthorityOverrideRemoved();

    UFUNCTION()
    void OnAuthorityOverrideAdded();

public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnAttemptedActivationNoFuel();

    UFUNCTION(BlueprintImplementableEvent)
    void OnAllFuelDepleted();

private:
    UFUNCTION()
    void HandleRemovedFromSlot(bool NewOwner);

    UFUNCTION()
    void HandlePlacedInSlot();

    UFUNCTION()
    void HandleOnSpawnedInSlot();

    UFUNCTION()
    void HandleFullyEmplaced();
};
