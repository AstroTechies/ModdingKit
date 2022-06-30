#pragma once
#include "CoreMinimal.h"
#include "EOutputEjectionType.generated.h"

UENUM()
enum class EOutputEjectionType : uint8 {
    None,
    StorageThenEject,
    StorageOnly,
};

