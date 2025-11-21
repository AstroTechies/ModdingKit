#include "AstroGameState.h"
#include "ActorEntityLinkComponent.h"
#include "ActuatorQueue.h"
#include "AstropediaAssetManager.h"
#include "MegastructureManager.h"
#include "Net/UnrealNetwork.h"
#include "RewardState.h"
#include "RewardSystem.h"
#include "Templates/SubclassOf.h"

AAstroGameState::AAstroGameState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
//    this->bSaveGameRelevant = true;
    this->GameSpeed = 1.00f;
    this->SolarTimeScaleMultiplierCreative = 1.00f;
    this->DeformToolActivation = NULL;
    this->TutorialInteractionMode = false;
    this->TutorialSlowMovement = false;
    this->ActiveThemes.AddDefaulted(1);
    this->MapLoadedFromSave = false;
    this->SaveGamePermitted = false;
    this->WindValue = 0.00f;
    this->NonPersistantActorClasses = NULL;
    this->bIsMultiplayerEnabled = false;
    this->bIsOutroCinematicActive = false;
    this->EntityLinkComponent = CreateDefaultSubobject<UActorEntityLinkComponent>(TEXT("EntityLink"));
    this->CurrentResearchPointBalance = 0.00f;
    this->CurrentResearchPointsPerMinute = 0.00f;
    this->OutroCinematicPlayer = NULL;
    this->OutroSequenceActor = NULL;
    this->bAchievementProgressionDisabled = false;
    this->bIsIndividualDedicatedServerGame = false;
    this->bCreativeModeActive = false;
    this->bCreativeAllCatalogItemsUnlocked = false;
    this->bCreativeFreeOxygenOn = true;
    this->bCreativeFreeFuelOn = true;
    this->bCreativeInvisibleToHazardsOn = false;
    this->bCreativeInvincibleOn = true;
    this->bCreativeUnlimitedBackpackPowerOn = true;
    this->MatCollectionGameSpeed = -1.00f;
    this->AstropediaAssetManager = CreateDefaultSubobject<UAstropediaAssetManager>(TEXT("AstropediaAssetManager"));
    this->ActuatorQueue = CreateDefaultSubobject<UActuatorQueue>(TEXT("ActuatorQueue"));
    this->RailNetwork = NULL;
    this->SplineNetwork = NULL;
    this->RewardSystem = CreateDefaultSubobject<URewardSystem>(TEXT("PrimaryRewardSystem"));
    this->RewardState = CreateDefaultSubobject<URewardState>(TEXT("GameRewardState"));
    this->MegastructureManager = CreateDefaultSubobject<UMegastructureManager>(TEXT("MegastructureManager"));
    this->MissionsManager = NULL;
    this->CustomGameManager = NULL;
    this->PreventCompletedMissionPlacements = false;
    this->InstalledRootKitCount = 0;
    this->StormsEnabled = false;
    this->StormsMissionBlocked = true;
    this->EnabledDonationRewards = 0;
    this->EnabledCollectionRewards = 0;
    this->IsInExpansionEnvironment = false;
    this->ActiveDLCEntitlements = 0;
}

void AAstroGameState::UpdateStormStates(float dt) {
}

void AAstroGameState::UpdateMaxStormCount(AAstroPlanet* Planet, int32 newMaxStormCount) {
}

void AAstroGameState::UnregisterSpawnedStartingItem(APhysicalItem* Item) {
}

bool AAstroGameState::TrySubmitHackedGatewayComplete(EPlanetIdentifier planetID) {
    return false;
}

bool AAstroGameState::TrySubmitCounterhackKeySubmittedToGateway(EPlanetIdentifier planetID, int32 StormID) {
    return false;
}

void AAstroGameState::SyncSettingsFromServer(bool IsCustomGame, const FAstroCustomGameSettings& CustomGameSettings, const FAstroCustomGameState& customGameStateToSync) {
}

void AAstroGameState::SetStormsMissionBlocked(bool NewState) {
}

void AAstroGameState::SetStormsEnabled(bool NewState) {
}

void AAstroGameState::SetPreventCompletedMissionPlacements() {
}

void AAstroGameState::SetOxygenFreeCreative(bool OxygenFree) {
}

void AAstroGameState::SetNewGameDropshipSequenceActive(bool IsActive) {
}

void AAstroGameState::SetIsInExpansion(bool inExpansion) {
}

void AAstroGameState::SetInvisibleToHazardsCreative(bool InvisibleToHazards) {
}

void AAstroGameState::SetInvincibleCreative(bool Invincible) {
}

void AAstroGameState::SetFuelFreeCreative(bool FreeFuelEnabled) {
}

void AAstroGameState::SetEntitledMegatechContentActivated() {
}

void AAstroGameState::SetCurrentObjective(FName Name) {
}

void AAstroGameState::SetCreativeModeActive(bool CreativeMode) {
}

void AAstroGameState::SetCatalogUnlockedCreative(bool CatalogUnlocked) {
}

void AAstroGameState::SetBackpackPowerUnlimitedCreative(bool BackpackPowerUnlimited) {
}

void AAstroGameState::SetAchievementProgressionDisabledCreative(bool AchievementProgressionDisabled) {
}

void AAstroGameState::ServerNotifyPlayerMadeLandfall_Implementation(AAstroPlayerController* PlayerController) {
}

void AAstroGameState::ServerNotifyPlayerLeftSession_Implementation(AAstroPlayerController* PlayerController) {
}

void AAstroGameState::ServerNotifyPlayerJoinedSession_Implementation(AAstroPlayerController* PlayerController) {
}

void AAstroGameState::SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy) {
}

void AAstroGameState::RemoveNewPlayerSpawnLocation(AActor* Spawn) {
}

void AAstroGameState::RemoveActivePlacementThemes(const TArray<FName>& themeNames) {
}

void AAstroGameState::RemoveActivePlacementTheme(const FName ThemeName) {
}

void AAstroGameState::RegisterSpawnedStartingItem(APhysicalItem* Item) {
}

void AAstroGameState::RegisterPlanetForStorms(AAstroPlanet* Planet, bool overrideExistingPlanetStormStates) {
}

bool AAstroGameState::PlanetHasStormState(EPlanetIdentifier planetID) {
    return false;
}

void AAstroGameState::OnRep_SplineNetwork(ASplineNetwork* previousValue) const {
}

void AAstroGameState::OnRep_RailNetwork(ARailNetwork* previousValue) {
}

void AAstroGameState::OnRep_PlanetVirusProtectionStates() {
}

void AAstroGameState::OnRep_MissionsManager(AAstroMissionsManager* previousValue) {
}

void AAstroGameState::OnRep_IsOutroCinematicActive() {
}

void AAstroGameState::OnRep_DonationRewardsUpdated() {
}

void AAstroGameState::OnRep_CustomGameManager(AAstroCustomGameManager* previousValue) {
}

void AAstroGameState::OnRep_CreativeModeSettings() {
}

void AAstroGameState::OnRep_CollectionRewardsUpdated() {
}

void AAstroGameState::OnAuthorityUnlockedItemsChanged(const TArray<TSubclassOf<UItemType>>& NewUnlockedItems) {
}

void AAstroGameState::OnAuthorityResearchPointBalanceChanged(float NewPointBalance) {
}

void AAstroGameState::OnAuthorityKnownItemsChanged(const TArray<TSubclassOf<UItemType>>& newKnownItems) {
}

void AAstroGameState::OnAuthorityHackedItemsChanged(const TArray<TSubclassOf<UItemType>>& newHackedItems) {
}

bool AAstroGameState::NotifyTutorial(FName Name, bool bShowText) {
    return false;
}

void AAstroGameState::NotifyOutroCinematicCompleted() {
}

void AAstroGameState::MultiSoundFX_Implementation(const FTransform& Transform, USoundBase* Sound, UParticleSystem* Particle) {
}

void AAstroGameState::MulticastSyncSettingsFromServer_Implementation(bool IsCustomGame, const FAstroCustomGameSettings& CustomGameSettings, const FAstroCustomGameState& customGameStateToSync) {
}

void AAstroGameState::MulticastSyncOneTimeTooltipStateFromServer_Implementation(const FAstroOneTimeTooltipState& oneTimeTooltipStateToSync) {
}

void AAstroGameState::MulticastSyncInitialCustomGameStateFromServer_Implementation(const FAstroCustomGameState& customGameStateToSync) {
}

void AAstroGameState::MulticastSyncCustomGameStateFromServer_Implementation(const FAstroCustomGameState& customGameStateToSync) {
}

void AAstroGameState::MulticastNewMaterialPalette_Implementation(ASolarBody* SolarBody, const TArray<FPackedVoxelMaterialInfo>& dynamicMaterials, const FVector& InLocation) {
}

void AAstroGameState::MulticastNewCreativeMaterialPalette_Implementation(ASolarBody* SolarBody, const TArray<FPackedVoxelMaterialInfo>& dynamicMaterials, const TArray<FCreativePaintMaterialMapping>& creativePaintData, const FVector& InLocation) {
}

void AAstroGameState::MulticastExplosionEffects_Implementation(const FTransform& Transform, AActor* Actor, const FName surfTypeSwitchName, const TArray<FString>& AudioEffects, const TArray<UParticleSystem*>& ParticleEffects, float Power) {
}

void AAstroGameState::MulticastDisplayResearchPointChange_Implementation(int32 researchPointDelta) {
}

void AAstroGameState::MulticastDisplayGrantDurableMessage_Implementation(TSubclassOf<UItemType> itemToUnlock) {
}

void AAstroGameState::MulticastAudioEventAndVFXWithTint_Implementation(const FTransform& Transform, const FString& AudioEvent, UParticleSystem* ParticleEffect, FLinearColor Color) {
}

void AAstroGameState::MulticastAudioEventAndVFX_Implementation(const FTransform& Transform, const FString& AudioEvent, UParticleSystem* ParticleEffect) {
}

bool AAstroGameState::IsRootKitInstalled(EPlanetIdentifier planetID, int32 StormID) {
    return false;
}

bool AAstroGameState::IsProbeUnlocked(AAstroCharacter* Character, FName ProbeName) const {
    return false;
}

bool AAstroGameState::IsOxygenFreeCreative() const {
    return false;
}

bool AAstroGameState::IsInvisibleToHazardsCreative() const {
    return false;
}

bool AAstroGameState::IsInvincibleCreative() const {
    return false;
}

bool AAstroGameState::IsGravitySimulationEnabled() const {
    return false;
}

bool AAstroGameState::IsFuelFreeCreative() const {
    return false;
}

bool AAstroGameState::IsDonationRewardActive(const EDonationReward inDonationReward) const {
    return false;
}

bool AAstroGameState::IsCreativeModeActive() const {
    return false;
}

bool AAstroGameState::IsCollectionRewardActive(const ECollectionReward inCollectionReward) const {
    return false;
}

bool AAstroGameState::IsCatalogUnlockedCreative() const {
    return false;
}

bool AAstroGameState::IsBackpackPowerUnlimitedCreative() const {
    return false;
}

bool AAstroGameState::IsAchievementProgressionDisabled() const {
    return false;
}

bool AAstroGameState::HasSaveGameCacheBeenEnumerated() const {
    return false;
}

bool AAstroGameState::HasEverBeenIndividualDedicatedServerGame() const {
    return false;
}

bool AAstroGameState::HasEverBeenCreativeGame() const {
    return false;
}

void AAstroGameState::HandleOnGameplayStartedEvent(bool StartedInExistingSavedGame) {
}

void AAstroGameState::GlitchWalkersFinalEncounterStart() {
}

void AAstroGameState::GlitchWalkersFinalEncounterReset() {
}

void AAstroGameState::GlitchWalkersFinalEncounterCompleted() {
}

bool AAstroGameState::GetThemeIsActive(const FName ThemeName) {
    return false;
}

FStormState AAstroGameState::GetStormState(AAstroStorm* storm) {
    return FStormState{};
}

bool AAstroGameState::GetStormsMissionBlocked() {
    return false;
}

bool AAstroGameState::GetStormsEnabled() {
    return false;
}

TArray<APhysicalItem*> AAstroGameState::GetStartingItemArrayRef() {
    return TArray<APhysicalItem*>();
}

URewardSystem* AAstroGameState::GetRewardSystem() const {
    return NULL;
}

URewardState* AAstroGameState::GetRewardState() const {
    return NULL;
}

bool AAstroGameState::GetPreventCompletedMissionPlacements() const {
    return false;
}

FPlanetVirusProtectionKitState AAstroGameState::GetPlanetVirusProtectionKitState(EPlanetIdentifier planetID) {
    return FPlanetVirusProtectionKitState{};
}

FStormStates AAstroGameState::GetPlanetStormStatesById(EPlanetIdentifier planetID) {
    return FStormStates{};
}

FStormStates AAstroGameState::GetPlanetStormStates(AAstroPlanet* Planet) {
    return FStormStates{};
}

FPlanetFirewallStates AAstroGameState::GetPlanetFirewallStates(EPlanetIdentifier planetID) {
    return FPlanetFirewallStates{};
}

TArray<FStormState> AAstroGameState::GetPlanetActiveStormStates(EPlanetIdentifier planetID) {
    return TArray<FStormState>();
}

TArray<int32> AAstroGameState::GetPlanetActiveStormIDs(EPlanetIdentifier planetID) {
    return TArray<int32>();
}

UActorClassList* AAstroGameState::GetNonPersistantActorClassList() {
    return NULL;
}

FScannableStatus AAstroGameState::GetNearestRelevantScannable(AAstroCharacter* Player) const {
    return FScannableStatus{};
}

AAstroMissionsManager* AAstroGameState::GetMissionsManager() const {
    return NULL;
}

TMap<FString, UActorClassList*> AAstroGameState::GetMissionPlacementClassLists() {
    return TMap<FString, UActorClassList*>();
}

UActorClassList* AAstroGameState::GetMissionPlacementClasses(const FString& missionId) {
    return NULL;
}

UMegastructureManager* AAstroGameState::GetMegastructureManager() const {
    return NULL;
}

bool AAstroGameState::GetIsNewGameDropshipSequenceActive() const {
    return false;
}

int32 AAstroGameState::GetInstalledRootKitCount() const {
    return 0;
}

TArray<UActorClassList*> AAstroGameState::GetInactiveLTEActorClassLists() {
    return TArray<UActorClassList*>();
}

TArray<TSubclassOf<UItemType>> AAstroGameState::GetHackedItemTypes() const {
    return TArray<TSubclassOf<UItemType>>();
}

AAstroCustomGameManager* AAstroGameState::GetCustomGameManager() const {
    return NULL;
}

TSubclassOf<UItemType> AAstroGameState::GetCounterhackKeyItemTypeClass(EPlanetIdentifier planetID, int32 StormID) {
    return NULL;
}

TSubclassOf<APhysicalItem> AAstroGameState::GetCounterhackKeyActorClass(EPlanetIdentifier planetID, int32 StormID) {
    return NULL;
}

FStormState AAstroGameState::GetClosestActiveStormToLocation(EPlanetIdentifier planetID, FVector Location) {
    return FStormState{};
}

bool AAstroGameState::GetCanGenerateCounterhackKey(EPlanetIdentifier planetID, int32 StormID) {
    return false;
}

UAstropediaAssetManager* AAstroGameState::GetAstropediaAssetManager() const {
    return NULL;
}

TArray<FStormState> AAstroGameState::GetAllActiveStormStates() {
    return TArray<FStormState>();
}

TArray<int32> AAstroGameState::GetAllActiveStormIDs() {
    return TArray<int32>();
}

UActuatorQueue* AAstroGameState::GetActuatorQueue() const {
    return NULL;
}

EAchievementProgressionState AAstroGameState::GetAchievementProgressionState() const {
    return EAchievementProgressionState::Unknown;
}

void AAstroGameState::EnableEXOVaultByName(FName Name) {
}

void AAstroGameState::DoDeformation(FDeformationParamsT2 params, bool shouldThrottle) {
}

void AAstroGameState::DisplayDiscoverItemTypeMessage_Implementation(TSubclassOf<UItemType> itemTypeDiscovered) {
}

void AAstroGameState::DestroyAllSpawnedStartingItems() {
}

void AAstroGameState::BroadcastUnlockedVintageProbesChanged() {
}

void AAstroGameState::BroadcastUnlockedItemsChanged() {
}

void AAstroGameState::BroadcastResearchPointBalanceChanged() {
}

void AAstroGameState::BroadcastOnCreativeModeCatalogUnlockedChanged() {
}

void AAstroGameState::BroadcastKnownItemsChanged() {
}

void AAstroGameState::BroadcastHackedItemsChanged() {
}

bool AAstroGameState::AuthorityTrySubmitStormData(EPlanetIdentifier planetID, int32 StormID) {
    return false;
}

bool AAstroGameState::AuthorityTrySubmitRootKit(EPlanetIdentifier planetID, int32 StormID) {
    return false;
}

void AAstroGameState::AuthoritySpawnFirewalls(AAstroPlanet* Planet) {
}

void AAstroGameState::AuthoritySetWandererRealityTearOpenState(EWandererRealityTearOpenState State) {
}

bool AAstroGameState::AuthorityRemoveStormSpawnLocationCandidate(AAstroStormSpawnLocationCandidate* candidate) {
    return false;
}

void AAstroGameState::AuthorityRegisterFirewall(EPlanetIdentifier planetID, AActor* FirewallActor) {
}

EWandererRealityTearOpenState AAstroGameState::AuthorityGetWandererRealityTearOpenState() const {
    return EWandererRealityTearOpenState::Closed;
}

bool AAstroGameState::AuthorityAddStormSpawnLocationCandidate(AAstroStormSpawnLocationCandidate* candidate) {
    return false;
}

bool AAstroGameState::ArePlayerNamesVisible() const {
    return false;
}

bool AAstroGameState::AreBeaconsVisible() const {
    return false;
}

bool AAstroGameState::AreAnyShuttlesLost() const {
    return false;
}

void AAstroGameState::AddLostShuttle(AShuttle* InShuttle) {
}

void AAstroGameState::AddAndPrioritizeNewPlayerSpawnLocation(AActor* Spawn) {
}

void AAstroGameState::AddActivePlacementThemes(const TArray<FName>& themeNames) {
}

void AAstroGameState::AddActivePlacementTheme(const FName ThemeName) {
}

void AAstroGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAstroGameState, GameSpeed);
    DOREPLIFETIME(AAstroGameState, SolarTimeScaleMultiplierCreative);
    DOREPLIFETIME(AAstroGameState, TutorialInteractionMode);
    DOREPLIFETIME(AAstroGameState, bIsOutroCinematicActive);
    DOREPLIFETIME(AAstroGameState, CurrentResearchPointBalance);
    DOREPLIFETIME(AAstroGameState, CurrentResearchPointsPerMinute);
    DOREPLIFETIME(AAstroGameState, KnownItemTypes);
    DOREPLIFETIME(AAstroGameState, UnlockedItemTypes);
    DOREPLIFETIME(AAstroGameState, HackedItemTypes);
    DOREPLIFETIME(AAstroGameState, ScannableStatuses);
    DOREPLIFETIME(AAstroGameState, ProbeUnlockStates);
    DOREPLIFETIME(AAstroGameState, DebugLocations);
    DOREPLIFETIME(AAstroGameState, bAchievementProgressionDisabled);
    DOREPLIFETIME(AAstroGameState, bIsIndividualDedicatedServerGame);
    DOREPLIFETIME(AAstroGameState, bCreativeModeActive);
    DOREPLIFETIME(AAstroGameState, bCreativeAllCatalogItemsUnlocked);
    DOREPLIFETIME(AAstroGameState, bCreativeFreeFuelOn);
    DOREPLIFETIME(AAstroGameState, RailNetwork);
    DOREPLIFETIME(AAstroGameState, SplineNetwork);
    DOREPLIFETIME(AAstroGameState, MissionsManager);
    DOREPLIFETIME(AAstroGameState, PerPlanetStormStates);
    DOREPLIFETIME(AAstroGameState, PlanetVirusProtectionStates);
    DOREPLIFETIME(AAstroGameState, InstalledRootKitCount);
    DOREPLIFETIME(AAstroGameState, PlanetFirewallStates);
    DOREPLIFETIME(AAstroGameState, StormsEnabled);
    DOREPLIFETIME(AAstroGameState, StormsMissionBlocked);
    DOREPLIFETIME(AAstroGameState, EnabledDonationRewards);
    DOREPLIFETIME(AAstroGameState, EnabledCollectionRewards);
    DOREPLIFETIME(AAstroGameState, IsInExpansionEnvironment);
}


