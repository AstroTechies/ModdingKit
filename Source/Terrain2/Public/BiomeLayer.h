#pragma once
#include "CoreMinimal.h"
#include "BiomeAudioEvents.h"
#include "BiomeLayer.generated.h"

class UProceduralModifier;
class UBoundedVoxelVolumeModifier;
class UBoundedVoxelVolumeModifierList;

USTRUCT()
struct TERRAIN2_API FBiomeLayer {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    UPROPERTY(EditAnywhere)
    UProceduralModifier* VoxelFunction;
    
    UPROPERTY(EditAnywhere)
    UProceduralModifier* VoxelFunctionOptimized;
    
    UPROPERTY(EditAnywhere)
    TArray<UProceduralModifier*> ObjectPlacementModifiers;
    
    UPROPERTY(EditAnywhere, Export)
    TArray<UBoundedVoxelVolumeModifier*> BoundedModifiers;
    
    UPROPERTY(EditAnywhere)
    UBoundedVoxelVolumeModifierList* SharedBoundedModifierList;
    
    UPROPERTY(AdvancedDisplay, EditAnywhere)
    float UpperMarginZone;
    
    UPROPERTY(AdvancedDisplay, EditAnywhere)
    float LowerMarginZone;
    
    UPROPERTY(AdvancedDisplay, EditAnywhere)
    float UpperTransitionZone;
    
    UPROPERTY(AdvancedDisplay, EditAnywhere)
    float LowerTransitionZone;
    
    UPROPERTY(EditAnywhere)
    FBiomeAudioEvents BiomeAudio;
    
    FBiomeLayer();
};

