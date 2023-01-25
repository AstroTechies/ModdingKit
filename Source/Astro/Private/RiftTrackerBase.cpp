#include "RiftTrackerBase.h"
#include "ItemTeleportHelperComponent.h"
#include "NavpointComponent.h"
#include "Net/UnrealNetwork.h"

class AActor;

void ARiftTrackerBase::OnRep_TrackerGameType() {
}

void ARiftTrackerBase::MulticastSetRiftTrackerState_Implementation(ERiftTrackerState NewState) {
}

ERiftTrackerState ARiftTrackerBase::GetTrackerState() {
    return ERiftTrackerState::Standby;
}

ERiftTrackerGameType ARiftTrackerBase::GetTrackerGameType() {
    return ERiftTrackerGameType::Eva;
}

bool ARiftTrackerBase::FindRiftTrackerChainLocations(const TArray<AActor*>& ActorsToIgnore, TArray<FVector>& outlocArray) {
    return false;
}

void ARiftTrackerBase::AuthoritySetTrackerGameType(ERiftTrackerGameType NewType) {
}

void ARiftTrackerBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARiftTrackerBase, SpawnedTarget);
    DOREPLIFETIME(ARiftTrackerBase, TrackerState);
    DOREPLIFETIME(ARiftTrackerBase, TrackerGameType);
}

ARiftTrackerBase::ARiftTrackerBase() {
    this->SpawnedTarget = NULL;
    this->NavpointComp = CreateDefaultSubobject<UNavpointComponent>(TEXT("Navpoint Component"));
    this->TeleportComp = CreateDefaultSubobject<UItemTeleportHelperComponent>(TEXT("Teleport Helper Component"));
    this->TrackerState = ERiftTrackerState::Standby;
    this->TrackerGameType = ERiftTrackerGameType::Eva;
}

