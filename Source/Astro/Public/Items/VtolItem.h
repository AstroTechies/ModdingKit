// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/ActivationSignals.h"
#include "Items/FuelConsumerComponent.h"
#include "Movement/FlyingVtolMovementComponent.h"
#include "Vehicles/VehicleBase.h"
#include "VtolItem.generated.h"

UCLASS(BlueprintType)
class ASTRO_API AVtolItem : public AVehicleBase
{
	GENERATED_BODY()

public:
	AVtolItem();

public:
	UFUNCTION(BlueprintCallable) void RouteAux1ToggleUse(AAstroPlayerController* controller, EInputEvent eventType);
	UFUNCTION(BlueprintCallable) void RouteAux2ToggleUse(AAstroPlayerController* controller, EInputEvent eventType);
	UFUNCTION(BlueprintCallable, BlueprintPure) ASolarBody* GetLocalSolarBody();
	UFUNCTION(BlueprintCallable) void SetRiseInputActive();
	UFUNCTION(BlueprintCallable) void SetRiseInputInactive();
	UFUNCTION(BlueprintCallable, BlueprintPure) bool IsLocallyControlled();
	UFUNCTION(BlueprintCallable) void HandleVehicleManned(AAstroPlayerController* NewPilot);
	UFUNCTION(BlueprintCallable) void HandleVehicleUnmanned(AAstroPlayerController* OldPilot);
	UFUNCTION(BlueprintCallable) void OnSlottedItemsChanged();
	UFUNCTION(BlueprintCallable) void OnFuelRecipeAmountChanged(float amount);
	UFUNCTION(BlueprintCallable) void OnCreativeModeFreeFuelChanged(bool bFreeFuel);
	UFUNCTION(BlueprintCallable) void MulticastNotifyLandedChanged(bool bLanded);
	UFUNCTION(BlueprintCallable) void TimeoutTooltipOverride();
	UFUNCTION(BlueprintCallable) void UpdateWashEffectsState();

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite) UFlyingVtolMovementComponent* MovementComponent;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite) UFuelConsumerComponent* FuelConsumerComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable) FOnLandedChanged OnLandedChanged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CollisionMeshBottomOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CeilingCheckInterval;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CeilingCheckHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float AutoHoverHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float LandingHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float MaxLandingSlope;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bMaintainHover;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float VerticalSpeedScalar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float IgnitionDuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float TakeOffRotationInterpolationSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float ControlsInterpRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float MinLandingSpeedScalar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float LandingSpeedInterpolationPercent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float DoubleTapInputWindow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float DoubleTapHoldThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float ControlsPromptDisplayDuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float ControlsPromptOpenDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FText DoubleTapActionText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float ThrusterWashUpdateInterval;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float MaxSpeedForHighAltitudeWash;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CurrentForwardSpeedNormalized;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CurrentLateralSpeedNormalized;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float FuelAmount;
};
