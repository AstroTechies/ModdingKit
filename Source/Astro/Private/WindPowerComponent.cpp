#include "WindPowerComponent.h"

UWindPowerComponent::UWindPowerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MinExposure = 0.25f;
    this->MinPowerOutput = 0.00f;
    this->MaxPowerOutput = 2.00f;
    this->CastComponent = NULL;
    this->WindExposure = 0.00f;
    this->CastDistance = 5000.00f;
    this->PowerComponent = NULL;
}


