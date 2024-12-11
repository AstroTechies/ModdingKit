#pragma once
#include "CoreMinimal.h"
#include "EOutputEjectionType.generated.h"

UENUM(BlueprintType)
enum class EOutputEjectionType : uint8 {
    None,
    StorageThenEject,
    StorageOnly,
};

