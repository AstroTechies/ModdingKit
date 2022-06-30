#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TerrainPlacementComponent.h"
#include "MeshDistributionBaseComponent.generated.h"

class AActor;
class UStaticMesh;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UMeshDistributionBaseComponent : public UTerrainPlacementComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float Radius;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool ScaleFromCenterDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMesh *Mesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    int32 Count;

    UPROPERTY(EditAnywhere)
    float ItemCollectionMultiplier;

    UPROPERTY(EditAnywhere)
    float LodMultiplier;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MeshScaleMin;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MeshScaleMax;

    UPROPERTY(EditAnywhere)
    bool UseParentMaterial;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<AActor> DestroySpawnActor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideTerrainCollisionRadius;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool Collision;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool TerrainOverlap;

    UMeshDistributionBaseComponent();
};
