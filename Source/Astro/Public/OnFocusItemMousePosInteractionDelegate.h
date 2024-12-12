#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnFocusItemMousePosInteractionDelegate.generated.h"

class UAstroGameMenuFocusItemWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFocusItemMousePosInteraction, const FVector2D&, MousePosition, UAstroGameMenuFocusItemWidget*, FocusItemWidget);

