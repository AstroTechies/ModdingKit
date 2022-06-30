#pragma once
#include "CoreMinimal.h"
#include "UserWidgetBlueprintDesignable.h"
#include "OnFocusItemMousePosInteractionDelegate.h"
#include "OnFocusItemGenericInteractionDelegate.h"
#include "OnFocusItemIsLastUsedStateChangedDelegate.h"
#include "OnFocusItemFocusStateChangedDelegate.h"
#include "OnEditingItemUnhandledKeyPressDelegate.h"
#include "OnFocusItemDragMovedDelegate.h"
#include "UObject/NoExportTypes.h"
#include "AstroGameMenuFocusItemWidget.generated.h"

class UOverlaySlot;
class UImage;

UCLASS(Blueprintable, Abstract, EditInlineNew)
class UAstroGameMenuFocusItemWidget : public UUserWidgetBlueprintDesignable
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FOnFocusItemGenericInteraction OnFocusItemUsedDelegate;

    UPROPERTY(BlueprintAssignable)
    FOnFocusItemGenericInteraction OnLockedFocusItemAttemptedUseDelegate;

    UPROPERTY(BlueprintAssignable)
    FOnFocusItemIsLastUsedStateChanged OnFocusItemIsLastUsedStateChangedDelegate;

    UPROPERTY(BlueprintAssignable)
    FOnFocusItemFocusStateChanged OnFocusItemFocusStateChangedDelegate;

    UPROPERTY(BlueprintAssignable)
    FOnEditingItemUnhandledKeyPress OnEditingUnhandledKeyPressed;

    UPROPERTY(BlueprintAssignable)
    FOnFocusItemMousePosInteraction OnFocusItemDiscreteEditStarted;

    UPROPERTY(BlueprintAssignable)
    FOnFocusItemGenericInteraction OnFocusItemDiscreteEditCommitted;

    UPROPERTY(BlueprintAssignable)
    FOnFocusItemGenericInteraction OnFocusItemDiscreteEditCanceled;

    UPROPERTY(BlueprintAssignable)
    FOnFocusItemGenericInteraction OnEditingItemValueIncremented;

    UPROPERTY(BlueprintAssignable)
    FOnFocusItemGenericInteraction OnEditingItemValueDecremented;

    UPROPERTY(BlueprintAssignable)
    FOnFocusItemMousePosInteraction OnFocusItemDragEditStarted;

    UPROPERTY(BlueprintAssignable)
    FOnFocusItemGenericInteraction OnFocusItemDragEditCommitted;

    UPROPERTY(BlueprintAssignable)
    FOnFocusItemGenericInteraction OnFocusItemDragEditCanceled;

    UPROPERTY(BlueprintAssignable)
    FOnFocusItemDragMoved OnFocusItemDragMovedDelegate;

    UPROPERTY(BlueprintReadWrite, Export, Transient, meta = (AllowPrivateAccess = true))
    UOverlaySlot *FocusBGImageOverlaySlot;

    UPROPERTY(BlueprintReadWrite, Export, Transient, meta = (AllowPrivateAccess = true))
    UImage *FocusBGImage;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DragEditStartDeadzone;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    uint8 bBlockFocusAudio : 1;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    uint8 bBlockUseAudio : 1;

    UPROPERTY(EditAnywhere)
    uint8 bDiscreteEditCannotBeCommittedWithButtonInput : 1;

protected:
    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    uint8 bIsFocused : 1;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    uint8 bIsLastUsed : 1;

    UPROPERTY(EditAnywhere)
    uint8 bEditTimeForceNotInteractive : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bCanBeCancelled : 1;

public:
    UAstroGameMenuFocusItemWidget();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetInteractionBlocked(bool NewIsInteractionBlocked);

    UFUNCTION(BlueprintPure)
    bool IsInteractionBlocked();

    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    FVector2D GetMenuFocusWidgetSize();

    UFUNCTION(BlueprintPure)
    bool GetIsBeingDragged() const;

    UFUNCTION(BlueprintPure)
    bool GetIsBeingDiscretelyEdited() const;

    UFUNCTION(BlueprintCallable)
    void ForceCommitDiscreteEditing();

    UFUNCTION(BlueprintCallable)
    bool AttemptToCommitDiscreteEdit();
};
