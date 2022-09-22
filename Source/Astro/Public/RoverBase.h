#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "VehicleBase.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "OnRoverMovementStateChangedDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EInputEvent -FallbackName=EInputEvent
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "RoverBase.generated.h"

class UWheeledChassisComponent;
class UControlledVehicleMovement;
class UParticleSystemComponent;
class UStorageChassisComponent;
class USceneComponent;
class AAstroPlayerController;

UCLASS(Blueprintable)
class ASTRO_API ARoverBase : public AVehicleBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> AuxSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TunnelBoringDeformerBaseScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D TunnelBoringTiltIndicatorPositionOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumDisplaySeatedFlipPromptVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumSeatedHideFlipPromptVelocity;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UControlledVehicleMovement* ControlledVehicleMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UWheeledChassisComponent* WheeledChassisComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStorageChassisComponent* StorageChassisComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UParticleSystemComponent*> WheelBlowFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AudioSurfaceTypes;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRoverMovementStateChanged OnRoverMovementStateChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UseSuppressionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsFlipped;
    
public:
    ARoverBase();
protected:
    UFUNCTION(BlueprintNativeEvent)
    void UpdateUseSuppression(bool ShouldBeSuppressed);
    
    UFUNCTION(BlueprintCallable)
    void UpdateTunnelBoringOriginInternal(USceneComponent* FrontRightWheel, USceneComponent* FrontLeftWheel, USceneComponent* BackRightWheel, USceneComponent* BackLeftWheel, bool IsFrontMountedDrill, USceneComponent* TunnelBoringOrigion);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    USceneComponent* UpdateAndGetTunnelBoringOrigin(FSlotReference slotDrillIsIn);
    
protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerReceiveSeatExitOverriddenWithFlip(bool ExitOverridden);
    
    UFUNCTION()
    void RouteAux2ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> eventType);
    
    UFUNCTION()
    void RouteAux1ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> eventType);
    
    UFUNCTION()
    void HandleVehicleUnmanned(AAstroPlayerController* OldPilot);
    
    UFUNCTION()
    void HandleVehicleManned(AAstroPlayerController* NewPilot);
    
public:
    UFUNCTION(BlueprintImplementableEvent)
    bool GetUnbundleOriginFromAuxSlot(FSlotReference AuxSlot, int32 SubslotIndex, FVector& OutLocation, FVector& OutForward);
    
protected:
    UFUNCTION()
    void EngageRollYawModifier();
    
    UFUNCTION()
    void DisengageRollYawModifier();
    
    UFUNCTION()
    void ConsumeLeftTriggerToggle();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    bool Authority_GetSeatExitOverriddenWithFlip() const;
    
};

