#pragma once
#include "CoreMinimal.h"
#include "EGravitySphereControllerType.generated.h"

UENUM()
enum class EGravitySphereControllerType : uint8 {
    Player,
    AI,
    None,
};

