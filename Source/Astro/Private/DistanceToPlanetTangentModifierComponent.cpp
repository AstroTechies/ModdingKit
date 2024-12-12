#include "DistanceToPlanetTangentModifierComponent.h"

UDistanceToPlanetTangentModifierComponent::UDistanceToPlanetTangentModifierComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TangentOffset = 0.00f;
    this->LimitDistance = 2000.00f;
}


