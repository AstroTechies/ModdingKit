#include "SolarPowerComponent.h"

USolarPowerComponent::USolarPowerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MinPowerOutput = 0.00f;
    this->MaxPowerOutput = 2.00f;
    this->PowerComponent = NULL;
}


