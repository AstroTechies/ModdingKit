#pragma once
#include "CoreMinimal.h"
#include "ETooltipPresentationStyleTypes.generated.h"

UENUM(BlueprintType)
enum class ETooltipPresentationStyleTypes : uint8 {
    StandardTooltip,
    BadgelessTooltip,
    AstroInteraction,
};

