// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FlyingVtolMovementComponent.generated.h"

class UPrimitiveComponent;
class UCameraComponent;
class APhysicalItem;

UCLASS(EditInlineNew, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASTRO_API UFlyingVtolMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) void SetControllingCamera(UCameraComponent* controllingCamera);
	UFUNCTION(BlueprintCallable) void SetFlightSpeedScalarNormalized(float normalizedFlightSpeedScalar);
	UFUNCTION(BlueprintCallable, BlueprintPure) float GetFlightSpeedScalarNormalized();

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector Velocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float MaxAcceleration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float MinFlightSpeedScalar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float MaxFlightSpeedScalar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float FullSpeedPercent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CruisingModeFullSpeedStartTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CruisingModeFullSpeedEndTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CruisingModeAirBrakeTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float NearGroundAirBrakeDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float DepenetrationStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UPrimitiveComponent* UpdatedComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) APhysicalItem* VTOLOwner;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float RotationSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CruisingModeRotationSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float RotationSpeedLerpRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float GravitySourceInterpolationTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector CurrentGravity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector LastControlInputVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector ControlInputVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UCameraComponent* PlayerCamera;
};