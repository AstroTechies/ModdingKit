#include "AstroGameState.h"
#include "ActorEntityLinkComponent.h"
#include "ActuatorQueue.h"
#include "AstropediaAssetManager.h"
#include "Net/UnrealNetwork.h"
#include "RewardState.h"
#include "RewardSystem.h"
#include "Templates/SubclassOf.h"

class AActor;
class AAstroCharacter;
class AAstroMissionsManager;
class AAstroPlanet;
class APhysicalItem;
class ARailNetwork;
class UAstroSaveCustomArchiveProxy;
class UItemType;
class UParticleSystem;
class USoundBase;

void AAstroGameState::UnregisterSpawnedStartingItem(APhysicalItem* Item) {
}

void AAstroGameState::SetOxygenFreeCreative(bool OxygenFree) {
}

void AAstroGameState::SetNewGameDropshipSequenceActive(bool IsActive) {
}

void AAstroGameState::SetInvisibleToHazardsCreative(bool InvisibleToHazards) {
}

void AAstroGameState::SetInvincibleCreative(bool Invincible) {
}

void AAstroGameState::SetFuelFreeCreative(bool FreeFuelEnabled) {
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

void AAstroGameState::OnRep_RailNetwork(ARailNetwork* previousValue) {
}

void AAstroGameState::OnRep_MissionsManager(AAstroMissionsManager* previousValue) {
}

void AAstroGameState::OnRep_IsOutroCinematicActive() {
}

void AAstroGameState::OnRep_CreativeModeSettings() {
}

void AAstroGameState::OnAuthorityUnlockedItemsChanged(const TArray<TSubclassOf<UItemType>>& NewUnlockedItems) {
}

void AAstroGameState::OnAuthorityResearchPointBalanceChanged(float NewPointBalance) {
}

void AAstroGameState::OnAuthorityKnownItemsChanged(const TArray<TSubclassOf<UItemType>>& newKnownItems) {
}

bool AAstroGameState::NotifyTutorial(FName Name, bool bShowText) {
    return false;
}

void AAstroGameState::NotifyOutroCinematicCompleted() {
}

void AAstroGameState::MultiSoundFX_Implementation(const FTransform& Transform, USoundBase* Sound, UParticleSystem* Particle) {
}

void AAstroGameState::MulticastNewMaterialPalette_Implementation(AAstroPlanet* Planet, const TArray<FPackedVoxelMaterialInfo>& dynamicMaterials) {
}

void AAstroGameState::MulticastNewCreativeMaterialPalette_Implementation(AAstroPlanet* Planet, const TArray<FPackedVoxelMaterialInfo>& dynamicMaterials, const TArray<FCreativePaintMaterialMapping>& creativePaintData) {
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

bool AAstroGameState::IsCreativeModeActive() const {
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

bool AAstroGameState::GetThemeIsActive(const FName ThemeName) {
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

FScannableStatus AAstroGameState::GetNearestRelevantScannable(AAstroCharacter* Player) const {
    return FScannableStatus{};
}

AAstroMissionsManager* AAstroGameState::GetMissionsManager() const {
    return NULL;
}

bool AAstroGameState::GetIsNewGameDropshipSequenceActive() const {
    return false;
}

UAstropediaAssetManager* AAstroGameState::GetAstropediaAssetManager() const {
    return NULL;
}

UActuatorQueue* AAstroGameState::GetActuatorQueue() const {
    return NULL;
}

EAchievementProgressionState AAstroGameState::GetAchievementProgressionState() const {
    return EAchievementProgressionState::Unknown;
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

void AAstroGameState::AuthoritySetWandererRealityTearOpenState(EWandererRealityTearOpenState State) {
}

EWandererRealityTearOpenState AAstroGameState::AuthorityGetWandererRealityTearOpenState() const {
    return EWandererRealityTearOpenState::Closed;
}

bool AAstroGameState::ArePlayerNamesVisible() const {
    return false;
}

bool AAstroGameState::AreBeaconsVisible() const {
    return false;
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
    DOREPLIFETIME(AAstroGameState, ScannableStatuses);
    DOREPLIFETIME(AAstroGameState, ProbeUnlockStates);
    DOREPLIFETIME(AAstroGameState, DebugLocations);
    DOREPLIFETIME(AAstroGameState, bAchievementProgressionDisabled);
    DOREPLIFETIME(AAstroGameState, bIsIndividualDedicatedServerGame);
    DOREPLIFETIME(AAstroGameState, bCreativeModeActive);
    DOREPLIFETIME(AAstroGameState, bCreativeAllCatalogItemsUnlocked);
    DOREPLIFETIME(AAstroGameState, bCreativeFreeFuelOn);
    DOREPLIFETIME(AAstroGameState, RailNetwork);
    DOREPLIFETIME(AAstroGameState, MissionsManager);
}

AAstroGameState::AAstroGameState() {
    this->GameSpeed = 1.00f;
    this->SolarTimeScaleMultiplierCreative = 1.00f;
    this->DeformToolActivation = NULL;
    this->TutorialInteractionMode = false;
    this->TutorialSlowMovement = false;
    this->MapLoadedFromSave = false;
    this->SaveGamePermitted = false;
    this->WindValue = 0.00f;
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
    this->RewardSystem = CreateDefaultSubobject<URewardSystem>(TEXT("PrimaryRewardSystem"));
    this->RewardState = CreateDefaultSubobject<URewardState>(TEXT("GameRewardState"));
    this->MissionsManager = NULL;
}

