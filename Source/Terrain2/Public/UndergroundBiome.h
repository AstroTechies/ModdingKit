#pragma once
#include "CoreMinimal.h"
#include "SubterraneanLayer.h"
#include "UndergroundBiome.generated.h"

USTRUCT(BlueprintType)
struct TERRAIN2_API FUndergroundBiome {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    UPROPERTY(EditAnywhere)
    float Thickness;
    
    UPROPERTY(EditAnywhere)
    TArray<FSubterraneanLayer> Layers;
    
    FUndergroundBiome();
};

