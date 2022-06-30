#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "Engine/NetSerialization.h"
#include "FlyingDroneMovementComponent.generated.h"

class UCameraComponent;
class UPrimitiveComponent;
class ADroneBase;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UFlyingDroneMovementComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector Velocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MaxAcceleration;

    UPROPERTY(EditAnywhere)
    float MinCreativeModeFlightSpeedScalar;

    UPROPERTY(EditAnywhere)
    float MaxCreativeModeFlightSpeedScalar;

    UPROPERTY(SaveGame)
    float CreativeModeFlightSpeedScalar;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DepenetrationStrength;

    UPROPERTY(Replicated)
    FVector_NetQuantizeNormal ClientMovementInputVector;

protected:
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, Export, meta = (AllowPrivateAccess = true))
    UPrimitiveComponent *UpdatedComponent;

    UPROPERTY()
    ADroneBase *DroneOwner;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RotationSpeed;

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
    UFlyingDroneMovementComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetCreativeModeFlightSpeedScalarNormalized(float NormalizedCreativeModeFlightSpeedScalar);

private:
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerUpdateClientMovementInputVector(FVector_NetQuantizeNormal ClientMovementInput);

public:
    UFUNCTION(BlueprintPure)
    float GetCreativeModeFlightSpeedScalarNormalized();
};
