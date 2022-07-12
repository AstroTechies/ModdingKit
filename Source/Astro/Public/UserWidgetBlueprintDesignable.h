#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=UserWidget -FallbackName=UserWidget	
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

