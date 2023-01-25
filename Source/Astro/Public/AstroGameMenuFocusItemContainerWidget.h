#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=EventReply -FallbackName=EventReply
#include "EFocusItemFocusChangeCause.h"
#include "EMouseFocusChangeSuppressionSource.h"
#include "UserWidgetBlueprintDesignable.h"
#include "AstroGameMenuFocusItemContainerWidget.generated.h"

class UAstroGameMenuFocusItemWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroGameMenuFocusItemContainerWidget : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAstroGameMenuFocusItemWidget*> FocusableWidgetsList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAstroGameMenuFocusItemWidget*> AllMenuItemWidgets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAstroGameMenuFocusItemWidget* CurrentlyFocusedItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<EMouseFocusChangeSuppressionSource> ActiveMouseFocusChangeSuppressions;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAstroGameMenuFocusItemWidget* LastUsedItem;
    
public:
    UAstroGameMenuFocusItemContainerWidget();
    UFUNCTION(BlueprintCallable)
    void RemoveMouseFocusSuppression(EMouseFocusChangeSuppressionSource MouseSuppression);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFocusIndexChanged(int32 NewFocusIndex);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMouseFocusSuppressed() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleLastUsedItemChanged(bool IsLastUsedItem, UAstroGameMenuFocusItemWidget* LastUsedWidget);
    
    UFUNCTION(BlueprintCallable)
    void HandleFocusedItemChanged(bool IsFocused, UAstroGameMenuFocusItemWidget* FocusedWidget, EFocusItemFocusChangeCause FocusChangeCause);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAstroGameMenuFocusItemWidget* GetCurrentFocusItem() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    FEventReply AttemptToUseFocusedItemViaMouse();
    
public:
    UFUNCTION(BlueprintCallable)
    FEventReply AttemptToToggleEditFocusedItem();
    
    UFUNCTION(BlueprintCallable)
    FEventReply AttemptToStartDragEditFocusedItem(const FVector2D& MousePos);
    
    UFUNCTION(BlueprintCallable)
    FEventReply AttemptToIncrementCurrentlyEditedItem();
    
    UFUNCTION(BlueprintCallable)
    FEventReply AttemptToDecrementCurrentlyEditedItem();
    
    UFUNCTION(BlueprintCallable)
    FEventReply AttemptToCancelDragOrEditFocusItem();
    
    UFUNCTION(BlueprintCallable)
    void AddMouseFocusSuppression(EMouseFocusChangeSuppressionSource MouseSuppression);
    
};

