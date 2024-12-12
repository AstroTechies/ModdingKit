#pragma once
#include "CoreMinimal.h"
#include "FPerPlayerUseSuppressionMode.generated.h"

UENUM()
enum class FPerPlayerUseSuppressionMode : int32 {
    None,
    Whitelist,
};

