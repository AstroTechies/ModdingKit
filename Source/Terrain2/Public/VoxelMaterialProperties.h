#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EPhysicalSurface -FallbackName=EPhysicalSurface
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

