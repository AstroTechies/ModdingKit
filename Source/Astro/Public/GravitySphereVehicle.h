#pragma once
#include "CoreMinimal.h"
#include "EGravitySphereControllerType.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "VehicleBase.h"
#include "GravitySphereVehicle.generated.h"

class AActor;
class AAstroPlayerController;
class APhysicalItem;
class UActorAttachmentsComponent;
class UAdaptiveTickComponent;
class UBallPhysicsMovementComponent;
class UControlComponent;
class UItemType;
class UPlanetEffect;
class USceneComponent;

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
    TSubclassOf<UItemType> EVA_ItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString AI_EnterAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString AI_ExitAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EVA_EnterAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EVA_ExitAudioEvent;
    
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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UControlComponent* ControlComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlanetEffect* PlanetEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAdaptiveTickComponent* AdaptiveTickComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBallPhysicsMovementComponent* MovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference AI_ItemControllerSlotRef;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnControllerAttachedChanged;
    
public:
    AGravitySphereVehicle(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION()
    void SetupComponentReferences(UActorAttachmentsComponent* attachmentComponent, USceneComponent* seatRoot, USceneComponent* cameraTargetNode);
    
    UFUNCTION(BlueprintCallable)
    void OnPilotExitComplete(AActor* pilot);
    
    UFUNCTION(BlueprintCallable)
    void OnEffectRelevanceChanged(bool IsInRelevancy);
    
    UFUNCTION(BlueprintCallable)
    void OnAI_ControllerReleased(APhysicalItem* controllerItem);
    
    UFUNCTION(BlueprintCallable)
    void OnAI_ControllerAttached(APhysicalItem* controllerItem);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocallyControlled() const;
    
    UFUNCTION(BlueprintCallable)
    void HandleVehicleUnmanned(AAstroPlayerController* OldPilot);
    
    UFUNCTION(BlueprintCallable)
    void HandleVehicleManned(AAstroPlayerController* NewPilot);
    
    UFUNCTION(BlueprintCallable)
    void HandleJumpInput();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EGravitySphereControllerType GetAttachedControllerType();
    
    UFUNCTION(BlueprintCallable)
    void AuthorityHandlePickedUp(bool PhysicalMovement);
    
};

