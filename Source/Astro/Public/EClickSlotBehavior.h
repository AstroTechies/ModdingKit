#pragma once
#include "CoreMinimal.h"
#include "EClickSlotBehavior.generated.h"

UENUM(BlueprintType)
enum class EClickSlotBehavior : uint8 {
    None,
    ItemSet,
    ConnectionPull,
    ConnectionJoin,
    EmptyHover,
};

