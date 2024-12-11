#include "SeatBase.h"
#include "Net/UnrealNetwork.h"

ASeatBase::ASeatBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ActorAttachmentsComponent = NULL;
}

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


