#pragma once
#include "CoreMinimal.h"
#include "ESlotConnectorType.generated.h"

UENUM(BlueprintType)
enum class ESlotConnectorType : uint8 {
    Plug,
    Socket,
};

