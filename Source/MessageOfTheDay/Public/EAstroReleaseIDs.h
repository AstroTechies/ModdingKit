#pragma once
#include "CoreMinimal.h"
#include "EAstroReleaseIDs.generated.h"

UENUM(BlueprintType)
enum class EAstroReleaseIDs : uint8 {
    Invalid,
    Megatech = 36,
    PS5Port = 35,
    Elevated = 34,
    AelouzUnlocked = 33,
    GlitchWalkers = 32,
    Count = Megatech,
};

