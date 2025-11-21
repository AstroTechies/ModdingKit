#pragma once
#include "CoreMinimal.h"
//#include "AstroCGMLibraryConfigEntryMetaData.h"
//#include "FAstroCGMLibraryConfigEntryType.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "AstroCustomGameConfigurationCache.h"
#include "AstroCustomGameSettings.h"
#include "AstroCustomGameState.h"
#include "AstroCustomGlitchWalkerSettings.h"
#include "AstroCustomMultiToolSettings.h"
#include "AstroCustomOxygenSettings.h"
#include "AstroCustomPowerSettings.h"
#include "AstroCustomResearchSettings.h"
#include "AutomaticMissionCompletionInfo.h"
#include "EAstroStartingSlotItem.h"
#include "EPlanetIdentifier.h"
#include "FAstroCustomGameConfigurationCacheType.h"
//#include "OnCGMConfigPublishedDelegateDelegate.h"
//#include "OnConfigCacheUpdatedDelegateDelegate.h"
//#include "OnConfigImportFailedMulticastDelegateDelegate.h"
//#include "OnConfigImportSucceededMulticastDelegateDelegate.h"
//#include "OnConfigLocalCacheUpdateFailedMulticastDelegateDelegate.h"
//#include "OnConfigMetaDataCachePlayfabUpdateFailedMulticastDelegateDelegate.h"
//#include "OnConfigPlayfabCacheUpdateFailedMulticastDelegateDelegate.h"
//#include "OnCustomGameSettingModifiedDelegate.h"
//#include "OnCustomGameSettingsChangedDelegate.h"
//#include "OnIsCustomGameChangedDelegate.h"
//#include "OnRespawnTokenCountUpdatedDelegate.h"
#include "StartingItemSlotData.h"
#include "Templates/SubclassOf.h"
#include "AstroCustomGameManager.generated.h"

class UItemType;

UCLASS(Blueprintable)
class ASTRO_API AAstroCustomGameManager : public AActor {
    GENERATED_BODY()
public:
//    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FOnConfigCacheUpdatedDelegate OnConfigCacheUpdatedDelegate;
    
//    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FOnCGMConfigPublishedDelegate OnCGMConfigPublishedDelegate;
    
//    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FOnConfigImportFailedMulticastDelegate OnConfigImportFailedMulticastDelegate;
    
//    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FOnConfigImportSucceededMulticastDelegate OnConfigImportSucceededMulticastDelegate;
    
//    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FOnConfigLocalCacheUpdateFailedMulticastDelegate OnConfigLocalCacheUpdateFailedMulticastDelegate;
    
//    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FOnConfigPlayfabCacheUpdateFailedMulticastDelegate OnConfigPlayfabCacheUpdateFailedMulticastDelegate;
    
//    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FOnConfigMetaDataCachePlayfabUpdateFailedMulticastDelegate OnConfigMetaDataCachePlayfabUpdateFailedMulticastDelegate;
    
//    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FOnRespawnTokenCountUpdated OnRespawnTokenCountUpdated;
    
//    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FOnIsCustomGameChanged OnIsCustomGameChanged;
    
//    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FOnCustomGameSettingsChanged OnCustomGameSettingsChanged;
    
//    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FOnCustomGameSettingModified OnCustomGameSettingModified;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsCreatingNewConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SettingsModifiedFromOriginal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsImportingConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool CustomGameConfigCachesInitialized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ActiveSettingsAreAppliedToWorld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool IsFirstTimeSettingsAreApplied;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool IsCustomGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroCustomGameSettings CustomGameSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroCustomGameSettings StagedCustomGameSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SettingsAreStaged;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
//    FAstroCGMLibraryConfigEntryMetaData MetaDataToLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool MetaDataToLoadIsForDSNewGame;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAutomaticMissionCompletionInfo> AutomaticMissionCompletionInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> MissionsToCompleteQueue;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
//    TMap<FAstroCGMLibraryConfigEntryType, FAstroCustomGameConfigurationCache> CustomGameRuntimeConfigurationCloudCaches;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
//    TMap<FAstroCGMLibraryConfigEntryType, FAstroCustomGameConfigurationCache> CustomGameRuntimeConfigurationDiskCaches;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
//    TMap<FAstroCGMLibraryConfigEntryType, FAstroCustomGameConfigurationCache> CustomGameRuntimeConfigurationCombinedCaches;
    
public:
    AAstroCustomGameManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdatePromotedConfigCacheFromPlayFab();
    
    UFUNCTION(BlueprintCallable)
    bool UpdatePlayerRespawnTokenCount(const FString& PlayerId);
    
    UFUNCTION(BlueprintCallable)
    void UpdateCloudSavedConfigsMetaDataFromPlayFab();
    
//    UFUNCTION(BlueprintCallable)
//    void UpdateCloudSavedConfigCacheFromPlayFab(TArray<FAstroCGMLibraryConfigEntryMetaData> MetaDataList);
    
    UFUNCTION(BlueprintCallable)
    void UpdateCloudImportedConfigsMetaDataFromPlayFab();
    
//    UFUNCTION(BlueprintCallable)
//    void UpdateCloudImportedConfigCacheFromPlayFab(TArray<FAstroCGMLibraryConfigEntryMetaData> MetaDataList);
    
    UFUNCTION(BlueprintCallable)
    bool UpdateCGMModifierScalar(FGameplayTagContainer tagsToUpdate, int32 currentIndex);
    
    UFUNCTION(BlueprintCallable)
    void TruncateModifiersForSwitch(FAstroCustomGameSettings& NewCustomGameSettings);
    
    UFUNCTION(BlueprintCallable)
    void SortCacheByMetaData(FAstroCustomGameConfigurationCache& cache);
    
    UFUNCTION(BlueprintCallable)
    void SetStartingUtilitySlotItem(EAstroStartingSlotItem Item, int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    void SetStartingToolSlotItem(EAstroStartingSlotItem Item, int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    void SetStartingPlanet(EPlanetIdentifier StartingPlanetId);
    
    UFUNCTION(BlueprintCallable)
    void SetStartingItemSlotData(const TArray<FStartingItemSlotData>& slotData);
    
    UFUNCTION(BlueprintCallable)
    void SetStartingBiome(const FString& StartingBiome);
    
    UFUNCTION(BlueprintCallable)
    void SetStartingBackpackSlotItem(EAstroStartingSlotItem Item, int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    void SetSkipDropPodLaunchSequence(bool skipLaunchSequence);
    
    UFUNCTION(BlueprintCallable)
    void SetRespawnTokenSettings(bool RespawnTokensActive, bool respawnTokensShared, int32 InitialRespawnTokenCount);
    
    UFUNCTION(BlueprintCallable)
    void SetResearchSettings(const FAstroCustomResearchSettings& newSettings);
    
    UFUNCTION(BlueprintCallable)
    void SetPowerSettings(const FAstroCustomPowerSettings& newSettings);
    
    UFUNCTION(BlueprintCallable)
    void SetPlayerRespawnTokenCount(const FString& PlayerId, int32 newRespawnTokenCount);
    
    UFUNCTION(BlueprintCallable)
    void SetOxygenSettings(const FAstroCustomOxygenSettings& newSettings);
    
    UFUNCTION(BlueprintCallable)
    void SetNoStartingShelter(bool NoStartingShelter);
    
    UFUNCTION(BlueprintCallable)
    void SetMultiToolSettings(const FAstroCustomMultiToolSettings& newSettings);
    
    UFUNCTION(BlueprintCallable)
    void SetIsCustomGame(bool customGameState);
    
    UFUNCTION(BlueprintCallable)
    void SetGlitchWalkerSettings(const FAstroCustomGlitchWalkerSettings& newSettings);
    
    UFUNCTION(BlueprintCallable)
    void SetCustomGameName(const FString& newCustomGameName);
    
//    UFUNCTION(BlueprintCallable)
//    FAstroCGMLibraryConfigEntryMetaData SaveConfigLocallyFromGameState();
    
    UFUNCTION(BlueprintCallable)
    void RestoreLocalSavedConfigCacheFromLegacyStorage(const TArray<FAstroCustomGameSettings> cache);
    
    UFUNCTION(BlueprintCallable)
    void RemoveResearchCatalogDisabledItems(TArray<TSubclassOf<UItemType>> itemTypes);
    
    UFUNCTION(BlueprintCallable)
    void RemoveResearchCatalogDisabledItem(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveLocalSavedCGMConfig(const FString& ShareCode);
    
//    UFUNCTION(BlueprintCallable)
//    bool RemoveFromCacheIfExists(FAstroCustomGameConfigurationCacheType cacheType, FAstroCGMLibraryConfigEntryType cacheId, const int32 Index);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveCloudSavedCGMConfig(const FString& ShareCode);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveCloudImportedCGMConfig(const FString& ShareCode);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveCGMModifierScalar(FGameplayTagContainer tagsToRemove);
    
    UFUNCTION(BlueprintCallable)
    void PushStagedSettingsToActive();
    
//    UFUNCTION(BlueprintCallable)
//    void ParseCustomGameSettingsFromJson(const FString& configJsonString, FAstroCGMLibraryConfigEntryMetaData& MetaData, FAstroCustomGameSettings& customGame);
    
//    UFUNCTION(BlueprintCallable)
//    void OnGetUGCItemSuccessGetConfigDataFromAzure(const FAstroCGMLibraryConfigEntryMetaData& MetaData, const FString& URL);
    
//    UFUNCTION(BlueprintCallable)
//    void OnGetConfigDataFromAzureSuccess(const FAstroCGMLibraryConfigEntryMetaData& MetaData, const FString& configJson);
    
    UFUNCTION(BlueprintCallable)
    void LogCustomGameSettings(bool logStaged);
    
//    UFUNCTION(BlueprintCallable)
//    void LoadLocalConfigurationCacheFromDisk(const FAstroCGMLibraryConfigEntryType cacheId);
    
//    UFUNCTION(BlueprintCallable)
//    bool LoadCGMConfigFromCache(const FAstroCGMLibraryConfigEntryMetaData& MetaData, bool staged);
    
    UFUNCTION(BlueprintCallable)
    void InitializeSettingsAndState(bool NewIsCustomGame, const FAstroCustomGameSettings& NewCustomGameSettings, const FAstroCustomGameState& customGameState);
    
    UFUNCTION(BlueprintCallable)
    void InitializeRespawnTokenPools(const FString& PlayerId);
    
    UFUNCTION(BlueprintCallable)
    void InitializeAllConfigurationCachesIfNotInitialized();
    
    UFUNCTION(BlueprintCallable)
    void ImportCGMConfigFromPlayfab(const FString& ShareCode);
    
    UFUNCTION(BlueprintCallable)
    void HandleMissionActivated(FName missionId);
    
    UFUNCTION(BlueprintCallable)
    EAstroStartingSlotItem GetStartingUtilitySlotItem(int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    EAstroStartingSlotItem GetStartingToolSlotItem(int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    EAstroStartingSlotItem GetStartingBackpackSlotItem(int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRespawnTokenCount(const FString& PlayerId);
    
    UFUNCTION(BlueprintCallable)
    FString GetNextAvailableLocalSaveShareCode();
    
//    UFUNCTION(BlueprintCallable)
//    int32 GetMetaDataCacheIndexFromCacheType(const FAstroCGMLibraryConfigEntryMetaData& MetaData, const FAstroCustomGameConfigurationCacheType cacheType);
    
//    UFUNCTION(BlueprintCallable)
//    int32 GetMetaDataCacheIndex(const FAstroCGMLibraryConfigEntryMetaData& MetaData, const FAstroCustomGameConfigurationCache& cache);
    
    UFUNCTION(BlueprintCallable)
    FGameplayTagContainer GetGameplayTagsFromString(const FString& tagsString);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FAstroCustomGameSettings GetCurrentInteractiveCustomGameSettings();
    
    UFUNCTION(BlueprintCallable)
    float GetCounter(const FString& PlayerId);
    
//    UFUNCTION(BlueprintCallable)
//    int32 GetConfigIndexInCache(FAstroCustomGameConfigurationCacheType cacheType, FAstroCGMLibraryConfigEntryType cacheId, const FString& ShareCode);
    
//    UFUNCTION(BlueprintCallable)
//    FAstroCustomGameConfigurationCache GetConfigCache(const FAstroCustomGameConfigurationCacheType cacheType, const FAstroCGMLibraryConfigEntryType cacheId);
    
    UFUNCTION(BlueprintCallable)
    void ExtractLegacyConfigDataAndUpdate(FAstroCustomGameSettings& NewCustomGameSettings, const FString& configJsonString);
    
    UFUNCTION(BlueprintCallable)
    void EnforceCustomGameSettingsRangeRestrictions(FAstroCustomGameSettings& NewCustomGameSettings);
    
    UFUNCTION(BlueprintCallable)
    void EndPlay(const TEnumAsByte<EEndPlayReason::Type> EndPlayReason);
    
//    UFUNCTION(BlueprintCallable)
//    void CombineCloudAndDiskCaches(const FAstroCGMLibraryConfigEntryType cacheId);
    
    UFUNCTION(BlueprintCallable)
    void ClearCustomGameSettingsState();
    
    UFUNCTION(BlueprintCallable)
    void BroadcastIsCustomGameChanged();
    
    UFUNCTION(BlueprintCallable)
    void BroadcastCustomGameSettingsChanged();
    
    UFUNCTION(BlueprintCallable)
    void BroadcastCustomGameSettingModified();
    
    UFUNCTION(BlueprintCallable)
    void BeginPlay();
    
    UFUNCTION(BlueprintCallable)
    void ApplyCustomGameSettingsToWorld();
    
    UFUNCTION(BlueprintCallable)
    void AddResearchCatalogDisabledItems(TArray<TSubclassOf<UItemType>> itemTypes);
    
    UFUNCTION(BlueprintCallable)
    void AddResearchCatalogDisabledItem(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    void AddPlayerRespawnTokenPoolIfNotExists(const FString& PlayerId);
    
    UFUNCTION(BlueprintCallable)
    void AddPlayerRespawnTokenPool(const FString& PlayerId);
    
//    UFUNCTION(BlueprintCallable)
//    bool AddCloudSavedCGMConfig(FAstroCGMLibraryConfigEntryMetaData MetaData, FAstroCustomGameSettings& NewCustomGameSettings);
    
    UFUNCTION(BlueprintCallable)
    bool AddCGMModifierScalar(FGameplayTagContainer tagsToAdd, float MinValue, float MaxValue, float stepValue, int32 currentIndex);
    
};

