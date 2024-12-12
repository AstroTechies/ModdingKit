#pragma once
#include "CoreMinimal.h"
#include "EItemVariantType.generated.h"

UENUM(BlueprintType)
enum class EItemVariantType : uint8 {
    Pioneer UMETA(DisplayName = "Left"),
    Engineer UMETA(DisplayName = "Right"),
};

