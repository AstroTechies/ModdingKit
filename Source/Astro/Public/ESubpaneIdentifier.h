#pragma once
#include "CoreMinimal.h"
#include "ESubpaneIdentifier.generated.h"

UENUM(BlueprintType)
enum class ESubpaneIdentifier : uint8 {
    Left,
    Right,
    None,
    Count,
};

