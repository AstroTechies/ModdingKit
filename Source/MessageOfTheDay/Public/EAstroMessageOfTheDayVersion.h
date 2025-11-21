#pragma once
#include "CoreMinimal.h"
#include "EAstroMessageOfTheDayVersion.generated.h"

UENUM(BlueprintType)
enum class EAstroMessageOfTheDayVersion : uint8 {
    InvalidZero,
    Invalid,
    WebCDNHosted,
    FirstPlayFabVersion,
    SegmentedMOTD,
    ServiceDrivenMarketingWidgets,
    Latest = ServiceDrivenMarketingWidgets,
};

