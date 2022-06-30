#include "GatewayObjectPlacementProperties.h"

FGatewayObjectPlacementProperties::FGatewayObjectPlacementProperties() {
    this->ChamberOctreeResOffset = 0;
    this->ChamberExclusionRadius = 0.00f;
    this->bApplyRandomRotationToChamberPlacement = false;
    this->bShouldHollowOutCoreAroundEngine = false;
    this->EngineType = NULL;
    this->EngineOctreeResOffset = 0;
    this->HollowCoreRadius = 0.00f;
    this->HollowCoreSmoothingZoneSize = 0.00f;
    this->SamePlanetChambersRequiredForEngineActivation = 0;
    this->SolarSystemChambersRequiredForEngineActivation = 0;
    this->GateObjectIndicators = NULL;
}

