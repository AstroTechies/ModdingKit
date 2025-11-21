#pragma once
#include "CoreMinimal.h"
#include "EOperationMode.generated.h"

UENUM(BlueprintType)
enum class EOperationMode : uint8 {
    Planet,
    Basic,
    Count,
};

