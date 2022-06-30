#pragma once
#include "CoreMinimal.h"
#include "EInteractionInputType.generated.h"

UENUM()
enum class EInteractionInputType {
    Cursor,
    Gamepad,
    None,
};

