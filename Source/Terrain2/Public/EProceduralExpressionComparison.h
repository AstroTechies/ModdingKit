#pragma once
#include "CoreMinimal.h"
#include "EProceduralExpressionComparison.generated.h"

UENUM()
enum class EProceduralExpressionComparison {
    NotEqual,
    Equal,
    LessThan,
    LessThanEqual,
    GreaterThan,
    GreaterThanEqual,
};

