#pragma once
#include "CoreMinimal.h"
#include "AstroMissionCompletedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAstroMissionCompletedDelegate, FName, missionId);

