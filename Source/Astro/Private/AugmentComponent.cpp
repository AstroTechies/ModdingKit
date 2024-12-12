#include "AugmentComponent.h"
#include "Net/UnrealNetwork.h"

UAugmentComponent::UAugmentComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    this->AugmentIsEquipped = false;
    this->AugmentIsActive = false;
    this->AugmentIsEnabled = true;
    this->SuppressClickableWhileDeactivated = true;
}

void UAugmentComponent::UnblockReactivation() {
}

void UAugmentComponent::SetPowerDrawEnabled(bool drawEnabled) {
}

void UAugmentComponent::SetAugmentEquipped(bool equipped) {
}

bool UAugmentComponent::SetAugmentEnabled(bool IsEnabled) {
    return false;
}

void UAugmentComponent::SetAugmentActive(bool Active) {
}

void UAugmentComponent::PhysicalItemUnslotted(bool NewOwner) {
}

void UAugmentComponent::OnReplicated_AugmentEquipped() {
}

void UAugmentComponent::OnReplicated_AugmentEnabled() {
}

void UAugmentComponent::OnReplicated_AugmentActive() {
}







void UAugmentComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UAugmentComponent, AugmentIsEquipped);
    DOREPLIFETIME(UAugmentComponent, AugmentIsActive);
    DOREPLIFETIME(UAugmentComponent, AugmentIsEnabled);
}


