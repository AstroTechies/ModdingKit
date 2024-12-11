#include "StormSpawnConfigurationState.h"

FStormSpawnConfigurationState::FStormSpawnConfigurationState() {
    this->Lifetime = 0.00f;
    this->ChooseClosestNonExcludedSpawnLocation = false;
    this->MinSpawnLocationHistoricalExclusionCount = 0;
}

