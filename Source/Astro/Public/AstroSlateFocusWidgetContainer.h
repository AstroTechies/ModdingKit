#pragma once
#include "CoreMinimal.h"
#include "UserWidgetBlueprintDesignable.h"
#include "AstroSlateFocusWidgetContainer.generated.h"

class UAstroSlateFocusWidget;

UCLASS(Blueprintable, Abstract, EditInlineNew)
class UAstroSlateFocusWidgetContainer : public UUserWidgetBlueprintDesignable
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Export)
    UAstroSlateFocusWidget *ChildWidgetWithFocusHighlight;

public:
    UAstroSlateFocusWidgetContainer();

protected:
    UFUNCTION(BlueprintCallable)
    void RestoreLastFocus();

public:
    UFUNCTION(BlueprintCallable)
    void ChildWidgetFocusHighlightChanged(UAstroSlateFocusWidget *FocusWidget);
};
