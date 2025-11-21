#pragma once
#include "CoreMinimal.h"
//#include "AnalyticsEventAttr.h"
//#include "AstroCGMLibraryConfigEntryMetaData.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineBaseTypes.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=NetUnstableActorReference -FallbackName=NetUnstableActorReference
#include "GameFramework/PlayerController.h"
#include "Engine/NetSerialization.h"
#include "Engine/NetSerialization.h"
#include "Engine/NetSerialization.h"
#include "DeformationParamsT2.h"
#include "PackedVoxelMaterialInfo.h"
#include "TerrainNodeNetChecksum.h"
#include "AchievementProgressReplicationData.h"
#include "AstroCharacterCustomization.h"
#include "AstroClientProperties.h"
#include "AstroCustomGameSettings.h"
#include "AstroCustomGameState.h"
#include "AstroNotificationTagAuthoringData.h"
#include "AstroOneTimeTooltipState.h"
#include "ClientCreativeModeResponseDelegateDelegate.h"
#include "ClientDeleteGameResponseDelegateDelegate.h"
#include "ClientListGamesResponseDelegateDelegate.h"
#include "ClientListPlayersResponseDelegateDelegate.h"
#include "ClientLoadGameResponseDelegateDelegate.h"
#include "ClientNewGameResponseDelegateDelegate.h"
#include "ClientRenameGameResponseDelegateDelegate.h"
#include "ClientSaveGameResponseDelegateDelegate.h"
#include "ClientServerStatisticsResponseDelegateDelegate.h"
#include "ClientSetPropertiesResponseDelegateDelegate.h"
#include "CountAchievement.h"
#include "DSTravelInitiatedDelegateDelegate.h"
#include "EAstroAchievementKeys.h"
#include "EPlanetIdentifier.h"
#include "EPlayerCategory.h"
#include "EStatusModifierType.h"
#include "EUseType.h"
#include "FloatCountAchievement.h"
#include "GameList.h"
#include "InitialClientStateParams.h"
#include "ItemCollectionAchievement.h"
#include "PlayFabDataRefreshedDelegateDelegate.h"
#include "PlayerList.h"
#include "ServerStatistics.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "AstroPlayerController.generated.h"

class AActor;
class AAstroCharacter;
class APhysicalItem;
class ASolarBody;
class UControlSymbol;
class UItemType;
class UObject;
class UPersistentLocalPlayerData;
class UPrimitiveComponent;
class UPrinterComponent;
class UUserWidget;
class UVoxelVolumeComponent;

UCLASS(Blueprintable)
class ASTRO_API AAstroPlayerController : public APlayerController {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_AchievementProgress, meta=(AllowPrivateAccess=true))
    FAchievementProgressReplicationData AchievementReplicationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableEscapeMenuToggle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EscMenuToggleAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString HelpMenuToggleAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* CurrentHelpMenu;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FireworksAchievementLaunchCountKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FireworksAchievementLaunchWindowKey;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnGameMenuResized;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnMultiplayerDisabled;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPlayerJoinedSession;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPlayerLeftSession;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayFabDataRefreshedDelegate OnPlayFabClientDataRefreshed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AActor* ControlledVehicle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPersistentLocalPlayerData* PersistentLocalData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool HasGlitchwalkersEntitlement;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 MotionBlurQuality;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* CurrentDebugMenu;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AActor* PendingSelectionActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UVoxelVolumeComponent*> VoxelVolumesAlreadyEncounteredForJIP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> LaunchedFireworkTimes;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClientNewGameResponseDelegate OnClientNewGameResponse;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClientSaveGameResponseDelegate OnClientSaveGameResponse;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClientLoadGameResponseDelegate OnClientLoadGameResponse;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClientDeleteGameResponseDelegate OnClientDeleteGameResponse;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClientRenameGameResponseDelegate OnClientRenameGameResponse;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClientListPlayersResponseDelegate OnClientListPlayersResponse;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClientListGamesResponseDelegate OnClientListGamesResponse;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClientServerStatisticsResponseDelegate OnClientServerStatisticsResponse;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClientSetPropertiesResponseDelegate OnClientSetPropertiesResponse;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClientCreativeModeResponseDelegate OnClientCreativeModeResponse;
    
    AAstroPlayerController(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void WouldCompleteCollection_RespondToServer(bool response, int32 RequestId);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void WouldCompleteCollection_RequestFromClient(EAstroAchievementKeys collectionAchievement, TSubclassOf<UItemType> newCollectionItem, int32 RequestId);
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void VoxelGenAuditToggleDebugMarkers(const FString& Name);
    
    UFUNCTION(BlueprintCallable, Exec)
    void VoxelGenAuditStop();
    
    UFUNCTION(Exec)
    void VoxelGenAuditStart(const int8 maxDepth);
    
    UFUNCTION(BlueprintCallable, Exec)
    void VoxelGenAuditDumpOutput(uint8 writeToFiles);
    
    UFUNCTION(BlueprintCallable)
    void TravelToDedicatedServerByURL(const FString& ServerURL, const FString& Password, const FDSTravelInitiatedDelegate& TravelInitiated);
    
    UFUNCTION(BlueprintCallable)
    void TrackFireworkLaunchedForAchievementProgress();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleProxyVisibility();
    
    UFUNCTION(BlueprintCallable)
    void ToggleEscapeMenu();
    
    UFUNCTION(BlueprintCallable)
    void ToggleAstropediaMenu();
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestSwitchProfilesPopup();
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestPurchase();
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestMountEncryptedPak();
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestListStoreItems();
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestListCatalogItems();
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestGetPrices();
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestDumpDSSessionMembership();
    
    UFUNCTION(BlueprintCallable, Exec)
    void TestDumpDSProxyState();
    
    UFUNCTION(BlueprintCallable, Exec)
    void T2Raycast(float Distance);
    
    UFUNCTION(BlueprintCallable, Exec)
    void StartNetworkSession();
    
    UFUNCTION(Exec)
    void SetSolarTime(double Time);
    
    UFUNCTION(BlueprintCallable)
    void SetMotionBlurEnabled(bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void SetItemForInitialSelection(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUseActor(AActor* Actor, FName Action, EInputEvent KeyEvent, EUseType useType);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSyncPlayfabBackendID(const FString& BackendPlayerId);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSyncOneTimeTooltipSystemState();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerStartPrint(UPrinterComponent* Component);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetSolarTimeScaleMultiplierCreative(float Scale);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSetPlayerOwnsMegaTech(bool ownsMegatech);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSetPlayerOwnsGlitchwalkers(bool ownsGlitchWalkers);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetNormalizedTimeOfDayCreative(float Scale);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetNormalizedSunOrbitCreative(float normalizedSunOrbit);
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetCharacterCustomization(const FAstroCharacterCustomization& Customization);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerResetGameStateAchievementProgress();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRequestUnlockItem(TSubclassOf<UItemType> ItemTypeToUnlock, bool bAllowPlayFabBinding);
    
private:
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerRequestTerrainCorrection(UVoxelVolumeComponent* voxelVolume, const TArray<uint64>& Nodes);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerRequestOrbitalPlatformSeed();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRequestFoliageDestruction(AActor* DestructionInstigator, FVector_NetQuantize100 Location, float Radius, float MassThreshold, bool bShouldCollectResourceNuggets);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerRemoveDebugLocation(const FString& Name);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRemote(const FString& consoleCommand);
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRedeemPlayerTicket(const FString& Ticket);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerPointItem(TSubclassOf<UItemType> ItemType, TSubclassOf<UControlSymbol> PingSymbol, const FVector& Location, const FVector_NetQuantizeNormal& Normal);
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerNotifyJoinMenuComplete();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerNotifyClientFullyJoined();
    
public:
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerNakDataChunk(uint32 transmissionID, uint32 missingChunkStart, uint32 missingChunkCount);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerIncrementPrinterBlueprintRow(UPrinterComponent* Component, int32 increment);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerIncrementPrinterBlueprint(UPrinterComponent* Component, int32 increment);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerGetServerStatistics();
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerFlushPendingUnlocks();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerFlushPendingAchievements();
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDumpProxyState();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDoDeformation(FDeformationParamsT2 params);
    
private:
    UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation)
    void ServerDoControlSystemInput(FVector_NetQuantize10 Input, FVector_NetQuantizeNormal cameraForward);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerCreateProxySessionResult(FGuid sessionGUID, bool success);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerClickSlotIndicator(FSlotReference Slot, TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerClickSlot(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerClickActor(AActor* Actor, FTransform CameraTransform);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerClick(UPrimitiveComponent* Primitive, FTransform CameraTransform);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerClearStormEffects();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerClearStatusModifiers();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerClearDebugLocations();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerCancelPrint(UPrinterComponent* Component);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAuxOverrideUseItem(APhysicalItem* Item, EInputEvent InputEvent);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetSaveGameInterval(const FString& Seconds);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerAdminSetProperties(uint64 PlayerGuid, const FAstroClientProperties& clientCapabilities, const FAstroClientProperties& Mask);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetPassword(const FString& Password);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetOxygenFreeCreative(bool Enable);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetInvisibleToHazardsCreative(bool Enable);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetInvincibleCreative(bool Enable);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetFuelFreeCreative(bool Enable);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetDenyUnlisted(const FString& Enable);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetCategoryForPlayerName(const FString& PlayerName, EPlayerCategory PlayerCategory);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetBackupSaveGamesInterval(const FString& Seconds);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetBackpackPowerUnlimitedCreative(bool Enable);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetActivityTimeout(const FString& Seconds);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminServerShutdown();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSaveGame(const FString& Name);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminRenameGame(const FString& fromName, const FString& toName);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminNewGame(const FString& Name, bool newGlitchWalkersGame);
    
//    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
//    void ServerAdminNewCustomGame(const FAstroCGMLibraryConfigEntryMetaData& MetaData);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminLoadGame(const FString& Name);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminListPlayers();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminListGames();
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerAdminKickPlayer(uint64 PlayerGuid);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminGetProperties();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminDeleteGame(const FString& Name);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminCreativeMode(bool Enable);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminBackupSaveGames();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAddProxySessionReservationResult(FGuid sessionGUID, const TArray<FString>& userIdsToAdd, bool success);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerAddDebugLocation(const FString& Name, FVector Location, FQuat Rotation);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerActuatorOverrideUseItem(APhysicalItem* Item, EInputEvent InputEvent);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerAckChunkedDataFinished(uint32 transmissionID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SaveGameAsAsset(const FString& Name);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SaveGame(const FString& Name);
    
    UFUNCTION(BlueprintCallable, Exec)
    void ResetPersistentLocalPlayerData();
    
    UFUNCTION(BlueprintCallable)
    void ResetInactivePlayerTimeout();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ResetAllUnlocks();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ResetAllAchievements();
    
    UFUNCTION(BlueprintCallable)
    void ReportAchievementProgress(const EAstroAchievementKeys AchievementKey, float Progress, float NeededCount);
    
    UFUNCTION(BlueprintCallable, Exec)
    void RemoveDebugLocation(const FString& Name);
    
    UFUNCTION(BlueprintCallable, Exec)
    void RebuildNodeWithLoggingBM(const FString& locationCode);
    
    UFUNCTION(BlueprintCallable, Exec)
    void RebuildNodeWithLogging(const FString& locationCode);
    
    UFUNCTION(BlueprintCallable)
    void PushPendingItemUnlock(const FString& itemUnlock);
    
    UFUNCTION(BlueprintCallable)
    void PublishCGMConfigFromGameState();
    
    UFUNCTION(BlueprintCallable, Exec)
    void PrintDebugLocations();
    
private:
    UFUNCTION(BlueprintCallable)
    void PersistCharacterCustomization();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnRep_AchievementProgress();
    
    UFUNCTION(BlueprintCallable)
    void OnPersistentLocalPlayerDataSaveCooldownExpired();
    
    UFUNCTION(BlueprintCallable)
    void OnPersistentLocalPlayerDataDirtied();
    
    UFUNCTION(BlueprintCallable)
    void OnInactivePlayerTimeout();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnClientTitleMenuComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnClientLoadingScreenComplete();
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void LogTerrainDataForNode(const FString& locationCode);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LoadSeamless(const FString& FURL);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LoadGameFromAsset(const FString& Name);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LoadGame(const FString& Name);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTerrainToolCreativeMenuBlocked() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMultiplayerDisabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMainController();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsHelpMenuVisible() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEscapeMenuVisible() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsControllerJoined() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsConnectionClosing() const;
    
    UFUNCTION(BlueprintCallable)
    void IncrementAchievementProgress(const FCountAchievement& AchievementDef, int32 AddedProgress);
    
    UFUNCTION(BlueprintCallable)
    void IncrementAchievementFloatProgress(const FFloatCountAchievement& AchievementDef, float AddedProgress);
    
    UFUNCTION(BlueprintCallable, Exec)
    void HidePlayerNames(bool hide);
    
    UFUNCTION(BlueprintCallable, Exec)
    void HideBeacons(bool hide);
    
    UFUNCTION(BlueprintCallable)
    bool HasAdminAccess();
    
    UFUNCTION(BlueprintCallable, Exec)
    void GrantAllUnlocks();
    
    UFUNCTION(BlueprintCallable, Exec)
    void GrantAchievement(const FString& AchievementName);
    
    UFUNCTION(BlueprintCallable)
    float GetStatusModifierValue(EStatusModifierType statusModifierType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsReturningPlayer() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    bool GameFullyLoaded();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ForceStartGame();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ForceCrash();
    
    UFUNCTION(BlueprintCallable)
    void FlushPendingAchievementsAndUnlocks();
    
    UFUNCTION(BlueprintCallable, Exec)
    void EndNetworkSession();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DumpMeshSummary();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DumpMeshMemory();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DumpActorDataTXT();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DumpActorDataCSV();
    
    UFUNCTION(Exec)
    void DropNextNetDeformations(uint32 Count);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DeleteSaveGame(const FString& Name);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DeleteAllAutoSaves();
    
    UFUNCTION(BlueprintCallable)
    void DeferredDisableEscapeMenu();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugTeleportCoord(FVector Location);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugTeleport(const FString& Name, bool safe);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientVoxelJIPComplete();
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientUnPossess(AAstroCharacter* oldCharacter);
    
private:
    UFUNCTION(BlueprintCallable, Client, Unreliable)
    void ClientTerrainValidateChecksumsT2(UVoxelVolumeComponent* voxelVolume, const TArray<FTerrainNodeNetChecksum>& checksums);
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSyncStateFromServer(const FAstroCustomGameState& customGameState);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSyncSettingsFromServer(const bool IsCustomGame, const FAstroCustomGameSettings& CustomGameSettings, const FAstroCustomGameState& customGameState, const TArray<ASolarBody*>& solarBodies, const TArray<FVector>& planetOffsets);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSyncOneTimeTooltipSystemState(const FAstroOneTimeTooltipState& stateToSync);
    
    UFUNCTION(Client, Reliable)
    void ClientStartChunkedTransmission(uint32 transmissionID, uint8 dataType, uint32 chunkCount, uint32 uncompressedSize, UObject* keyObject);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetSaveGameIntervalResponse(bool success, const FString& Message);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetPropertiesResponse(const FAstroClientProperties& clientCapabilities);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetPasswordResponse(bool success);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetOxygenFreeCreativeResponse(bool success, bool Enable);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetInvisibleToHazardsCreativeResponse(bool success, bool Enable);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetInvincibleCreativeResponse(bool success, bool Enable);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetFuelFreeCreativeResponse(bool success, bool Enable);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetDenyUnlistedResponse(bool success, const FString& Message);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetBackupSaveGamesIntervalResponse(bool success, const FString& Message);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetBackpackPowerUnlimitedCreativeResponse(bool success, bool Enable);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetAstroViewTarget(AActor* ViewTarget);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetActivityTimeoutResponse(bool success);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientServerStatisticsResponse(const FServerStatistics& ServerStatistics);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSaveGameResponse(bool success, const FString& Name);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientRequestFoliageDestruction(AActor* DestructionInstigator, FVector_NetQuantize100 Location, float Radius, float MassThreshold, bool bShouldCollectResourceNuggets);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientRenameGameResponse(bool copySuccess, bool removeSuccess, const FString& fromName, const FString& toName);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientRecvSeeds(const TArray<ASolarBody*>& solarBodies, const TArray<int32>& seeds, const TArray<FVector>& Offsets);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientRecvPlayerState(const FInitialClientStateParams& params);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientRecvPlanetMaterials(ASolarBody* Planet, const TArray<FPackedVoxelMaterialInfo>& Materials, const FVector& InLocation);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientRecvOrbitalPlatformSeed(const int32 Seed);
    
    UFUNCTION(Client, Unreliable)
    void ClientRecvChunkedDataCompletionSignal(uint32 transmissionID);
    
    UFUNCTION(Client, Unreliable)
    void ClientRecvChunkedData(uint32 transmissionID, int32 chunkIndex, const TArray<int8>& Data, UObject* keyObject);
    
//    UFUNCTION(BlueprintCallable, Client, Reliable)
//    void ClientRecordPlayerEventWithCallback(const FString& EventName, const TArray<FAnalyticsEventAttr>& Attributes);
    
//    UFUNCTION(BlueprintCallable, Client, Reliable)
//    void ClientRecordPlayerEvent(const FString& EventName, const TArray<FAnalyticsEventAttr>& Attributes);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientNotifyPlayerMadeLandfall(const FText& PlayerName, EPlanetIdentifier planetID);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientNotifyPlayerLeftSession(const FText& PlayerName);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientNotifyPlayerJoinedSession(const FText& PlayerName);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientNoInitialPlanetSignal();
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientNewGameResponse(bool success, const FString& Name);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientLoadGameResponse(bool success, const FString& Name);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientListPlayersResponse(const FPlayerList& PlayerList);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientListGamesResponse(const FGameList& GameList);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientKickPlayerResponse(bool success);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientJoinedDedicatedServer();
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientGrantItems(const TArray<FString>& ItemIds);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientGetPropertiesResponse(const FAstroClientProperties& clientCapabilities);
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientFlushPendingUnlocks(const TArray<FString>& serverPendingUnlocks);
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientEnqueueNotification(const FAstroNotificationTagAuthoringData& AuthoringData);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientDoDeformation(FDeformationParamsT2 params);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientDeleteGameResponse(bool success, const FString& Name);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientCreativeModeResponse(bool success, bool Enable);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientCreateProxySession(FGuid sessionGUID);
    
private:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientBeginAuthHandshake(const FString& LobbyId);
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientBackupSaveGamesResponse(bool success);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientAwardAchievement(const EAstroAchievementKeys AchievementKey);
    
private:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientAuthComplete(bool bSuccess);
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientAddProxySessionReservations(const TArray<FString>& userIdsToAdd);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientAddPlayFabCatalogItem(const FString& unlockedItem) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void ClearDebugLocations();
    
    UFUNCTION(BlueprintCallable)
    void AwardAchievementOffline(const FString& AchievementName);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetStatusModifier(EStatusModifierType statusModifierType, float _value);
    
    UFUNCTION(BlueprintCallable)
    void AttemptEnableMultiplayer();
    
    UFUNCTION(BlueprintCallable)
    void AdminSetPropertiesForPlayer(const FString& PlayerGuid, const FAstroClientProperties& clientCapabilities);
    
    UFUNCTION(BlueprintCallable)
    void AdminKickPlayer(const FString& PlayerGuid);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddDebugLocation(const FString& Name);
    
    UFUNCTION(BlueprintCallable)
    void AddAchievementCollectionItem(const FItemCollectionAchievement& AchievementDef, TSubclassOf<UItemType> Item);
    
};

