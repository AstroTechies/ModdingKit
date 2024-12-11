#include "RiftOrbBase.h"
#include "Net/UnrealNetwork.h"

ARiftOrbBase::ARiftOrbBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ParentTarget = NULL;
    this->OrbState = ERiftOrbState::Scattering;
    this->OrbGameType = ERiftTrackerGameType::Random;
}

void ARiftOrbBase::MulticastSetRiftOrbState_Implementation(ERiftOrbState NewState) {
}

ERiftOrbState ARiftOrbBase::GetOrbState() {
    return ERiftOrbState::Scattering;
}

ERiftTrackerGameType ARiftOrbBase::GetOrbGameType() {
    return ERiftTrackerGameType::Eva;
}

void ARiftOrbBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARiftOrbBase, ParentTarget);
    DOREPLIFETIME(ARiftOrbBase, OrbState);
    DOREPLIFETIME(ARiftOrbBase, OrbGameType);
}


