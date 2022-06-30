#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "EAirControlSecondaryType.h"
#include "ERoverID.h"
#include "PhysicsMovementReplicatedInput.h"
#include "UObject/NoExportTypes.h"
#include "PhysicsMovementComponent.generated.h"

class USceneComponent;
class UStorageChassisComponent;
class APlayerController;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UPhysicsMovementComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FResistanceChangeEvent, int32, REP_ResistanceLevel);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FParkingBrakeEvent, bool, ParkingBrakeEngaged);

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MaxSteerAngle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RotationForce;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float HeadingStabilization;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SteeringInterpolationSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SteeringCorrectionResetThresholdAngle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float CrossFriction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MinMovementStrength;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MovementStrength;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool Upright;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MaxSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float BrakingForceScalar;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RotationDrag;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ForceOffset;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float Groundedness;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector SteeringDirection;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector SteeredWheelsDirection;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *ForceLocation;

    UPROPERTY(EditAnywhere)
    FVector ForceLocationRelative;

    UPROPERTY(EditAnywhere)
    FVector ForceLocationReverseRelative;

    UPROPERTY(EditAnywhere)
    float ReverseThreshold;

    UPROPERTY(EditAnywhere)
    float ResistanceHillBoost;

    UPROPERTY(EditAnywhere)
    float TowBoostViaSlot;

    UPROPERTY(EditAnywhere)
    int32 MaxBoostedTowCount;

    UPROPERTY(EditDefaultsOnly)
    float OverallFrictionForceScalar;

    UPROPERTY(EditDefaultsOnly)
    float ParkingBreakVelocityThreshold;

    UPROPERTY(EditDefaultsOnly)
    float MinResistanceDampner;

    UPROPERTY(EditDefaultsOnly)
    float MaxResistanceDampner;

    UPROPERTY(EditDefaultsOnly)
    int32 MaxResistanceLevel;

    UPROPERTY(EditDefaultsOnly)
    float MaxSpeedSteeringAngleScalar;

    UPROPERTY(EditDefaultsOnly)
    float DrillingSteerAngleReduction;

    UPROPERTY(EditDefaultsOnly)
    float MinimumSpeedForAnyAirControl;

    UPROPERTY(EditDefaultsOnly)
    float MaximumSpeedForFullAutoStabilization;

    UPROPERTY(EditDefaultsOnly)
    float MaximumGroundednessForAnyAirControl;

    UPROPERTY(EditDefaultsOnly)
    float MinimumGroundednessForFullAutoStabilization;

    UPROPERTY(EditDefaultsOnly)
    float MinimumGravityAlignmentAngleAnyAutoStabilization;

    UPROPERTY(EditDefaultsOnly)
    float MaximumGravityAlignmentAngleForFullAutoStabilization;

    UPROPERTY(EditDefaultsOnly)
    float AutoStabilizationInterpolationRate;

    UPROPERTY(EditDefaultsOnly)
    float PrimaryManualAirControlRate;

    UPROPERTY(EditDefaultsOnly)
    float SecondaryManualAirControlRate;

    UPROPERTY(EditDefaultsOnly)
    float ManualAirControlInterpolationRate;

    UPROPERTY(EditDefaultsOnly)
    EAirControlSecondaryType ManualAirControlSecondaryType;

    UPROPERTY(EditAnywhere)
    ERoverID RoverTierForTelemetry;

    UPROPERTY(Export)
    UStorageChassisComponent *StorageComponent;

    UPROPERTY(BlueprintAssignable)
    FParkingBrakeEvent OnParkingBrakeChanged;

    UPROPERTY(BlueprintAssignable)
    FParkingBrakeEvent OnBrakesChanged;

    UPROPERTY(BlueprintAssignable)
    FResistanceChangeEvent OnResistanceLevelChanged;

private:
    UPROPERTY(Replicated)
    FPhysicsMovementReplicatedInput ReplicatedInput;

    UPROPERTY(Transient)
    APlayerController *CurrentOperatingController;

    UPROPERTY(ReplicatedUsing = ApplyResistanceLevel)
    int32 REP_ResistanceLevel;

public:
    UPhysicsMovementComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

private:
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerUpdateClientMovementInput(FPhysicsMovementReplicatedInput ClientSteeringInput);

public:
    UFUNCTION(BlueprintCallable)
    void Move(APlayerController *Controller, const FVector2D &Value, float Multiplier);

    UFUNCTION()
    void ApplyResistanceLevel();
};
