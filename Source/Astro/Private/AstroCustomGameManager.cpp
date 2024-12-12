#include "AstroCustomGameManager.h"
#include "Templates/SubclassOf.h"

AAstroCustomGameManager::AAstroCustomGameManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
//    this->bSaveGameRelevant = true;
    this->IsCreatingNewConfig = false;
    this->SettingsModifiedFromOriginal = false;
    this->IsImportingConfig = false;
    this->CustomGameConfigCachesInitialized = false;
    this->ActiveSettingsAreAppliedToWorld = false;
    this->IsFirstTimeSettingsAreApplied = true;
    this->IsCustomGame = false;
    this->SettingsAreStaged = false;
    this->MetaDataToLoadIsForDSNewGame = false;
}

void AAstroCustomGameManager::UpdatePromotedConfigCacheFromPlayFab() {
}

bool AAstroCustomGameManager::UpdatePlayerRespawnTokenCount(const FString& PlayerId) {
    return false;
}

void AAstroCustomGameManager::UpdateCloudSavedConfigsMetaDataFromPlayFab() {
}

//void AAstroCustomGameManager::UpdateCloudSavedConfigCacheFromPlayFab(TArray<FAstroCGMLibraryConfigEntryMetaData> MetaDataList) {
//}

void AAstroCustomGameManager::UpdateCloudImportedConfigsMetaDataFromPlayFab() {
}

//void AAstroCustomGameManager::UpdateCloudImportedConfigCacheFromPlayFab(TArray<FAstroCGMLibraryConfigEntryMetaData> MetaDataList) {
//}

bool AAstroCustomGameManager::UpdateCGMModifierScalar(FGameplayTagContainer tagsToUpdate, int32 currentIndex) {
    return false;
}

void AAstroCustomGameManager::TruncateModifiersForSwitch(FAstroCustomGameSettings& NewCustomGameSettings) {
}

void AAstroCustomGameManager::SortCacheByMetaData(FAstroCustomGameConfigurationCache& cache) {
}

void AAstroCustomGameManager::SetStartingUtilitySlotItem(EAstroStartingSlotItem Item, int32 SlotIndex) {
}

void AAstroCustomGameManager::SetStartingToolSlotItem(EAstroStartingSlotItem Item, int32 SlotIndex) {
}

void AAstroCustomGameManager::SetStartingPlanet(EPlanetIdentifier StartingPlanetId) {
}

void AAstroCustomGameManager::SetStartingItemSlotData(const TArray<FStartingItemSlotData>& slotData) {
}

void AAstroCustomGameManager::SetStartingBiome(const FString& StartingBiome) {
}

void AAstroCustomGameManager::SetStartingBackpackSlotItem(EAstroStartingSlotItem Item, int32 SlotIndex) {
}

void AAstroCustomGameManager::SetSkipDropPodLaunchSequence(bool skipLaunchSequence) {
}

void AAstroCustomGameManager::SetRespawnTokenSettings(bool RespawnTokensActive, bool respawnTokensShared, int32 InitialRespawnTokenCount) {
}

void AAstroCustomGameManager::SetResearchSettings(const FAstroCustomResearchSettings& newSettings) {
}

void AAstroCustomGameManager::SetPowerSettings(const FAstroCustomPowerSettings& newSettings) {
}

void AAstroCustomGameManager::SetPlayerRespawnTokenCount(const FString& PlayerId, int32 newRespawnTokenCount) {
}

void AAstroCustomGameManager::SetOxygenSettings(const FAstroCustomOxygenSettings& newSettings) {
}

void AAstroCustomGameManager::SetNoStartingShelter(bool NoStartingShelter) {
}

void AAstroCustomGameManager::SetMultiToolSettings(const FAstroCustomMultiToolSettings& newSettings) {
}

void AAstroCustomGameManager::SetIsCustomGame(bool customGameState) {
}

void AAstroCustomGameManager::SetCustomGameName(const FString& newCustomGameName) {
}

//FAstroCGMLibraryConfigEntryMetaData AAstroCustomGameManager::SaveConfigLocallyFromGameState() {
//    return FAstroCGMLibraryConfigEntryMetaData{};
//}

void AAstroCustomGameManager::RestoreLocalSavedConfigCacheFromLegacyStorage(const TArray<FAstroCustomGameSettings> cache) {
}

void AAstroCustomGameManager::RemoveResearchCatalogDisabledItems(TArray<TSubclassOf<UItemType>> itemTypes) {
}

void AAstroCustomGameManager::RemoveResearchCatalogDisabledItem(TSubclassOf<UItemType> ItemType) {
}

bool AAstroCustomGameManager::RemoveLocalSavedCGMConfig(const FString& ShareCode) {
    return false;
}

//bool AAstroCustomGameManager::RemoveFromCacheIfExists(FAstroCustomGameConfigurationCacheType cacheType, FAstroCGMLibraryConfigEntryType cacheId, const int32 Index) {
//    return false;
//}

bool AAstroCustomGameManager::RemoveCloudSavedCGMConfig(const FString& ShareCode) {
    return false;
}

bool AAstroCustomGameManager::RemoveCloudImportedCGMConfig(const FString& ShareCode) {
    return false;
}

bool AAstroCustomGameManager::RemoveCGMModifierScalar(FGameplayTagContainer tagsToRemove) {
    return false;
}

void AAstroCustomGameManager::PushStagedSettingsToActive() {
}

//void AAstroCustomGameManager::ParseCustomGameSettingsFromJson(const FString& configJsonString, const FAstroCGMLibraryConfigEntryMetaData& MetaData, FAstroCustomGameSettings& customGame) {
//}

//void AAstroCustomGameManager::OnGetUGCItemSuccessGetConfigDataFromAzure(const FAstroCGMLibraryConfigEntryMetaData& MetaData, const FString& URL) {
//}

//void AAstroCustomGameManager::OnGetConfigDataFromAzureSuccess(const FAstroCGMLibraryConfigEntryMetaData& MetaData, const FString& configJson) {
//}

void AAstroCustomGameManager::LogCustomGameSettings(bool logStaged) {
}

//void AAstroCustomGameManager::LoadLocalConfigurationCacheFromDisk(const FAstroCGMLibraryConfigEntryType cacheId) {
//}

//bool AAstroCustomGameManager::LoadCGMConfigFromCache(const FAstroCGMLibraryConfigEntryMetaData& MetaData, bool staged) {
//    return false;
//}

void AAstroCustomGameManager::InitializeSettingsAndState(bool NewIsCustomGame, const FAstroCustomGameSettings& NewCustomGameSettings, const FAstroCustomGameState& customGameState) {
}

void AAstroCustomGameManager::InitializeRespawnTokenPools(const FString& PlayerId) {
}

void AAstroCustomGameManager::InitializeAllConfigurationCachesIfNotInitialized() {
}

void AAstroCustomGameManager::ImportCGMConfigFromPlayfab(const FString& ShareCode) {
}

void AAstroCustomGameManager::HandleMissionActivated(FName missionId) {
}

EAstroStartingSlotItem AAstroCustomGameManager::GetStartingUtilitySlotItem(int32 SlotIndex) {
    return EAstroStartingSlotItem::None;
}

EAstroStartingSlotItem AAstroCustomGameManager::GetStartingToolSlotItem(int32 SlotIndex) {
    return EAstroStartingSlotItem::None;
}

EAstroStartingSlotItem AAstroCustomGameManager::GetStartingBackpackSlotItem(int32 SlotIndex) {
    return EAstroStartingSlotItem::None;
}

int32 AAstroCustomGameManager::GetRespawnTokenCount(const FString& PlayerId) {
    return 0;
}

FString AAstroCustomGameManager::GetNextAvailableLocalSaveShareCode() {
    return TEXT("");
}

//int32 AAstroCustomGameManager::GetMetaDataCacheIndexFromCacheType(const FAstroCGMLibraryConfigEntryMetaData& MetaData, const FAstroCustomGameConfigurationCacheType cacheType) {
//    return 0;
//}

//int32 AAstroCustomGameManager::GetMetaDataCacheIndex(const FAstroCGMLibraryConfigEntryMetaData& MetaData, const FAstroCustomGameConfigurationCache& cache) {
//    return 0;
//}

FGameplayTagContainer AAstroCustomGameManager::GetGameplayTagsFromString(const FString& tagsString) {
    return FGameplayTagContainer{};
}

FAstroCustomGameSettings AAstroCustomGameManager::GetCurrentInteractiveCustomGameSettings() {
    return FAstroCustomGameSettings{};
}

float AAstroCustomGameManager::GetCounter(const FString& PlayerId) {
    return 0.0f;
}

//int32 AAstroCustomGameManager::GetConfigIndexInCache(FAstroCustomGameConfigurationCacheType cacheType, FAstroCGMLibraryConfigEntryType cacheId, const FString& ShareCode) {
//    return 0;
//}

//FAstroCustomGameConfigurationCache AAstroCustomGameManager::GetConfigCache(const FAstroCustomGameConfigurationCacheType cacheType, const FAstroCGMLibraryConfigEntryType cacheId) {
//    return FAstroCustomGameConfigurationCache{};
//}

void AAstroCustomGameManager::ExtractLegacyConfigDataAndUpdate(FAstroCustomGameSettings& NewCustomGameSettings, const FString& configJsonString) {
}

void AAstroCustomGameManager::EnforceCustomGameSettingsRangeRestrictions(FAstroCustomGameSettings& NewCustomGameSettings) {
}

void AAstroCustomGameManager::EndPlay(const TEnumAsByte<EEndPlayReason::Type> EndPlayReason) {
}

//void AAstroCustomGameManager::CombineCloudAndDiskCaches(const FAstroCGMLibraryConfigEntryType cacheId) {
//}

void AAstroCustomGameManager::ClearCustomGameSettingsState() {
}

void AAstroCustomGameManager::BroadcastIsCustomGameChanged() {
}

void AAstroCustomGameManager::BroadcastCustomGameSettingsChanged() {
}

void AAstroCustomGameManager::BroadcastCustomGameSettingModified() {
}

void AAstroCustomGameManager::BeginPlay() {
}

void AAstroCustomGameManager::ApplyCustomGameSettingsToWorld() {
}

void AAstroCustomGameManager::AddResearchCatalogDisabledItems(TArray<TSubclassOf<UItemType>> itemTypes) {
}

void AAstroCustomGameManager::AddResearchCatalogDisabledItem(TSubclassOf<UItemType> ItemType) {
}

void AAstroCustomGameManager::AddPlayerRespawnTokenPoolIfNotExists(const FString& PlayerId) {
}

void AAstroCustomGameManager::AddPlayerRespawnTokenPool(const FString& PlayerId) {
}

//bool AAstroCustomGameManager::AddCloudSavedCGMConfig(FAstroCGMLibraryConfigEntryMetaData MetaData, FAstroCustomGameSettings& NewCustomGameSettings) {
//    return false;
//}

bool AAstroCustomGameManager::AddCGMModifierScalar(FGameplayTagContainer tagsToAdd, float MinValue, float MaxValue, float stepValue, int32 currentIndex) {
    return false;
}


