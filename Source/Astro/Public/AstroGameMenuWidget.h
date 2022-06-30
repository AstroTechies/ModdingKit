#pragma once
#include "CoreMinimal.h"
#include "EAstroGameMenuContext.h"
#include "UserWidgetBlueprintDesignable.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"
#include "SignalDelegate.h"
#include "EGameMenuNavigationCommand.h"
#include "Components/SlateWrapperTypes.h"
#include "AstroGameMenuWidget.generated.h"

class UAstroGameMenuTabBarWidget;
class UAstroGameMenuScrollBarBase;
class UAstroGameMenuSubPaneWidget;
class USpacer;
class UUserWidget;
class UAstroGameMenuPopoutWidget;
class UAstroGameMenuFocusItemContainerWidget;
class UImage;
class UBorder;
class UCanvasPanel;
class UVerticalBox;
class UOverlay;

UCLASS(Blueprintable, Abstract, EditInlineNew)
class UAstroGameMenuWidget : public UUserWidgetBlueprintDesignable
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMenuOpenClose, EAstroGameMenuContext, GameMenuContext);

    UPROPERTY(EditDefaultsOnly)
    TArray<FKey> WhitelistedKeys;

    UPROPERTY(EditDefaultsOnly)
    TArray<FKey> WhitelistedAxis;

    UPROPERTY(BlueprintAssignable)
    FOnMenuOpenClose OnMenuOpened;

    UPROPERTY(BlueprintAssignable)
    FOnMenuOpenClose OnMenuClosed;

    UPROPERTY(BlueprintAssignable)
    FSignal OnDisplayMOTD;

    UPROPERTY(BlueprintAssignable)
    FSignal OnPopoutPresented;

    UPROPERTY(BlueprintAssignable)
    FSignal OnPopoutDismissed;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USpacer *ScrollBarSpacer;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UAstroGameMenuScrollBarBase *ScrollBarWidget;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UAstroGameMenuSubPaneWidget *ActiveSubPaneWidget;

protected:
    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UAstroGameMenuTabBarWidget *ActiveTabBarWidget;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UAstroGameMenuPopoutWidget *ActivePopoutWidget;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MinimumMenuWidth;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ScrollDelta;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UAstroGameMenuFocusItemContainerWidget *ScrollBarContainerWidget;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UImage *PopoutConnectorWidget;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector2D PopoutPositionOffset;

public:
    UAstroGameMenuWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void RequestNavigation(EGameMenuNavigationCommand NavCommand);

    UFUNCTION(BlueprintCallable)
    void ReCalculateMenuSize();

public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnFullScreenPaneVisibilityChange(ESlateVisibility newVisibility);

    UFUNCTION(BlueprintCallable)
    void LockControls(bool bLockControls);

private:
    UFUNCTION()
    void HandleDebugMenuVisbilityChanged(bool IsVisible);

public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    float GetVerticalPaddingForContentSubPaneRegion() const;

    UFUNCTION(BlueprintImplementableEvent)
    UAstroGameMenuTabBarWidget *GetTabBarWidget() const;

    UFUNCTION(BlueprintImplementableEvent)
    UBorder *GetSubPaneWrapper() const;

    UFUNCTION(BlueprintImplementableEvent)
    UCanvasPanel *GetPopoutWrapper() const;

    UFUNCTION(BlueprintImplementableEvent)
    FVector2D GetOriginOfActiveSubPaneContentsRegion() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    UUserWidget *GetMOTDWidget() const;

    UFUNCTION(BlueprintImplementableEvent)
    UVerticalBox *GetMenuContentsWrapper() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    float GetMaxHeightOfContentSubPaneRegion() const;

    UFUNCTION(BlueprintImplementableEvent)
    float GetLowerBoundOfMenu() const;

    UFUNCTION(BlueprintImplementableEvent)
    UOverlay *GetFullScreenPaneWrapper() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    FVector2D GetBoundedSizeOfMenu() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    UUserWidget *GetAchievementProgressionWarningWidget() const;

    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void BackToMainMenuHack();
};
