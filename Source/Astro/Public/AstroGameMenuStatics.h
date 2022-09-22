#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EAstroGameMenuTutorialSlideDeckKey.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "AstroGameMenuNavigationCoordinates.h"
#include "EAstroGameMenuContext.h"
#include "EMouseFocusChangeSuppressionSource.h"
#include "AstroGameMenuTabBarAuthoringData.h"
#include "EAstroGameMenuTutoriaSlideCardKey.h"
#include "AstroGameMenuTutorialSlide.h"
#include "AstroGameMenuTutorialSlideDeck.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "AstroDiscreteInputDefinition.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include "FailedToSaveGameOnQuitDelegate.h"
#include "AstroGameMenuStatics.generated.h"

class UAstroGameMenuPopoutWidgetContentsBase;
class UObject;
class UAstroGameMenuFocusItemWidget;
class UUserWidget;
class UAstroGameMenuPopoutWidget;
class UAstroGameMenuWidget;
class UAstroGameMenuSubPaneWidget;

UCLASS(Blueprintable)
class ASTRO_API UAstroGameMenuStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAstroGameMenuStatics();
    UFUNCTION(BlueprintPure)
    static bool TryGetCurrentGameMenuContext(UObject* WorldContextObject, EAstroGameMenuContext& OutCurrentMenuContext);
    
    UFUNCTION(BlueprintCallable)
    static void RestoreKeyboardFocusToGameMenu(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void ResizeCurrentPopout(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveMouseFocusSuppressionFromCurrentSubPane(UObject* WorldContextObject, EMouseFocusChangeSuppressionSource MouseSuppression);
    
    UFUNCTION(BlueprintCallable)
    static void PushNavigationStackCoordinates(UObject* WorldContextObject, const FAstroGameMenuNavigationCoordinates& NavCoordinates);
    
    UFUNCTION(BlueprintCallable)
    static void PresentTitleGameMenu(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static UAstroGameMenuPopoutWidget* PresentGameMenuPopoutWidgetPreconstructed(UObject* WorldContextObject, UAstroGameMenuFocusItemWidget* OwningFocusItem, UAstroGameMenuPopoutWidgetContentsBase* PopoutContents, UAstroGameMenuPopoutWidget* PopoutWrapper);
    
    UFUNCTION(BlueprintCallable)
    static UAstroGameMenuPopoutWidget* PresentGameMenuPopoutWidget(UObject* WorldContextObject, UAstroGameMenuFocusItemWidget* OwningFocusItem, UAstroGameMenuPopoutWidgetContentsBase* PopoutContents, TSubclassOf<UAstroGameMenuPopoutWidget> OptionalCustomPopoutWrapper);
    
    UFUNCTION(BlueprintCallable)
    static void PopNavigationStack(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void LockGameMenuControls(UObject* WorldContextObject, bool IsLocked);
    
    UFUNCTION(BlueprintCallable)
    static void LayoutGameMenuActiveSubPane(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void LayoutGameMenu(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure)
    static bool IsMenuEntryBeingEditedOrDragged(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure)
    static bool IsGameMenuTabBarAuthoringDataValid(const FAstroGameMenuTabBarAuthoringData& tabBarData);
    
    UFUNCTION(BlueprintPure)
    static EAstroGameMenuTutorialSlideDeckKey GetTutorialSlideDeckForCard(UObject* WorldContextObject, EAstroGameMenuTutoriaSlideCardKey TutorialSlideCardKey);
    
    UFUNCTION(BlueprintPure)
    static bool GetTutorialSlideDeck(UObject* WorldContextObject, EAstroGameMenuTutorialSlideDeckKey TutorialSlideDeckKey, FAstroGameMenuTutorialSlideDeck& OutTutorialSlideDeckData);
    
    UFUNCTION(BlueprintPure)
    static bool GetTutorialSlideCard(UObject* WorldContextObject, EAstroGameMenuTutoriaSlideCardKey TutorialSlideCardKey, FAstroGameMenuTutorialSlide& OutTutorialSlideCardData);
    
    UFUNCTION(BlueprintPure)
    static FVector2D GetOriginOfActiveSubPaneContentsRegion(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure)
    static UUserWidget* GetMOTDWidget(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure)
    static bool GetKeybindingForDiscreteInputMapping(FAstroDiscreteInputDefinition DiscreteInputDefinition, FKey& OutKey, bool& OutIsAxis, bool ForGamepad);
    
    UFUNCTION(BlueprintPure)
    static UAstroGameMenuWidget* GetGameMenuWidget(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure)
    static FVector2D GetCachedSizeOfGameMenu(UObject* WorldContextObject, bool IncludeScrollBarSize);
    
    UFUNCTION(BlueprintPure)
    static UUserWidget* GetAchievementProgressionWarningWidget(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void GameMenuTryToSaveAndQuitGame(UObject* WorldContextObject, bool ReturnToTitleScreen, FFailedToSaveGameOnQuit OnFailedToSaveGame);
    
    UFUNCTION(BlueprintCallable)
    static void GameMenuForceQuitGame(UObject* WorldContextObject, bool ReturnToTitleScreen, bool AttemptToSave);
    
    UFUNCTION(BlueprintCallable)
    static void DismissTitleGameMenu(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void DismissGameMenu(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void DismissCurrentGameMenuPopoutWidget(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void ClearGameMenuSelection(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void ChangeSubPaneOnTopOfNavigationStack(UObject* WorldContextObject, TSubclassOf<UAstroGameMenuSubPaneWidget> NewSubPane);
    
    UFUNCTION(BlueprintCallable)
    static void ChangeMenuContext(UObject* WorldContextObject, EAstroGameMenuContext NewMenuContext);
    
    UFUNCTION(BlueprintPure)
    static bool AreGameMenuTabBarAuthoringDataEqual(const FAstroGameMenuTabBarAuthoringData& tabBarDataA, const FAstroGameMenuTabBarAuthoringData& tabBarDataB);
    
    UFUNCTION(BlueprintCallable)
    static bool AreGameMenuControlsLocked(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void AddMouseFocusSuppressionToCurrentSubPane(UObject* WorldContextObject, EMouseFocusChangeSuppressionSource MouseSuppression);
    
};

