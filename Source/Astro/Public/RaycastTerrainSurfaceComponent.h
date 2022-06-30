#pragma once
#include "CoreMinimal.h"
#include "SurfaceCriteria.h"
#include "TerrainPlacementComponent.h"
#include "ESurfaceOrientation.h"
#include "ERaycastOrientation.h"
#include "RaycastTerrainSurfaceComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API URaycastTerrainSurfaceComponent : public UTerrainPlacementComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float RandomOrientation;

    UPROPERTY(EditAnywhere)
    ESurfaceOrientation Orientation;

    UPROPERTY(EditAnywhere)
    uint8 bApplyOffsetDownFromHit : 1;

    UPROPERTY(EditAnywhere)
    float OffsetDownFromHitDistance;

    UPROPERTY(EditAnywhere)
    float RaycastDistance;

    UPROPERTY(EditAnywhere)
    FSurfaceCriteria SurfaceCriteria;

    UPROPERTY(EditAnywhere)
    ERaycastOrientation RaycastDirection;

    UPROPERTY(EditAnywhere)
    uint8 bUseVoxelTrace : 1;

    UPROPERTY(EditAnywhere)
    float VoxelTraceAccuracy;

    URaycastTerrainSurfaceComponent();
};
