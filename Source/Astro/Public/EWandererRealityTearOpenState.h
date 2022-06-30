#pragma once
#include "CoreMinimal.h"
#include "EWandererRealityTearOpenState.generated.h"

UENUM()
enum class EWandererRealityTearOpenState : uint8 {
    Closed,
    WillOpen,
    Open,
};

