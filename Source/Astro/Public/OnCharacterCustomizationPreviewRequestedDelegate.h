#pragma once
#include "CoreMinimal.h"
#include "AstroCharacterCustomization.h"
#include "TooltipWidgetDisplayData.h"
#include "OnCharacterCustomizationPreviewRequestedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCharacterCustomizationPreviewRequested, const FAstroCharacterCustomization&, customizationToPreview, bool, IsLocked, FTooltipWidgetDisplayData, lockedTooltipDisplayData);

