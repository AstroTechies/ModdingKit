#include "VoxelVolumeComponent.h"

float UVoxelVolumeComponent::GetSurfaceHeightAtLocation(FVector Location) const {
    return 0.0f;
}

UVoxelVolumeComponent::UVoxelVolumeComponent() {
    this->DynamicPlanetOptimization = 0.00f;
    this->PlanetOptimization = EPlanetOptimization::None;
    this->Seed = -1;
    this->CinematicFixedSeed = -1;
    this->CinematicFixedSeedSecondary = -1;
    this->RandomizeSeedInGame = true;
    this->RandomizeSeedInPIE = true;
    this->ClientsWaitForSeed = true;
    this->VolumeRadius = 51200.00f;
    this->HighestDetailVoxelSize = 150.00f;
    this->HigestDetailRadius = 448.00f;
    this->LODCascadeScale = 1.20f;
    this->bCastShadow = true;
    this->bCastFarShadow = true;
    this->ManuallySetLODRanges = false;
    this->MaxOctreeDepth = 6;
    this->LODRanges.AddDefaulted(7);
    this->MultiplayerCorrectionRange = 512.00f;
    this->NodeCachingFactor = 5.00f;
    this->DefaultMaterial = NULL;
    this->DefaultMaterialShadows = NULL;
    this->DefaultMaterialShadowsHQ = NULL;
    this->HQMaterialRemapTable = NULL;
    this->MaterialPalette = NULL;
    this->PolygonizerType = EPolygonizerType::MarchingCubes;
    this->ObjectDestructionTimeslice = 0.00f;
    this->ObjectCreationTimeslice = 0.00f;
    this->ObjectRegistrationTimeslice = 0.00f;
    this->SurfaceBiomeHighWeightCutoff = 0.80f;
    this->SurfaceBiomeLowWeightCutoff = 0.10f;
    this->m_destructionData = NULL;
    this->m_foliageActor = NULL;
    this->m_locusActorClass = NULL;
    this->m_proxyMesh = NULL;
}

