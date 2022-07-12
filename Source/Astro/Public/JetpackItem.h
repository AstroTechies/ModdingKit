#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EPhysicalSurface -FallbackName=EPhysicalSurface
#include "PhysicalItem.h"
#include "ERemainingFuelState.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "JetpackItem.generated.h"

class ABackpack;
class UFuelConsumerComponent;
class UJetpackMovementOverrideComponent;
class AAstroCharacter;

UCLASS(Blueprintable)
class ASTRO_API AJetpackItem : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UFuelConsumerComponent* FuelConsumerComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
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
    AJetpackItem();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
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
    void OnItemSelectionChanged(APhysicalItem* Item);
    
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

