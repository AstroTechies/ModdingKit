#include "RailPostTurntable.h"
#include "Net/UnrealNetwork.h"

void ARailPostTurntable::AuthoritySetCarSlotConnectionState(int32 State, bool ForceUpdate) {
}

void ARailPostTurntable::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARailPostTurntable, CurrentCarSlotConnectionID);
}

ARailPostTurntable::ARailPostTurntable() {
    this->CurrentCarSlotConnectionState = 0;
    this->CurrentCarSlotConnectionID = -1;
}

