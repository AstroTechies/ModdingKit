#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PaintModeMaterial.h"
#include "VoxelVolumePaintModePalette.generated.h"

UCLASS(Blueprintable)
class TERRAIN2_API UVoxelVolumePaintModePalette : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPaintModeMaterial> DefaultMappings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPaintModeMaterial> PaletteEntries;
    
public:
    UVoxelVolumePaintModePalette();

};

