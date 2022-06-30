#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "HoverboardItem.generated.h"

class UPowerComponent;
class UHoverboardMovementOverrideComponent;
class AAstroCharacter;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AHoverboardItem : public APhysicalItem
{
    GENERATED_BODY()
public:
    UPROPERTY(Export)
    UPowerComponent *PowerComponent;

private:
    UPROPERTY(Export, VisibleAnywhere)
    UHoverboardMovementOverrideComponent *HoverboardMovementOverride;

    UPROPERTY(Transient)
    AAstroCharacter *AstroCharacter;

    UPROPERTY(EditDefaultsOnly)
    float DoubleJumpInputWindow;

    UPROPERTY(Replicated, SaveGame)
    FGuid Guid;

    UPROPERTY(ReplicatedUsing = OnRep_HoverboardActive)
    uint8 bHoverboardActive : 1;

public:
    AHoverboardItem();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION()
    void SelfAbortedOverride();

    UFUNCTION(BlueprintImplementableEvent)
    void OnUpdateHoverboardOrientation();

private:
    UFUNCTION()
    void OnRep_HoverboardActive();

    UFUNCTION()
    void OnMovementOverrideTick(float DeltaTime);

public:
    UFUNCTION()
    void OnJumpStarted();

private:
    UFUNCTION()
    void OnItemSelectionChanged(APhysicalItem *Item);

public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnHoverboardActivated(bool Activated);

private:
    UFUNCTION()
    void OnHasPowerAvailableChanged(bool HasAvailablePower);

    UFUNCTION()
    void OnEndOperation();

    UFUNCTION()
    void OnClientActionPressed();

    UFUNCTION()
    void OnAuthorityOverrideRemoved();

    UFUNCTION()
    void OnAuthorityOverrideAdded();

    UFUNCTION()
    void HandleRemovedFromSlot(bool NewOwner);

    UFUNCTION()
    void HandlePlacedInSlot();

    UFUNCTION()
    void HandleOnSpawnedInSlot();

public:
    UFUNCTION(BlueprintPure)
    bool GetHoverboardActive();

    UFUNCTION(BlueprintCallable)
    FRotator CalculateHoverboardRotation(float minVelocitySize, float maxPitchDegrees, float maxRollDegrees, float maxTurnDegrees, float &outRollDegree);
};
