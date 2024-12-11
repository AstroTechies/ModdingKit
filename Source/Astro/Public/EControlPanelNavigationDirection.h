#pragma once
#include "CoreMinimal.h"
#include "EControlPanelNavigationDirection.generated.h"

UENUM(BlueprintType)
enum class EControlPanelNavigationDirection : uint8 {
    Left,
    Right,
    Up,
    Down,
};

