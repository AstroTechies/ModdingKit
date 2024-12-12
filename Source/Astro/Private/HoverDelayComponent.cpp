#include "HoverDelayComponent.h"

UHoverDelayComponent::UHoverDelayComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->HoverBeginDelay = 0.20f;
    this->HoverEndDelay = 1.00f;
    this->Hovering = false;
}

void UHoverDelayComponent::OnTimerEnd() {
}

void UHoverDelayComponent::OnHoverEnd(AActor* Actor) {
}

void UHoverDelayComponent::OnHoverBegin(AActor* Actor) {
}


