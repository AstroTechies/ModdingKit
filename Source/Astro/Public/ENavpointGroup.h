#pragma once
#include "CoreMinimal.h"
#include "ENavpointGroup.generated.h"

UENUM(BlueprintType)
enum class ENavpointGroup : uint8 {
    None,
    SnailBuff,
    Scannable,
    SnailMission = 0x4,
};

