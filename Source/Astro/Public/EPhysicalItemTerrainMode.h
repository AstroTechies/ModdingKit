#pragma once
#include "CoreMinimal.h"
#include "EPhysicalItemTerrainMode.generated.h"

UENUM(BlueprintType)
enum class EPhysicalItemTerrainMode : uint8 {
    Attach,
    Stick,
    Bury,
    Free,
};

