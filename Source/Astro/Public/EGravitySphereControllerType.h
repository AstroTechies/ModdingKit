#pragma once
#include "CoreMinimal.h"
#include "EGravitySphereControllerType.generated.h"

UENUM(BlueprintType)
enum class EGravitySphereControllerType : uint8 {
    Player,
    AI,
    None,
};

