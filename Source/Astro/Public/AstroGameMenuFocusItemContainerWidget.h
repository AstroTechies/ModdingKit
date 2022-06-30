#pragma once
#include "CoreMinimal.h"
#include "UserWidgetBlueprintDesignable.h"
#include "UObject/NoExportTypes.h"
#include "EMouseFocusChangeSuppressionSource.h"
#include "EFocusItemFocusChangeCause.h"
#include "Components/SlateWrapperTypes.h"
#include "AstroGameMenuFocusItemContainerWidget.generated.h"

class UAstroGameMenuFocusItemWidget;

UCLASS(Blueprintable, Abstract, EditInlineNew)
class UAstroGameMenuFocusItemContainerWidget : public UUserWidgetBlueprintDesignable
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Export, Transient, meta = (AllowPrivateAccess = true))
    TArray<UAstroGameMenuFocusItemWidget *> FocusableWidgetsList;

    UPROPERTY(BlueprintReadWrite, Export, Transient, meta = (AllowPrivateAccess = true))
    TArray<UAstroGameMenuFocusItemWidget *> AllMenuItemWidgets;

    UPROPERTY(Export, Transient)
    UAstroGameMenuFocusItemWidget *CurrentlyFocusedItem;

    UPROPERTY(Transient)
    TArray<EMouseFocusChangeSuppressionSource> ActiveMouseFocusChangeSuppressions;

private:
    UPROPERTY(Export, Transient)
    UAstroGameMenuFocusItemWidget *LastUsedItem;

public:
    UAstroGameMenuFocusItemContainerWidget();
    UFUNCTION(BlueprintCallable)
    void RemoveMouseFocusSuppression(EMouseFocusChangeSuppressionSource MouseSuppression);

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnFocusIndexChanged(int32 NewFocusIndex);

public:
    UFUNCTION(BlueprintPure)
    bool IsMouseFocusSuppressed() const;

private:
    UFUNCTION()
    void HandleLastUsedItemChanged(bool IsLastUsedItem, UAstroGameMenuFocusItemWidget *LastUsedWidget);

    UFUNCTION()
    void HandleFocusedItemChanged(bool IsFocused, UAstroGameMenuFocusItemWidget *FocusedWidget, EFocusItemFocusChangeCause FocusChangeCause);

public:
    UFUNCTION(BlueprintPure)
    UAstroGameMenuFocusItemWidget *GetCurrentFocusItem() const;

protected:
    UFUNCTION()
    FEventReply AttemptToUseFocusedItemViaMouse();

public:
    UFUNCTION()
    FEventReply AttemptToToggleEditFocusedItem();

    UFUNCTION()
    FEventReply AttemptToStartDragEditFocusedItem(const FVector2D &MousePos);

    UFUNCTION()
    FEventReply AttemptToIncrementCurrentlyEditedItem();

    UFUNCTION()
    FEventReply AttemptToDecrementCurrentlyEditedItem();

    UFUNCTION()
    FEventReply AttemptToCancelDragOrEditFocusItem();

    UFUNCTION(BlueprintCallable)
    void AddMouseFocusSuppression(EMouseFocusChangeSuppressionSource MouseSuppression);
};
