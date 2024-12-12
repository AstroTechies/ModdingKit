#include "ReplicatedAugmentState.h"

FReplicatedAugmentState::FReplicatedAugmentState() {
    this->AugmentedIntensity = 0.00f;
    this->AugmentedBrushSize = 0.00f;
    this->AugmentedPowerLevel = false;
    this->AugmentedTerrainAnalyzed = false;
    this->AugmentedFixedAlignment = false;
    this->AugmentedHardnessTier = 0.00f;
    this->AugmentedTerrainHardness = 0.00f;
    this->AugmentedTerrainSurfaceType = SurfaceType_Default;
    this->RevertModifications = false;
}

