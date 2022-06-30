#pragma once
#include "CoreMinimal.h"
#include "EFuelSource.generated.h"

UENUM()
enum class EFuelSource : uint8 {
    InternalPortioned,
    External,
};

