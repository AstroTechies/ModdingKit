#pragma once
#include "CoreMinimal.h"
#include "EStatusModifierType.generated.h"

UENUM(BlueprintType)
enum class EStatusModifierType : uint8 {
    OxygenShutdown,
    PowerShutdown,
    Hacked,
    NumTypes,
};

