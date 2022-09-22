#pragma once
#include "CoreMinimal.h"
#include "UserWidgetBlueprintDesignable.h"
#include "EAstroGameMenuContext.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "EGameMenuNavigationCommand.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=ESlateVisibility -FallbackName=ESlateVisibility
#include "AstroGameMenuWidget.generated.h"

class UAstroGameMenuTabBarWidget;
class UBorder;
class USpacer;
class UAstroGameMenuScrollBarBase;
class UAstroGameMenuSubPaneWidget;
class UUserWidget;
class UAstroGameMenuPopoutWidget;
class UAstroGameMenuFocusItemContainerWidget;
class UImage;
class UCanvasPanel;
class UVerticalBox;
class UOverlay;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USpacer* ScrollBarSpacer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UAstroGameMenuScrollBarBase* ScrollBarWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UAstroGameMenuSubPaneWidget* ActiveSubPaneWidget;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UAstroGameMenuTabBarWidget* ActiveTabBarWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UAstroGameMenuPopoutWidget* ActivePopoutWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumMenuWidth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScrollDelta;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UAstroGameMenuFocusItemContainerWidget* ScrollBarContainerWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
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
    UAstroGameMenuTabBarWidget* GetTabBarWidget() const;
    
    UFUNCTION(BlueprintImplementableEvent)
    UBorder* GetSubPaneWrapper() const;
    
    UFUNCTION(BlueprintImplementableEvent)
    UCanvasPanel* GetPopoutWrapper() const;
    
    UFUNCTION(BlueprintImplementableEvent)
    FVector2D GetOriginOfActiveSubPaneContentsRegion() const;
    
    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    UUserWidget* GetMOTDWidget() const;
    
    UFUNCTION(BlueprintImplementableEvent)
    UVerticalBox* GetMenuContentsWrapper() const;
    
    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    float GetMaxHeightOfContentSubPaneRegion() const;
    
    UFUNCTION(BlueprintImplementableEvent)
    float GetLowerBoundOfMenu() const;
    
    UFUNCTION(BlueprintImplementableEvent)
    UOverlay* GetFullScreenPaneWrapper() const;
    
    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    FVector2D GetBoundedSizeOfMenu() const;
    
    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    UUserWidget* GetAchievementProgressionWarningWidget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void BackToMainMenuHack();
    
};

