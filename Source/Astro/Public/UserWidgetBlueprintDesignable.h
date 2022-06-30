#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidgetBlueprintDesignable.generated.h"

UCLASS(Blueprintable, Abstract, EditInlineNew)
class UUserWidgetBlueprintDesignable : public UUserWidget
{
    GENERATED_BODY()
public:
    UUserWidgetBlueprintDesignable();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetupStylingData();

    UFUNCTION(BlueprintNativeEvent)
    void PostLayoutWidget();

    UFUNCTION(BlueprintNativeEvent)
    void OnSynchronizeProperties();

public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool LayoutWidget();

protected:
    UFUNCTION(BlueprintPure)
    bool GetStylingDataSetupComplete();
};
