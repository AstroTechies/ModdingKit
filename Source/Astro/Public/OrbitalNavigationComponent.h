#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "Components/ActorComponent.h"
#include "OrbitalReplicatedData.h"
#include "ReplicatedOrbitalTimeData.h"
#include "SignalDelegate.h"
#include "UpdateCanLaunchSignalDelegate.h"
#include "OrbitalNavigationComponent.generated.h"

class AActor;
class AAstroPlayerController;
class ASolarBody;
class UObject;
class UOrbitalNavigationComponent;
class UStorageChassisComponent;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
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
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetOrbitSpeedScalarDegree(float speedScalarDegree);
    
public:
    UFUNCTION(BlueprintCallable)
    void PerformLaunch(UObject* Target);
    
    UFUNCTION(BlueprintCallable)
    void OnStorageAttachmentsChanged(bool Entered);
    
    UFUNCTION(BlueprintCallable)
    void OnSolarBodyClick(ASolarBody* SolarBody);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_TargetOrbitSpeedScalarDegree();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ReplicatedTimeData();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ReplicatedData();
    
    UFUNCTION(BlueprintCallable)
    void OnOrbitSpeedInputUpOrDown(float AxisValue);
    
    UFUNCTION(BlueprintCallable)
    void OnOrbitSpeedInputUp();
    
    UFUNCTION(BlueprintCallable)
    void OnOrbitSpeedInputEnd();
    
    UFUNCTION(BlueprintCallable)
    void OnOrbitSpeedInputDown();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnLandEndHover();
    
    UFUNCTION(BlueprintCallable)
    void OnLandClick(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OnLandBeginHover();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool LocalPlayerOnBoard();
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleVehicleUnmanned(AAstroPlayerController* VehicleDriver);
    
    UFUNCTION(BlueprintCallable)
    void HandleVehicleManned(AAstroPlayerController* VehicleDriver);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASolarBody* GetTargetOrbitingBody();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetOrbitSpeedPercent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLaunchTime();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLaunched();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLanding();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLanded();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsInOrbit();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCanLaunch();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetCameraUpVector();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySnapToTarget(UObject* Target);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetInterplanetaryTravelRangeMultiplier(float rangeMultiplier);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UOrbitalNavigationComponent* ActorOrbitalNavigationComponent(AActor* Actor);
    
};

