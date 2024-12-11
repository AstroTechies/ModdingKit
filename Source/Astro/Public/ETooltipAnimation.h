#pragma once
#include "CoreMinimal.h"
#include "ETooltipAnimation.generated.h"

UENUM(BlueprintType)
enum class ETooltipAnimation : uint8 {
    None,
    BadgeExpanding,
    DetailsExpanding,
    DetailsContracting,
    BadgeContracting,
};

