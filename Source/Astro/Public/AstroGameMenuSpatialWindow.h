#pragma once
#include "CoreMinimal.h"
#include "AstroGameMenuFocusItemContainerWidget.h"
#include "UObject/NoExportTypes.h"
#include "AstroGameMenuSpatialWindow.generated.h"

class UAstroGameMenuFocusItemWidget;

UCLASS(Blueprintable, Abstract, EditInlineNew)
class UAstroGameMenuSpatialWindow : public UAstroGameMenuFocusItemContainerWidget
{
    GENERATED_BODY()
public:
    UAstroGameMenuSpatialWindow();
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    FVector2D GetUnboundedDimensionOfSubPane();

    UFUNCTION(BlueprintPure)
    float GetTotalHeightOfSubPaneFocusItemWidgets() const;

    UFUNCTION(BlueprintPure)
    float GetMaxWidthOfSubPaneFocusItemWidgets() const;

    UFUNCTION(BlueprintPure)
    FVector2D GetLocalPositionOfFocusItemWidget(UAstroGameMenuFocusItemWidget *FocusItemWidget) const;
};
