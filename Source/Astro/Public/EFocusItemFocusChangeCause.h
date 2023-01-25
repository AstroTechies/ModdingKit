#pragma once
#include "CoreMinimal.h"
#include "EFocusItemFocusChangeCause.generated.h"

UENUM(BlueprintType)
enum class EFocusItemFocusChangeCause : uint8 {
    AutoNavigation,
    MouseHover,
    KeyPress,
};

