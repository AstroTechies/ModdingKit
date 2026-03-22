#include "HarvestableComponent.h"

FHarvestableComponent::FHarvestableComponent() {
    this->bIsUprooted = false;
    this->bHasPostHarvestUsableSlots = false;
    this->UprootedDestructionDelayRemaining = 0.00f;
}

