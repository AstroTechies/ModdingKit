#pragma once
#include "CoreMinimal.h"
#include "EResearchBonusTimelineType.generated.h"

UENUM(BlueprintType)
enum class EResearchBonusTimelineType : uint8 {
    CumulativeResearchTime,
    CumulativeResearchPoints,
};

