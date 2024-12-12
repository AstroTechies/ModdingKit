#include "FixedGravityVolumeComponent.h"

UFixedGravityVolumeComponent::UFixedGravityVolumeComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BoxExtent = 1000.00f;
    this->bApplyGravityUpward = false;
}


