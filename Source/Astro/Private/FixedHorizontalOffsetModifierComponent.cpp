#include "FixedHorizontalOffsetModifierComponent.h"

UFixedHorizontalOffsetModifierComponent::UFixedHorizontalOffsetModifierComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->UpperLimit = 0.00f;
    this->LowerLimit = 0.00f;
}


