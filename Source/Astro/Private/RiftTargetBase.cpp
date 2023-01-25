#include "RiftTargetBase.h"
#include "ItemTeleportHelperComponent.h"
#include "Net/UnrealNetwork.h"


void ARiftTargetBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARiftTargetBase, ParentTracker);
    DOREPLIFETIME(ARiftTargetBase, SpawnedOrbs);
}

ARiftTargetBase::ARiftTargetBase() {
    this->NumOrbs = 5;
    this->ParentTracker = NULL;
    this->TeleportComp = CreateDefaultSubobject<UItemTeleportHelperComponent>(TEXT("Teleport Helper Component"));
}

