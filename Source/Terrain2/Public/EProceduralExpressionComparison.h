#pragma once
#include "CoreMinimal.h"
#include "EProceduralExpressionComparison.generated.h"

UENUM(BlueprintType)
enum class EProceduralExpressionComparison : uint8 {
    NotEqual,
    Equal,
    LessThan,
    LessThanEqual,
    GreaterThan,
    GreaterThanEqual,
};

