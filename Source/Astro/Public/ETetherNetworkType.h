#pragma once
#include "CoreMinimal.h"
#include "ETetherNetworkType.generated.h"

UENUM(BlueprintType)
enum class ETetherNetworkType : uint8 {
    NullNetwork,
    TetherPostNetwork,
    TetherableOxygenProviderNetwork,
};

