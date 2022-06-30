#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PaintModeMaterial.h"
#include "VoxelVolumePaintModePalette.generated.h"

UCLASS(Blueprintable, Blueprintable)
class TERRAIN2_API UVoxelVolumePaintModePalette : public UObject
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    TArray<FPaintModeMaterial> DefaultMappings;

    UPROPERTY(EditDefaultsOnly)
    TArray<FPaintModeMaterial> PaletteEntries;

public:
    UVoxelVolumePaintModePalette();
};
