#include "AstroGameInstance.h"
#include "Templates/SubclassOf.h"

UAstroGameInstance::UAstroGameInstance() {
    this->AstroServerCommSingleton = NULL;
    this->SanitizeNonPersistentPlacements = false;
    this->SanitizeInactiveLTEPlacements = false;
    this->SanitizeCompletedMissionPlacements = false;
    this->LoadingMenuAfterKickedFromSession = false;
//    this->PlayFabTxnManager = NULL;
    this->ActiveLoadingScreen = NULL;
    this->ActiveWaitForInputScreen = NULL;
    this->ActiveConfirmChangeUsersPopup = NULL;
    this->ActiveReconnectControllerPopup = NULL;
//    this->DlcManager = NULL;
}

void UAstroGameInstance::SetSanitizeNonPersistentPlacements(bool Sanitize) {
}

void UAstroGameInstance::SetSanitizeInactiveLTEPlacements(bool Sanitize) {
}

void UAstroGameInstance::SetSanitizeCompletedMissionPlacements(bool Sanitize) {
}

void UAstroGameInstance::SetIsTransitioningToExpansionViaPortal(bool viaPortal) {
}

void UAstroGameInstance::SetActiveSaveFileDescriptiveName(const FString& newName) {
}

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

void UAstroGameInstance::NotifyOnTitleScreenCharacterCustomizationUnlockTooltipInvalidated() {
}

void UAstroGameInstance::NotifyOnTitleScreenCharacterCustomizationStarted() {
}

void UAstroGameInstance::NotifyOnTitleScreenCharacterCustomizationFinalizationStarted() {
}

void UAstroGameInstance::NotifyOnTitleScreenCharacterCustomizationFinalizationCanceled() {
}

void UAstroGameInstance::NotifyOnTitleScreenCharacterCustomizationCommitted() {
}

void UAstroGameInstance::NotifyOnTitleScreenCharacterCustomizationCanceled() {
}

void UAstroGameInstance::NotifyOnMultiplayerModeChanged() {
}

void UAstroGameInstance::NotifyOnEmotePreviewRequested(UAstroEmoteDefinition* emoteDefinition, bool IsLocked, FTooltipWidgetDisplayData lockedTooltipDisplayData) {
}

void UAstroGameInstance::NotifyOnCharacterCustomizationPreviewRequested(const FAstroCharacterCustomization& customizationToPreview, bool IsLocked, FTooltipWidgetDisplayData lockedTooltipDisplayData) {
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

bool UAstroGameInstance::HasMicroTxnStoreDataUpdated() {
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

//void UAstroGameInstance::HandleFriendJoinRequestSucceeded(const FFriendJoinRequestSucceededPayload& joinRequestSucceededPayload) {
//}

//void UAstroGameInstance::HandleFriendJoinRequestFailed(EAstroFriendJoinRequestFailure JoinFailureReason) {
//}

void UAstroGameInstance::HandleCultureChanged() {
}

//FAstroPlayFabTitleData UAstroGameInstance::GetTitleData() {
//    return FAstroPlayFabTitleData{};
//}

bool UAstroGameInstance::GetSanitizeNonPersistentPlacements() const {
    return false;
}

bool UAstroGameInstance::GetSanitizeInactiveLTEPlacements() const {
    return false;
}

bool UAstroGameInstance::GetSanitizeCompletedMissionPlacements() const {
    return false;
}

//UAstroPlayFabTxnManager* UAstroGameInstance::GetPlayFabTxnManager() {
//    return NULL;
//}

//FAstroPlayFabMicroTxnStoreData UAstroGameInstance::GetMicroTxnStoreData() {
//    return FAstroPlayFabMicroTxnStoreData{};
//}

bool UAstroGameInstance::GetIsTransitioningToExpansionViaPortal() {
    return false;
}

float UAstroGameInstance::GetEstimatedLoadPercentage(const UObject* WorldContextObject, const float dt, const bool lastCall) {
    return 0.0f;
}

//UAstroDlcManager* UAstroGameInstance::GetDlcManager() {
//    return NULL;
//}

FString UAstroGameInstance::GetActiveSaveFileDescriptiveName() const {
    return TEXT("");
}

void UAstroGameInstance::ForceRefreshMicroTxnStoreData() {
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


