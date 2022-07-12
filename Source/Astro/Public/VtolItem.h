#pragma once
#include "CoreMinimal.h"
#include "VehicleBase.h"
#include "InteractionPromptEntryData.h"
#include "EControlsPromptStatus.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "OnLandedChangedDelegate.h"
#include "LandingInfo.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EInputEvent -FallbackName=EInputEvent
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "VtolItem.generated.h"

class UFlyingVtolMovementComponent;
class UFuelConsumerComponent;
class ASolarBody;
class AAstroPlayerController;

UCLASS(Blueprintable)
class ASTRO_API AVtolItem : public AVehicleBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CollisionMeshBottomOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CeilingCheckInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CeilingCheckHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoHoverHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LandingHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxLandingSlope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMaintainHover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VerticalSpeedScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IgnitionDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TakeOffRotationInterpolationSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ControlsInterpRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinLandingSpeedScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LandingSpeedInterpolationPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DoubleTapInputWindow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DoubleTapHoldThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ControlsPromptDisplayDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ControlsPromptOpenDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DoubleTapActionText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInteractionPromptEntryData TakeOffActionPrompt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInteractionPromptEntryData LandActionPrompt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInteractionPromptEntryData AscendActionPrompt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInteractionPromptEntryData DescendActionPrompt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThrusterWashUpdateInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSpeedForHighAltitudeWash;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UFlyingVtolMovementComponent* MovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float CurrentForwardSpeedNormalized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float CurrentLateralSpeedNormalized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsNearGround, meta=(AllowPrivateAccess=true))
    uint8 bIsNearGround: 1;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UFuelConsumerComponent* FuelConsumerComponent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLandedChanged OnLandedChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_EnginesActivated, meta=(AllowPrivateAccess=true))
    uint8 bEnginesActive: 1;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_FuelAmount, meta=(AllowPrivateAccess=true))
    float FuelAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bHasIgnition: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EControlsPromptStatus MovementControlsPromptStatus;
    
public:
    AVtolItem();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION()
    void UpdateWashEffectsState();
    
    UFUNCTION(BlueprintImplementableEvent)
    void UpdateWashEffects(int32 effectSide, bool effectiveActive, const FVector& effectLocation);
    
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
    void RouteAux2ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> eventType);
    
    UFUNCTION()
    void RouteAux1ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> eventType);
    
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
    void HandleVehicleUnmanned(AAstroPlayerController* OldPilot);
    
    UFUNCTION()
    void HandleVehicleManned(AAstroPlayerController* NewPilot);
    
    UFUNCTION(BlueprintImplementableEvent)
    void GetThrusterTransform(int32 thrusterSide, FTransform& thrusterLocation);
    
public:
    UFUNCTION(BlueprintPure)
    ASolarBody* GetLocalSolarBody() const;
    
};

