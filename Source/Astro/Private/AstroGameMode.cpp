#include "AstroGameMode.h"
#include "AstroGameState.h"
#include "AstroPlayerState.h"

AAstroGameMode::AAstroGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GameStateClass = AAstroGameState::StaticClass();
    this->PlayerStateClass = AAstroPlayerState::StaticClass();
    this->bUseSeamlessTravel = true;
    this->CustomGameModifiersDefaultValueDatabase = NULL;
    this->CustomGameSettingsTags = NULL;
    this->IsFirstLaunch = true;
    this->IsInExpansionEnvironment = false;
    this->InitialKnownItemTypeList = NULL;
    this->CreativeModeForceKnownItemTypeList = NULL;
    this->InitialItemTypeUnlockList = NULL;
    this->InitialHackedItemTypeList = NULL;
    this->InitialResearchPointBalance = 0;
    this->bPlayerStartsWithTerrainTool = true;
    this->bAllowsMultiplayer = true;
    this->bIsTutorialMode = false;
    this->bDeferStartListenServer = false;
    this->NewGamesUseIntroCinematic = false;
    this->PlayIntroOnce = false;
    this->NewGamesUseTitleMenu = false;
    this->EnableSavedGamesAutomatically = true;
    this->DefaultSpawnPoint = NULL;
    this->IntroSequencePlayer = NULL;
}

void AAstroGameMode::UnregisterSpawnPointActorAttachmentsComponent(UStorageChassisComponent* spawnPoint) {
}

void AAstroGameMode::SwitchLifecycleState(EGameLifecycleState NewState, const FString& Reason) {
}

void AAstroGameMode::SpawnPlayerFromHistory(int64 NetworkUuid) {
}

void AAstroGameMode::SetPlayerHasSeenIntro(bool playerHasSeenIntro) {
}

void AAstroGameMode::SetMultiplayerEnabled(bool bIsEnabled) {
}

void AAstroGameMode::SetIsInExpansion(bool inExpansion) {
}

void AAstroGameMode::ServerSaveGameName(const FString& Name) {
}

void AAstroGameMode::ServerSaveGameAndQuit() {
}

void AAstroGameMode::ServerSaveGame() {
}

void AAstroGameMode::ServerNewGame() {
}

bool AAstroGameMode::ServerLoadGameName(const FString& Name) {
    return false;
}

void AAstroGameMode::RespawnPlayer(APlayController* Player, FVector locationOnDeath) {
}

void AAstroGameMode::RegisterSpawnPointActorAttachmentsComponent(UStorageChassisComponent* spawnPoint) {
}

bool AAstroGameMode::PlanetHasStartingPointCandidate(EPlanetIdentifier planetID) {
    return false;
}

void AAstroGameMode::OnOutroCinematicComplete() {
}

void AAstroGameMode::OnNewGameInitiated() {
}

void AAstroGameMode::OnIntroCinematicFinished() {
}

void AAstroGameMode::OnIntroCinematicComplete() {
}

void AAstroGameMode::OnFullLicenseDetected() {
}

void AAstroGameMode::MovePlayersToSpawnPositions() {
}

void AAstroGameMode::LoadMap(UObject* WorldContextObject, TSoftObjectPtr<UWorld> Map) {
}

bool AAstroGameMode::IsPackagedBuild() {
    return false;
}

bool AAstroGameMode::IsMultiplayerEnabled() const {
    return false;
}

void AAstroGameMode::InitializeForSolarSystem(USolarSystem* SolarSystem) {
}

void AAstroGameMode::HandleIntroCinematicSkip() {
}

void AAstroGameMode::HandleControllingLocalPlayerLoggedOut() {
}

UStorageChassisComponent* AAstroGameMode::GetDefaultSpawnPoint() const {
    return NULL;
}

EGameLifecycleState AAstroGameMode::GetCurrentLifecycleState() {
    return EGameLifecycleState::Initializing;
}

void AAstroGameMode::ClearCinematicTerrainPoints() {
}

void AAstroGameMode::AuthoritySetDefaultSpawnLocation(FVector SpawnLocation) {
}

bool AAstroGameMode::AuthoritySelectStartingPointFromCandiates(FVector& outStartingLocation, FRotator& outStartingRotation) {
    return false;
}

void AAstroGameMode::AuthorityAddStartingPointCandiateActor(const AActor* candidateActor) {
}

void AAstroGameMode::AddTerrainResolutionPoint(float X, float Y, float Z, float Radius) {
}


