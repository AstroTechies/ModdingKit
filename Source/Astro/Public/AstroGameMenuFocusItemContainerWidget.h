#pragma once
#include "CoreMinimal.h"
#include "UserWidgetBlueprintDesignable.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=EventReply -FallbackName=EventReply
#include "EMouseFocusChangeSuppressionSource.h"
#include "EFocusItemFocusChangeCause.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "AstroGameMenuFocusItemContainerWidget.generated.h"

class UAstroGameMenuFocusItemWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroGameMenuFocusItemContainerWidget : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAstroGameMenuFocusItemWidget*> FocusableWidgetsList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAstroGameMenuFocusItemWidget*> AllMenuItemWidgets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UAstroGameMenuFocusItemWidget* CurrentlyFocusedItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<EMouseFocusChangeSuppressionSource> ActiveMouseFocusChangeSuppressions;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UAstroGameMenuFocusItemWidget* LastUsedItem;
    
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
    void HandleLastUsedItemChanged(bool IsLastUsedItem, UAstroGameMenuFocusItemWidget* LastUsedWidget);
    
    UFUNCTION()
    void HandleFocusedItemChanged(bool IsFocused, UAstroGameMenuFocusItemWidget* FocusedWidget, EFocusItemFocusChangeCause FocusChangeCause);
    
public:
    UFUNCTION(BlueprintPure)
    UAstroGameMenuFocusItemWidget* GetCurrentFocusItem() const;
    
protected:
    UFUNCTION()
    FEventReply AttemptToUseFocusedItemViaMouse();
    
public:
    UFUNCTION()
    FEventReply AttemptToToggleEditFocusedItem();
    
    UFUNCTION()
    FEventReply AttemptToStartDragEditFocusedItem(const FVector2D& MousePos);
    
    UFUNCTION()
    FEventReply AttemptToIncrementCurrentlyEditedItem();
    
    UFUNCTION()
    FEventReply AttemptToDecrementCurrentlyEditedItem();
    
    UFUNCTION()
    FEventReply AttemptToCancelDragOrEditFocusItem();
    
    UFUNCTION(BlueprintCallable)
    void AddMouseFocusSuppression(EMouseFocusChangeSuppressionSource MouseSuppression);
    
};

