#pragma once
#include "CoreMinimal.h"
#include "UserWidgetBlueprintDesignable.h"
#include "AstroSlateFocusWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroSlateFocusWidget : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
    UAstroSlateFocusWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GrantFocus();
    
    UFUNCTION(BlueprintImplementableEvent)
    void DisableChildWidgetFocusHighlight();
    
};

