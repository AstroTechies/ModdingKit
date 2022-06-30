#pragma once
#include "CoreMinimal.h"
#include "FractalProperties.h"
#include "PerturbProperties.generated.h"

USTRUCT()
struct FPerturbProperties {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float Amplitude;
    
    UPROPERTY(EditAnywhere)
    float Frequency;
    
    UPROPERTY(EditAnywhere)
    FFractalProperties FractalProp;
    
    UPROPERTY(EditAnywhere)
    float NormalizationLength;
    
    TERRAIN2_API FPerturbProperties();
};

