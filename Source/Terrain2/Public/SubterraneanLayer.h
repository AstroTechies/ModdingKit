#pragma once
#include "CoreMinimal.h"
#include "BiomeLayer.h"
#include "SubterraneanLayer.generated.h"

USTRUCT(BlueprintType)
struct TERRAIN2_API FSubterraneanLayer : public FBiomeLayer {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float Thickness;
    
    FSubterraneanLayer();
};

