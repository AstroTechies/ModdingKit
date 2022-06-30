#pragma once
#include "CoreMinimal.h"
#include "EControlsPromptStatus.generated.h"

UENUM()
enum class EControlsPromptStatus : uint8 {
    PromptNotShown,
    PromptShowing,
    PromptShown,
};

