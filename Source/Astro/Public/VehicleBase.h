#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "OnVehicleMannedStatusChangedDelegate.h"
#include "VehicleBaseReplicationData.h"
#include "Engine/EngineBaseTypes.h"
#include "PerformAuxSignalDelegate.h"
#include "VehicleBase.generated.h"

class ASeatBase;
class UStorageChassisComponent;
class AAstroPlayerController;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AVehicleBase : public APhysicalItem
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FOnVehicleMannedStatusChanged OnVehicleManned;

    UPROPERTY(BlueprintAssignable)
    FOnVehicleMannedStatusChanged OnVehicleUnmanned;

protected:
    UPROPERTY(ReplicatedUsing = OnRep_VehicleBaseReplicationData)
    FVehicleBaseReplicationData VehicleBaseReplicationData;

    UPROPERTY()
    FVehicleBaseReplicationData PrevVehicleBaseReplicationData;

    UPROPERTY(BlueprintAssignable)
    FPerformAuxSignal OnVehicleAux1ActionPerformed;

    UPROPERTY(BlueprintAssignable)
    FPerformAuxSignal OnVehicleAux2ActionPerformed;

    UPROPERTY(Export)
    UStorageChassisComponent *storage;

public:
    AVehicleBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintImplementableEvent)
    void VehicleLostPilotInSeat(AAstroPlayerController *Driver, ASeatBase *Seat);

    UFUNCTION(BlueprintImplementableEvent)
    void VehicleGainedPilotInSeat(AAstroPlayerController *Driver, ASeatBase *Seat);

    UFUNCTION(BlueprintCallable)
    void PerformVehicleAux2Action(AAstroPlayerController *OriginatingController, EInputEvent eventType);

    UFUNCTION(BlueprintCallable)
    void PerformVehicleAux1Action(AAstroPlayerController *OriginatingController, EInputEvent eventType);

protected:
    UFUNCTION()
    void OnRep_VehicleBaseReplicationData();

public:
    UFUNCTION(BlueprintPure)
    ASeatBase *GetDrivingControllerSeat();

    UFUNCTION(BlueprintPure)
    AAstroPlayerController *GetDrivingController();
};
