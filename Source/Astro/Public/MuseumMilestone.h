#pragma once
#include "CoreMinimal.h"
#include "EDonationReward.h"
#include "EDonationRewardType.h"
#include "Templates/SubclassOf.h"
#include "MuseumMilestone.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FMuseumMilestone {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int64 MilestoneThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDonationRewardType rewardType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDonationReward BuffReward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UItemType>, int32> ItemRewards;
    
    ASTRO_API FMuseumMilestone();
};

