#pragma once
#include "CoreMinimal.h"
#include "ELRDType.generated.h"

UENUM(BlueprintType)
enum class ELRDType : uint8 {
    None,
    Zebra,
    Checkers,
    Leopard,
    Hypno,
    Dragon,
    MAX = Dragon,
};

