#include "FuelConsumerComponent.h"
#include "Templates/SubclassOf.h"

UFuelConsumerComponent::UFuelConsumerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
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

void UFuelConsumerComponent::OnItemSlotted(APhysicalItem* Item) {
}

void UFuelConsumerComponent::OnItemRemoved(APhysicalItem* Item) {
}

void UFuelConsumerComponent::OnItemAmountChanged() {
}

TSubclassOf<UItemType> UFuelConsumerComponent::GetFuelType() {
    return NULL;
}


