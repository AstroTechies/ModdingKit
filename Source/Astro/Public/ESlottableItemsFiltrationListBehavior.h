#pragma once
#include "CoreMinimal.h"
#include "ESlottableItemsFiltrationListBehavior.generated.h"

UENUM(BlueprintType)
enum class ESlottableItemsFiltrationListBehavior : uint8 {
    Ignore,
    Whitelist,
    Blacklist,
};

