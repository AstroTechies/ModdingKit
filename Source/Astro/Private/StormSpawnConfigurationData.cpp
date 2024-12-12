#include "StormSpawnConfigurationData.h"

FStormSpawnConfigurationData::FStormSpawnConfigurationData() {
    this->InfiniteStormLifetime = false;
    this->UseFixedIDsFromStorms = false;
    this->BaseLifetime = 0.00f;
    this->LifetimeVariance = 0.00f;
    this->MaxStormCount = 0;
    this->ChooseClosestNonExcludedSpawnLocation = false;
    this->MinSpawnLocationHistoricalExclusionCount = 0;
    this->StormMutualExclusionRadius = 0;
}

