#pragma once
#include "CoreMinimal.h"
#include "EItemStorageBehavior.generated.h"

UENUM(BlueprintType)
enum class EItemStorageBehavior : uint8 {
    None,
    IsContainedOnly,
    Container,
    DeployablePackage,
};

