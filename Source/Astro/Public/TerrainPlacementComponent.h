#pragma once
#include "CoreMinimal.h"
#include "TerrainModifierBase.h"
#include "TerrainPlacementComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UTerrainPlacementComponent : public UTerrainModifierBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OctreeResOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExclusionRadius;
    
    UTerrainPlacementComponent(const FObjectInitializer& ObjectInitializer);

};

