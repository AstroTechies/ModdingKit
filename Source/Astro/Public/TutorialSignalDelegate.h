#pragma once
#include "CoreMinimal.h"
#include "TutorialSignalDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTutorialSignal, FName, Name, bool, First, bool, ShowText);

