#pragma once
#include "CoreMinimal.h"
#include "ECrackableActorMethod.generated.h"

UENUM(BlueprintType)
enum class ECrackableActorMethod : uint8 {
    Hover,
    HoverFaceCamera,
    Pivot,
    None,
};

