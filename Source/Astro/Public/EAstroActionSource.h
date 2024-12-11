#pragma once
#include "CoreMinimal.h"
#include "EAstroActionSource.generated.h"

UENUM(BlueprintType)
enum class EAstroActionSource : uint8 {
    Server,
    ControllingClient,
};

