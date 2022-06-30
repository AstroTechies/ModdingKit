#pragma once
#include "CoreMinimal.h"
#include "EFocusItemFocusChangeCause.generated.h"

UENUM()
enum class EFocusItemFocusChangeCause : uint8 {
    AutoNavigation,
    MouseHover,
    KeyPress,
};

