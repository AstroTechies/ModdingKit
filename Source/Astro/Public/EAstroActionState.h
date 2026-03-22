#pragma once
#include "CoreMinimal.h"
#include "EAstroActionState.generated.h"

UENUM(BlueprintType)
enum class EAstroActionState : uint8 {
    Inactive,
    Active,
    Aborted,
    Completed,
};

