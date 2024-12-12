#include "HazardTargetingService.h"

UHazardTargetingService::UHazardTargetingService() {
    this->NodeName = TEXT("Hazard Targeting Service");
    this->RequireLineOfSight = true;
    this->NearestTargetOnly = true;
    this->MaximumTargetDistance = 3000.00f;
}


