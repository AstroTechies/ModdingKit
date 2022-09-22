#pragma once
#include "CoreMinimal.h"
#include "ResearchBonus.h"
#include "EResearchBonusTimelineType.h"
#include "ResearchBonusTimeline.generated.h"

USTRUCT(BlueprintType)
struct FResearchBonusTimeline {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> PrerequisiteTimelines;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EResearchBonusTimelineType TimelineType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FResearchBonus> Bonuses;
    
    ASTRO_API FResearchBonusTimeline();
};

