#pragma once
#include "CoreMinimal.h"
#include "OnFocusItemIsLastUsedStateChangedDelegate.h"
#include "UserWidgetBlueprintDesignable.h"
#include "OnFocusItemGenericInteractionDelegate.h"
#include "OnFocusItemFocusStateChangedDelegate.h"
#include "OnEditingItemUnhandledKeyPressDelegate.h"
#include "OnFocusItemMousePosInteractionDelegate.h"
#include "OnFocusItemDragMovedDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "AstroGameMenuFocusItemWidget.generated.h"

class UOverlaySlot;
class UImage;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UOverlaySlot* FocusBGImageOverlaySlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UImage* FocusBGImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DragEditStartDeadzone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bBlockFocusAudio: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bBlockUseAudio: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bDiscreteEditCannotBeCommittedWithButtonInput: 1;
    
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

