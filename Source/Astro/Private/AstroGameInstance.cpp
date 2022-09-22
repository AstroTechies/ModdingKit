#include "AstroGameInstance.h"
#include "Templates/SubclassOf.h"

class UObject;
class UUserWidget;

void UAstroGameInstance::PlatformLogout() {
}

void UAstroGameInstance::PlatformLogin() {
}

void UAstroGameInstance::OnInvitePasswordEntryComplete(const FString& Password) {
}

void UAstroGameInstance::NotifyWaitForInputScreenComplete() {
}

void UAstroGameInstance::NotifyTutorialStartSelected() {
}

void UAstroGameInstance::NotifyStartingGameDropshipSpawned() {
}

void UAstroGameInstance::NotifyPlayerRespondedToWaitForInputScreen(int32 playerIndex) {
}

void UAstroGameInstance::NotifyPlayerExitedStartingDropship() {
}

void UAstroGameInstance::NotifyPlayerConfirmedChangeUsers() {
}

void UAstroGameInstance::NotifyPlayerCancelledChangeUsers() {
}

void UAstroGameInstance::NotifyOnMultiplayerModeChanged() {
}

void UAstroGameInstance::NotifyNewGameSetupComplete() {
}

void UAstroGameInstance::NotifyLoadScreenFadeoutComplete() {
}

void UAstroGameInstance::NotifyLoadScreenComplete(bool RemoveFromViewport) {
}

void UAstroGameInstance::NotifyIntroCinematicComplete() {
}

void UAstroGameInstance::NotifyActorBeginPlay() {
}

bool UAstroGameInstance::IsPlayTogetherSessionPending() const {
    return false;
}

bool UAstroGameInstance::IsLoadingScreenActive() {
    return false;
}

bool UAstroGameInstance::IsGameLicenseValid() {
    return false;
}

bool UAstroGameInstance::IsGameInTrialMode() {
    return false;
}

bool UAstroGameInstance::HasIntroCinematicCompleted() {
    return false;
}

bool UAstroGameInstance::HasGameSessionStarted() const {
    return false;
}

void UAstroGameInstance::HandleServerListCacheUpdated() {
}

void UAstroGameInstance::HandleFriendsListCacheUpdated() {
}

void UAstroGameInstance::HandleCultureChanged() {
}


float UAstroGameInstance::GetEstimatedLoadPercentage(const UObject* WorldContextObject, const float dt, const bool lastCall) {
    return 0.0f;
}

void UAstroGameInstance::DisplayLoadScreenWidget(TSubclassOf<UUserWidget> overrideWidget) {
}

void UAstroGameInstance::DisplayConfirmChangeUsersPopup() {
}

void UAstroGameInstance::DebugLicenseOverride(int32 Type) {
}

void UAstroGameInstance::DebugExpirationOverride() {
}

void UAstroGameInstance::CheckUserPrivilege(FCheckUserPrivilegeComplete OnComplete) {
}

bool UAstroGameInstance::AllowLoadingScreenDismiss() {
    return false;
}

UAstroGameInstance::UAstroGameInstance() {
    this->AstroServerCommSingleton = NULL;
    this->ActiveLoadingScreen = NULL;
    this->ActiveWaitForInputScreen = NULL;
    this->ActiveConfirmChangeUsersPopup = NULL;
    this->ActiveReconnectControllerPopup = NULL;
}

