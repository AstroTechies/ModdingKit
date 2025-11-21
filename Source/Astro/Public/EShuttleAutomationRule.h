#pragma once
#include "CoreMinimal.h"
#include "EShuttleAutomationRule.generated.h"

UENUM(BlueprintType)
enum class EShuttleAutomationRule : uint8 {
    Manual,
    Automatic,
    Recall,
};

