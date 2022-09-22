#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
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

