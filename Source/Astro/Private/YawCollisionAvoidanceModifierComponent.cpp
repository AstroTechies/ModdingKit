#include "YawCollisionAvoidanceModifierComponent.h"

UYawCollisionAvoidanceModifierComponent::UYawCollisionAvoidanceModifierComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->WhiskerCastSize = 1000.00f;
    this->VelocityScaleDivisor = 800.00f;
}


