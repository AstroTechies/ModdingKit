#pragma once
#include "CoreMinimal.h"
#include "ERepackagingTargetState.generated.h"

UENUM(BlueprintType)
enum class ERepackagingTargetState : uint8 {
    None,
    Invalid,
    Valid,
};

