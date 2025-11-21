#pragma once
#include "CoreMinimal.h"
#include "EDonationReward.h"
#include "OnDonationRewardChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDonationRewardChanged, EDonationReward, inRewardChanged);

