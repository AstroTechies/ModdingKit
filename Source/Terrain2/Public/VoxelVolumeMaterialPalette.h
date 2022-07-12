#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EPhysicalSurface -FallbackName=EPhysicalSurface
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "CreativePaintMaterialMapping.h"
#include "VoxelMaterial.h"
#include "VoxelVolumeMaterialPalette.generated.h"

class UMaterialInterface;

UCLASS()
class TERRAIN2_API UVoxelVolumeMaterialPalette : public UObject {
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
    UMaterialInterface* DefaultMaterial;
    
    UPROPERTY(Transient)
    TMap<TEnumAsByte<EPhysicalSurface>, UMaterialInterface*> DefaultMaterialsBySurfaceType;
    
public:
    UVoxelVolumeMaterialPalette();
};

