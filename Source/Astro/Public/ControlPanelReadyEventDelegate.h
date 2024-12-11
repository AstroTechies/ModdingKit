#pragma once
#include "CoreMinimal.h"
#include "ControlPanelReadyEventDelegate.generated.h"

class AControlPanel;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FControlPanelReadyEvent, AControlPanel*, ControlPanel);

