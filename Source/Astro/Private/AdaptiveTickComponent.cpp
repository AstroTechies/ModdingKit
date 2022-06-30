#include "AdaptiveTickComponent.h"

UAdaptiveTickComponent::UAdaptiveTickComponent() {
    this->MinTickInterval = 0.00f;
    this->MaxTickInterval = -1.00f;
    this->FarTickDistance = 5000.00f;
    this->NearTickDistance = 3000.00f;
}

