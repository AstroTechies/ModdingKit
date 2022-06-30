#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Engine/DataAsset.h"
#include "EAstroColor.h"
#include "ColorPaletteGameMenuTabBarButton.h"
#include "Layout/Margin.h"
#include "Fonts/SlateFontInfo.h"
#include "AstroGameMenuAuthoringDefinition.h"
#include "AstroUIStylingDatabase.generated.h"

class UAstroGameMenuTabBarButtonWidget;

UCLASS(Blueprintable, BlueprintType)
class UAstroUIStylingDatabase : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    EAstroColor ColorGameMenuTitle;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    EAstroColor ColorGameMenuSubsectionHeader;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    EAstroColor ColorGameMenuEntryTextUnfocused;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    EAstroColor ColorGameMenuEntryTextFocused;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    EAstroColor ColorGameMenuEntryInteractiveElementFocused;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    EAstroColor ColorGameMenuEntryInteractiveElementUnfocused;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    EAstroColor ColorGameMenuEntryFocusedBG;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    EAstroColor ColorGameMenuEntryDisabled;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    EAstroColor ColorGameMenuTabBarBG;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    EAstroColor ColorGameMenuPanelBG;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    EAstroColor ColorGameMenuTabBarSubPaneSeparator;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    EAstroColor ColorGameMenuScrollBarHandleColor;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    EAstroColor ColorGameMenuScrollBarBGColor;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FColorPaletteGameMenuTabBarButton ColorPaletteGameMenuTabBarGeneric;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FColorPaletteGameMenuTabBarButton ColorPaletteGameMenuTabBarButtonBack;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FColorPaletteGameMenuTabBarButton ColorPaletteGameMenuTabBarButtonQuit;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FSlateFontInfo FontGameMenuTitle;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FSlateFontInfo FontGameMenuSubsectionHeader;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FSlateFontInfo FontGameMenuSubsectionSubtitle;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FSlateFontInfo FontGameMenuEntryBold;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FSlateFontInfo FontGameMenuEntryNormal;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FAstroGameMenuAuthoringDefinition HostMidGameMenu;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FAstroGameMenuAuthoringDefinition ClientMidGameMenu;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FAstroGameMenuAuthoringDefinition HostTitleScreenMenu;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FAstroGameMenuAuthoringDefinition HostTitleScreenMenuConsole;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FAstroGameMenuAuthoringDefinition ClientTitleScreenMenu;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FAstroGameMenuAuthoringDefinition ClientTitleScreenMenuConsole;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FAstroGameMenuAuthoringDefinition JoiningPasswordRequestMenu;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UAstroGameMenuTabBarButtonWidget> AstropediaTabBarButtonClass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UAstroGameMenuTabBarButtonWidget> CreativeModeTabBarButtonClass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UAstroGameMenuTabBarButtonWidget> StoreTabBarButtonClass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UAstroGameMenuTabBarButtonWidget> ServerAdminTabBarButtonClass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UAstroGameMenuTabBarButtonWidget> ServerInfoTabBarButtonClass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UAstroGameMenuTabBarButtonWidget> ServerListTabBarButtonClass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FMargin StandardMenuEntryWidgetMargin;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText CosmeticUnlockSucceededMsg;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText CosmeticUnlockFailedGenericMsg;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText CosmeticUnlockFailedTimeoutMsg;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText CosmeticUnlockFailedCodeInvalidMsg;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText CosmeticUnlockFailedCodeAlreadyUsedMsg;

    UAstroUIStylingDatabase();
};
