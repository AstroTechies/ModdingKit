#pragma once
#include "CoreMinimal.h"
#include "EDonationRewardType.h"
#include "ESinkType.h"
#include "OnMilestoneRewardClaimedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMilestoneRewardClaimed, const ESinkType, sinkType, const EDonationRewardType, rewardType);

