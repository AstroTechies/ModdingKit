#pragma once
#include "CoreMinimal.h"
#include "ESlotPosition.generated.h"

UENUM(BlueprintType)
enum class ESlotPosition : uint8 {
    RelativeTransform,
    Socket,
    SceneComponent,
};

