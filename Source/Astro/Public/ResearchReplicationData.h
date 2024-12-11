#pragma once
#include "CoreMinimal.h"
#include "EResearchState.h"
#include "ResearchSubjectReplicationData.h"
#include "ResearchReplicationData.generated.h"

USTRUCT(BlueprintType)
struct FResearchReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EResearchState ResearchState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentPowerLevelRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentResearchRateMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentResearchPointsPerMinute;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FResearchSubjectReplicationData> ResearchSubjects;
    
    ASTRO_API FResearchReplicationData();
};

