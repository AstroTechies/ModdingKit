#include "GateObjectComponent.h"

FGateObjectComponent::FGateObjectComponent() {
    this->Type = EGateObjectType::Chamber;
    this->bCanBeActivated = false;
    this->bIsActivated = false;
    this->bHasEncounteredPlayer = false;
    this->ChamberCoordinateIndex = 0;
    this->EventListener = NULL;
}

