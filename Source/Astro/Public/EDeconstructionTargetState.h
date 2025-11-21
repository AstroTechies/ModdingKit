#pragma once
#include "CoreMinimal.h"
#include "EDeconstructionTargetState.generated.h"

UENUM(BlueprintType)
enum class EDeconstructionTargetState : uint8 {
    None,
    Invalid,
    Valid,
};

