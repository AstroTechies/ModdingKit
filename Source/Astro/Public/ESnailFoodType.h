#pragma once
#include "CoreMinimal.h"
#include "ESnailFoodType.generated.h"

UENUM(BlueprintType)
enum class ESnailFoodType : uint8 {
    InvalidFood,
    NormalFood,
    PreferredFood,
    FavoriteFood,
};

