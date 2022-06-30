#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "VoxelMaterialProperties.generated.h"

USTRUCT(BlueprintType)
struct TERRAIN2_API FVoxelMaterialProperties {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, SaveGame)
    FLinearColor TerrainColor;
    
    UPROPERTY(EditAnywhere, SaveGame)
    int32 TerrainHardness;
    
    UPROPERTY(EditAnywhere, SaveGame)
    TEnumAsByte<EPhysicalSurface> TerrainSurfaceType;
    
    FVoxelMaterialProperties();
};

