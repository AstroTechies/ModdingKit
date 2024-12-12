#include "TappableObjectComponent.h"

UTappableObjectComponent::UTappableObjectComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ResourceItemType = NULL;
    this->ResourceProductionRate = 1.00f;
}

void UTappableObjectComponent::UnregisterTapperSlot(FSlotReference tapperSlot) {
}

void UTappableObjectComponent::RegisterTapperSlot(FSlotReference tapperSlot) {
}

float UTappableObjectComponent::GetCurrentTappingEfficiency() {
    return 0.0f;
}

void UTappableObjectComponent::AwakenSlottedItems() {
}


