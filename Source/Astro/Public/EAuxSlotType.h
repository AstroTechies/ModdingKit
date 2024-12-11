#pragma once
#include "CoreMinimal.h"
#include "EAuxSlotType.generated.h"

UENUM(BlueprintType)
enum class EAuxSlotType : uint8 {
    None,
    Left,
    Right,
    LeftAndRight,
};

