#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EPlacementMode.h"
#include "ManualPlacement.h"
#include "RandomDistributionProperties.h"
#include "BoundedVoxelVolumeModifier.generated.h"

UCLASS(Blueprintable, DefaultToInstanced, EditInlineNew)
class TERRAIN2_API UBoundedVoxelVolumeModifier : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint8 bEnabled : 1;

    UPROPERTY(EditAnywhere)
    uint8 PlacementLODOffset;

    UPROPERTY(AdvancedDisplay, EditAnywhere)
    uint8 ExecutionLODOffset;

    UPROPERTY(EditAnywhere)
    uint32 Seed;

    UPROPERTY(EditAnywhere)
    EPlacementMode PlacementMode;

    UPROPERTY(EditAnywhere)
    float ExclusionRadius;

    UPROPERTY(EditAnywhere)
    float DefaultCullingDistance;

    UPROPERTY(EditAnywhere)
    TArray<FManualPlacement> ManualPlacements;

    UPROPERTY(EditAnywhere)
    float PlacementDensity;

    UPROPERTY(EditAnywhere)
    int32 MinCount;

    UPROPERTY(EditAnywhere)
    int32 maxCount;

    UPROPERTY(EditAnywhere)
    FRandomDistributionProperties DistributionOptions;

    UBoundedVoxelVolumeModifier();
};
