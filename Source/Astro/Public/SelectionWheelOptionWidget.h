#pragma once
#include "CoreMinimal.h"
#include "SelectionWheelOption.h"
#include "UserWidgetBlueprintDesignable.h"
#include "SelectionWheelOptionWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class USelectionWheelOptionWidget : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
    USelectionWheelOptionWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetSelected(bool isSelected);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayClickedFX();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InitializeSelectionWheelOption(FSelectionWheelOption Option);
    
};

