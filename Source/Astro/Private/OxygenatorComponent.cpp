#include "OxygenatorComponent.h"
#include "Net/UnrealNetwork.h"

UOxygenatorComponent::UOxygenatorComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    this->bRequiresPower = true;
    this->bSuppliesOxygenToContainedCharactersOnly = false;
    this->bIsSupplyingOxygen = false;
    this->bIsOxygenSupplyEnabled = true;
    this->OwnerItem = NULL;
}

void UOxygenatorComponent::OnRep_IsSupplyingOxygen() {
}

void UOxygenatorComponent::OnOwnerNotFullyPowered() {
}

void UOxygenatorComponent::OnOwnerItemRemovedFromSlot(bool bNewOwner) {
}

void UOxygenatorComponent::OnOwnerItemPlacedInSlot() {
}

void UOxygenatorComponent::OnOwnerFullyPowered() {
}

void UOxygenatorComponent::OnItemPadSpawned() {
}

void UOxygenatorComponent::OnItemPadDestroyed() {
}

void UOxygenatorComponent::AuthoritySetOxygenSupplyEnabled(bool bSupplyEnabled) {
}

void UOxygenatorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UOxygenatorComponent, bIsSupplyingOxygen);
}


