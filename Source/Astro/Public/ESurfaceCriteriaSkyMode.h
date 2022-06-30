#pragma once
#include "CoreMinimal.h"
#include "ESurfaceCriteriaSkyMode.generated.h"

UENUM()
enum class ESurfaceCriteriaSkyMode : uint8 {
    Any,
    SkyVisible,
    SkyNotVisible,
};

