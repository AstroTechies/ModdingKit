#pragma once
#include "CoreMinimal.h"
#include "CumulativeResearchTracker.generated.h"

USTRUCT(BlueprintType)
struct FCumulativeResearchTracker {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    double Time;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float DisplayedTime;
    
    UPROPERTY(SaveGame)
    double Points;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float DisplayedPoints;
    
    UPROPERTY(SaveGame)
    float MissionsNotificationAccumulator;
    
    ASTRO_API FCumulativeResearchTracker();
};

