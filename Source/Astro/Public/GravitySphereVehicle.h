#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "VehicleBase.h"
#include "SignalDelegate.h"
#include "EGravitySphereControllerType.h"
#include "GravitySphereVehicle.generated.h"

class UActorAttachmentsComponent;
class UAdaptiveTickComponent;
class UControlComponent;
class UBallPhysicsMovementComponent;
class UPlanetEffect;
class USceneComponent;
class AActor;
class APhysicalItem;
class AAstroPlayerController;

UCLASS(Blueprintable)
class ASTRO_API AGravitySphereVehicle : public AVehicleBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurningInputBias;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SeatFacingInputDirectionBias;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AI_ItemControllerSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString AI_EnterAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString AI_ExitAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString HatchOpenAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString HatchCloseAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName GravitySphereMissionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString TopSpeedCustomObjectiveID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSpeedThresholdForTopSpeedObjective;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnGainedController;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnLostController;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UControlComponent* ControlComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UPlanetEffect* PlanetEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UAdaptiveTickComponent* AdaptiveTickComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UBallPhysicsMovementComponent* MovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference AI_ItemControllerSlotRef;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnControllerAttachedChanged;
    
public:
    AGravitySphereVehicle();
protected:
    UFUNCTION(BlueprintCallable)
    void SetupComponentReferences(UActorAttachmentsComponent* attachmentComponent, USceneComponent* seatRoot, USceneComponent* cameraTargetNode);
    
    UFUNCTION()
    void OnPilotExitComplete(AActor* pilot);
    
    UFUNCTION()
    void OnEffectRelevanceChanged(bool IsInRelevancy);
    
    UFUNCTION()
    void OnAI_ControllerReleased(APhysicalItem* controllerItem);
    
    UFUNCTION()
    void OnAI_ControllerAttached(APhysicalItem* controllerItem);
    
    UFUNCTION(BlueprintPure)
    bool IsLocallyControlled() const;
    
    UFUNCTION()
    void HandleVehicleUnmanned(AAstroPlayerController* OldPilot);
    
    UFUNCTION()
    void HandleVehicleManned(AAstroPlayerController* NewPilot);
    
    UFUNCTION()
    void HandleJumpInput();
    
    UFUNCTION(BlueprintPure)
    EGravitySphereControllerType GetAttachedControllerType();
    
    UFUNCTION()
    void AuthorityHandlePickedUp(bool PhysicalMovement);
    
};

