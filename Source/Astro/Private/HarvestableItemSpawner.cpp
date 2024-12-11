#include "HarvestableItemSpawner.h"

FHarvestableItemSpawner::FHarvestableItemSpawner() {
    this->ItemType = NULL;
    this->SecondsUntilRespawn = 0.00f;
    this->SpawnerType = EHarvestableItemSpawnerType::Primary;
}

