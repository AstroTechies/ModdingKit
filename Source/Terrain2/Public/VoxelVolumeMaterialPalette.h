#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EPhysicalSurface -FallbackName=EPhysicalSurface
#include "CreativePaintMaterialMapping.h"
#include "VoxelMaterial.h"
#include "VoxelVolumeMaterialPalette.generated.h"

class UMaterialInterface;

UCLASS(Blueprintable)
class TERRAIN2_API UVoxelVolumeMaterialPalette : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCreativePaintMaterialMapping> CreativePaintIndices;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVoxelMaterial> PaletteEntries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FVoxelMaterial> RuntimePalette;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DefaultMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TEnumAsByte<EPhysicalSurface>, UMaterialInterface*> DefaultMaterialsBySurfaceType;
    
public:
    UVoxelVolumeMaterialPalette();
};

