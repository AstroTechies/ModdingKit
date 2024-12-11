#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AstroGameMenuFocusItemContainerWidget.h"
#include "AstroGameMenuSpatialWindow.generated.h"

class UAstroGameMenuFocusItemWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroGameMenuSpatialWindow : public UAstroGameMenuFocusItemContainerWidget {
    GENERATED_BODY()
public:
    UAstroGameMenuSpatialWindow();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FVector2D GetUnboundedDimensionOfSubPane();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTotalHeightOfSubPaneFocusItemWidgets() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxWidthOfSubPaneFocusItemWidgets() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetLocalPositionOfFocusItemWidget(UAstroGameMenuFocusItemWidget* FocusItemWidget) const;
    
};

