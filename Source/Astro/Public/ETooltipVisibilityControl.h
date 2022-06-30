#pragma once
#include "CoreMinimal.h"
#include "ETooltipVisibilityControl.generated.h"

UENUM()
enum class ETooltipVisibilityControl : uint8 {
    ShowOnFocus,
    BadgeAlwaysDetailsOnFocus,
    BadgeAlwaysDetailsProximity,
    BadgeProximityDetailsOnFocus,
    BadgeAlwaysDetailsCustom,
    BadgeProximityDetailsCustom,
    BadgeProximityDetailsProximity,
    Custom,
};

