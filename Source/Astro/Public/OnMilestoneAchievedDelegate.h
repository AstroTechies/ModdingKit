#pragma once
#include "CoreMinimal.h"
#include "OnMilestoneAchievedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMilestoneAchieved, uint8, milestoneIndex);

