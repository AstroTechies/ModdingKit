#include "TeleportationBubbleReplicationData.h"

FTeleportationBubbleReplicationData::FTeleportationBubbleReplicationData() {
    this->State = ETeleportationBubbleState::Uninitialized;
    this->DestinationPlanet = NULL;
}

