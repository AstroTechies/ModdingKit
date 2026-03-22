#pragma once
#include "CoreMinimal.h"
#include "EFullnessActuatorResponseMode.generated.h"

UENUM(BlueprintType)
enum class EFullnessActuatorResponseMode : uint8 {
    FullOrNotFull,
    EmptyOrNotEmpty,
    FullOrEmpty,
    Count,
};

