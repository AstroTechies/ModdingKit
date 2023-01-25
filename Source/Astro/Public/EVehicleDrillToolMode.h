#pragma once
#include "CoreMinimal.h"
#include "EVehicleDrillToolMode.generated.h"

UENUM(BlueprintType)
enum class EVehicleDrillToolMode : uint8 {
    Invalid,
    TunnelBoring,
    Excavation,
    DummyDrill,
};

