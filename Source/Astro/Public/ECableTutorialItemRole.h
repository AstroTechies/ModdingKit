#pragma once
#include "CoreMinimal.h"
#include "ECableTutorialItemRole.generated.h"

UENUM(BlueprintType)
enum class ECableTutorialItemRole : uint8 {
    Receiver,
    Provider,
};

