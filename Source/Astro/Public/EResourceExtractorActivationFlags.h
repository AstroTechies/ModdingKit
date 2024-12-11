#pragma once
#include "CoreMinimal.h"
#include "EResourceExtractorActivationFlags.generated.h"

UENUM(BlueprintType)
enum class EResourceExtractorActivationFlags : uint8 {
    None,
    HasPower,
    IsPlaced,
    HasAvailableStorage = 4,
    HasWorkRemaining = 8,
    IsTurnedOn = 16,
    CouldBeTurnedOn = 15,
    CouldProcessWork = 23,
    FullActivation = 31,
};

