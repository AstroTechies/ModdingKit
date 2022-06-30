#pragma once
#include "CoreMinimal.h"
#include "EPowerCableConnectionDirection.generated.h"

UENUM()
enum class EPowerCableConnectionDirection : uint8 {
    InputConnection,
    OutputConnection,
    None,
};

