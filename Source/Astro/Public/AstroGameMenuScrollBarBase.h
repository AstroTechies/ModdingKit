#pragma once
#include "CoreMinimal.h"
#include "AstroGameMenuFocusItemWidget.h"
#include "EFocusItemFocusChangeCause.h"
#include "AstroGameMenuScrollBarBase.generated.h"

class UAstroGameMenuSubPaneWidget;
class UWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroGameMenuScrollBarBase : public UAstroGameMenuFocusItemWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UAstroGameMenuSubPaneWidget* ScrollBarTarget;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UWidget* ScrollBarHandleWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UWidget* ScrollBarBGWidget;
    
public:
    UAstroGameMenuScrollBarBase();
    UFUNCTION(BlueprintCallable)
    void SetScrollBarHandlePositionNormalized(float NormalizedPosition);
    
    UFUNCTION(BlueprintCallable)
    void SetScrollBarHandlePosition(float Position);
    
    UFUNCTION(BlueprintPure)
    bool IsScrollBarActive() const;
    
protected:
    UFUNCTION()
    void HandleTargetFocusItemChanged(UAstroGameMenuFocusItemWidget* FocusItem, EFocusItemFocusChangeCause FocusChangeCause);
    
public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    float GetScrollBarWidth();
    
    UFUNCTION(BlueprintPure)
    float GetScrollBarHandlePositionNormalized() const;
    
    UFUNCTION(BlueprintPure)
    float GetScrollBarHandlePosition() const;
    
    UFUNCTION(BlueprintCallable)
    void DeactivateScrollBar();
    
    UFUNCTION(BlueprintCallable)
    void AddScrollDelta(float ScrollDelta);
    
    UFUNCTION(BlueprintCallable)
    void ActivateScrollBar(float NewViewableHeightOfScrollTargetContainer, float VerticalPaddingOfScrollTargetContainer, UAstroGameMenuSubPaneWidget* NewScrollBarTarget);
    
};

