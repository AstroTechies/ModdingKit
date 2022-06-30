#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SurfaceCriteria.h"
#include "TerrainPlacementComponent.h"
#include "ESurfaceOrientation.h"
#include "ERaycastDistributionShape.h"
#include "ETerrainPlacementMode.h"
#include "ActorSpecifier.h"
#include "RaycastDistributionComponent.generated.h"

class AActor;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API URaycastDistributionComponent : public UTerrainPlacementComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    int32 Seed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float Radius;

    UPROPERTY(EditAnywhere)
    float Depth;

    UPROPERTY(EditAnywhere)
    float RandomOrientation;

    UPROPERTY(EditAnywhere)
    FSurfaceCriteria SurfaceCriteria;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    ERaycastDistributionShape Shape;

    UPROPERTY(EditAnywhere)
    ESurfaceOrientation Orientation;

    UPROPERTY(EditAnywhere)
    ETerrainPlacementMode TerrainMode;

    UPROPERTY(EditAnywhere)
    uint8 Centered : 1;

    UPROPERTY(EditAnywhere)
    uint8 ApplyTerrainTypeToActor : 1;

    UPROPERTY(EditAnywhere)
    uint8 UseParentMaterial : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 ScaleCount : 1;

    UPROPERTY(EditAnywhere)
    float RaycastDistance;

    UPROPERTY(EditAnywhere)
    float DefaultCullingDistance;

    UPROPERTY()
    int32 Count;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FracCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ActorScaleMin;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ActorScaleMax;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<AActor> Actor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FActorSpecifier> Actors;

    URaycastDistributionComponent();
};
