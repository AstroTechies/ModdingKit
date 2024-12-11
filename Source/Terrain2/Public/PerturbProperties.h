#pragma once
#include "CoreMinimal.h"
#include "FractalProperties.h"
#include "PerturbProperties.generated.h"

USTRUCT(BlueprintType)
struct FPerturbProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Amplitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Frequency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFractalProperties FractalProp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NormalizationLength;
    
    TERRAIN2_API FPerturbProperties();
};

