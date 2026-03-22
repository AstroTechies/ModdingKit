#pragma once
#include "CoreMinimal.h"
#include "BiomeLayer.h"
#include "SurfaceLayer.generated.h"

USTRUCT(BlueprintType)
struct TERRAIN2_API FSurfaceLayer : public FBiomeLayer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LayerCeiling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LayerFloor;
    
    FSurfaceLayer();
};

