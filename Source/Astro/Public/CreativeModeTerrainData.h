#pragma once
#include "CoreMinimal.h"
#include "PaintIndex.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "CreativeModeTerrainData.generated.h"

class UVoxelVolumePaintModePalette;
class UWorld;
class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct FCreativeModeTerrainData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FPaintIndex PaintIndex;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    int32 TerrainHardnessOverride;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FName CustomMaterialOverride;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EPhysicalSurface> TerrainSurfaceTypeOverride;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FLinearColor ColorOverride;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    UVoxelVolumePaintModePalette* PaintPalette;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    int32 SpecialPaletteIndex;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FVector PlayerRefPos;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    UWorld* World;
    
    UPROPERTY(Transient)
    TMap<uint32, UMaterialInstanceDynamic*> PlanetButtonInstances;
    
    ASTRO_API FCreativeModeTerrainData();
};

