#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"
#include "Components/SlateWrapperTypes.h"
#include "EAstroGameMenuContext.h"
#include "EGameMenuNavigationCommand.h"
#include "EGameMenuWarningWidgetTypes.h"
#include "ESubpaneIdentifier.h"
#include "FAstroCGMPlayfabFailureReason.h"
#include "GameMenuWarningData.h"
#include "SignalDelegate.h"
#include "UserWidgetBlueprintDesignable.h"
#include "AstroGameMenuWidget.generated.h"

class UAstroGameMenuFocusItemContainerWidget;
class UAstroGameMenuPopoutWidget;
class UAstroGameMenuScrollBarBase;
class UAstroGameMenuSubPaneWidget;
class UAstroGameMenuTabBarWidget;
class UBorder;
class UCanvasPanel;
class UImage;
class UOverlay;
class USpacer;
class UVerticalBox;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroGameMenuWidget : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMenuOpenClose, EAstroGameMenuContext, GameMenuContext);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMenuNavigationBackWithConfirmation);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FKey> WhitelistedKeys;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FKey> WhitelistedAxis;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMenuNavigationBackWithConfirmation OnMenuNavigationBackWithConfirmation;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMenuOpenClose OnMenuOpened;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMenuOpenClose OnMenuClosed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDisplayMOTD;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPopoutPresented;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPopoutDismissed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpacer* ScrollBarSpacerLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpacer* ScrollBarSpacerRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroGameMenuScrollBarBase* ScrollBarWidgetLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroGameMenuScrollBarBase* ScrollBarWidgetRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroGameMenuSubPaneWidget* ActiveSubPaneWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroGameMenuSubPaneWidget* SubPaneWidgetLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroGameMenuSubPaneWidget* SubPaneWidgetRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameMenuWarningData GameMenuWarningData;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroGameMenuTabBarWidget* ActiveTabBarWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroGameMenuTabBarWidget* TabBarWidgetLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroGameMenuTabBarWidget* TabBarWidgetRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroGameMenuPopoutWidget* ActivePopoutWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* ActivePopoutWidgetAnchorPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumMenuWidthLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumMenuWidthRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScrollDelta;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroGameMenuFocusItemContainerWidget* ScrollBarContainerWidgetLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroGameMenuFocusItemContainerWidget* ScrollBarContainerWidgetRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* PopoutConnectorWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D PopoutPositionOffset;
    
public:
    UAstroGameMenuWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UseFMOTDWidget();
    
    UFUNCTION(BlueprintCallable)
    void ShowWarningsMenuPane();
    
    UFUNCTION(BlueprintCallable)
    void ShowMarketingMenuPane();
    
    UFUNCTION(BlueprintCallable)
    void ShowGameMenuWarningWidget(EGameMenuWarningWidgetTypes warningType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowFMOTDWidget(bool FadeIn);
    
    UFUNCTION(BlueprintCallable)
    void SetSubpaneHoverTarget(ESubpaneIdentifier hoverTarget);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetSaveErrorText(FText saveErrorText);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetRightPanelHidden(bool isHidden);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentPlayfabFailureReason(FAstroCGMPlayfabFailureReason failureReason);
    
protected:
    UFUNCTION(BlueprintCallable)
    void RequestNavigation(EGameMenuNavigationCommand NavCommand);
    
    UFUNCTION(BlueprintCallable)
    void ReCalculateMenuSize();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFullScreenPaneVisibilityChange(ESlateVisibility newVisibility);
    
    UFUNCTION(BlueprintCallable)
    void LockControls(bool bLockControls);
    
    UFUNCTION(BlueprintCallable)
    void HideGameMenuWarningWidget(EGameMenuWarningWidgetTypes warningType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideFMOTDWidget(bool FadeOut);
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleDebugMenuVisbilityChanged(bool IsVisible);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    float GetVerticalPaddingForContentSubPaneRegionRight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    float GetVerticalPaddingForContentSubPaneRegionLeft() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UCanvasPanel* GetTitleBannerWrapper() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UAstroGameMenuTabBarWidget* GetTabBarWidgetRight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UAstroGameMenuTabBarWidget* GetTabBarWidgetLeft() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UBorder* GetSubPaneWrapperRight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UBorder* GetSubPaneWrapperLeft() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ESubpaneIdentifier GetSubpaneHoverTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UBorder* GetSubPaneCursorAwarenessBorderRight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UBorder* GetSubPaneCursorAwarenessBorderLeft() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UCanvasPanel* GetPopoutWrapperRight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UCanvasPanel* GetPopoutWrapperLeft() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FVector2D GetOriginOfActiveSubPaneContentsRegionRight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FVector2D GetOriginOfActiveSubPaneContentsRegionLeft() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UVerticalBox* GetMenuContentsWrapperRight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UVerticalBox* GetMenuContentsWrapperLeft() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    float GetMaxHeightOfContentSubPaneRegionRight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    float GetMaxHeightOfContentSubPaneRegionLeft() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float GetLowerBoundOfMenuRight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float GetLowerBoundOfMenuLeft() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsRightPanelHidden() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UOverlay* GetFullScreenPaneWrapper() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetCachedBoundedSizeOfMenuPanelRight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetCachedBoundedSizeOfMenuPanelLeft() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    FVector2D GetBoundedSizeOfMenuPanelRight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    FVector2D GetBoundedSizeOfMenuPanelLeft() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAnyGameMenuWarningVisible();
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void BackToMainMenuHack();
    
};

