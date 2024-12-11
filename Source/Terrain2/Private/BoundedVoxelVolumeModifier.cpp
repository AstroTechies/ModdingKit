#include "BoundedVoxelVolumeModifier.h"

UBoundedVoxelVolumeModifier::UBoundedVoxelVolumeModifier() {
    this->bEnabled = true;
    this->PlacementLODOffset = 0;
    this->ExecutionLODOffset = 0;
    this->Seed = 0;
    this->PlacementMode = EPlacementMode::RandomDistribution;
    this->ExclusionRadius = 0.00f;
    this->DefaultCullingDistance = 0.00f;
    this->MinManualPlacementRandomPitch = 0.00f;
    this->MinManualPlacementRandomYaw = 0.00f;
    this->MaxManualPlacementRandomPitch = 0.00f;
    this->MaxManualPlacementRandomYaw = 0.00f;
    this->PlacementDensity = 0.00f;
    this->MinCount = 0;
    this->maxCount = 0;
    this->CustomGameScalar = 0.00f;
}


