#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "EDroneFlightState.h"
#include "PhysicalItem.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "DroneBase.generated.h"

class AActor;
class APlayController;
class ASolarBody;
class UFixedFOVModifierComponent;
class UFlyingDroneMovementComponent;
class USceneComponent;
class USkeletalMeshComponent;

UCLASS(Abstract, Blueprintable)
class ADroneBase : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFlyingDroneMovementComponent* MovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSlotReference DockingSlotRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* PrevAstroViewTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_FlightState, meta=(AllowPrivateAccess=true))
    EDroneFlightState flightState;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnFlightStateChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* OldOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FlightSpeedRTPCName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ZoomInSoundEventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ZoomOutSoundEventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZoomedInCameraFOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZoomedOutCameraFOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DiscreteCameraZoomIncrement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DiscreteFlightSpeedIncrement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZoomSFXReplayDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DockingRotationInterpolationStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UndockingRotationInterpolationStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DockingLocationInterpolationStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UndockingLocationInterpolationStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DockingScaleInterpolationStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UndockingScaleInterpolationStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* AudioListener;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference AudioListenerReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFixedFOVModifierComponent* fixedFOVModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LerpStrengthScaleFactor;
    
public:
    ADroneBase(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void ZoomOut();
    
    UFUNCTION(BlueprintCallable)
    void ZoomIn();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TakePhoto();
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetRiseInputInactive();
    
    UFUNCTION(BlueprintCallable)
    void SetRiseInputActive();
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetFlightState(EDroneFlightState NewFlightState);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_FlightState();
    
    UFUNCTION(BlueprintCallable)
    void NudgeFlightSpeedSlower();
    
    UFUNCTION(BlueprintCallable)
    void NudgeFlightSpeedFaster();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocallyControlled() const;
    
    UFUNCTION(BlueprintCallable)
    void HandlePlayerReachedSpaceInShuttle();
    
    UFUNCTION(BlueprintCallable)
    void HandlePlacedInSlot();
    
    UFUNCTION(BlueprintCallable)
    void HandleOutroCinematicCompleted();
    
    UFUNCTION(BlueprintCallable)
    void HandleOutroCinematicBecameActive();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASolarBody* GetLocalSolarBody() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    USkeletalMeshComponent* GetDroneSkeletalMesh();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentFOV() const;
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityRecallDrone();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityLaunchDrone(APlayController* OwningController);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityEmergencyRecallDrone();
    
};

