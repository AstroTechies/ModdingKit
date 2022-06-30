#pragma once
#include "CoreMinimal.h"
#include "ResearchPhase.generated.h"

USTRUCT(BlueprintType)
struct FResearchPhase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    float PointsPerMinute;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    float PhaseDurationSeconds;
    
    ASTRO_API FResearchPhase();
};

