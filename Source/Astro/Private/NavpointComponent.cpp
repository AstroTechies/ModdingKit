#include "NavpointComponent.h"

UNavpointComponent::UNavpointComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bShouldRegisterNavpoint = true;
}

void UNavpointComponent::HandleNavpointOwnershipChanged(const FGuid& NewNavpointID) {
}

void UNavpointComponent::HandleNavpointEnabled(const FGuid& NewNavpointID) {
}

void UNavpointComponent::HandleNavpointDisabled(const FGuid& NewNavpointID) {
}

void UNavpointComponent::AuthoritySetShouldRegisterNavpoint(bool bShouldRegister) {
}

void UNavpointComponent::AuthoritySetNavpointEnabled(bool bNavpointEnabled) {
}


