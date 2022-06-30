#include "RaycastTerrainSurfaceComponent.h"

URaycastTerrainSurfaceComponent::URaycastTerrainSurfaceComponent() {
    this->RandomOrientation = 0.00f;
    this->Orientation = ESurfaceOrientation::TerrainNormal;
    this->bApplyOffsetDownFromHit = false;
    this->OffsetDownFromHitDistance = 0.00f;
    this->RaycastDistance = 1000.00f;
    this->RaycastDirection = ERaycastOrientation::PlanetUp;
    this->bUseVoxelTrace = false;
    this->VoxelTraceAccuracy = 10.00f;
}

