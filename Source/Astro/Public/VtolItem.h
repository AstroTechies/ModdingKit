#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EInputEvent -FallbackName=EInputEvent
#include "EControlsPromptStatus.h"
#include "InteractionPromptEntryData.h"
#include "LandingInfo.h"
#include "OnLandedChangedDelegate.h"
#include "VehicleBase.h"
#include "VtolItem.generated.h"

class AAstroPlayerController;
class ASolarBody;
class UFlyingVtolMovementComponent;
class UFuelConsumerComponent;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFlyingVtolMovementComponent* MovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float CurrentForwardSpeedNormalized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float CurrentLateralSpeedNormalized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsNearGround, meta=(AllowPrivateAccess=true))
    uint8 bIsNearGround: 1;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
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
    UFUNCTION(BlueprintCallable)
    void UpdateWashEffectsState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateWashEffects(int32 effectSide, bool effectiveActive, const FVector& effectLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateLandingInRange(bool InRange, bool canLand);
    
    UFUNCTION(BlueprintCallable)
    void TimeoutTooltipOverride();
    
    UFUNCTION(BlueprintCallable)
    void SetRiseInputInactive();
    
    UFUNCTION(BlueprintCallable)
    void SetRiseInputActive();
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetNormalizedSpeeds(float Forward, float lateral);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerNotifyLandedChanged(bool bLanded);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerNearGroundChanged(bool bNearGround);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerEnginesActivated(bool bActivated, FLandingInfo LandingInfo);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerConsumeFuel(float Time);
    
public:
    UFUNCTION(BlueprintCallable)
    void RouteAux2ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> eventType);
    
    UFUNCTION(BlueprintCallable)
    void RouteAux1ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> eventType);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSlottedItemsChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_IsNearGround(bool bPreviousValue);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_FuelAmount();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_EnginesActivated(bool bPreviousValue);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNearGroundChanged(bool nearGround);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnIgnitionTurned(bool ignite);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnIgnitionPercentChanged(float percent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnIgnitionFailed(bool hasFuel, bool onPlanet);
    
    UFUNCTION(BlueprintCallable)
    void OnFuelRecipeAmountChanged(float Amount);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFuelPercentChanged(float percent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnginesActivated(bool Activated);
    
    UFUNCTION(BlueprintCallable)
    void OnCreativeModeFreeFuelChanged(bool bFreeFuel);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastNotifyLandedChanged(bool bLanded);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocallyControlled() const;
    
    UFUNCTION(BlueprintCallable)
    void HandleVehicleUnmanned(AAstroPlayerController* OldPilot);
    
    UFUNCTION(BlueprintCallable)
    void HandleVehicleManned(AAstroPlayerController* NewPilot);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetThrusterTransform(int32 thrusterSide, FTransform& thrusterLocation);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASolarBody* GetLocalSolarBody() const;
    
};

