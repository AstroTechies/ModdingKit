#pragma once
#include "CoreMinimal.h"
#include "VehicleFacingSetDelegate.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "UObject/NoExportTypes.h"
#include "RepWheeledChassisMovement.h"
#include "Engine/EngineTypes.h"
#include "WheelInfo.h"
#include "WheeledChassisComponent.generated.h"

class UActivation;
class UStaticMeshComponent;
class APhysicalItem;
class USceneComponent;
class UPhysicsConstraintComponent;
class UComponentDelegateWrapper;
class UControlledVehicleMovement;
class UPhysicsMovementComponent;
class UParticleSystemComponent;
class UAstroSaveCustomArchiveProxy;
class AActor;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UWheeledChassisComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float MaxNetworkPositionErrorSquared;

    UPROPERTY(EditDefaultsOnly)
    float UprightFlipSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SpringStiffness;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SpringDamping;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float PhysicsSleepSpeedThreshold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float PhysicsSleepDelay;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UActivation *MyActivation;

    UPROPERTY(BlueprintAssignable)
    FSignal OnImpact;

    UPROPERTY(BlueprintAssignable)
    FSignal OnLand;

    UPROPERTY(BlueprintAssignable)
    FVehicleFacingSet OnVehicleFacingSet;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float Groundedness;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float AnyGroundedness;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<float> GroundednessByWheel;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FVector> ContactByWheel;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FVector> ImpactNormalByWheel;

    UPROPERTY(EditAnywhere)
    float ImpactThreshold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LateralWheelFriction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MaxDepenetrationVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float CenterOfMassAdjustment;

    UPROPERTY()
    TArray<APhysicalItem *> WheelOwners;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    TArray<UStaticMeshComponent *> WheelColliders;

    UPROPERTY(Export)
    TArray<USceneComponent *> WheelAttachParents;

    UPROPERTY(Export)
    TArray<USceneComponent *> WheelOrigins;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    TArray<UPhysicsConstraintComponent *> WheelConstraints;

    UPROPERTY()
    TArray<UComponentDelegateWrapper *> WheelHitDelegates;

    UPROPERTY()
    TArray<bool> WheelIsSkidding;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 LinkedWheelCount;

private:
    UPROPERTY(Transient, ReplicatedUsing = OnRep_Movement)
    FRepWheeledChassisMovement ReplicatedChassisMovement;

    UPROPERTY()
    APhysicalItem *ItemOwner;

    UPROPERTY(Export)
    UControlledVehicleMovement *ControlledMovementCompt;

    UPROPERTY(Export)
    UPhysicsMovementComponent *PhysicsMovementComp;

    UPROPERTY()
    FVector Throttle;

    UPROPERTY(Transient, ReplicatedUsing = OnRep_IsFlippingUpright)
    uint8 REP_bIsFlippingUpright : 1;

    UPROPERTY(Transient, ReplicatedUsing = OnRep_UprightFlipComplete)
    uint8 REP_bUprightFlipComplete : 1;

public:
    UWheeledChassisComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION()
    void WakePhysics();

    UFUNCTION(BlueprintCallable)
    void UpdateVehicleEffects(TArray<UParticleSystemComponent *> wheelBlows, TArray<FName> AudioSurfaceTypes);

    UFUNCTION()
    void SleepPhysics(bool sleepAllConnectedVehicles);

    UFUNCTION()
    void SetThrottle(const FVector &Direction);

private:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerUpdateUprightFlipComplete(bool bReceivedUprightFlipComplete);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerUpdateIsFlippingUpright(bool bReceivedIsFlippingUpright);

    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerUpdateClientMotionState(FRepWheeledChassisMovement Movement);

protected:
    UFUNCTION()
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy *proxy);

public:
    UFUNCTION(BlueprintCallable)
    void Reset();

    UFUNCTION()
    void OnWheelHit(USceneComponent *Component, const FVector &Normal, const FHitResult &Hit);

    UFUNCTION()
    void OnWakePhysics();

private:
    UFUNCTION()
    void OnRep_UprightFlipComplete();

    UFUNCTION()
    void OnRep_Movement();

    UFUNCTION()
    void OnRep_IsFlippingUpright();

public:
    UFUNCTION()
    void OnActorHit(AActor *SelfActor, AActor *OtherActor, FVector NormalImpulse, const FHitResult &Hit);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityInitiateUprightFlip(bool initiateFlipOnAllConnectedVehicles);

    UFUNCTION(BlueprintCallable)
    void AddWheelCollider(APhysicalItem *WheelItem, UStaticMeshComponent *WheelCollider, const FWheelInfo &WheelInfo, bool bUseLinearMotors);
};
