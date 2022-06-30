#pragma once
#include "CoreMinimal.h"
#include "EResearchBonusTimelineType.generated.h"

UENUM()
enum class EResearchBonusTimelineType : uint8 {
    CumulativeResearchTime,
    CumulativeResearchPoints,
};

