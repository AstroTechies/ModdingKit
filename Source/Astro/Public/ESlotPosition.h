#pragma once
#include "CoreMinimal.h"
#include "ESlotPosition.generated.h"

UENUM()
enum class ESlotPosition : uint8 {
    RelativeTransform,
    Socket,
    SceneComponent,
};

