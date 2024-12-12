#include "SunlightDetectorComponent.h"

USunlightDetectorComponent::USunlightDetectorComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MinExposure = 0.00f;
    this->CastComponent = NULL;
    this->SunExposure = 0.00f;
}


