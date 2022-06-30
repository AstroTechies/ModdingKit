#include "ControlSwitchComponent.h"

class USceneComponent;

void UControlSwitchComponent::SetControlledSlot(int32 Index) {
}

void UControlSwitchComponent::OnSwitchClicked(USceneComponent* Component) {
}

UControlSwitchComponent::UControlSwitchComponent() {
    this->ActiveControlIndex = 0;
}

