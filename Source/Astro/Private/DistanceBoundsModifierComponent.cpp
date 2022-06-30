#include "DistanceBoundsModifierComponent.h"

UDistanceBoundsModifierComponent::UDistanceBoundsModifierComponent() {
    this->InnerBound = 0.00f;
    this->OuterBound = 0.00f;
    this->CorrectionSpeed = 0.00f;
    this->bMaintainHeightOnCorrection = false;
}

