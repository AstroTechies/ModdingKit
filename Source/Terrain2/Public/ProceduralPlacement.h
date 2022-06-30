#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PlacementVariant.h"
#include "EPlacementType.h"
#include "EPlacementImportanceMode.h"
#include "EPlacementPhysicsMode.h"
#include "ProceduralPlacement.generated.h"

UCLASS(Blueprintable, Blueprintable)
class TERRAIN2_API UProceduralPlacement : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FPlacementVariant> Variants;

    UPROPERTY(AdvancedDisplay, EditAnywhere)
    int32 DistributionVariance;

    UPROPERTY(EditAnywhere)
    int32 Seed;

    UPROPERTY(EditAnywhere)
    uint16 SpawnDepthOffset;

    UPROPERTY(EditAnywhere)
    float Radius;

    UPROPERTY(EditAnywhere)
    EPlacementType SurfaceType;

    UPROPERTY(EditAnywhere)
    EPlacementPhysicsMode PhysicsMode;

    UPROPERTY(EditAnywhere)
    EPlacementImportanceMode Importance;

    UPROPERTY(EditAnywhere)
    float MaxAlignmentThresholdDegrees;

    UPROPERTY(EditAnywhere)
    float MinAlignmentThresholdDegrees;

    UPROPERTY(EditAnywhere)
    float MaxProjectionDistance;

    UPROPERTY(EditAnywhere)
    float DensityThreshold;

    UPROPERTY(EditAnywhere)
    float SurfaceHeightAllowedDelta;

private:
    UPROPERTY()
    uint8 bAllVariantsReplicated : 1;

public:
    UProceduralPlacement();
};
