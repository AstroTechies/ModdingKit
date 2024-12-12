#include "SphericalGravityVolumeComponent.h"

USphericalGravityVolumeComponent::USphericalGravityVolumeComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SphereRadius = 1000.00f;
    this->bApplyGravityOutward = false;
}


