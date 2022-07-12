#pragma once
#include "CoreMinimal.h"
#include "PerformAuxSignalDelegate.h"
#include "OnVehicleMannedStatusChangedDelegate.h"
#include "PhysicalItem.h"
#include "VehicleBaseReplicationData.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EInputEvent -FallbackName=EInputEvent
#include "VehicleBase.generated.h"

class UStorageChassisComponent;
class AAstroPlayerController;
class ASeatBase;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStorageChassisComponent* storage;
    
public:
    AVehicleBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintImplementableEvent)
    void VehicleLostPilotInSeat(AAstroPlayerController* Driver, ASeatBase* Seat);
    
    UFUNCTION(BlueprintImplementableEvent)
    void VehicleGainedPilotInSeat(AAstroPlayerController* Driver, ASeatBase* Seat);
    
    UFUNCTION(BlueprintCallable)
    void PerformVehicleAux2Action(AAstroPlayerController* OriginatingController, TEnumAsByte<EInputEvent> eventType);
    
    UFUNCTION(BlueprintCallable)
    void PerformVehicleAux1Action(AAstroPlayerController* OriginatingController, TEnumAsByte<EInputEvent> eventType);
    
protected:
    UFUNCTION()
    void OnRep_VehicleBaseReplicationData();
    
public:
    UFUNCTION(BlueprintPure)
    ASeatBase* GetDrivingControllerSeat();
    
    UFUNCTION(BlueprintPure)
    AAstroPlayerController* GetDrivingController();
    
};

