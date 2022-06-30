#include "GatesGameState.h"
#include "Net/UnrealNetwork.h"

void AGatesGameState::OnReplicationDataReceived() {
}

void AGatesGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AGatesGameState, ReplicationData);
}

AGatesGameState::AGatesGameState() {
    this->TotalActivatedChambers = 0;
    this->TotalActivatedEngines = 0;
}

