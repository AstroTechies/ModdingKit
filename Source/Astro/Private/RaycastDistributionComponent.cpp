#include "RaycastDistributionComponent.h"

URaycastDistributionComponent::URaycastDistributionComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Seed = -1;
    this->Radius = 1000.00f;
    this->Depth = 0.00f;
    this->RandomOrientation = 0.00f;
    this->Shape = ERaycastDistributionShape::Cylinder;
    this->Orientation = ESurfaceOrientation::TerrainNormal;
    this->TerrainMode = ETerrainPlacementMode::Stick;
    this->Centered = true;
    this->ApplyTerrainTypeToActor = false;
    this->UseParentMaterial = false;
    this->ScaleCount = true;
    this->RaycastDistance = 1000.00f;
    this->DefaultCullingDistance = 0.00f;
    this->Count = 50;
    this->FracCount = 50.00f;
    this->ActorScaleMin = 1.00f;
    this->ActorScaleMax = 1.00f;
    this->Actor = NULL;
}


