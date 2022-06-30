#pragma once
#include "CoreMinimal.h"
#include "SurfaceLayer.h"
#include "GlobalBiome.generated.h"

class UBoundedVoxelVolumeModifier;
class UProceduralModifier;
class UBoundedVoxelVolumeModifierList;

USTRUCT(BlueprintType)
struct TERRAIN2_API FGlobalBiome {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float BaseVolumeRadius;
    
    UPROPERTY(EditAnywhere)
    float TopsoilDepth;
    
    UPROPERTY(EditAnywhere)
    TArray<FSurfaceLayer> MountainLayers;
    
    UPROPERTY(EditAnywhere)
    TArray<UProceduralModifier*> ObjectPlacementModifiers;
    
    UPROPERTY(EditAnywhere, Export)
    TArray<UBoundedVoxelVolumeModifier*> BoundedModifiers;
    
    UPROPERTY(EditAnywhere)
    UBoundedVoxelVolumeModifierList* SharedBoundedModifierList;
    
    FGlobalBiome();
};

