#include "OrbitalPlatformStorageCanisterComponent.h"
#include "Net/UnrealNetwork.h"

UOrbitalPlatformStorageCanisterComponent::UOrbitalPlatformStorageCanisterComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->REP_StoredFuel = 0;
    this->AmountDrained = 0;
    this->AcceptedItemType = NULL;
}

void UOrbitalPlatformStorageCanisterComponent::SetManagedSlots(const TArray<FSlotReference>& inSlotRefs) {
}

void UOrbitalPlatformStorageCanisterComponent::OnSlotEvent(APhysicalItem* inItem) {
}

void UOrbitalPlatformStorageCanisterComponent::OnRep_StoredFuel() const {
}

void UOrbitalPlatformStorageCanisterComponent::OnItemUnslotted(APhysicalItem* inItem) {
}

void UOrbitalPlatformStorageCanisterComponent::OnItemSlotted(APhysicalItem* inItem) {
}

int32 UOrbitalPlatformStorageCanisterComponent::GetStoredFuelAmount() const {
    return 0;
}

void UOrbitalPlatformStorageCanisterComponent::AuthorityPerformJump(const int32 inFuelUsed) {
}

void UOrbitalPlatformStorageCanisterComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UOrbitalPlatformStorageCanisterComponent, REP_StoredFuel);
}


