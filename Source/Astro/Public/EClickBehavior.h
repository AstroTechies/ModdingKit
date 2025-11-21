#pragma once
#include "CoreMinimal.h"
#include "EClickBehavior.generated.h"

UENUM(BlueprintType)
enum class EClickBehavior : uint8 {
    None,
    ClickDelegate,
    CrackableActor,
    Use,
    PhysicalItem,
    ImmovablePhysicalItem,
    InteractionActor,
    Tool,
    Slot,
    Actuator,
    RailSpline,
};

