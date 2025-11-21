#pragma once
#include "CoreMinimal.h"
#include "EHarvesterOrganizationRuleState.generated.h"

UENUM(BlueprintType)
enum class EHarvesterOrganizationRuleState : uint8 {
    Hold,
    Request,
    Push,
};

