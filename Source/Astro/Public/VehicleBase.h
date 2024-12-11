#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "OnVehicleMannedStatusChangedDelegate.h"
#include "PerformAuxSignalDelegate.h"
#include "PhysicalItem.h"
#include "VehicleBaseReplicationData.h"
#include "VehicleBase.generated.h"

class AAstroPlayerController;
class ASeatBase;
class UStorageChassisComponent;

UCLASS(Blueprintable)
class ASTRO_API AVehicleBase : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnVehicleMannedStatusChanged OnVehicleManned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnVehicleMannedStatusChanged OnVehicleUnmanned;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_VehicleBaseReplicationData, meta=(AllowPrivateAccess=true))
    FVehicleBaseReplicationData VehicleBaseReplicationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVehicleBaseReplicationData PrevVehicleBaseReplicationData;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerformAuxSignal OnVehicleAux1ActionPerformed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerformAuxSignal OnVehicleAux2ActionPerformed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStorageChassisComponent* storage;
    
public:
    AVehicleBase(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void VehicleLostPilotInSeat(AAstroPlayerController* Driver, ASeatBase* Seat);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void VehicleGainedPilotInSeat(AAstroPlayerController* Driver, ASeatBase* Seat);
    
    UFUNCTION(BlueprintCallable)
    void PerformVehicleAux2Action(AAstroPlayerController* OriginatingController, TEnumAsByte<EInputEvent> eventType);
    
    UFUNCTION(BlueprintCallable)
    void PerformVehicleAux1Action(AAstroPlayerController* OriginatingController, TEnumAsByte<EInputEvent> eventType);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_VehicleBaseReplicationData();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASeatBase* GetDrivingControllerSeat();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAstroPlayerController* GetDrivingController();
    
};

