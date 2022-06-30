#include "BoundedVoxelVolumeModifier.h"

UBoundedVoxelVolumeModifier::UBoundedVoxelVolumeModifier() {
    this->bEnabled = true;
    this->PlacementLODOffset = 0;
    this->ExecutionLODOffset = 0;
    this->Seed = 0;
    this->PlacementMode = EPlacementMode::RandomDistribution;
    this->ExclusionRadius = 0.00f;
    this->DefaultCullingDistance = 0.00f;
    this->PlacementDensity = 0.00f;
    this->MinCount = 0;
    this->maxCount = 0;
}

