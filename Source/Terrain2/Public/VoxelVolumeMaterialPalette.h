#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CreativePaintMaterialMapping.h"
#include "VoxelMaterial.h"
#include "Engine/EngineTypes.h"
#include "VoxelVolumeMaterialPalette.generated.h"

class UMaterialInterface;

UCLASS(Blueprintable, Blueprintable)
class TERRAIN2_API UVoxelVolumeMaterialPalette : public UObject
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    TArray<FCreativePaintMaterialMapping> CreativePaintIndices;

    UPROPERTY(EditDefaultsOnly)
    TArray<FVoxelMaterial> PaletteEntries;

    UPROPERTY(Transient)
    TArray<FVoxelMaterial> RuntimePalette;

    UPROPERTY(Transient)
    UMaterialInterface *DefaultMaterial;

    UPROPERTY(Transient)
    TMap<TEnumAsByte<EPhysicalSurface>, UMaterialInterface *> DefaultMaterialsBySurfaceType;

public:
    UVoxelVolumeMaterialPalette();
};
