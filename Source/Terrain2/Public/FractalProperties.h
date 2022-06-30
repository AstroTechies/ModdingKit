#pragma once
#include "CoreMinimal.h"
#include "FractalProperties.generated.h"

USTRUCT(BlueprintType)
struct FFractalProperties {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    int32 Octaves;
    
    UPROPERTY(EditAnywhere)
    float Lacunarity;
    
    UPROPERTY(EditAnywhere)
    float Gain;
    
    TERRAIN2_API FFractalProperties();
};

