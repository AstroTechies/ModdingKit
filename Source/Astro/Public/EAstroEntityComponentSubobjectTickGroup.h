#pragma once
#include "CoreMinimal.h"
#include "EAstroEntityComponentSubobjectTickGroup.generated.h"

UENUM(BlueprintType)
enum class EAstroEntityComponentSubobjectTickGroup : uint8 {
    PrePhysics,
    PostPhysics,
};

