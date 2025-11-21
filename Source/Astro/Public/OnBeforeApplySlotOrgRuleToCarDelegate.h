#pragma once
#include "CoreMinimal.h"
#include "EStationLoadingState.h"
#include "OnBeforeApplySlotOrgRuleToCarDelegate.generated.h"

class USlotOrganizationRule;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnBeforeApplySlotOrgRuleToCar, EStationLoadingState, StationLoadingState, USlotOrganizationRule*, PushRule, USlotOrganizationRule*, PullRule);

