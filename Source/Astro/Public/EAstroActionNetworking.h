#pragma once
#include "CoreMinimal.h"
#include "EAstroActionNetworking.generated.h"

UENUM(BlueprintType)
enum class EAstroActionNetworking : uint8 {
    Networked,
    LocalOwnerOnly,
    LocalSimulatedProxy,
};

