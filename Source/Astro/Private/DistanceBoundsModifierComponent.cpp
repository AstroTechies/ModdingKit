#include "DistanceBoundsModifierComponent.h"

UDistanceBoundsModifierComponent::UDistanceBoundsModifierComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InnerBound = 0.00f;
    this->OuterBound = 0.00f;
    this->CorrectionSpeed = 0.00f;
    this->bMaintainHeightOnCorrection = false;
}


