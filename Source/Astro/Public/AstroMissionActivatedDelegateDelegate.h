#pragma once
#include "CoreMinimal.h"
#include "AstroMissionActivatedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAstroMissionActivatedDelegate, FName, missionId);

