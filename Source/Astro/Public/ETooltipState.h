#pragma once
#include "CoreMinimal.h"
#include "ETooltipState.generated.h"

UENUM(BlueprintType)
enum class ETooltipState : uint8 {
    Collapsed,
    BadgeVisible,
    FullyPresented,
};

