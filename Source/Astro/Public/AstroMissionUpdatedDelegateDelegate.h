#pragma once
#include "CoreMinimal.h"
#include "AstroMissionUpdatedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAstroMissionUpdatedDelegate, FName, missionId);

