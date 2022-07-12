#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UserWidgetBlueprintDesignable.h"
#include "SelectionWheelEventDelegate.h"
#include "EAstroSelectionWheelOptionType.h"
#include "SelectionWheelOption.h"
#include "SelectionWheelWidget.generated.h"

class USelectionWheelOptionWidget;
class APlayController;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class USelectionWheelWidget : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSelectionWheelEvent OnSelectionMade;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSelectionWheelEvent OnCurrentSelectionChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USelectionWheelOptionWidget> OptionWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSelectionWheelOption> Options;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<USelectionWheelOptionWidget*> OptionWidgets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentSelection;
    
public:
    USelectionWheelWidget();
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void SetOptionWidgets(const TArray<USelectionWheelOptionWidget*>& widgets);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentSelection(int32 Selection);
    
public:
    UFUNCTION(BlueprintPure)
    static bool SelectionOptionTypeIsValid(APlayController* Controller, EAstroSelectionWheelOptionType OptionType);
    
protected:
    UFUNCTION()
    void InitializeOptionWidget(int32 OptionIndex);
    
    UFUNCTION(BlueprintCallable)
    void HandleSelectionMade(int32 SelectionIndex);
    
};

