#pragma once
#include "CoreMinimal.h"
#include "ESlotType.generated.h"

UENUM(BlueprintType)
enum class ESlotType : uint8 {
    Power,
    Resource,
    Control,
    Tether,
    Rail,
    Inert,
    PowerResource,
    ChassisBlock,
    IDCard,
    Schematic,
    Actuator,
    Unpowered,
    RailConnection,
    RailCar,
};

