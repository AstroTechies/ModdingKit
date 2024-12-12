#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnEditingItemUnhandledKeyPressDelegate.h"
#include "OnFocusItemDragMovedDelegate.h"
#include "OnFocusItemFocusStateChangedDelegate.h"
#include "OnFocusItemGenericInteractionDelegate.h"
#include "OnFocusItemIsLastUsedStateChangedDelegate.h"
#include "OnFocusItemMousePosInteractionDelegate.h"
#include "UserWidgetBlueprintDesignable.h"
#include "AstroGameMenuFocusItemWidget.generated.h"

class UImage;
class UOverlaySlot;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroGameMenuFocusItemWidget : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFocusItemGenericInteraction OnFocusItemUsedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFocusItemGenericInteraction OnLockedFocusItemAttemptedUseDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFocusItemIsLastUsedStateChanged OnFocusItemIsLastUsedStateChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFocusItemFocusStateChanged OnFocusItemFocusStateChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnEditingItemUnhandledKeyPress OnEditingUnhandledKeyPressed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFocusItemMousePosInteraction OnFocusItemDiscreteEditStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFocusItemGenericInteraction OnFocusItemDiscreteEditCommitted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFocusItemGenericInteraction OnFocusItemDiscreteEditCanceled;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFocusItemGenericInteraction OnEditingItemValueIncremented;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFocusItemGenericInteraction OnEditingItemValueDecremented;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFocusItemMousePosInteraction OnFocusItemDragEditStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFocusItemGenericInteraction OnFocusItemDragEditCommitted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFocusItemGenericInteraction OnFocusItemDragEditCanceled;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFocusItemDragMoved OnFocusItemDragMovedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UOverlaySlot* FocusBGImageOverlaySlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UImage* FocusBGImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DragEditStartDeadzone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bBlockFocusAudio: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bBlockUseAudio: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bDiscreteEditCannotBeCommittedWithButtonInput: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool OverrideMenuPopoutHeight;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsFocused: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsLastUsed: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bEditTimeForceNotInteractive: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCanBeCancelled: 1;
    
public:
    UAstroGameMenuFocusItemWidget();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetInteractionBlocked(bool NewIsInteractionBlocked);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInteractionBlocked();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FVector2D GetMenuFocusWidgetSize();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsBeingDragged() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsBeingDiscretelyEdited() const;
    
    UFUNCTION(BlueprintCallable)
    void ForceCommitDiscreteEditing();
    
    UFUNCTION(BlueprintCallable)
    bool AttemptToCommitDiscreteEdit();
    
};

