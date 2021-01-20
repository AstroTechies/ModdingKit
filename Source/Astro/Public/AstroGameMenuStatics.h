// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/ActivationSignals.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AstroGameMenuStatics.generated.h"

class UUserWidget;
class UAstroGameMenuWidget;
struct FVector2D;

UENUM(BlueprintType)
enum class EAstroGameMenuContext : uint8 {
	InGame = 0,
	TitleMenu = 1,
	TutorialLaunching = 2,
	OutroCinematic = 3,
	ExitingGame = 4
};

UENUM(BlueprintType)
enum class EMouseFocusChangeSuppressionSource : uint8 {
	PopoutIsActive = 0,
	NavigationCommandWasIssued = 1,
	ScrollbarActive = 2,
	AstropediaSlidesOpen = 3
};

/**
 * 
 */
UCLASS()
class ASTRO_API UAstroGameMenuStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/*UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static void ChangeSubPaneOnTopOfNavigationStack(UObject* WorldContextObject, TSubclassOf<UAstroGameMenuSubPaneWidget> NewSubPane);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static void PushNavigationStackCoordinates(UObject* WorldContextObject, FAstroGameMenuNavigationCoordinates NavCoordinates);*/
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static void PopNavigationStack(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static void RestoreKeyboardFocusToGameMenu(UObject* WorldContextObject);
	/*UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static UAstroGameMenuPopoutWidget* PresentGameMenuPopoutWidget(UObject* WorldContextObject, UAstroGameMenuFocusItemWidget* OwningFocusItem, UAstroGameMenuPopoutWidgetContentsBase* PopoutContents, TSubclassOf<UAstroGameMenuPopoutWidget> OptionalCustomPopoutWrapper);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static UAstroGameMenuPopoutWidget* PresentGameMenuPopoutWidgetPreconstructed(UObject* WorldContextObject, UAstroGameMenuFocusItemWidget* OwningFocusItem, UAstroGameMenuPopoutWidgetContentsBase* PopoutContents, UAstroGameMenuPopoutWidget* PopoutWrapper);*/
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static void DismissCurrentGameMenuPopoutWidget(UObject* WorldContextObject);
	/*UFUNCTION(BlueprintCallable)
		static bool IsGameMenuTabBarAuthoringDataValid(FAstroGameMenuTabBarAuthoringData tabBarData);
	UFUNCTION(BlueprintCallable)
		static bool AreGameMenuTabBarAuthoringDataEqual(FAstroGameMenuTabBarAuthoringData tabBarDataA, FAstroGameMenuTabBarAuthoringData tabBarDataB);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static bool GetTutorialSlideDeck(UObject* WorldContextObject, EAstroGameMenuTutorialSlideDeckKey TutorialSlideDeckKey, FAstroGameMenuTutorialSlideDeck OutTutorialSlideDeckData);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static bool GetTutorialSlideCard(UObject* WorldContextObject, EAstroGameMenuTutoriaSlideCardKey TutorialSlideCardKey, FAstroGameMenuTutorialSlide OutTutorialSlideCardData);*/
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static bool IsMenuEntryBeingEditedOrDragged(UObject* WorldContextObject);
	/*UFUNCTION(BlueprintCallable)
		static bool GetKeybindingForDiscreteInputMapping(FAstroDiscreteInputDefinition* DiscreteInputDefinition, FKey OutKey, bool OutIsAxis);*/
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "worldContextObject"))
		static void GameMenuTryToSaveAndQuitGame(UObject* worldContextObject, bool returnToTitleScreen, FFailedToSaveGameOnQuit onFailedToSaveGame);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "worldContextObject"))
		static void GameMenuForceQuitGame(UObject* worldContextObject, bool returnToTitleScreen, bool attemptToSave);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static void PresentTitleGameMenu(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static void DismissTitleGameMenu(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static void DismissGameMenu(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static void ChangeMenuContext(UObject* WorldContextObject, EAstroGameMenuContext NewMenuContext);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static void LayoutGameMenu(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static void LayoutGameMenuActiveSubPane(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static void ResizeCurrentPopout(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static void LockGameMenuControls(UObject* WorldContextObject, bool IsLocked);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "worldContextObject"))
		static void AddMouseFocusSuppressionToCurrentSubPane(UObject* worldContextObject, EMouseFocusChangeSuppressionSource mouseSuppression);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "worldContextObject"))
		static void RemoveMouseFocusSuppressionFromCurrentSubPane(UObject* worldContextObject, EMouseFocusChangeSuppressionSource mouseSuppression);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static bool AreGameMenuControlsLocked(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static void ClearGameMenuSelection(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static bool TryGetCurrentGameMenuContext(UObject* WorldContextObject, EAstroGameMenuContext OutCurrentMenuContext);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static bool IsPreviewingCharacterCustomizationFromTitleScreen(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static void SetIsPreviewingCharacterCustomizationFromTitleScreen(UObject* WorldContextObject, bool IsPreviewing);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static FVector2D GetCachedSizeOfGameMenu(UObject* WorldContextObject, bool includeScrollBarSize);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static FVector2D GetOriginOfActiveSubPaneContentsRegion(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static UUserWidget* GetAchievementProgressionWarningWidget(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static UUserWidget* GetMOTDWidget(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
		static UAstroGameMenuWidget* GetGameMenuWidget(UObject* WorldContextObject);
};
