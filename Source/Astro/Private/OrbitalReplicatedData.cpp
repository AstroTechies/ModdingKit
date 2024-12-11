#include "OrbitalReplicatedData.h"

FOrbitalReplicatedData::FOrbitalReplicatedData() {
    this->SourceComponent = NULL;
    this->SourceOrbitingBody = NULL;
    this->TargetComponent = NULL;
    this->TargetOrbitingBody = NULL;
    this->CurrentComponent = NULL;
    this->CurrentOrbitingBody = NULL;
    this->Launched = false;
    this->TravelDistance = 0.00f;
    this->LaunchLength = 0.00f;
    this->InterplanetaryTravelRangeMultiplier = 0.00f;
}

