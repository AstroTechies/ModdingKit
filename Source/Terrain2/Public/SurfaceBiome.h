#pragma once
#include "CoreMinimal.h"
#include "SurfaceLayer.h"
#include "SurfaceBiome.generated.h"

class UProceduralModifier;

USTRUCT(BlueprintType)
struct TERRAIN2_API FSurfaceBiome {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    UPROPERTY(EditAnywhere)
    int32 Priority;
    
    UPROPERTY(EditAnywhere)
    UProceduralModifier* HeightFunction;
    
    UPROPERTY(EditAnywhere)
    UProceduralModifier* HeightFunctionOptimized;
    
    UPROPERTY(EditAnywhere)
    UProceduralModifier* WeightFuntion;
    
    UPROPERTY(EditAnywhere)
    UProceduralModifier* WeightFuntionOptimized;
    
    UPROPERTY(EditAnywhere)
    TArray<FSurfaceLayer> Layers;
    
    FSurfaceBiome();
};

