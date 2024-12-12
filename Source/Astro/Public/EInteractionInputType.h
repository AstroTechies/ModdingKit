#pragma once
#include "CoreMinimal.h"
#include "EInteractionInputType.generated.h"

UENUM(BlueprintType)
enum class EInteractionInputType : uint8 {
    Cursor,
    Gamepad,
    None,
};

