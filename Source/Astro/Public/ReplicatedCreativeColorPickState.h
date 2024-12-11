#pragma once
#include "CoreMinimal.h"
#include "VoxelMaterialProperties.h"
#include "ReplicatedCreativeColorPickState.generated.h"

USTRUCT(BlueprintType)
struct FReplicatedCreativeColorPickState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVoxelMaterialProperties TerrainProperties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName TerrainCustomMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    ASTRO_API FReplicatedCreativeColorPickState();
};

