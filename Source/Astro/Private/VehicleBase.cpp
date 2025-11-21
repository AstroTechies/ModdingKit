#include "VehicleBase.h"
#include "Net/UnrealNetwork.h"

AVehicleBase::AVehicleBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->storage = NULL;
}



void AVehicleBase::PerformVehicleAux2Action(AAstroPlayerController* OriginatingController, TEnumAsByte<EInputEvent> EventType) {
}

void AVehicleBase::PerformVehicleAux1Action(AAstroPlayerController* OriginatingController, TEnumAsByte<EInputEvent> EventType) {
}

void AVehicleBase::OnRep_VehicleBaseReplicationData() {
}

ASeatBase* AVehicleBase::GetDrivingControllerSeat() {
    return NULL;
}

AAstroPlayerController* AVehicleBase::GetDrivingController() {
    return NULL;
}

void AVehicleBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AVehicleBase, VehicleBaseReplicationData);
}


