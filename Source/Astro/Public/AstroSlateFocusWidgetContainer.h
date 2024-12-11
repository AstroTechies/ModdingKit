#pragma once
#include "CoreMinimal.h"
#include "UserWidgetBlueprintDesignable.h"
#include "AstroSlateFocusWidgetContainer.generated.h"

class UAstroSlateFocusWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroSlateFocusWidgetContainer : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroSlateFocusWidget* ChildWidgetWithFocusHighlight;
    
public:
    UAstroSlateFocusWidgetContainer();

protected:
    UFUNCTION(BlueprintCallable)
    void RestoreLastFocus();
    
public:
    UFUNCTION(BlueprintCallable)
    void ChildWidgetFocusHighlightChanged(UAstroSlateFocusWidget* FocusWidget);
    
};

