#pragma once
#include "CoreMinimal.h"
#include "EMarketingWidgetType.generated.h"

UENUM(BlueprintType)
enum class EMarketingWidgetType : uint8 {
    Invalid,
    PaidContentWidget,
    FreeContentWidget,
    Count,
};

