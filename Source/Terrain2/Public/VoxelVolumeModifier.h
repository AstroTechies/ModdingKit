#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "VoxelVolumeModifier.generated.h"

UCLASS(Abstract)
class TERRAIN2_API UVoxelVolumeModifier : public UObject {
    GENERATED_BODY()
public:
    UVoxelVolumeModifier();
};

