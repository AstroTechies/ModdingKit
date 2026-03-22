#pragma once
#include "CoreMinimal.h"
#include "SurfaceLayer.h"
#include "GlobalBiome.generated.h"

class UBoundedVoxelVolumeModifier;
class UBoundedVoxelVolumeModifierList;
class UProceduralModifier;

USTRUCT(BlueprintType)
struct TERRAIN2_API FGlobalBiome {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseVolumeRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TopsoilDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSurfaceLayer> MountainLayers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UProceduralModifier*> ObjectPlacementModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UBoundedVoxelVolumeModifier*> BoundedModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBoundedVoxelVolumeModifierList* SharedBoundedModifierList;
    
    FGlobalBiome();
};

