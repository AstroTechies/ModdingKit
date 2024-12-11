#pragma once
#include "CoreMinimal.h"
#include "ECrackableMethod.generated.h"

UENUM(BlueprintType)
enum class ECrackableMethod : uint8 {
    Hover,
    HoverFaceCamera,
    Pivot,
    None,
};

