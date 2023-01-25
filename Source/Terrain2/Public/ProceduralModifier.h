#pragma once
#include "CoreMinimal.h"
#include "PlacementApply.h"
#include "VoxelVolumeModifier.h"
#include "ProceduralModifier.generated.h"

UCLASS(Blueprintable)
class TERRAIN2_API UProceduralModifier : public UVoxelVolumeModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPlacementApply> m_compiledPlacements;
    
    UProceduralModifier();
};

