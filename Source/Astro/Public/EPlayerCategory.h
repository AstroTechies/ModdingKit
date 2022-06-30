#pragma once
#include "CoreMinimal.h"
#include "EPlayerCategory.generated.h"

UENUM(BlueprintType)
enum class EPlayerCategory : uint8 {
    Pending,
    Unlisted,
    Blacklisted,
    Whitelisted,
    Admin,
    Owner,
};

