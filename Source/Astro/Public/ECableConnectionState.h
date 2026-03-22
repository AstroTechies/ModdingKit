#pragma once
#include "CoreMinimal.h"
#include "ECableConnectionState.generated.h"

UENUM(BlueprintType)
enum class ECableConnectionState : uint8 {
    DisconnectedCable,
    DirectionalCable,
    MergedCable,
};

