#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "SlotReference.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
#include "SignalDelegate.h"
#include "EDroneFlightState.h"
#include "DroneBase.generated.h"

class UFlyingDroneMovementComponent;
class AActor;
class USceneComponent;
class UFixedFOVModifierComponent;
class ASolarBody;
class USkeletalMeshComponent;
class APlayController;

UCLASS(Abstract, Blueprintable)
class ADroneBase : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* AudioListener;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference AudioListenerReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UFixedFOVModifierComponent* fixedFOVModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LerpStrengthScaleFactor;
    
public:
    ADroneBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
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
    ASolarBody* GetLocalSolarBody() const;
    
    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    USkeletalMeshComponent* GetDroneSkeletalMesh();
    
protected:
    UFUNCTION(BlueprintPure)
    float GetCurrentFOV() const;
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityRecallDrone();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityLaunchDrone(APlayController* OwningController);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityEmergencyRecallDrone();
    
};

