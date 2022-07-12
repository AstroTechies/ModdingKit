#include "Navpoint.h"

FNavpoint::FNavpoint() {
    this->NavpointType = ENavpointType::None;
    this->NavpointGroup = ENavpointGroup::None;
    this->Radius = 0.00f;
    this->MinFadeoutDistance = 0.00f;
    this->MaxFadeoutDistance = 0.00f;
    this->MinFadeoutElevation = 0.00f;
    this->MaxFadeoutElevation = 0.00f;
    this->bIsEnabled = false;
    this->bDefaultIsEnabled = false;
    this->bIsOnPlanet = false;
    this->bUseOverrideColor = false;
    this->bUseOverrideIcon = false;
    this->OverrideIcon = NULL;
}

