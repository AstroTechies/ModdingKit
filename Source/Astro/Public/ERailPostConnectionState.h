#pragma once
#include "CoreMinimal.h"
#include "ERailPostConnectionState.generated.h"

UENUM()
enum class ERailPostConnectionState : uint8 {
    Asleep_Valid,
    Awake,
    GeneratingConnections,
    Asleep_Invalid,
};

