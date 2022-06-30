#include "MeshDistributionBaseComponent.h"

UMeshDistributionBaseComponent::UMeshDistributionBaseComponent() {
    this->Radius = 1000.00f;
    this->ScaleFromCenterDistance = true;
    this->Mesh = NULL;
    this->Count = 50;
    this->ItemCollectionMultiplier = 1.00f;
    this->LodMultiplier = 1.00f;
    this->MeshScaleMin = 1.00f;
    this->MeshScaleMax = 1.00f;
    this->UseParentMaterial = true;
    this->DestroySpawnActor = NULL;
    this->OverrideTerrainCollisionRadius = 0.00f;
    this->Collision = false;
    this->TerrainOverlap = false;
}

