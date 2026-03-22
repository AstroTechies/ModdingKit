#pragma once
#include "CoreMinimal.h"
#include "AstroMissionObjectiveProgress.h"
#include "AstroMissionObjectiveUpdatedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAstroMissionObjectiveUpdatedDelegate, FName, missionId, const FAstroMissionObjectiveProgress&, objectiveProgress, int32, objectiveIndex);

