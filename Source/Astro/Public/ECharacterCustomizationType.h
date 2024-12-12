#pragma once
#include "CoreMinimal.h"
#include "ECharacterCustomizationType.generated.h"

UENUM(BlueprintType)
enum class ECharacterCustomizationType : uint8 {
    None,
    Suit,
    Visor,
    Palette,
    Overlay,
    Hat,
    Mask,
    Emote,
    Filter,
    Outfit,
};

