#include "PowerSlot.h"
#include "ESlotType.h"

APowerSlot::APowerSlot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->slotType = ESlotType::Power;
}

void APowerSlot::SetPoweredTrue() {
}

void APowerSlot::SetPoweredFalse() {
}



void APowerSlot::PowerSetItem(APhysicalItem* Item) {
}

void APowerSlot::PowerReleaseItem(APhysicalItem* Item) {
}


