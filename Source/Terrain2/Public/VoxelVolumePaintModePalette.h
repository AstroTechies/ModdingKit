#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "PaintModeMaterial.h"
#include "VoxelVolumePaintModePalette.generated.h"

UCLASS()
class TERRAIN2_API UVoxelVolumePaintModePalette : public UObject {
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

