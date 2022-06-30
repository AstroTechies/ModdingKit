#pragma once
#include "CoreMinimal.h"
#include "TerrainModifierBase.h"
#include "TerrainPlacementComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UTerrainPlacementComponent : public UTerrainModifierBase
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    int32 OctreeResOffset;

    UPROPERTY(EditAnywhere)
    float ExclusionRadius;

    UTerrainPlacementComponent();
};
