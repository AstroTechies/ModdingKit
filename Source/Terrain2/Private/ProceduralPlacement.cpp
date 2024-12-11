#include "ProceduralPlacement.h"

UProceduralPlacement::UProceduralPlacement() {
    this->DistributionVariance = 3;
    this->Seed = -1;
    this->SpawnDepthOffset = 0;
    this->Radius = 0.00f;
    this->SurfaceType = EPlacementType::Ground;
    this->PhysicsMode = EPlacementPhysicsMode::Bury;
    this->Importance = EPlacementImportanceMode::Normal;
    this->MaxAlignmentThresholdDegrees = 10.00f;
    this->MinAlignmentThresholdDegrees = 0.00f;
    this->MaxProjectionDistance = 0.00f;
    this->DensityThreshold = 0.50f;
    this->SurfaceHeightAllowedDelta = 500.00f;
    this->bAllVariantsReplicated = false;
}


