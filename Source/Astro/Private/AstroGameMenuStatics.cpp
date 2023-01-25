#include "AstroGameMenuStatics.h"
#include "Templates/SubclassOf.h"

class UAstroGameMenuFocusItemWidget;
class UAstroGameMenuPopoutWidget;
class UAstroGameMenuPopoutWidgetContentsBase;
class UAstroGameMenuSubPaneWidget;
class UAstroGameMenuWidget;
class UObject;
class UUserWidget;

bool UAstroGameMenuStatics::TryGetCurrentGameMenuContext(UObject* WorldContextObject, EAstroGameMenuContext& OutCurrentMenuContext) {
    return false;
}

void UAstroGameMenuStatics::RestoreKeyboardFocusToGameMenu(UObject* WorldContextObject) {
}

void UAstroGameMenuStatics::ResizeCurrentPopout(UObject* WorldContextObject) {
}

void UAstroGameMenuStatics::RemoveMouseFocusSuppressionFromCurrentSubPane(UObject* WorldContextObject, EMouseFocusChangeSuppressionSource MouseSuppression) {
}

void UAstroGameMenuStatics::PushNavigationStackCoordinates(UObject* WorldContextObject, const FAstroGameMenuNavigationCoordinates& NavCoordinates) {
}

void UAstroGameMenuStatics::PresentTitleGameMenu(UObject* WorldContextObject) {
}

UAstroGameMenuPopoutWidget* UAstroGameMenuStatics::PresentGameMenuPopoutWidgetPreconstructed(UObject* WorldContextObject, UAstroGameMenuFocusItemWidget* OwningFocusItem, UAstroGameMenuPopoutWidgetContentsBase* PopoutContents, UAstroGameMenuPopoutWidget* PopoutWrapper) {
    return NULL;
}

UAstroGameMenuPopoutWidget* UAstroGameMenuStatics::PresentGameMenuPopoutWidget(UObject* WorldContextObject, UAstroGameMenuFocusItemWidget* OwningFocusItem, UAstroGameMenuPopoutWidgetContentsBase* PopoutContents, TSubclassOf<UAstroGameMenuPopoutWidget> OptionalCustomPopoutWrapper) {
    return NULL;
}

void UAstroGameMenuStatics::PopNavigationStack(UObject* WorldContextObject) {
}

void UAstroGameMenuStatics::LockGameMenuControls(UObject* WorldContextObject, bool IsLocked) {
}

void UAstroGameMenuStatics::LayoutGameMenuActiveSubPane(UObject* WorldContextObject) {
}

void UAstroGameMenuStatics::LayoutGameMenu(UObject* WorldContextObject) {
}

bool UAstroGameMenuStatics::IsMenuEntryBeingEditedOrDragged(UObject* WorldContextObject) {
    return false;
}

bool UAstroGameMenuStatics::IsGameMenuTabBarAuthoringDataValid(const FAstroGameMenuTabBarAuthoringData& tabBarData) {
    return false;
}

EAstroGameMenuTutorialSlideDeckKey UAstroGameMenuStatics::GetTutorialSlideDeckForCard(UObject* WorldContextObject, EAstroGameMenuTutoriaSlideCardKey TutorialSlideCardKey) {
    return EAstroGameMenuTutorialSlideDeckKey::Invalid;
}

bool UAstroGameMenuStatics::GetTutorialSlideDeck(UObject* WorldContextObject, EAstroGameMenuTutorialSlideDeckKey TutorialSlideDeckKey, FAstroGameMenuTutorialSlideDeck& OutTutorialSlideDeckData) {
    return false;
}

bool UAstroGameMenuStatics::GetTutorialSlideCard(UObject* WorldContextObject, EAstroGameMenuTutoriaSlideCardKey TutorialSlideCardKey, FAstroGameMenuTutorialSlide& OutTutorialSlideCardData) {
    return false;
}

FVector2D UAstroGameMenuStatics::GetOriginOfActiveSubPaneContentsRegion(UObject* WorldContextObject) {
    return FVector2D{};
}

UUserWidget* UAstroGameMenuStatics::GetMOTDWidget(UObject* WorldContextObject) {
    return NULL;
}

bool UAstroGameMenuStatics::GetKeybindingForDiscreteInputMapping(FAstroDiscreteInputDefinition DiscreteInputDefinition, FKey& OutKey, bool& OutIsAxis, bool ForGamepad) {
    return false;
}

UAstroGameMenuWidget* UAstroGameMenuStatics::GetGameMenuWidget(UObject* WorldContextObject) {
    return NULL;
}

FVector2D UAstroGameMenuStatics::GetCachedSizeOfGameMenu(UObject* WorldContextObject, bool IncludeScrollBarSize) {
    return FVector2D{};
}

UUserWidget* UAstroGameMenuStatics::GetAchievementProgressionWarningWidget(UObject* WorldContextObject) {
    return NULL;
}

void UAstroGameMenuStatics::GameMenuTryToSaveAndQuitGame(UObject* WorldContextObject, bool ReturnToTitleScreen, FFailedToSaveGameOnQuit OnFailedToSaveGame) {
}

void UAstroGameMenuStatics::GameMenuForceQuitGame(UObject* WorldContextObject, bool ReturnToTitleScreen, bool AttemptToSave) {
}

void UAstroGameMenuStatics::DismissTitleGameMenu(UObject* WorldContextObject) {
}

void UAstroGameMenuStatics::DismissGameMenu(UObject* WorldContextObject) {
}

void UAstroGameMenuStatics::DismissCurrentGameMenuPopoutWidget(UObject* WorldContextObject) {
}

void UAstroGameMenuStatics::ClearGameMenuSelection(UObject* WorldContextObject) {
}

void UAstroGameMenuStatics::ChangeSubPaneOnTopOfNavigationStack(UObject* WorldContextObject, TSubclassOf<UAstroGameMenuSubPaneWidget> NewSubPane) {
}

void UAstroGameMenuStatics::ChangeMenuContext(UObject* WorldContextObject, EAstroGameMenuContext NewMenuContext) {
}

bool UAstroGameMenuStatics::AreGameMenuTabBarAuthoringDataEqual(const FAstroGameMenuTabBarAuthoringData& tabBarDataA, const FAstroGameMenuTabBarAuthoringData& tabBarDataB) {
    return false;
}

bool UAstroGameMenuStatics::AreGameMenuControlsLocked(UObject* WorldContextObject) {
    return false;
}

void UAstroGameMenuStatics::AddMouseFocusSuppressionToCurrentSubPane(UObject* WorldContextObject, EMouseFocusChangeSuppressionSource MouseSuppression) {
}

UAstroGameMenuStatics::UAstroGameMenuStatics() {
}

