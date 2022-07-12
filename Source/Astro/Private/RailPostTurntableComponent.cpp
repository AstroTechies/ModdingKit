#include "RailPostTurntableComponent.h"
#include "Net/UnrealNetwork.h"

void URailPostTurntableComponent::OnRep_CurrentConnection() {
}

void URailPostTurntableComponent::HandleUse() {
}

bool URailPostTurntableComponent::AuthoritySetInternalConnectionState(int32 State) {
    return false;
}

void URailPostTurntableComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(URailPostTurntableComponent, CurrentCarSlotConnectionID);
}

URailPostTurntableComponent::URailPostTurntableComponent() {
    this->CurrentCarSlotConnectionState = 0;
    this->CurrentCarSlotConnectionID = -1;
}

