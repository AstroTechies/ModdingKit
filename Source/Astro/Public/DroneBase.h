#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "EDroneFlightState.h"
#include "SlotReference.h"
#include "SignalDelegate.h"
#include "Engine/EngineTypes.h"
#include "DroneBase.generated.h"

class USceneComponent;
class UFlyingDroneMovementComponent;
class AActor;
class UFixedFOVModifierComponent;
class ASolarBody;
class USkeletalMeshComponent;
class APlayController;

UCLASS(Blueprintable, Abstract)
class ADroneBase : public APhysicalItem
{
    GENERATED_BODY()
public:
    UPROPERTY(Export, VisibleAnywhere)
    UFlyingDroneMovementComponent *MovementComponent;

    UPROPERTY(SaveGame)
    FSlotReference DockingSlotRef;

    UPROPERTY()
    AActor *PrevAstroViewTarget;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_FlightState, meta = (AllowPrivateAccess = true))
    EDroneFlightState flightState;

    UPROPERTY(BlueprintAssignable)
    FSignal OnFlightStateChanged;

protected:
    UPROPERTY(Transient)
    AActor *OldOwner;

    UPROPERTY(EditDefaultsOnly)
    FName FlightSpeedRTPCName;

    UPROPERTY(EditDefaultsOnly)
    FString ZoomInSoundEventName;

    UPROPERTY(EditDefaultsOnly)
    FString ZoomOutSoundEventName;

    UPROPERTY(EditDefaultsOnly)
    float ZoomedInCameraFOV;

    UPROPERTY(EditDefaultsOnly)
    float ZoomedOutCameraFOV;

    UPROPERTY(EditDefaultsOnly)
    float DiscreteCameraZoomIncrement;

    UPROPERTY(EditDefaultsOnly)
    float DiscreteFlightSpeedIncrement;

    UPROPERTY(EditDefaultsOnly)
    float ZoomSFXReplayDelay;

    UPROPERTY(EditDefaultsOnly)
    float DockingRotationInterpolationStrength;

    UPROPERTY(EditDefaultsOnly)
    float UndockingRotationInterpolationStrength;

    UPROPERTY(EditDefaultsOnly)
    float DockingLocationInterpolationStrength;

    UPROPERTY(EditDefaultsOnly)
    float UndockingLocationInterpolationStrength;

    UPROPERTY(EditDefaultsOnly)
    float DockingScaleInterpolationStrength;

    UPROPERTY(EditDefaultsOnly)
    float UndockingScaleInterpolationStrength;

    UPROPERTY(Export)
    USceneComponent *AudioListener;

    UPROPERTY(EditAnywhere)
    FComponentReference AudioListenerReference;

    UPROPERTY(Export)
    UFixedFOVModifierComponent *fixedFOVModifier;

    UPROPERTY(EditDefaultsOnly)
    float LerpStrengthScaleFactor;

public:
    ADroneBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void ZoomOut();

    UFUNCTION()
    void ZoomIn();

public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TakePhoto();

protected:
    UFUNCTION()
    void SetRiseInputInactive();

    UFUNCTION()
    void SetRiseInputActive();

public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetFlightState(EDroneFlightState NewFlightState);

protected:
    UFUNCTION()
    void OnRep_FlightState();

    UFUNCTION()
    void NudgeFlightSpeedSlower();

    UFUNCTION()
    void NudgeFlightSpeedFaster();

    UFUNCTION(BlueprintPure)
    bool IsLocallyControlled() const;

    UFUNCTION()
    void HandlePlayerReachedSpaceInShuttle();

    UFUNCTION()
    void HandlePlacedInSlot();

    UFUNCTION()
    void HandleOutroCinematicCompleted();

    UFUNCTION()
    void HandleOutroCinematicBecameActive();

public:
    UFUNCTION(BlueprintPure)
    ASolarBody *GetLocalSolarBody() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    USkeletalMeshComponent *GetDroneSkeletalMesh();

protected:
    UFUNCTION(BlueprintPure)
    float GetCurrentFOV() const;

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityRecallDrone();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityLaunchDrone(APlayController *OwningController);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityEmergencyRecallDrone();
};
