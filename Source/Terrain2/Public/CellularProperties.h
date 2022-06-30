#pragma once
#include "CoreMinimal.h"
#include "ECellType.h"
#include "EDistanceFunction.h"
#include "ENoiseType.h"
#include "CellularProperties.generated.h"

USTRUCT()
struct FCellularProperties {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    ECellType CellType;
    
    UPROPERTY(EditAnywhere)
    float Jitter;
    
    UPROPERTY(EditAnywhere)
    EDistanceFunction DistanceFunction;
    
    UPROPERTY(EditAnywhere)
    int32 DistanceIndex0;
    
    UPROPERTY(EditAnywhere)
    int32 DistanceIndex1;
    
    UPROPERTY(EditAnywhere)
    ENoiseType LookupType;
    
    UPROPERTY(EditAnywhere)
    float Frequency;
    
    TERRAIN2_API FCellularProperties();
};

