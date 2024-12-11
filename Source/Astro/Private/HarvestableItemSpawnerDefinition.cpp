#include "HarvestableItemSpawnerDefinition.h"

FHarvestableItemSpawnerDefinition::FHarvestableItemSpawnerDefinition() {
    this->bItemCanBeUsedBeforeHarvest = false;
    this->bItemRespawns = false;
    this->bSlotRemainsUsableAfterItemHarvested = false;
    this->bItemRespawnsAtEndOfDelay = false;
    this->RespawnDelay = 0.00f;
}

