#include "SlotResourceBehaviorComponent.h"

USlotResourceBehaviorComponent::USlotResourceBehaviorComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->EjectWhenFull = true;
    this->EjectForce = 100000.00f;
}


