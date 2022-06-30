#pragma once
#include "CoreMinimal.h"
#include "EResearchState.h"
#include "ResearchSubjectReplicationData.h"
#include "ResearchReplicationData.generated.h"

USTRUCT(BlueprintType)
struct FResearchReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    EResearchState ResearchState;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float CurrentPowerLevelRatio;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float CurrentResearchRateMultiplier;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float CurrentResearchPointsPerMinute;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TArray<FResearchSubjectReplicationData> ResearchSubjects;
    
    ASTRO_API FResearchReplicationData();
};

