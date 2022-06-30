#pragma once
#include "CoreMinimal.h"
#include "EPlayerPlatform.generated.h"

UENUM(BlueprintType)
enum class EPlayerPlatform : uint8 {
    Unknown,
    Steam,
    Live,
    PSN,
    Oddish,
};

