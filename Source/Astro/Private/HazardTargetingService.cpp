#include "HazardTargetingService.h"

UHazardTargetingService::UHazardTargetingService() {
    this->RequireLineOfSight = true;
    this->NearestTargetOnly = true;
    this->MaximumTargetDistance = 3000.00f;
}

