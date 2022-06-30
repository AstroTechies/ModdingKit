#pragma once
#include "CoreMinimal.h"
#include "EVehicleDrillToolMode.generated.h"

UENUM()
enum class EVehicleDrillToolMode : uint8 {
    Invalid,
    TunnelBoring,
    Excavation,
    DummyDrill,
};

