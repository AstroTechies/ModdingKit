#pragma once
#include "CoreMinimal.h"
#include "EControlsPromptStatus.generated.h"

UENUM(BlueprintType)
enum class EControlsPromptStatus : uint8 {
    PromptNotShown,
    PromptShowing,
    PromptShown,
};

