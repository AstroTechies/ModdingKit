#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InputCoreTypes.h"
#include "AstroDiscreteInputDefinition.h"
#include "AstroGameMenuNavigationCoordinates.h"
#include "AstroGameMenuTabBarAuthoringData.h"
#include "AstroGameMenuTutorialSlide.h"
#include "AstroGameMenuTutorialSlideDeck.h"
#include "EAstroGameMenuContext.h"
#include "EAstroGameMenuTutoriaSlideCardKey.h"
#include "EAstroGameMenuTutorialSlideDeckKey.h"
#include "EGameMenuWarningWidgetTypes.h"
#include "EMouseFocusChangeSuppressionSource.h"
#include "FAstroCGMPlayfabFailureReason.h"
#include "FailedToSaveGameOnQuitDelegate.h"
#include "Templates/SubclassOf.h"
#include "AstroGameMenuStatics.generated.h"

class UAstroGameMenuFocusItemWidget;
class UAstroGameMenuPopoutWidget;
class UAstroGameMenuPopoutWidgetContentsBase;
class UAstroGameMenuSubPaneWidget;
class UAstroGameMenuWidget;
class UObject;

UCLASS(Blueprintable)
class ASTRO_API UAstroGameMenuStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAstroGameMenuStatics();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool TrySetCurrentGameMenuContext(UObject* WorldContextObject, EAstroGameMenuContext NewMenuContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool TryGetPreviousGameMenuContext(UObject* WorldContextObject, EAstroGameMenuContext& OutPreviousMenuContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool TryGetCurrentGameMenuContext(UObject* WorldContextObject, EAstroGameMenuContext& OutCurrentMenuContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ShowWarningPane(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ShowMarketingPane(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ShowGameMenuWarningWidget(UObject* WorldContextObject, EGameMenuWarningWidgetTypes warningType);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetRightMenuPanelHidden(UObject* WorldContextObject, bool isHidden);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetIsPreviewingCharacterCustomizationFromTitleScreen(UObject* WorldContextObject, bool IsPreviewing);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetCurrentPlayfabFailureReason(UObject* WorldContextObject, FAstroCGMPlayfabFailureReason failureReason);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RestoreKeyboardFocusToGameMenu(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ResizeCurrentPopout(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RemoveMouseFocusSuppressionFromCurrentSubPane(UObject* WorldContextObject, EMouseFocusChangeSuppressionSource MouseSuppression);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PushNavigationStackCoordinates(UObject* WorldContextObject, const FAstroGameMenuNavigationCoordinates& NavCoordinates);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PresentTitleGameMenu(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAstroGameMenuPopoutWidget* PresentGameMenuPopoutWidgetPreconstructed(UObject* WorldContextObject, UAstroGameMenuFocusItemWidget* OwningFocusItem, UAstroGameMenuPopoutWidgetContentsBase* PopoutContents, UAstroGameMenuPopoutWidget* PopoutWrapper);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAstroGameMenuPopoutWidget* PresentGameMenuPopoutWidget(UObject* WorldContextObject, UAstroGameMenuFocusItemWidget* OwningFocusItem, UAstroGameMenuPopoutWidgetContentsBase* PopoutContents, bool SkipInitialFocus, TSubclassOf<UAstroGameMenuPopoutWidget> OptionalCustomPopoutWrapper, bool IsRightPanelPopout);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PopNavigationStack(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LockGameMenuControls(UObject* WorldContextObject, bool IsLocked);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LayoutGameMenuActiveSubPane(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LayoutGameMenu(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsPreviewingCharacterCustomizationFromTitleScreen(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsMenuEntryBeingEditedOrDragged(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsGameMenuTabBarAuthoringDataValid(const FAstroGameMenuTabBarAuthoringData& tabBarData);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void HideGameMenuWarningWidget(UObject* WorldContextObject, EGameMenuWarningWidgetTypes warningType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static EAstroGameMenuTutorialSlideDeckKey GetTutorialSlideDeckForCard(UObject* WorldContextObject, EAstroGameMenuTutoriaSlideCardKey TutorialSlideCardKey);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool GetTutorialSlideDeck(UObject* WorldContextObject, EAstroGameMenuTutorialSlideDeckKey TutorialSlideDeckKey, FAstroGameMenuTutorialSlideDeck& OutTutorialSlideDeckData);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool GetTutorialSlideCard(UObject* WorldContextObject, EAstroGameMenuTutoriaSlideCardKey TutorialSlideCardKey, FAstroGameMenuTutorialSlide& OutTutorialSlideCardData);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FVector2D GetOriginOfActiveSubPaneContentsRegionRight(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FVector2D GetOriginOfActiveSubPaneContentsRegionLeft(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetKeybindingForDiscreteInputMapping(FAstroDiscreteInputDefinition DiscreteInputDefinition, FKey& OutKey, bool& OutIsAxis, bool ForGamepad);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UAstroGameMenuWidget* GetGameMenuWidget(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GameMenuTryToSaveAndQuitGame(UObject* WorldContextObject, bool ReturnToTitleScreen, FFailedToSaveGameOnQuit OnFailedToSaveGame);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GameMenuForceQuitGame(UObject* WorldContextObject, bool ReturnToTitleScreen, bool AttemptToSave, bool DisplayOutOfLivesPrompt);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DismissTitleGameMenu(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DismissGameMenu(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DismissCurrentGameMenuPopoutWidget(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ClearGameMenuSelection(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ChangeSubPaneOnTopOfNavigationStack(UObject* WorldContextObject, TSubclassOf<UAstroGameMenuSubPaneWidget> NewSubPaneLeft, TSubclassOf<UAstroGameMenuSubPaneWidget> NewSubPaneRight, int32 TabBarSelectionIndex);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ChangeMenuContext(UObject* WorldContextObject, EAstroGameMenuContext NewMenuContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AreGameMenuTabBarAuthoringDataEqual(const FAstroGameMenuTabBarAuthoringData& tabBarDataA, const FAstroGameMenuTabBarAuthoringData& tabBarDataB);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool AreGameMenuControlsLocked(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void AddMouseFocusSuppressionToCurrentSubPane(UObject* WorldContextObject, EMouseFocusChangeSuppressionSource MouseSuppression);
    
};

