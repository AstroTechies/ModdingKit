#pragma once
#include "CoreMinimal.h"
#include "VoxelMaterialProperties.h"
#include "ReplicatedCreativeColorPickState.generated.h"

USTRUCT(BlueprintType)
struct FReplicatedCreativeColorPickState {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    FVoxelMaterialProperties TerrainProperties;
    
    UPROPERTY(Transient)
    FName TerrainCustomMaterial;
    
    UPROPERTY(Transient)
    int32 Index;
    
    ASTRO_API FReplicatedCreativeColorPickState();
};

