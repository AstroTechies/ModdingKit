#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidgetBlueprintDesignable.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UUserWidgetBlueprintDesignable : public UUserWidget {
    GENERATED_BODY()
public:
    UUserWidgetBlueprintDesignable();
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetupStylingData();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void PostLayoutWidget();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSynchronizeProperties();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool LayoutWidget();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetStylingDataSetupComplete();
    
};

