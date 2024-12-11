#pragma once
#include "CoreMinimal.h"
#include "ECharacterCustomizationVisibility.generated.h"

UENUM(BlueprintType)
enum class ECharacterCustomizationVisibility : uint8 {
    HiddenToAll,
    HiddenUnlessUnlocked,
    ObfuscatedUnlessUnlocked,
    VisibleButUnlockRequired,
    AvailableToAll,
};

