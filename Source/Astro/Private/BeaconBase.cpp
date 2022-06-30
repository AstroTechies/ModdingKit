#include "BeaconBase.h"

ABeaconBase::ABeaconBase() {
    this->HoverPointComponent = NULL;
    this->PlanetDistance = 1000000.00f;
    this->MinViewDistance = 2500.00f;
    this->MaxViewDistance = 15000.00f;
    this->BeaconHeight = 1200.00f;
    this->PlumbLineOffset = 0.00f;
    this->IconComponent = NULL;
    this->IndicatorLineComponent = NULL;
    this->IconRootComponent = NULL;
    this->bBeaconVisible = true;
}

