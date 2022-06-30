#include "ControlPanelButtonChildActorComponent.h"

void UControlPanelButtonChildActorComponent::SpoofButtonPress() {
}

void UControlPanelButtonChildActorComponent::SetEnabled(bool Enabled) {
}

void UControlPanelButtonChildActorComponent::RerouteOnPressed() {
}

void UControlPanelButtonChildActorComponent::RerouteOnArmedChanged(bool IsArmed) {
}

bool UControlPanelButtonChildActorComponent::GetEnabled() {
    return false;
}

bool UControlPanelButtonChildActorComponent::GetArmed() {
    return false;
}

UControlPanelButtonChildActorComponent::UControlPanelButtonChildActorComponent() {
    this->ChildButtonClass = NULL;
    this->ButtonActor = NULL;
}

