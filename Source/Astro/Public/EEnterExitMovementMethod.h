#pragma once
#include "CoreMinimal.h"
#include "EEnterExitMovementMethod.generated.h"

UENUM(BlueprintType)
enum class EEnterExitMovementMethod : uint8 {
    SnapToPosition,
    LerpToPosition,
};

