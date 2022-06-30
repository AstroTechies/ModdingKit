#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "Engine/NetSerialization.h"
#include "FlyingVtolMovementComponent.generated.h"

class UCameraComponent;
class APhysicalItem;
class UPrimitiveComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UFlyingVtolMovementComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector Velocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MaxAcceleration;

    UPROPERTY(EditAnywhere)
    float MinFlightSpeedScalar;

    UPROPERTY(EditAnywhere)
    float MaxFlightSpeedScalar;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float FullSpeedPercent;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float CruisingModeFullSpeedStartTime;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float CruisingModeFullSpeedEndTime;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float CruisingModeAirBrakeTime;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float NearGroundAirBrakeDelay;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DepenetrationStrength;

    UPROPERTY(Replicated)
    FVector_NetQuantizeNormal ClientMovementInputVector;

protected:
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, Export, meta = (AllowPrivateAccess = true))
    UPrimitiveComponent *UpdatedComponent;

    UPROPERTY()
    APhysicalItem *VTOLOwner;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RotationSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float CruisingModeRotationSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RotationSpeedLerpRate;

private:
    UPROPERTY(EditDefaultsOnly)
    float GravitySourceInterpolationTime;

    UPROPERTY()
    FVector CurrentGravity;

    UPROPERTY(Transient)
    FVector LastControlInputVector;

    UPROPERTY(Transient)
    FVector ControlInputVector;

    UPROPERTY(Export)
    UCameraComponent *PlayerCamera;

public:
    UFlyingVtolMovementComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetFlightSpeedScalarNormalized(float normalizedFlightSpeedScalar);

    UFUNCTION(BlueprintCallable)
    void SetControllingCamera(UCameraComponent *controllingCamera);

private:
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerUpdateClientMovementInputVector(FVector_NetQuantizeNormal ClientMovementInput);

public:
    UFUNCTION(BlueprintPure)
    float GetFlightSpeedScalarNormalized();
};
