#pragma once
#include "CoreMinimal.h"
#include "EResourceExtractorActivationFlags.generated.h"

UENUM()
enum class EResourceExtractorActivationFlags : uint8 {
    None,
    HasPower,
    IsPlaced,
    HasAvailableStorage = 0x4,
    HasWorkRemaining = 0x8,
    IsTurnedOn = 0x10,
    CouldBeTurnedOn = 0xF,
    CouldProcessWork = 0x17,
    FullActivation = 0x1F,
};

