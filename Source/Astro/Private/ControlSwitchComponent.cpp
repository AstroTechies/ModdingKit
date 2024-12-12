#include "ControlSwitchComponent.h"

UControlSwitchComponent::UControlSwitchComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ActiveControlIndex = 0;
}

void UControlSwitchComponent::SetControlledSlot(int32 Index) {
}

void UControlSwitchComponent::OnSwitchClicked(USceneComponent* Component) {
}


