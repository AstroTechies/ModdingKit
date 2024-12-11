#pragma once
#include "CoreMinimal.h"
#include "EMicroTxnStoreItemFlags.generated.h"

UENUM(BlueprintType)
enum class EMicroTxnStoreItemFlags : uint8 {
    New,
    Featured,
};

