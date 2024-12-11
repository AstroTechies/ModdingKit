#include "TerrainPlacementComponent.h"

UTerrainPlacementComponent::UTerrainPlacementComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OctreeResOffset = 0;
    this->ExclusionRadius = 0.00f;
}


