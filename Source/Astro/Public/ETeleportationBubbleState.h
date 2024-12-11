#pragma once
#include "CoreMinimal.h"
#include "ETeleportationBubbleState.generated.h"

UENUM(BlueprintType)
enum class ETeleportationBubbleState : uint8 {
    Uninitialized,
    CharacterEntering,
    Expanding,
    WaitingForTerrain,
    ArrivalCollisionExpanding,
    ReadyToTeleport,
    ArrivedAtDestination,
    CharacterExiting,
    Aborting,
};

