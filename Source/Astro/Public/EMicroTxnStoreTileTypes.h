#pragma once
#include "CoreMinimal.h"
#include "EMicroTxnStoreTileTypes.generated.h"

UENUM(BlueprintType)
enum class EMicroTxnStoreTileTypes : uint8 {
    None,
    Normal,
    Featured,
    Tall,
    Wide,
    Large,
};

