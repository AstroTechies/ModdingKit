#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnFocusItemDragMovedDelegate.generated.h"

class UAstroGameMenuFocusItemWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnFocusItemDragMoved, FVector2D, MousePosition, FVector2D, MousePosDelta, UAstroGameMenuFocusItemWidget*, FocusableWidget);

