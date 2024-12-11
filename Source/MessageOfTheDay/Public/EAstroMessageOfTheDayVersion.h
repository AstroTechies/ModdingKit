#pragma once
#include "CoreMinimal.h"
#include "EAstroMessageOfTheDayVersion.generated.h"

UENUM(BlueprintType)
enum class EAstroMessageOfTheDayVersion : uint8 {
    Invalid = 1,
    WebCDNHosted,
    FirstPlayFabVersion,
    SegmentedMOTD,
    Latest = SegmentedMOTD,
};

