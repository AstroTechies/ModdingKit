#pragma once
#include "CoreMinimal.h"
#include "ECrackableActorMethod.generated.h"

UENUM()
enum class ECrackableActorMethod : uint8 {
    Hover,
    HoverFaceCamera,
    Pivot,
    None,
};

