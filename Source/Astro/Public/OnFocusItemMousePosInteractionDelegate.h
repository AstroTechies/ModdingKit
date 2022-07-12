#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "OnFocusItemMousePosInteractionDelegate.generated.h"

class UAstroGameMenuFocusItemWidget;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFocusItemMousePosInteraction, const FVector2D&, MousePosition, UAstroGameMenuFocusItemWidget*, FocusItemWidget);

