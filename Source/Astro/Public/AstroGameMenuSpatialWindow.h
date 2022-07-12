#pragma once
#include "CoreMinimal.h"
#include "AstroGameMenuFocusItemContainerWidget.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "AstroGameMenuSpatialWindow.generated.h"

class UAstroGameMenuFocusItemWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroGameMenuSpatialWindow : public UAstroGameMenuFocusItemContainerWidget {
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
    FVector2D GetLocalPositionOfFocusItemWidget(UAstroGameMenuFocusItemWidget* FocusItemWidget) const;
    
};

