#pragma once
#include "CoreMinimal.h"
#include "ELogisticsComplexChannel.h"
#include "ControlPanelReadyEventDelegate.generated.h"

class AControlPanel;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FControlPanelReadyEvent, AControlPanel*, ControlPanel, ELogisticsComplexChannel, PadChannel);

