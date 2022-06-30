#pragma once
#include "CoreMinimal.h"
#include "AstroMissionRewardClaimedDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAstroMissionRewardClaimedDelegate, FName, missionId);

