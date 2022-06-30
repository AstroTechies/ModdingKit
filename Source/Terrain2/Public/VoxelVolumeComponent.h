#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/SceneComponent.h"
#include "T2MaterialCache.h"
#include "DeformableInterfaceT2.h"
#include "Engine/EngineTypes.h"
#include "DeformationParamsT2.h"
#include "EPlanetOptimization.h"
#include "EPolygonizerType.h"
#include "GlobalBiome.h"
#include "ChildModifierCacheEntry.h"
#include "SurfaceBiome.h"
#include "UndergroundBiome.h"
#include "DeferredObjectCreationNodeData.h"
#include "UObject/NoExportTypes.h"
#include "VoxelVolumeComponent.generated.h"

class UMaterialInterface;
class UVoxelVolumeMaterialPalette;
class UMaterialRemapTable;
class UTerrain2ProceduralMeshComponent;
class UAstroFoliageDestructionData;
class AActor;
class AAstroFoliageActor;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class TERRAIN2_API UVoxelVolumeComponent : public USceneComponent, public IDeformableInterfaceT2
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeformationT2CompleteEvent, const FDeformationParamsT2 &, params);

    UPROPERTY(EditAnywhere)
    float DynamicPlanetOptimization;

    UPROPERTY(EditAnywhere)
    EPlanetOptimization PlanetOptimization;

private:
    UPROPERTY(EditAnywhere)
    int32 Seed;

    UPROPERTY(EditAnywhere)
    int32 CinematicFixedSeed;

    UPROPERTY(EditAnywhere)
    int32 CinematicFixedSeedSecondary;

    UPROPERTY(EditAnywhere)
    bool RandomizeSeedInGame;

    UPROPERTY(EditAnywhere)
    bool RandomizeSeedInPIE;

    UPROPERTY(EditAnywhere)
    bool ClientsWaitForSeed;

public:
    UPROPERTY(EditAnywhere)
    float VolumeRadius;

    UPROPERTY(EditAnywhere)
    float HighestDetailVoxelSize;

    UPROPERTY(EditAnywhere)
    float HigestDetailRadius;

    UPROPERTY(EditAnywhere)
    float LODCascadeScale;

    UPROPERTY(EditAnywhere)
    uint8 bCastShadow : 1;

    UPROPERTY(EditAnywhere)
    uint8 bCastFarShadow : 1;

    UPROPERTY(AdvancedDisplay, EditAnywhere)
    uint8 ManuallySetLODRanges : 1;

    UPROPERTY(AdvancedDisplay, EditAnywhere)
    int8 MaxOctreeDepth;

    UPROPERTY(AdvancedDisplay, EditAnywhere, EditFixedSize)
    TArray<float> LODRanges;

    UPROPERTY(AdvancedDisplay, EditAnywhere)
    float MultiplayerCorrectionRange;

    UPROPERTY(AdvancedDisplay, EditAnywhere)
    float NodeCachingFactor;

    UPROPERTY(EditAnywhere)
    UMaterialInterface *DefaultMaterial;

    UPROPERTY(EditAnywhere)
    TMap<TEnumAsByte<EPhysicalSurface>, UMaterialInterface *> DefaultMaterialsBySurfaceType;

    UPROPERTY(EditAnywhere)
    UMaterialInterface *DefaultMaterialShadows;

    UPROPERTY(EditAnywhere)
    UMaterialInterface *DefaultMaterialShadowsHQ;

    UPROPERTY(EditAnywhere)
    UMaterialRemapTable *HQMaterialRemapTable;

    UPROPERTY(EditAnywhere)
    UVoxelVolumeMaterialPalette *MaterialPalette;

    UPROPERTY(EditAnywhere)
    EPolygonizerType PolygonizerType;

    UPROPERTY(EditAnywhere)
    float ObjectDestructionTimeslice;

    UPROPERTY(EditAnywhere)
    float ObjectCreationTimeslice;

    UPROPERTY(EditAnywhere)
    float ObjectRegistrationTimeslice;

    UPROPERTY(AdvancedDisplay, EditAnywhere)
    float SurfaceBiomeHighWeightCutoff;

    UPROPERTY(AdvancedDisplay, EditAnywhere)
    float SurfaceBiomeLowWeightCutoff;

    UPROPERTY(EditAnywhere)
    FGlobalBiome GlobalBiome;

    UPROPERTY(EditAnywhere)
    TArray<FSurfaceBiome> SurfaceBiomes;

    UPROPERTY(EditAnywhere)
    FUndergroundBiome CrustBiome;

    UPROPERTY(EditAnywhere)
    FUndergroundBiome MantleBiome;

    UPROPERTY(EditAnywhere)
    FUndergroundBiome CoreBiome;

    UPROPERTY(Transient)
    FT2MaterialCache MaterialCache;

private:
    UPROPERTY(Export, Transient)
    TArray<UTerrain2ProceduralMeshComponent *> m_LODInProgressMeshes;

    UPROPERTY(Transient)
    UAstroFoliageDestructionData *m_destructionData;

    UPROPERTY(Export, Transient)
    TArray<UTerrain2ProceduralMeshComponent *> m_meshComponentPool;

    UPROPERTY(Export, Transient)
    TArray<UTerrain2ProceduralMeshComponent *> m_meshRecyclePool;

    UPROPERTY(Export, Transient)
    TArray<UTerrain2ProceduralMeshComponent *> m_meshCleanupPool;

    UPROPERTY()
    TMap<FName, FChildModifierCacheEntry> m_childModifierCache;

    UPROPERTY(Transient)
    TArray<AActor *> m_spawnedActorList;

    UPROPERTY(Transient)
    TArray<AActor *> m_deferredDestructionActors;

    UPROPERTY(Transient)
    TArray<AAstroFoliageActor *> m_deferredDestructionFoliageActors;

    UPROPERTY(Transient)
    TArray<FDeferredObjectCreationNodeData> m_deferredObjectCreationNodes;

    UPROPERTY(Transient)
    TArray<UMaterialInterface *> LodMaterials;

    UPROPERTY(Transient)
    TArray<UMaterialInterface *> RandomMaterials;

    UPROPERTY(Transient)
    AAstroFoliageActor *m_foliageActor;

    UPROPERTY(Transient)
    TSubclassOf<AActor> m_locusActorClass;

    UPROPERTY(Export, Transient)
    UTerrain2ProceduralMeshComponent *m_proxyMesh;

public:
    UVoxelVolumeComponent();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    float GetSurfaceHeightAtLocation(FVector Location) const;

    // Fix for true pure virtual functions not being implemented
};
