#pragma once
#include "CoreMinimal.h"
#include "BoundedVoxelVolumeModifier.h"
#include "CavesModifier.generated.h"

UCLASS(EditInlineNew)
class TERRAIN2_API UCavesModifier : public UBoundedVoxelVolumeModifier {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    int32 Count;
    
    UPROPERTY(EditAnywhere)
    int32 BackwardCount;
    
    UPROPERTY(EditAnywhere)
    float CaveRadius;
    
    UPROPERTY(EditAnywhere)
    float CaveIntensity;
    
    UPROPERTY(EditAnywhere)
    float FloorFlatness;
    
    UPROPERTY(EditAnywhere)
    float Incline;
    
    UPROPERTY(EditAnywhere)
    float WalkVariation;
    
    UCavesModifier();
};

