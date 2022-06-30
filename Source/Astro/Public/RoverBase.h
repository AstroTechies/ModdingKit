#pragma once
#include "CoreMinimal.h"
#include "VehicleBase.h"
#include "SlotReference.h"
#include "UObject/NoExportTypes.h"
#include "OnRoverMovementStateChangedDelegate.h"
#include "Engine/EngineBaseTypes.h"
#include "UObject/NoExportTypes.h"
#include "RoverBase.generated.h"

class UControlledVehicleMovement;
class UWheeledChassisComponent;
class UStorageChassisComponent;
class UParticleSystemComponent;
class USceneComponent;
class AAstroPlayerController;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ARoverBase : public AVehicleBase
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> AuxSlots;

    UPROPERTY(EditAnywhere)
    float TunnelBoringDeformerBaseScale;

    UPROPERTY(EditAnywhere)
    FVector2D TunnelBoringTiltIndicatorPositionOffset;

    UPROPERTY(EditDefaultsOnly)
    float MaximumDisplaySeatedFlipPromptVelocity;

    UPROPERTY(EditDefaultsOnly)
    float MinimumSeatedHideFlipPromptVelocity;

protected:
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UControlledVehicleMovement *ControlledVehicleMovement;

    UPROPERTY(Export)
    UWheeledChassisComponent *WheeledChassisComponent;

    UPROPERTY(Export)
    UStorageChassisComponent *StorageChassisComponent;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    TArray<UParticleSystemComponent *> WheelBlowFX;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TArray<FName> AudioSurfaceTypes;

    UPROPERTY(BlueprintAssignable)
    FOnRoverMovementStateChanged OnRoverMovementStateChanged;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FName UseSuppressionID;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool bIsFlipped;

public:
    ARoverBase();

protected:
    UFUNCTION(BlueprintNativeEvent)
    void UpdateUseSuppression(bool ShouldBeSuppressed);

    UFUNCTION(BlueprintCallable)
    void UpdateTunnelBoringOriginInternal(USceneComponent *FrontRightWheel, USceneComponent *FrontLeftWheel, USceneComponent *BackRightWheel, USceneComponent *BackLeftWheel, bool IsFrontMountedDrill, USceneComponent *TunnelBoringOrigion);

public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    USceneComponent *UpdateAndGetTunnelBoringOrigin(FSlotReference slotDrillIsIn);

protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerReceiveSeatExitOverriddenWithFlip(bool ExitOverridden);

    UFUNCTION()
    void RouteAux2ToggleUse(AAstroPlayerController *Controller, EInputEvent eventType);

    UFUNCTION()
    void RouteAux1ToggleUse(AAstroPlayerController *Controller, EInputEvent eventType);

    UFUNCTION()
    void HandleVehicleUnmanned(AAstroPlayerController *OldPilot);

    UFUNCTION()
    void HandleVehicleManned(AAstroPlayerController *NewPilot);

public:
    UFUNCTION(BlueprintImplementableEvent)
    bool GetUnbundleOriginFromAuxSlot(FSlotReference AuxSlot, int32 SubslotIndex, FVector &OutLocation, FVector &OutForward);

protected:
    UFUNCTION()
    void EngageRollYawModifier();

    UFUNCTION()
    void DisengageRollYawModifier();

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    bool Authority_GetSeatExitOverriddenWithFlip() const;
};
