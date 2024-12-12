#include "ScannableComponent.h"

UScannableComponent::UScannableComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ScannableType = EScannableType::None;
    this->RecalculateSolarBodyDistanceSquared = 100000000.00f;
    this->StartDisabled = false;
}

void UScannableComponent::EnableComponent() {
}

void UScannableComponent::DisableComponent() {
}


