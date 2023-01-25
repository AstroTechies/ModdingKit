#pragma once
#include "CoreMinimal.h"
#include "ECellType.generated.h"

UENUM(BlueprintType)
enum class ECellType : uint8 {
    CellValue,
    NoiseLookUp,
    Distance,
    Dot,
    DotSpherical,
    Distance2,
    Distance2Add,
    Distance2Sub,
    Distance2Mul,
    Distance2Div,
};

