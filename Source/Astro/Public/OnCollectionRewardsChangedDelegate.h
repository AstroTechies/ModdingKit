#pragma once
#include "CoreMinimal.h"
#include "ECollectionReward.h"
#include "OnCollectionRewardsChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCollectionRewardsChanged, ECollectionReward, inRewardChanged);

