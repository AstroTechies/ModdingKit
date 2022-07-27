#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EMouseFocusChangeSuppressionSource.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "EAstroGameMenuContext.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include "EAstroGameMenuTutorialSlideDeckKey.h"
#include "AstroGameMenuTutorialSlide.h"
#include "AstroGameMenuTabBarAuthoringData.h"
#include "AstroGameMenuNavigationCoordinates.h"
#include "EAstroGameMenuTutoriaSlideCardKey.h"
#include "AstroGameMenuTutorialSlideDeck.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "AstroDiscreteInputDefinition.h"
#include "FailedToSaveGameOnQuitDelegate.h"
#include "AstroGameMenuStatics.generated.h"

class UAstroGameMenuFocusItemWidget;
class UUserWidget;
class UAstroGameMenuPopoutWidget;
class UObject;
class UAstroGameMenuPopoutWidgetContentsBase;
class UAstroGameMenuWidget;
class UAstroGameMenuSubPaneWidget;

UCLASS(Blueprintable)
class ASTRO_API UAstroGameMenuStatics : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UAstroGameMenuStatics();
    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool TryGetCurrentGameMenuContext(UObject *WorldContextObject, EAstroGameMenuContext &OutCurrentMenuContext);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void RestoreKeyboardFocusToGameMenu(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void ResizeCurrentPopout(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void RemoveMouseFocusSuppressionFromCurrentSubPane(UObject *WorldContextObject, EMouseFocusChangeSuppressionSource MouseSuppression);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void PushNavigationStackCoordinates(UObject *WorldContextObject, const FAstroGameMenuNavigationCoordinates &NavCoordinates);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void PresentTitleGameMenu(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static UAstroGameMenuPopoutWidget *PresentGameMenuPopoutWidgetPreconstructed(UObject *WorldContextObject, UAstroGameMenuFocusItemWidget *OwningFocusItem, UAstroGameMenuPopoutWidgetContentsBase *PopoutContents, UAstroGameMenuPopoutWidget *PopoutWrapper);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static UAstroGameMenuPopoutWidget *PresentGameMenuPopoutWidget(UObject *WorldContextObject, UAstroGameMenuFocusItemWidget *OwningFocusItem, UAstroGameMenuPopoutWidgetContentsBase *PopoutContents, TSubclassOf<UAstroGameMenuPopoutWidget> OptionalCustomPopoutWrapper);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void PopNavigationStack(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void LockGameMenuControls(UObject *WorldContextObject, bool IsLocked);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void LayoutGameMenuActiveSubPane(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void LayoutGameMenu(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool IsMenuEntryBeingEditedOrDragged(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool IsGameMenuTabBarAuthoringDataValid(const FAstroGameMenuTabBarAuthoringData &tabBarData);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static EAstroGameMenuTutorialSlideDeckKey GetTutorialSlideDeckForCard(UObject *WorldContextObject, EAstroGameMenuTutoriaSlideCardKey TutorialSlideCardKey);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool GetTutorialSlideDeck(UObject *WorldContextObject, EAstroGameMenuTutorialSlideDeckKey TutorialSlideDeckKey, FAstroGameMenuTutorialSlideDeck &OutTutorialSlideDeckData);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool GetTutorialSlideCard(UObject *WorldContextObject, EAstroGameMenuTutoriaSlideCardKey TutorialSlideCardKey, FAstroGameMenuTutorialSlide &OutTutorialSlideCardData);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static FVector2D GetOriginOfActiveSubPaneContentsRegion(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static UUserWidget *GetMOTDWidget(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool GetKeybindingForDiscreteInputMapping(FAstroDiscreteInputDefinition DiscreteInputDefinition, FKey &OutKey, bool &OutIsAxis, bool ForGamepad);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static UAstroGameMenuWidget *GetGameMenuWidget(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static FVector2D GetCachedSizeOfGameMenu(UObject *WorldContextObject, bool IncludeScrollBarSize);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static UUserWidget *GetAchievementProgressionWarningWidget(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void GameMenuTryToSaveAndQuitGame(UObject *WorldContextObject, bool ReturnToTitleScreen, FFailedToSaveGameOnQuit OnFailedToSaveGame);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void GameMenuForceQuitGame(UObject *WorldContextObject, bool ReturnToTitleScreen, bool AttemptToSave);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void DismissTitleGameMenu(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void DismissGameMenu(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void DismissCurrentGameMenuPopoutWidget(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void ClearGameMenuSelection(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void ChangeSubPaneOnTopOfNavigationStack(UObject *WorldContextObject, TSubclassOf<UAstroGameMenuSubPaneWidget> NewSubPane);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void ChangeMenuContext(UObject *WorldContextObject, EAstroGameMenuContext NewMenuContext);

    UFUNCTION(BlueprintPure)
    static bool AreGameMenuTabBarAuthoringDataEqual(const FAstroGameMenuTabBarAuthoringData &tabBarDataA, const FAstroGameMenuTabBarAuthoringData &tabBarDataB);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static bool AreGameMenuControlsLocked(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void AddMouseFocusSuppressionToCurrentSubPane(UObject *WorldContextObject, EMouseFocusChangeSuppressionSource MouseSuppression);
};
