#pragma once
#include "CoreMinimal.h"
#include "InteractionPromptEntryData.h"
#include "VehicleBase.h"
#include "OnLandedChangedDelegate.h"
#include "EControlsPromptStatus.h"
#include "UObject/NoExportTypes.h"
#include "LandingInfo.h"
#include "Engine/EngineBaseTypes.h"
#include "UObject/NoExportTypes.h"
#include "VtolItem.generated.h"

class UFlyingVtolMovementComponent;
class UFuelConsumerComponent;
class AAstroPlayerController;
class ASolarBody;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AVtolItem : public AVehicleBase
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    float CollisionMeshBottomOffset;

    UPROPERTY(EditDefaultsOnly)
    float CeilingCheckInterval;

    UPROPERTY(EditDefaultsOnly)
    float CeilingCheckHeight;

    UPROPERTY(EditDefaultsOnly)
    float AutoHoverHeight;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float LandingHeight;

    UPROPERTY(EditDefaultsOnly)
    float MaxLandingSlope;

    UPROPERTY(EditDefaultsOnly)
    bool bMaintainHover;

    UPROPERTY(EditDefaultsOnly)
    float VerticalSpeedScalar;

    UPROPERTY(EditDefaultsOnly)
    float IgnitionDuration;

    UPROPERTY(EditDefaultsOnly)
    float TakeOffRotationInterpolationSpeed;

    UPROPERTY(EditDefaultsOnly)
    float ControlsInterpRate;

    UPROPERTY(EditDefaultsOnly)
    float MinLandingSpeedScalar;

    UPROPERTY(EditDefaultsOnly)
    float LandingSpeedInterpolationPercent;

    UPROPERTY(EditDefaultsOnly)
    float DoubleTapInputWindow;

    UPROPERTY(EditDefaultsOnly)
    float DoubleTapHoldThreshold;

    UPROPERTY(EditDefaultsOnly)
    float ControlsPromptDisplayDuration;

    UPROPERTY(EditDefaultsOnly)
    float ControlsPromptOpenDelay;

    UPROPERTY(EditDefaultsOnly)
    FText DoubleTapActionText;

    UPROPERTY(EditDefaultsOnly)
    FInteractionPromptEntryData TakeOffActionPrompt;

    UPROPERTY(EditDefaultsOnly)
    FInteractionPromptEntryData LandActionPrompt;

    UPROPERTY(EditDefaultsOnly)
    FInteractionPromptEntryData AscendActionPrompt;

    UPROPERTY(EditDefaultsOnly)
    FInteractionPromptEntryData DescendActionPrompt;

    UPROPERTY(EditDefaultsOnly)
    float ThrusterWashUpdateInterval;

    UPROPERTY(EditDefaultsOnly)
    float MaxSpeedForHighAltitudeWash;

    UPROPERTY(Export, VisibleAnywhere)
    UFlyingVtolMovementComponent *MovementComponent;

    UPROPERTY(BlueprintReadWrite, Replicated, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    float CurrentForwardSpeedNormalized;

    UPROPERTY(BlueprintReadWrite, Replicated, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    float CurrentLateralSpeedNormalized;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_IsNearGround, meta = (AllowPrivateAccess = true))
    uint8 bIsNearGround : 1;

protected:
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UFuelConsumerComponent *FuelConsumerComponent;

    UPROPERTY(BlueprintAssignable)
    FOnLandedChanged OnLandedChanged;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_EnginesActivated, meta = (AllowPrivateAccess = true))
    uint8 bEnginesActive : 1;

private:
    UPROPERTY(ReplicatedUsing = OnRep_FuelAmount)
    float FuelAmount;

    UPROPERTY(SaveGame)
    uint8 bHasIgnition : 1;

    UPROPERTY(SaveGame)
    EControlsPromptStatus MovementControlsPromptStatus;

public:
    AVtolItem();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void UpdateWashEffectsState();

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateWashEffects(int32 effectSide, bool effectiveActive, const FVector &effectLocation);

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateLandingInRange(bool InRange, bool canLand);

    UFUNCTION()
    void TimeoutTooltipOverride();

    UFUNCTION()
    void SetRiseInputInactive();

    UFUNCTION()
    void SetRiseInputActive();

public:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSetNormalizedSpeeds(float Forward, float lateral);

protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerNotifyLandedChanged(bool bLanded);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerNearGroundChanged(bool bNearGround);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerEnginesActivated(bool bActivated, FLandingInfo LandingInfo);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerConsumeFuel(float Time);

public:
    UFUNCTION()
    void RouteAux2ToggleUse(AAstroPlayerController *Controller, EInputEvent eventType);

    UFUNCTION()
    void RouteAux1ToggleUse(AAstroPlayerController *Controller, EInputEvent eventType);

protected:
    UFUNCTION()
    void OnSlottedItemsChanged();

    UFUNCTION()
    void OnRep_IsNearGround(bool bPreviousValue);

    UFUNCTION()
    void OnRep_FuelAmount();

    UFUNCTION()
    void OnRep_EnginesActivated(bool bPreviousValue);

    UFUNCTION(BlueprintImplementableEvent)
    void OnNearGroundChanged(bool nearGround);

    UFUNCTION(BlueprintImplementableEvent)
    void OnIgnitionTurned(bool ignite);

    UFUNCTION(BlueprintImplementableEvent)
    void OnIgnitionPercentChanged(float percent);

    UFUNCTION(BlueprintImplementableEvent)
    void OnIgnitionFailed(bool hasFuel, bool onPlanet);

    UFUNCTION()
    void OnFuelRecipeAmountChanged(float Amount);

    UFUNCTION(BlueprintImplementableEvent)
    void OnFuelPercentChanged(float percent);

    UFUNCTION(BlueprintImplementableEvent)
    void OnEnginesActivated(bool Activated);

    UFUNCTION()
    void OnCreativeModeFreeFuelChanged(bool bFreeFuel);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastNotifyLandedChanged(bool bLanded);

    UFUNCTION(BlueprintPure)
    bool IsLocallyControlled() const;

    UFUNCTION()
    void HandleVehicleUnmanned(AAstroPlayerController *OldPilot);

    UFUNCTION()
    void HandleVehicleManned(AAstroPlayerController *NewPilot);

    UFUNCTION(BlueprintImplementableEvent)
    void GetThrusterTransform(int32 thrusterSide, FTransform &thrusterLocation);

public:
    UFUNCTION(BlueprintPure)
    ASolarBody *GetLocalSolarBody() const;
};
