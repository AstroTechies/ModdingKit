#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "Components/ActorComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "RepWheeledChassisMovement.h"
#include "SignalDelegate.h"
#include "VehicleFacingSetDelegate.h"
#include "WheelInfo.h"
#include "WheeledChassisComponent.generated.h"

class AActor;
class APhysicalItem;
class UActivation;
class UAstroSaveCustomArchiveProxy;
class UComponentDelegateWrapper;
class UControlledVehicleMovement;
class UParticleSystemComponent;
class UPhysicsConstraintComponent;
class UPhysicsMovementComponent;
class USceneComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UWheeledChassisComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxNetworkPositionErrorSquared;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UprightFlipSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpringStiffness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpringDamping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PhysicsSleepSpeedThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PhysicsSleepDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* MyActivation;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnImpact;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnLand;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVehicleFacingSet OnVehicleFacingSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Groundedness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnyGroundedness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> GroundednessByWheel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> ContactByWheel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> ImpactNormalByWheel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImpactThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LateralWheelFriction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDepenetrationVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CenterOfMassAdjustment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APhysicalItem*> WheelOwners;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> WheelColliders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USceneComponent*> WheelAttachParents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USceneComponent*> WheelOrigins;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UPhysicsConstraintComponent*> WheelConstraints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UComponentDelegateWrapper*> WheelHitDelegates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<bool> WheelIsSkidding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LinkedWheelCount;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Movement, meta=(AllowPrivateAccess=true))
    FRepWheeledChassisMovement ReplicatedChassisMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* ItemOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UControlledVehicleMovement* ControlledMovementCompt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhysicsMovementComponent* PhysicsMovementComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Throttle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsFlippingUpright, meta=(AllowPrivateAccess=true))
    uint8 REP_bIsFlippingUpright: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_UprightFlipComplete, meta=(AllowPrivateAccess=true))
    uint8 REP_bUprightFlipComplete: 1;
    
public:
    UWheeledChassisComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void WakePhysics();
    
    UFUNCTION(BlueprintCallable)
    void UpdateVehicleEffects(TArray<UParticleSystemComponent*> wheelBlows, TArray<FName> AudioSurfaceTypes);
    
    UFUNCTION(BlueprintCallable)
    void SleepPhysics(bool sleepAllConnectedVehicles);
    
    UFUNCTION(BlueprintCallable)
    void SetThrottle(const FVector& Direction);
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUpdateUprightFlipComplete(bool bReceivedUprightFlipComplete);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUpdateIsFlippingUpright(bool bReceivedIsFlippingUpright);
    
    UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation)
    void ServerUpdateClientMotionState(FRepWheeledChassisMovement Movement);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
public:
    UFUNCTION(BlueprintCallable)
    void Reset();
    
    UFUNCTION(BlueprintCallable)
    void OnWheelHit(USceneComponent* Component, const FVector& Normal, const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable)
    void OnWakePhysics();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_UprightFlipComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Movement();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_IsFlippingUpright();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityInitiateUprightFlip(bool initiateFlipOnAllConnectedVehicles);
    
    UFUNCTION(BlueprintCallable)
    void AddWheelCollider(APhysicalItem* WheelItem, UStaticMeshComponent* WheelCollider, const FWheelInfo& WheelInfo, bool bUseLinearMotors);
    
};

