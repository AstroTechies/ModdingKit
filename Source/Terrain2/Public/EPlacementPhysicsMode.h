#pragma once
#include "CoreMinimal.h"
#include "EPlacementPhysicsMode.generated.h"

UENUM(BlueprintType)
enum class EPlacementPhysicsMode : uint8 {
    Bury,
    Free,
    None,
};

