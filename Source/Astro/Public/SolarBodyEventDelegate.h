#pragma once
#include "CoreMinimal.h"
#include "SolarBodyEventDelegate.generated.h"

class ASolarBody;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSolarBodyEvent, ASolarBody*, SolarBody);

