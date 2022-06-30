#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "UpdateCanLaunchSignalDelegate.h"
#include "OrbitalReplicatedData.h"
#include "UObject/NoExportTypes.h"
#include "SignalDelegate.h"
#include "ReplicatedOrbitalTimeData.h"
#include "OrbitalNavigationComponent.generated.h"

class UObject;
class UStorageChassisComponent;
class ASolarBody;
class AActor;
class AAstroPlayerController;
class UOrbitalNavigationComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UOrbitalNavigationComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bPreventRespawnWhileDriving : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LaunchLength;

    UPROPERTY(EditDefaultsOnly)
    float DefaultOrbitSpeed;

    UPROPERTY(EditDefaultsOnly)
    float MinOrbitSpeed;

    UPROPERTY(EditDefaultsOnly)
    float MaxOrbitSpeed;

    UPROPERTY(EditDefaultsOnly)
    float OrbitSpeedRangeStep;

    UPROPERTY(EditDefaultsOnly)
    float OrbitSpeedTransitionRate;

    UPROPERTY(EditDefaultsOnly)
    float OrbitSpeedInputRepeatDelay;

    UPROPERTY(EditAnywhere)
    FTransform LandingOffset;

    UPROPERTY(EditAnywhere)
    bool UseLaunchUpVector;

    UPROPERTY(EditAnywhere)
    float OrbitDistance;

    UPROPERTY(EditAnywhere)
    float EasePower;

    UPROPERTY(EditAnywhere)
    float LerpPower;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_ReplicatedData, meta = (AllowPrivateAccess = true))
    FOrbitalReplicatedData ReplicatedData;

    UPROPERTY(SaveGame)
    bool PhysicsDisabled;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UObject *SelectedTarget;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector MajorForceVector;

    UPROPERTY()
    float LaunchTime;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool planetSelection;

    UPROPERTY()
    bool shouldLaunchUpdate;

    UPROPERTY(BlueprintAssignable)
    FSignal OnLaunchEnd;

    UPROPERTY(BlueprintAssignable)
    FSignal OnLaunch;

    UPROPERTY(BlueprintAssignable)
    FUpdateCanLaunchSignal OnUpdateCanLaunch;

    UPROPERTY(BlueprintAssignable)
    FSignal OnOrbitSpeedChanged;

    UPROPERTY()
    float SourceTime;

    UPROPERTY()
    float TargetTime;

    UPROPERTY()
    float CurrentTime;

    UPROPERTY(Export)
    UStorageChassisComponent *storage;

    UPROPERTY(BlueprintAssignable)
    FSignal OnPlanetSelectionChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal HandleLandBeginHover;

    UPROPERTY(BlueprintAssignable)
    FSignal HandleLandEndHover;

protected:
    UPROPERTY(Transient)
    float CurrOrbitGameSpeedScalarDegree;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_TargetOrbitSpeedScalarDegree)
    float REP_TargetOrbitGameSpeedScalarDegree;

    UPROPERTY(Transient)
    float Local_TargetOrbitGameSpeedScalarDegree;

    UPROPERTY(Transient)
    float DefaultOrbitSpeedScalarDegree;

    UPROPERTY(EditAnywhere)
    float InterplanetaryTravelRange;

    UPROPERTY(ReplicatedUsing = OnRep_ReplicatedTimeData)
    FReplicatedOrbitalTimeData TimeData;

    UPROPERTY()
    FOrbitalReplicatedData LastData;

    UPROPERTY(Transient)
    ASolarBody *SourceSolarBody;

    UPROPERTY(Transient)
    float TimeSinceLastOrbitSpeedChange;

    UPROPERTY(Transient)
    int32 CurrOrbitSpeedInput;

    UPROPERTY(Transient)
    int32 DiscreteOrbitSpeedInput;

    UPROPERTY(Transient)
    int32 AxisOrbitSpeedInput;

    UPROPERTY(Transient)
    float MaxOrbitSpeedScalar;

    UPROPERTY(Transient)
    float MinOrbitSpeedScalar;

public:
    UOrbitalNavigationComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetPlanetSelection(bool Enable);

    UFUNCTION(BlueprintCallable)
    void SetActiveLaunchLength(float newLaunchLength);

protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSetOrbitSpeedScalarDegree(float speedScalarDegree);

public:
    UFUNCTION(BlueprintCallable)
    void PerformLaunch(UObject *Target);

    UFUNCTION()
    void OnStorageAttachmentsChanged(bool Entered);

    UFUNCTION()
    void OnSolarBodyClick(ASolarBody *SolarBody);

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
    void OnLandClick(AActor *Actor);

    UFUNCTION()
    void OnLandBeginHover();

    UFUNCTION(BlueprintPure)
    bool LocalPlayerOnBoard();

protected:
    UFUNCTION()
    void HandleVehicleUnmanned(AAstroPlayerController *VehicleDriver);

    UFUNCTION()
    void HandleVehicleManned(AAstroPlayerController *VehicleDriver);

public:
    UFUNCTION(BlueprintPure)
    ASolarBody *GetTargetOrbitingBody();

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
    void AuthoritySnapToTarget(UObject *Target);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetInterplanetaryTravelRangeMultiplier(float rangeMultiplier);

    UFUNCTION(BlueprintPure)
    static UOrbitalNavigationComponent *ActorOrbitalNavigationComponent(AActor *Actor);
};
