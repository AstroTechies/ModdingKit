#pragma once
#include "CoreMinimal.h"
#include "EIndicatorTooltipType.generated.h"

UENUM(BlueprintType)
enum class EIndicatorTooltipType : uint8 {
    ResourceRequest,
    CraftingOutputPreview,
    NoTooltip,
};

