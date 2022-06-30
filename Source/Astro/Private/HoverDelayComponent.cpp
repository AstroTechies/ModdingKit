#include "HoverDelayComponent.h"

class AActor;

void UHoverDelayComponent::OnTimerEnd() {
}

void UHoverDelayComponent::OnHoverEnd(AActor* Actor) {
}

void UHoverDelayComponent::OnHoverBegin(AActor* Actor) {
}

UHoverDelayComponent::UHoverDelayComponent() {
    this->HoverBeginDelay = 0.20f;
    this->HoverEndDelay = 1.00f;
    this->Hovering = false;
}

