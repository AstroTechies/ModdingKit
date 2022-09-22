#pragma once
#include "CoreMinimal.h"
#include "SubterraneanLayer.h"
#include "UndergroundBiome.generated.h"

USTRUCT(BlueprintType)
struct TERRAIN2_API FUndergroundBiome {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Thickness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSubterraneanLayer> Layers;
    
    FUndergroundBiome();
};

