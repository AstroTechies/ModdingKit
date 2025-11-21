#include "ControlPanelButtonChildActorComponent.h"

UControlPanelButtonChildActorComponent::UControlPanelButtonChildActorComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ChildButtonClass = NULL;
    this->ButtonActor = NULL;
}

void UControlPanelButtonChildActorComponent::SpoofButtonPress() {
}

void UControlPanelButtonChildActorComponent::SetEnabled(bool Enabled) {
}

void UControlPanelButtonChildActorComponent::RerouteOnPressed(AControlPanelButton* Actor) {
}

void UControlPanelButtonChildActorComponent::RerouteOnArmedChanged(bool IsArmed, AControlPanelButton* Actor) {
}

bool UControlPanelButtonChildActorComponent::GetEnabled() {
    return false;
}

bool UControlPanelButtonChildActorComponent::GetArmed() {
    return false;
}


