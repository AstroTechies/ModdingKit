#include "VoxelVolumeComponent.h"

UVoxelVolumeComponent::UVoxelVolumeComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Mobility = EComponentMobility::Static;
    this->DynamicPlanetOptimization = 0.00f;
    this->PlanetOptimization = EPlanetOptimization::None;
    this->Seed = -1;
    this->CinematicFixedSeed = -1;
    this->CinematicFixedSeedSecondary = -1;
    this->RandomizeSeedInGame = true;
    this->RandomizeSeedInPIE = true;
    this->ClientsWaitForSeed = true;
    this->CustomGameSeed = -1;
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
    this->IsCustomGame = false;
    this->m_destructionData = NULL;
    this->m_foliageActor = NULL;
    this->m_locusActorClass = NULL;
    this->m_proxyMesh = NULL;
}

void UVoxelVolumeComponent::SetCustomGameSeed(int32 newCustomGameSeed) {
}

void UVoxelVolumeComponent::SetCustomGameBiomeModifiersData(FCustomGameModifierData& modifierData) {
}

void UVoxelVolumeComponent::LogCustomGameBiomeModifiersData() {
}

float UVoxelVolumeComponent::GetSurfaceHeightAtLocation(FVector Location) const {
    return 0.0f;
}

void UVoxelVolumeComponent::GetCustomGameBiomesData(TArray<FCustomGameBiomeData>& outData) {
}

void UVoxelVolumeComponent::GetCustomGameBiomeModifiersData(FGameplayTagContainer biomeTags, FCustomGameModifierCollection& outData) {
}

void UVoxelVolumeComponent::ClearCustomGameState() {
}


