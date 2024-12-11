#pragma once
#include "CoreMinimal.h"
#include "TooltipWidgetDisplayData.h"
#include "OnEmotePreviewRequestedDelegate.generated.h"

class UAstroEmoteDefinition;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnEmotePreviewRequested, UAstroEmoteDefinition*, emoteToPreview, bool, IsLocked, FTooltipWidgetDisplayData, lockedTooltipDisplayData);

