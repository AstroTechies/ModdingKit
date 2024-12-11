#include "RiftTargetBase.h"
#include "ItemTeleportHelperComponent.h"
#include "Net/UnrealNetwork.h"

ARiftTargetBase::ARiftTargetBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->NumOrbs = 5;
    this->ParentTracker = NULL;
    this->TeleportComp = CreateDefaultSubobject<UItemTeleportHelperComponent>(TEXT("Teleport Helper Component"));
}


void ARiftTargetBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARiftTargetBase, ParentTracker);
    DOREPLIFETIME(ARiftTargetBase, SpawnedOrbs);
}


