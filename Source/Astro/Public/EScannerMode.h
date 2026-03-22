#pragma once
#include "CoreMinimal.h"
#include "EScannerMode.generated.h"

UENUM(BlueprintType)
enum class EScannerMode : uint8 {
    Asleep,
    Awake,
    Scanning,
    ScanCooldown,
};

