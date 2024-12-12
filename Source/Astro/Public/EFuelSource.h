#pragma once
#include "CoreMinimal.h"
#include "EFuelSource.generated.h"

UENUM(BlueprintType)
enum class EFuelSource : uint8 {
    InternalPortioned,
    External,
};

