#include "PlanetaryGateObjectsState.h"

FPlanetaryGateObjectsState::FPlanetaryGateObjectsState() {
    this->Planet = NULL;
    this->bEngineActivated = false;
    this->NumChambersActivated = 0;
    this->ChamberActivationBitMask = 0;
}

