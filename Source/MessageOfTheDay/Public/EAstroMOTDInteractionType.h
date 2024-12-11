#pragma once
#include "CoreMinimal.h"
#include "EAstroMOTDInteractionType.generated.h"

UENUM(BlueprintType)
enum class EAstroMOTDInteractionType : uint8 {
    ExternalLink,
    QBitStorePage,
    SteamStorePage,
};

