#pragma once
#include "CoreMinimal.h"
#include "ESinkType.generated.h"

UENUM(BlueprintType)
enum class ESinkType : uint8 {
    None,
    Resource,
    Byte,
    Power = 4,
    Seed = 8,
};

