#pragma once
#include "CoreMinimal.h"
#include "ResearchPhase.generated.h"

USTRUCT(BlueprintType)
struct FResearchPhase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PointsPerMinute;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PhaseDurationSeconds;
    
    ASTRO_API FResearchPhase();
};

