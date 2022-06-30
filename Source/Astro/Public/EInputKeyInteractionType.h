#pragma once
#include "CoreMinimal.h"
#include "EInputKeyInteractionType.generated.h"

UENUM(BlueprintType)
enum class EInputKeyInteractionType : uint8 {
    Hold,
    Press,
};

