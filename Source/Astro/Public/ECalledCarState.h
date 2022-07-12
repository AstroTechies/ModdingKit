#pragma once
#include "CoreMinimal.h"
#include "ECalledCarState.generated.h"

UENUM(BlueprintType)
enum class ECalledCarState : uint8 {
    None,
    Searching,
    Calling,
    Failed,
    Cancelled,
};

