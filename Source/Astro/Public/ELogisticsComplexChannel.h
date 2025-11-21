#pragma once
#include "CoreMinimal.h"
#include "ELogisticsComplexChannel.generated.h"

UENUM(BlueprintType)
enum class ELogisticsComplexChannel : uint8 {
    None,
    RailA,
    RailB,
    RailC,
    ShuttleA,
    ShuttleB,
    ShuttleC,
};

