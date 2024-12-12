#include "CylindricalGravityVolumeComponent.h"

UCylindricalGravityVolumeComponent::UCylindricalGravityVolumeComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CylinderRadius = 200.00f;
    this->CylinderHeight = 1000.00f;
    this->bApplyGravityOutward = false;
}


