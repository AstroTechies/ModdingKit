#pragma once
#include "CoreMinimal.h"
#include "UserWidgetBlueprintDesignable.h"
#include "SelectionWheelOption.h"
#include "SelectionWheelOptionWidget.generated.h"

UCLASS(Blueprintable, Abstract, EditInlineNew)
class USelectionWheelOptionWidget : public UUserWidgetBlueprintDesignable
{
    GENERATED_BODY()
public:
    USelectionWheelOptionWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetSelected(bool isSelected);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayClickedFX();

    UFUNCTION(BlueprintImplementableEvent)
    void InitializeSelectionWheelOption(FSelectionWheelOption Option);
};
