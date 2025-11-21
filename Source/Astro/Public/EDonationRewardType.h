#pragma once
#include "CoreMinimal.h"
#include "EDonationRewardType.generated.h"

UENUM(BlueprintType)
enum class EDonationRewardType : uint8 {
    None,
    Item,
    Buff,
};

