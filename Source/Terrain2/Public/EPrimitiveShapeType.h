#pragma once
#include "CoreMinimal.h"
#include "EPrimitiveShapeType.generated.h"

UENUM()
enum class EPrimitiveShapeType {
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

