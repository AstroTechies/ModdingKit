#pragma once
#include "CoreMinimal.h"
#include "EBiodomeFertiliserState.generated.h"

UENUM(BlueprintType)
enum class EBiodomeFertiliserState : uint8 {
    Inactive,
    Sprinkling,
    Waiting,
};

