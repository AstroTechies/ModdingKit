#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "VoxelVolumeModifier.generated.h"

UCLASS(Abstract, Blueprintable)
class TERRAIN2_API UVoxelVolumeModifier : public UObject {
    GENERATED_BODY()
public:
    UVoxelVolumeModifier();

};

