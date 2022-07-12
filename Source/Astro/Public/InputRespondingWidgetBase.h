#pragma once
#include "CoreMinimal.h"
#include "UserWidgetBlueprintDesignable.h"
#include "InputRespondingWidgetBase.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UInputRespondingWidgetBase : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
    UInputRespondingWidgetBase();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InputStarted(FName ActionOrAxisName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InputComplete(FName ActionOrAxisName, bool InputSucceeded);
    
};

