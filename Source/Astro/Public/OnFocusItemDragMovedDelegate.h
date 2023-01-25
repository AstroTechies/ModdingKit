#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "OnFocusItemDragMovedDelegate.generated.h"

class UAstroGameMenuFocusItemWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnFocusItemDragMoved, FVector2D, MousePosition, FVector2D, MousePosDelta, UAstroGameMenuFocusItemWidget*, FocusableWidget);

