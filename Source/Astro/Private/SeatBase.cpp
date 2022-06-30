#include "SeatBase.h"
#include "Net/UnrealNetwork.h"

class AVehicleBase;

void ASeatBase::HandleSeatReleasedFromSlot(bool NewOwner) {
}

void ASeatBase::HandleSeatPlacedInSlot() {
}

AVehicleBase* ASeatBase::GetVehicleSlottedTo() const {
    return NULL;
}

void ASeatBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ASeatBase, SeatReplicationData);
}

ASeatBase::ASeatBase() {
    this->ActorAttachmentsComponent = NULL;
}

