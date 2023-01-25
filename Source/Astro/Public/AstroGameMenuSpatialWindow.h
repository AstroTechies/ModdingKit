#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
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

