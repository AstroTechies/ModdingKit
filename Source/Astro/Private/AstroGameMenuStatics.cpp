// Fill out your copyright notice in the Description page of Project Settings.


#include "AstroGameMenuStatics.h"

/*void UAstroGameMenuStatics::ChangeSubPaneOnTopOfNavigationStack(UObject* WorldContextObject, TSubclassOf<UAstroGameMenuSubPaneWidget> NewSubPane)
{

}

void UAstroGameMenuStatics::PushNavigationStackCoordinates(UObject* WorldContextObject, FAstroGameMenuNavigationCoordinates NavCoordinates)
{

}*/

void UAstroGameMenuStatics::PopNavigationStack(UObject* WorldContextObject)
{

}

void UAstroGameMenuStatics::RestoreKeyboardFocusToGameMenu(UObject* WorldContextObject)
{

}

/*UAstroGameMenuPopoutWidget* UAstroGameMenuStatics::PresentGameMenuPopoutWidget(UObject* WorldContextObject, UAstroGameMenuFocusItemWidget* OwningFocusItem, UAstroGameMenuPopoutWidgetContentsBase* PopoutContents, TSubclassOf<UAstroGameMenuPopoutWidget> OptionalCustomPopoutWrapper)
{
	return nullptr;
}

UAstroGameMenuPopoutWidget* UAstroGameMenuStatics::PresentGameMenuPopoutWidgetPreconstructed(UObject* WorldContextObject, UAstroGameMenuFocusItemWidget* OwningFocusItem, UAstroGameMenuPopoutWidgetContentsBase* PopoutContents, UAstroGameMenuPopoutWidget* PopoutWrapper)
{
	return nullptr;
}*/

void UAstroGameMenuStatics::DismissCurrentGameMenuPopoutWidget(UObject* WorldContextObject)
{

}

/*bool UAstroGameMenuStatics::IsGameMenuTabBarAuthoringDataValid(FAstroGameMenuTabBarAuthoringData tabBarData)
{
	return false;
}

bool UAstroGameMenuStatics::AreGameMenuTabBarAuthoringDataEqual(FAstroGameMenuTabBarAuthoringData tabBarDataA, FAstroGameMenuTabBarAuthoringData tabBarDataB)
{
	return false;
}

bool UAstroGameMenuStatics::GetTutorialSlideDeck(UObject* WorldContextObject, EAstroGameMenuTutorialSlideDeckKey TutorialSlideDeckKey, FAstroGameMenuTutorialSlideDeck OutTutorialSlideDeckData)
{
	return false;
}

bool UAstroGameMenuStatics::GetTutorialSlideCard(UObject* WorldContextObject, EAstroGameMenuTutoriaSlideCardKey TutorialSlideCardKey, FAstroGameMenuTutorialSlide OutTutorialSlideCardData)
{
	return false;
}*/

bool UAstroGameMenuStatics::IsMenuEntryBeingEditedOrDragged(UObject* WorldContextObject)
{
	return false;
}

/*bool UAstroGameMenuStatics::GetKeybindingForDiscreteInputMapping(FAstroDiscreteInputDefinition* DiscreteInputDefinition, FKey OutKey, bool OutIsAxis)
{
	return false;
}*/

void UAstroGameMenuStatics::GameMenuTryToSaveAndQuitGame(UObject* worldContextObject, bool returnToTitleScreen, FFailedToSaveGameOnQuit onFailedToSaveGame)
{

}

void UAstroGameMenuStatics::GameMenuForceQuitGame(UObject* worldContextObject, bool returnToTitleScreen, bool attemptToSave)
{

}

void UAstroGameMenuStatics::PresentTitleGameMenu(UObject* WorldContextObject)
{

}

void UAstroGameMenuStatics::DismissTitleGameMenu(UObject* WorldContextObject)
{

}

void UAstroGameMenuStatics::DismissGameMenu(UObject* WorldContextObject)
{

}

void UAstroGameMenuStatics::ChangeMenuContext(UObject* WorldContextObject, EAstroGameMenuContext NewMenuContext)
{

}

void UAstroGameMenuStatics::LayoutGameMenu(UObject* WorldContextObject)
{

}

void UAstroGameMenuStatics::LayoutGameMenuActiveSubPane(UObject* WorldContextObject)
{

}

void UAstroGameMenuStatics::ResizeCurrentPopout(UObject* WorldContextObject)
{

}

void UAstroGameMenuStatics::LockGameMenuControls(UObject* WorldContextObject, bool IsLocked)
{

}

void UAstroGameMenuStatics::AddMouseFocusSuppressionToCurrentSubPane(UObject* worldContextObject, EMouseFocusChangeSuppressionSource mouseSuppression)
{

}

void UAstroGameMenuStatics::RemoveMouseFocusSuppressionFromCurrentSubPane(UObject* worldContextObject, EMouseFocusChangeSuppressionSource mouseSuppression)
{

}

bool UAstroGameMenuStatics::AreGameMenuControlsLocked(UObject* WorldContextObject)
{
	return false;
}

void UAstroGameMenuStatics::ClearGameMenuSelection(UObject* WorldContextObject)
{

}

bool UAstroGameMenuStatics::TryGetCurrentGameMenuContext(UObject* WorldContextObject, EAstroGameMenuContext OutCurrentMenuContext)
{
	return false;
}

bool UAstroGameMenuStatics::IsPreviewingCharacterCustomizationFromTitleScreen(UObject* WorldContextObject)
{
	return false;
}

void UAstroGameMenuStatics::SetIsPreviewingCharacterCustomizationFromTitleScreen(UObject* WorldContextObject, bool IsPreviewing)
{

}

FVector2D UAstroGameMenuStatics::GetCachedSizeOfGameMenu(UObject* WorldContextObject, bool includeScrollBarSize)
{
	return FVector2D(0, 0);
}

FVector2D UAstroGameMenuStatics::GetOriginOfActiveSubPaneContentsRegion(UObject* WorldContextObject)
{
	return FVector2D(0, 0);
}

UUserWidget* UAstroGameMenuStatics::GetAchievementProgressionWarningWidget(UObject* WorldContextObject)
{
	return nullptr;
}

UUserWidget* UAstroGameMenuStatics::GetMOTDWidget(UObject* WorldContextObject)
{
	return nullptr;
}

UAstroGameMenuWidget* UAstroGameMenuStatics::GetGameMenuWidget(UObject* WorldContextObject)
{
	return nullptr;
}