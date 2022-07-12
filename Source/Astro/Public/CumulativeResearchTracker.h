#pragma once
#include "CoreMinimal.h"
#include "CumulativeResearchTracker.generated.h"

USTRUCT(BlueprintType)
struct FCumulativeResearchTracker {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, SaveGame)
    double Time;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DisplayedTime;
    
    UPROPERTY(EditAnywhere, SaveGame)
    double Points;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DisplayedPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float MissionsNotificationAccumulator;
    
    ASTRO_API FCumulativeResearchTracker();
};

