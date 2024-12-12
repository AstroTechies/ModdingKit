#include "GatesGameState.h"
#include "Net/UnrealNetwork.h"

AGatesGameState::AGatesGameState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ActiveThemes.AddDefaulted(1);
    this->TotalActivatedChambers = 0;
    this->TotalActivatedEngines = 0;
}

void AGatesGameState::OnReplicationDataReceived() {
}

void AGatesGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AGatesGameState, ReplicationData);
}


