#pragma once
#include "CoreMinimal.h"
#include "EPrimitiveShapeType.generated.h"

UENUM(BlueprintType)
enum class EPrimitiveShapeType : uint8 {
    Sphere,
    Box,
    RoundedBox,
    Torus,
    Cylinder,
    Capsule,
    Cone,
    CappedCone,
    HexagonalPrism,
    TriangularPrism,
};

