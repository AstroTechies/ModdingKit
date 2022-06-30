#pragma once
#include "CoreMinimal.h"
#include "EAstroEntityComponentSubobjectTickGroup.generated.h"

UENUM()
enum class EAstroEntityComponentSubobjectTickGroup : uint8 {
    PrePhysics,
    PostPhysics,
};

