#include "TappableObjectComponent.h"

void UTappableObjectComponent::UnregisterTapperSlot(FSlotReference tapperSlot) {
}

void UTappableObjectComponent::RegisterTapperSlot(FSlotReference tapperSlot) {
}

float UTappableObjectComponent::GetCurrentTappingEfficiency() {
    return 0.0f;
}

UTappableObjectComponent::UTappableObjectComponent() {
    this->ResourceItemType = NULL;
    this->ResourceProductionRate = 1.00f;
}

