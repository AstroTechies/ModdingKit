#include "ItemConverterReplicationData.h"

FItemConverterReplicationData::FItemConverterReplicationData() {
    this->bWantsToBeActive = false;
    this->bShouldLoopProduction = false;
    this->ItemConverterState = EItemConverterState::Inactive;
    this->PowerRatio = 0.00f;
    this->SelectedOutputItemTypeIndex = 0;
}

