#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EAstroSelectionWheelOptionType.h"
#include "UserWidgetBlueprintDesignable.h"
#include "SelectionWheelOption.h"
#include "SelectionWheelEventDelegate.h"
#include "SelectionWheelWidget.generated.h"

class USelectionWheelOptionWidget;
class APlayController;

UCLASS(Blueprintable, Abstract, EditInlineNew)
class USelectionWheelWidget : public UUserWidgetBlueprintDesignable
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSelectionWheelEvent OnSelectionMade;

    UPROPERTY(BlueprintAssignable)
    FSelectionWheelEvent OnCurrentSelectionChanged;

protected:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<USelectionWheelOptionWidget> OptionWidgetClass;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FSelectionWheelOption> Options;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    TArray<USelectionWheelOptionWidget *> OptionWidgets;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 CurrentSelection;

public:
    USelectionWheelWidget();

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void SetOptionWidgets(const TArray<USelectionWheelOptionWidget *> &widgets);

    UFUNCTION(BlueprintCallable)
    void SetCurrentSelection(int32 Selection);

public:
    UFUNCTION(BlueprintPure)
    static bool SelectionOptionTypeIsValid(APlayController *Controller, EAstroSelectionWheelOptionType OptionType);

protected:
    UFUNCTION()
    void InitializeOptionWidget(int32 OptionIndex);

    UFUNCTION(BlueprintCallable)
    void HandleSelectionMade(int32 SelectionIndex);
};
