#pragma once
#include "CoreMinimal.h"
#include "ERoverID.generated.h"

UENUM(BlueprintType)
enum class ERoverID : uint8 {
    SmallRover,
    MediumRover,
    LargeRover,
    UntrackedRover,
};

