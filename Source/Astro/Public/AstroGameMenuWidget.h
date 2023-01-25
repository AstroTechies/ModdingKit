#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=ESlateVisibility -FallbackName=ESlateVisibility
#include "EAstroGameMenuContext.h"
#include "EGameMenuNavigationCommand.h"
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
class UUserWidget;
class UVerticalBox;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroGameMenuWidget : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMenuOpenClose, EAstroGameMenuContext, GameMenuContext);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FKey> WhitelistedKeys;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FKey> WhitelistedAxis;
    
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
    USpacer* ScrollBarSpacer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroGameMenuScrollBarBase* ScrollBarWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroGameMenuSubPaneWidget* ActiveSubPaneWidget;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroGameMenuTabBarWidget* ActiveTabBarWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroGameMenuPopoutWidget* ActivePopoutWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumMenuWidth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScrollDelta;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroGameMenuFocusItemContainerWidget* ScrollBarContainerWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* PopoutConnectorWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D PopoutPositionOffset;
    
public:
    UAstroGameMenuWidget();
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
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleDebugMenuVisbilityChanged(bool IsVisible);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    float GetVerticalPaddingForContentSubPaneRegion() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UAstroGameMenuTabBarWidget* GetTabBarWidget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UBorder* GetSubPaneWrapper() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UCanvasPanel* GetPopoutWrapper() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FVector2D GetOriginOfActiveSubPaneContentsRegion() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UUserWidget* GetMOTDWidget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UVerticalBox* GetMenuContentsWrapper() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    float GetMaxHeightOfContentSubPaneRegion() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float GetLowerBoundOfMenu() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UOverlay* GetFullScreenPaneWrapper() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    FVector2D GetBoundedSizeOfMenu() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UUserWidget* GetAchievementProgressionWarningWidget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void BackToMainMenuHack();
    
};

