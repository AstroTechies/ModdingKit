#pragma once
#include "CoreMinimal.h"
#include "ELodAnchorState.generated.h"

UENUM()
enum class ELodAnchorState : int8 {
    Invalid = -1,
    NotAnchored = 0,
    Anchored,
};

