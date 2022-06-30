#pragma once
#include "CoreMinimal.h"
#include "ELodAnchorState.generated.h"

UENUM()
enum class ELodAnchorState : int8 {
    Invalid = -0x1,
    NotAnchored,
    Anchored,
};

