#include "NavpointComponent.h"

void UNavpointComponent::HandleNavpointOwnershipChanged(const FGuid& NewNavpointID) {
}

void UNavpointComponent::HandleNavpointEnabled(const FGuid& NewNavpointID) {
}

void UNavpointComponent::HandleNavpointDisabled(const FGuid& NewNavpointID) {
}

void UNavpointComponent::AuthoritySetShouldRegisterNavpoint(bool bShouldRegister) {
}

UNavpointComponent::UNavpointComponent() {
    this->bShouldRegisterNavpoint = true;
}

