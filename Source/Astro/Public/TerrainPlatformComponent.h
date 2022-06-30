#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "VoxelMaterial.h"
#include "UObject/NoExportTypes.h"
#include "DeformationParamsT2.h"
#include "TerrainPlatformComponent.generated.h"

class AAstroPlanet;
class AActor;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UTerrainPlatformComponent : public USceneComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    bool RemoveTopHemisphere;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float Radius;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SoftEdgeStartRadius;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ExtendedMaterialOverrideRadius;

    UPROPERTY(EditAnywhere)
    float Intensity;

    UPROPERTY(EditAnywhere)
    bool UseOverrideMaterial;

    UPROPERTY(EditAnywhere)
    FVoxelMaterial OverrideMaterial;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    bool Enabled;

protected:
    UPROPERTY()
    FVector PlatformCenter;

private:
    UPROPERTY()
    AAstroPlanet *m_planet;

    UPROPERTY(Transient)
    TArray<FDeformationParamsT2> BufferedT2Deforms;

public:
    UTerrainPlatformComponent();

private:
    UFUNCTION()
    void OwnerDestroyed(AActor *DestroyedActor);
};
