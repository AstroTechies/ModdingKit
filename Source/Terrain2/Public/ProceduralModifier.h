#pragma once
#include "CoreMinimal.h"
#include "VoxelVolumeModifier.h"
#include "PlacementApply.h"
#include "ProceduralModifier.generated.h"

UCLASS(Blueprintable, Blueprintable)
class TERRAIN2_API UProceduralModifier : public UVoxelVolumeModifier
{
    GENERATED_BODY()
public:
    UPROPERTY()
    TArray<FPlacementApply> m_compiledPlacements;

    UProceduralModifier();
};
