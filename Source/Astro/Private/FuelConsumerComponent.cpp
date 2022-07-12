#include "FuelConsumerComponent.h"
#include "Templates/SubclassOf.h"

class UItemType;
class APhysicalItem;

void UFuelConsumerComponent::OnItemSlotted(APhysicalItem* Item) {
}

void UFuelConsumerComponent::OnItemRemoved(APhysicalItem* Item) {
}

void UFuelConsumerComponent::OnItemAmountChanged() {
}

TSubclassOf<UItemType> UFuelConsumerComponent::GetFuelType() {
    return NULL;
}

UFuelConsumerComponent::UFuelConsumerComponent() {
    this->bOperatesOnCharacterOnly = true;
    this->LowFuelThreshold = 0.10f;
    this->FuelPerPortion = 0.00f;
    this->FuelSource = EFuelSource::External;
    this->FuelType = NULL;
    this->ConsumptionRate = 0.00f;
    this->NetworkSyncFuelTimer = 0.50f;
    this->SlotsComponent = NULL;
    this->ItemOwner = NULL;
    this->AstroCharacter = NULL;
}

