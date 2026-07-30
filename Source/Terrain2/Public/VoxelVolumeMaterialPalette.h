#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h" // Data Asset fix
#include "Chaos/ChaosEngineInterface.h"
#include "CreativePaintMaterialMapping.h"
#include "VoxelMaterial.h"
#include "VoxelVolumeMaterialPalette.generated.h"

class UMaterialInterface;

UCLASS(Blueprintable, BlueprintType) 
class TERRAIN2_API UVoxelVolumeMaterialPalette : public UDataAsset { 
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
