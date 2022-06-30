#pragma once
#include "CoreMinimal.h"
#include "EAstroMessageOfTheDayVersion.generated.h"

UENUM(BlueprintType)
enum class EAstroMessageOfTheDayVersion : uint8 {
    Invalid = 0x1,
    WebCDNHosted,
    FirstPlayFabVersion,
    Latest = 0x3,
};

