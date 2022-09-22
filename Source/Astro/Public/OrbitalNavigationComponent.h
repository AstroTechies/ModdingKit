#pragma once
#include "CoreMinimal.h"
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "UpdateCanLaunchSignalDelegate.h"
#include "ReplicatedOrbitalTimeData.h"
#include "OrbitalReplicatedData.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "OrbitalNavigationComponent.generated.h"

class UObject;
class UStorageChassisComponent;
class ASolarBody;
class AActor;
class AAstroPlayerController;
class UOrbitalNavigationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UOrbitalNavigationComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bPreventRespawnWhileDriving: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LaunchLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultOrbitSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinOrbitSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxOrbitSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OrbitSpeedRangeStep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OrbitSpeedTransitionRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OrbitSpeedInputRepeatDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform LandingOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseLaunchUpVector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OrbitDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EasePower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LerpPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_ReplicatedData, meta=(AllowPrivateAccess=true))
    FOrbitalReplicatedData ReplicatedData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool PhysicsDisabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* SelectedTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector MajorForceVector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LaunchTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool planetSelection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool shouldLaunchUpdate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnLaunchEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnLaunch;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUpdateCanLaunchSignal OnUpdateCanLaunch;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnOrbitSpeedChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SourceTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStorageChassisComponent* storage;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPlanetSelectionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal HandleLandBeginHover;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal HandleLandEndHover;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CurrOrbitGameSpeedScalarDegree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_TargetOrbitSpeedScalarDegree, meta=(AllowPrivateAccess=true))
    float REP_TargetOrbitGameSpeedScalarDegree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Local_TargetOrbitGameSpeedScalarDegree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float DefaultOrbitSpeedScalarDegree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterplanetaryTravelRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ReplicatedTimeData, meta=(AllowPrivateAccess=true))
    FReplicatedOrbitalTimeData TimeData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOrbitalReplicatedData LastData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASolarBody* SourceSolarBody;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float TimeSinceLastOrbitSpeedChange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 CurrOrbitSpeedInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 DiscreteOrbitSpeedInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 AxisOrbitSpeedInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float MaxOrbitSpeedScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float MinOrbitSpeedScalar;
    
public:
    UOrbitalNavigationComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SetPlanetSelection(bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void SetActiveLaunchLength(float newLaunchLength);
    
protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSetOrbitSpeedScalarDegree(float speedScalarDegree);
    
public:
    UFUNCTION(BlueprintCallable)
    void PerformLaunch(UObject* Target);
    
    UFUNCTION()
    void OnStorageAttachmentsChanged(bool Entered);
    
    UFUNCTION()
    void OnSolarBodyClick(ASolarBody* SolarBody);
    
protected:
    UFUNCTION()
    void OnRep_TargetOrbitSpeedScalarDegree();
    
    UFUNCTION()
    void OnRep_ReplicatedTimeData();
    
    UFUNCTION()
    void OnRep_ReplicatedData();
    
    UFUNCTION()
    void OnOrbitSpeedInputUpOrDown(float AxisValue);
    
    UFUNCTION()
    void OnOrbitSpeedInputUp();
    
    UFUNCTION()
    void OnOrbitSpeedInputEnd();
    
    UFUNCTION()
    void OnOrbitSpeedInputDown();
    
public:
    UFUNCTION()
    void OnLandEndHover();
    
    UFUNCTION()
    void OnLandClick(AActor* Actor);
    
    UFUNCTION()
    void OnLandBeginHover();
    
    UFUNCTION(BlueprintPure)
    bool LocalPlayerOnBoard();
    
protected:
    UFUNCTION()
    void HandleVehicleUnmanned(AAstroPlayerController* VehicleDriver);
    
    UFUNCTION()
    void HandleVehicleManned(AAstroPlayerController* VehicleDriver);
    
public:
    UFUNCTION(BlueprintPure)
    ASolarBody* GetTargetOrbitingBody();
    
    UFUNCTION(BlueprintPure)
    float GetOrbitSpeedPercent();
    
    UFUNCTION(BlueprintPure)
    float GetLaunchTime();
    
    UFUNCTION(BlueprintPure)
    bool GetLaunched();
    
    UFUNCTION(BlueprintPure)
    bool GetLanding();
    
    UFUNCTION(BlueprintPure)
    bool GetLanded();
    
    UFUNCTION(BlueprintPure)
    bool GetIsInOrbit();
    
    UFUNCTION(BlueprintPure)
    bool GetCanLaunch();
    
    UFUNCTION(BlueprintPure)
    FVector GetCameraUpVector();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySnapToTarget(UObject* Target);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetInterplanetaryTravelRangeMultiplier(float rangeMultiplier);
    
    UFUNCTION(BlueprintPure)
    static UOrbitalNavigationComponent* ActorOrbitalNavigationComponent(AActor* Actor);
    
};

