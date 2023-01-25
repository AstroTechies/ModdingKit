#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EInputEvent -FallbackName=EInputEvent
#include "OnRoverMovementStateChangedDelegate.h"
#include "SlotReference.h"
#include "VehicleBase.h"
#include "RoverBase.generated.h"

class AAstroPlayerController;
class UControlledVehicleMovement;
class UParticleSystemComponent;
class USceneComponent;
class UStorageChassisComponent;
class UWheeledChassisComponent;

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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UControlledVehicleMovement* ControlledVehicleMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWheeledChassisComponent* WheeledChassisComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStorageChassisComponent* StorageChassisComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
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
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateUseSuppression(bool ShouldBeSuppressed);
    
    UFUNCTION(BlueprintCallable)
    void UpdateTunnelBoringOriginInternal(USceneComponent* FrontRightWheel, USceneComponent* FrontLeftWheel, USceneComponent* BackRightWheel, USceneComponent* BackLeftWheel, bool IsFrontMountedDrill, USceneComponent* TunnelBoringOrigion);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    USceneComponent* UpdateAndGetTunnelBoringOrigin(FSlotReference slotDrillIsIn);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerReceiveSeatExitOverriddenWithFlip(bool ExitOverridden);
    
    UFUNCTION(BlueprintCallable)
    void RouteAux2ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> eventType);
    
    UFUNCTION(BlueprintCallable)
    void RouteAux1ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> eventType);
    
    UFUNCTION(BlueprintCallable)
    void HandleVehicleUnmanned(AAstroPlayerController* OldPilot);
    
    UFUNCTION(BlueprintCallable)
    void HandleVehicleManned(AAstroPlayerController* NewPilot);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool GetUnbundleOriginFromAuxSlot(FSlotReference AuxSlot, int32 SubslotIndex, FVector& OutLocation, FVector& OutForward);
    
protected:
    UFUNCTION(BlueprintCallable)
    void EngageRollYawModifier();
    
    UFUNCTION(BlueprintCallable)
    void DisengageRollYawModifier();
    
    UFUNCTION(BlueprintCallable)
    void ConsumeLeftTriggerToggle();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    bool Authority_GetSeatExitOverriddenWithFlip() const;
    
};

