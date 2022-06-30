#pragma once
#include "CoreMinimal.h"
#include "ResearchBonus.h"
#include "EResearchBonusTimelineType.h"
#include "ResearchBonusTimeline.generated.h"

USTRUCT(BlueprintType)
struct FResearchBonusTimeline {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    FName Name;
    
    UPROPERTY(EditDefaultsOnly)
    TArray<FName> PrerequisiteTimelines;
    
    UPROPERTY(EditDefaultsOnly)
    EResearchBonusTimelineType TimelineType;
    
    UPROPERTY(EditDefaultsOnly)
    TArray<FResearchBonus> Bonuses;
    
    ASTRO_API FResearchBonusTimeline();
};

