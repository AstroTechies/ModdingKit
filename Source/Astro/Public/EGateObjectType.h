#pragma once
#include "CoreMinimal.h"
#include "EGateObjectType.generated.h"

UENUM(BlueprintType)
enum class EGateObjectType : uint8 {
    Chamber,
    Engine,
    Station,
};

