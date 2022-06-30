#include "SlotConnectionReplicationData.h"

FSlotConnectionReplicationData::FSlotConnectionReplicationData() {
    this->TargetScale = 0.00f;
    this->ConnectedComponent = NULL;
    this->Destroying = false;
    this->bIsRetracting = false;
    this->bIsCarryingOxygen = false;
}

