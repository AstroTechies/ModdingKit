#include "ScannableComponent.h"

UScannableComponent::UScannableComponent() {
    this->ScannableType = EScannableType::None;
    this->RecalculateSolarBodyDistanceSquared = 100000000.00f;
}

