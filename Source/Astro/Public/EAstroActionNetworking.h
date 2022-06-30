#pragma once
#include "CoreMinimal.h"
#include "EAstroActionNetworking.generated.h"

UENUM()
enum class EAstroActionNetworking : uint8 {
    Networked,
    LocalOwnerOnly,
    LocalSimulatedProxy,
};

