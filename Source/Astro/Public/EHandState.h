#pragma once
#include "CoreMinimal.h"
#include "EHandState.generated.h"

UENUM(BlueprintType)
enum class EHandState : uint8 {
    HS_Empty,
    HS_Grabbing,
    HS_Holding,
    HS_Releasing,
    HS_MAX UMETA(Hidden),
};

