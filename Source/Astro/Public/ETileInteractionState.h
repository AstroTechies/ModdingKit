#pragma once
#include "CoreMinimal.h"
#include "ETileInteractionState.generated.h"

UENUM(BlueprintType)
enum class ETileInteractionState : uint8 {
    Inactive,
    Hovered,
    Active,
};

