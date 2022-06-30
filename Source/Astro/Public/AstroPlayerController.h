#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "InitialClientStateParams.h"
#include "UObject/NoExportTypes.h"
#include "AchievementProgressReplicationData.h"
#include "SignalDelegate.h"
#include "DeformationParamsT2.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=NetUnstableActorReference -FallbackName=NetUnstableActorReference
#include "ServerStatistics.h"
#include "Engine/NetSerialization.h"
#include "GameList.h"
#include "ClientNewGameResponseDelegateDelegate.h"
#include "AstroNotificationTagAuthoringData.h"
#include "ClientSaveGameResponseDelegateDelegate.h"
#include "ClientLoadGameResponseDelegateDelegate.h"
#include "ClientDeleteGameResponseDelegateDelegate.h"
#include "ClientRenameGameResponseDelegateDelegate.h"
#include "ClientListPlayersResponseDelegateDelegate.h"
#include "EPlayerCategory.h"
#include "EAstroAchievementKeys.h"
#include "ClientListGamesResponseDelegateDelegate.h"
#include "ClientServerStatisticsResponseDelegateDelegate.h"
#include "ClientSetPropertiesResponseDelegateDelegate.h"
#include "Engine/NetSerialization.h"
#include "ClientCreativeModeResponseDelegateDelegate.h"
#include "Engine/EngineBaseTypes.h"
#include "DSTravelInitiatedDelegateDelegate.h"
#include "FloatCountAchievement.h"
#include "EUseType.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/NetSerialization.h"
#include "UObject/NoExportTypes.h"
#include "SlotReference.h"
#include "AstroClientProperties.h"
#include "CountAchievement.h"
#include "TerrainNodeNetChecksum.h"
#include "PackedVoxelMaterialInfo.h"
#include "PlayerList.h"
#include "ItemCollectionAchievement.h"
#include "AstroPlayerController.generated.h"

class UUserWidget;
class AActor;
class UItemType;
class UPersistentLocalPlayerData;
class UVoxelVolumeComponent;
class UPrimitiveComponent;
class APhysicalItem;
class UPrinterComponent;
class UControlSymbol;
class AAstroCharacter;
class AAstroPlanet;
class UObject;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AAstroPlayerController : public APlayerController
{
    GENERATED_BODY()
public:
    UPROPERTY(ReplicatedUsing = OnRep_AchievementProgress)
    FAchievementProgressReplicationData AchievementReplicationData;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool EnableEscapeMenuToggle;

    UPROPERTY(EditAnywhere)
    FString EscMenuToggleAudioEvent;

    UPROPERTY(EditAnywhere)
    FString HelpMenuToggleAudioEvent;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UUserWidget *CurrentHelpMenu;

    UPROPERTY(EditDefaultsOnly)
    FName FireworksAchievementLaunchCountKey;

    UPROPERTY(EditDefaultsOnly)
    FName FireworksAchievementLaunchWindowKey;

    UPROPERTY(BlueprintAssignable)
    FSignal OnGameMenuResized;

    UPROPERTY(BlueprintAssignable)
    FSignal OnMultiplayerDisabled;

protected:
    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    AActor *ControlledVehicle;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    UPersistentLocalPlayerData *PersistentLocalData;

private:
    UPROPERTY(Transient)
    int32 MotionBlurQuality;

    UPROPERTY(Export)
    UUserWidget *CurrentDebugMenu;

    UPROPERTY(Replicated)
    AActor *PendingSelectionActor;

    UPROPERTY(Export)
    TArray<UVoxelVolumeComponent *> VoxelVolumesAlreadyEncounteredForJIP;

    UPROPERTY()
    TArray<float> LaunchedFireworkTimes;

public:
    UPROPERTY(BlueprintAssignable)
    FClientNewGameResponseDelegate OnClientNewGameResponse;

    UPROPERTY(BlueprintAssignable)
    FClientSaveGameResponseDelegate OnClientSaveGameResponse;

    UPROPERTY(BlueprintAssignable)
    FClientLoadGameResponseDelegate OnClientLoadGameResponse;

    UPROPERTY(BlueprintAssignable)
    FClientDeleteGameResponseDelegate OnClientDeleteGameResponse;

    UPROPERTY(BlueprintAssignable)
    FClientRenameGameResponseDelegate OnClientRenameGameResponse;

    UPROPERTY(BlueprintAssignable)
    FClientListPlayersResponseDelegate OnClientListPlayersResponse;

    UPROPERTY(BlueprintAssignable)
    FClientListGamesResponseDelegate OnClientListGamesResponse;

    UPROPERTY(BlueprintAssignable)
    FClientServerStatisticsResponseDelegate OnClientServerStatisticsResponse;

    UPROPERTY(BlueprintAssignable)
    FClientSetPropertiesResponseDelegate OnClientSetPropertiesResponse;

    UPROPERTY(BlueprintAssignable)
    FClientCreativeModeResponseDelegate OnClientCreativeModeResponse;

    AAstroPlayerController();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void WouldCompleteCollection_RespondToServer(bool response, int32 RequestID);

    UFUNCTION(Client, Reliable, WithValidation)
    void WouldCompleteCollection_RequestFromClient(EAstroAchievementKeys collectionAchievement, TSubclassOf<UItemType> newCollectionItem, int32 RequestID);

public:
    UFUNCTION(Exec)
    void VoxelGenAuditToggleDebugMarkers(const FString &Name);

    UFUNCTION(Exec)
    void VoxelGenAuditStop();

    UFUNCTION(Exec)
    void VoxelGenAuditStart(const int8 maxDepth);

    UFUNCTION(Exec)
    void VoxelGenAuditDumpOutput(uint8 writeToFiles);

    UFUNCTION(BlueprintCallable)
    void TravelToDedicatedServerByURL(const FString &ServerURL, const FString &Password, const FDSTravelInitiatedDelegate &TravelInitiated);

    UFUNCTION(BlueprintCallable)
    void TrackFireworkLaunchedForAchievementProgress();

    UFUNCTION(Exec)
    void ToggleProxyVisibility();

    UFUNCTION(BlueprintCallable)
    void ToggleEscapeMenu();

    UFUNCTION(BlueprintCallable)
    void ToggleAstropediaMenu();

    UFUNCTION(Exec)
    void TestSwitchProfilesPopup();

    UFUNCTION(Exec)
    void TestPurchase();

    UFUNCTION(Exec)
    void TestMountEncryptedPak();

    UFUNCTION(Exec)
    void TestListStoreItems();

    UFUNCTION(Exec)
    void TestListCatalogItems();

    UFUNCTION(Exec)
    void TestGetPrices();

    UFUNCTION(Exec)
    void TestDumpDSSessionMembership();

    UFUNCTION(Exec)
    void TestDumpDSProxyState();

    UFUNCTION(Exec)
    void T2Raycast(float Distance);

    UFUNCTION(Exec)
    void StartNetworkSession();

    UFUNCTION(Exec)
    void SetSolarTime(double Time);

    UFUNCTION(BlueprintCallable)
    void SetMotionBlurEnabled(bool Enable);

    UFUNCTION(BlueprintCallable)
    void SetItemForInitialSelection(APhysicalItem *Item);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerUseActor(AActor *Actor, FName Action, EInputEvent KeyEvent, EUseType useType);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerStartPrint(UPrinterComponent *Component);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetSolarTimeScaleMultiplierCreative(float Scale);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetNormalizedTimeOfDayCreative(float Scale);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetNormalizedSunOrbitCreative(float normalizedSunOrbit);

public:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerResetGameStateAchievementProgress();

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRequestUnlockItem(TSubclassOf<UItemType> ItemTypeToUnlock, bool bAllowPlayFabBinding);

private:
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerRequestTerrainCorrection(UVoxelVolumeComponent *voxelVolume, const TArray<uint64> &Nodes);

public:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerRequestFoliageDestruction(AActor *DestructionInstigator, FVector_NetQuantize100 Location, float Radius, float MassThreshold, bool bShouldCollectResourceNuggets);

    UFUNCTION(Reliable, Server)
    void ServerRemoveDebugLocation(const FString &Name);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerRemote(const FString &consoleCommand);

private:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerRedeemPlayerTicket(const FString &Ticket);

public:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerPointItem(TSubclassOf<UItemType> ItemType, TSubclassOf<UControlSymbol> PingSymbol, const FVector &Location, const FVector_NetQuantizeNormal &Normal);

private:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerNotifyJoinMenuComplete();

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerNotifyClientFullyJoined();

public:
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerNakDataChunk(uint32 transmissionID, uint32 missingChunkStart, uint32 missingChunkCount);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerIncrementBlueprint(UPrinterComponent *Component, int32 increment);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerGetServerStatistics();

protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerFlushPendingUnlocks();

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerFlushPendingAchievements();

public:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerDumpProxyState();

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerDoDeformation(FDeformationParamsT2 params);

private:
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerDoControlSystemInput(FVector_NetQuantize10 Input, FVector_NetQuantizeNormal cameraForward);

public:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerCreateProxySessionResult(FGuid sessionGUID, bool success);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerClickSlotIndicator(FSlotReference Slot, TSubclassOf<UItemType> Type);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerClickSlot(FSlotReference Slot);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerClickActor(AActor *Actor, FTransform CameraTransform);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerClick(UPrimitiveComponent *Primitive, FTransform CameraTransform);

    UFUNCTION(Reliable, Server)
    void ServerClearDebugLocations();

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerCancelPrint(UPrinterComponent *Component);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerAuxOverrideUseItem(APhysicalItem *Item, EInputEvent InputEvent);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerAdminSetSaveGameInterval(const FString &Seconds);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerAdminSetProperties(uint64 PlayerGuid, const FAstroClientProperties &clientCapabilities, const FAstroClientProperties &Mask);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetPassword(const FString &Password);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetOxygenFreeCreative(bool Enable);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetInvisibleToHazardsCreative(bool Enable);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetInvincibleCreative(bool Enable);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetFuelFreeCreative(bool Enable);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetDenyUnlisted(const FString &Enable);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetCategoryForPlayerName(const FString &PlayerName, EPlayerCategory PlayerCategory);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerAdminSetBackupSaveGamesInterval(const FString &Seconds);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSetBackpackPowerUnlimitedCreative(bool Enable);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerAdminSetActivityTimeout(const FString &Seconds);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminServerShutdown();

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminSaveGame(const FString &Name);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminRenameGame(const FString &fromName, const FString &toName);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminNewGame(const FString &Name);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminLoadGame(const FString &Name);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminListPlayers();

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminListGames();

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerAdminKickPlayer(uint64 PlayerGuid);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminGetProperties();

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminDeleteGame(const FString &Name);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAdminCreativeMode(bool Enable);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerAdminBackupSaveGames();

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerAddProxySessionReservationResult(FGuid sessionGUID, const TArray<FString> &userIdsToAdd, bool success);

    UFUNCTION(Reliable, Server)
    void ServerAddDebugLocation(const FString &Name, FVector Location, FQuat Rotation);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerActuatorOverrideUseItem(APhysicalItem *Item, EInputEvent InputEvent);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerAckChunkedDataFinished(uint32 transmissionID);

    UFUNCTION(Exec)
    void SaveGameAsAsset(const FString &Name);

    UFUNCTION(Exec)
    void SaveGame(const FString &Name);

    UFUNCTION(Exec)
    void ResetPersistentLocalPlayerData();

    UFUNCTION()
    void ResetInactivePlayerTimeout();

    UFUNCTION(Exec)
    void ResetAllUnlocks();

    UFUNCTION(Exec)
    void ResetAllAchievements();

    UFUNCTION()
    void ReportAchievementProgress(const EAstroAchievementKeys AchievementKey, float Progress, float NeededCount);

    UFUNCTION(Exec)
    void RemoveDebugLocation(const FString &Name);

    UFUNCTION(Exec)
    void RebuildNodeWithLoggingBM(const FString &locationCode);

    UFUNCTION(Exec)
    void RebuildNodeWithLogging(const FString &locationCode);

    UFUNCTION(Exec)
    void PrintDebugLocations();

private:
    UFUNCTION()
    void PersistCharacterCustomization();

public:
    UFUNCTION()
    void OnRep_AchievementProgress();

    UFUNCTION()
    void OnPersistentLocalPlayerDataSaveCooldownExpired();

    UFUNCTION()
    void OnPersistentLocalPlayerDataDirtied();

    UFUNCTION()
    void OnInactivePlayerTimeout();

private:
    UFUNCTION()
    void OnClientTitleMenuComplete();

    UFUNCTION()
    void OnClientLoadingScreenComplete();

public:
    UFUNCTION(Exec)
    void LogTerrainDataForNode(const FString &locationCode);

    UFUNCTION(Exec)
    void LoadSeamless(const FString &FURL);

    UFUNCTION(Exec)
    void LoadGameFromAsset(const FString &Name);

    UFUNCTION(Exec)
    void LoadGame(const FString &Name);

    UFUNCTION(BlueprintPure)
    bool IsTerrainToolCreativeMenuBlocked() const;

    UFUNCTION(BlueprintPure)
    bool IsMultiplayerDisabled() const;

    UFUNCTION(BlueprintPure)
    bool IsMainController();

    UFUNCTION(BlueprintPure)
    bool IsHelpMenuVisible() const;

    UFUNCTION(BlueprintPure)
    bool IsEscapeMenuVisible() const;

    UFUNCTION(BlueprintPure)
    bool IsControllerJoined() const;

    UFUNCTION(BlueprintPure)
    bool IsConnectionClosing() const;

    UFUNCTION()
    void IncrementAchievementProgress(const FCountAchievement &AchievementDef, int32 AddedProgress);

    UFUNCTION()
    void IncrementAchievementFloatProgress(const FFloatCountAchievement &AchievementDef, float AddedProgress);

    UFUNCTION(Exec)
    void HidePlayerNames(bool hide);

    UFUNCTION(Exec)
    void HideBeacons(bool hide);

    UFUNCTION(BlueprintCallable)
    bool HasAdminAccess();

    UFUNCTION(Exec)
    void GrantAllUnlocks();

    UFUNCTION(Exec)
    void GrantAchievement(const FString &AchievementName);

    UFUNCTION(BlueprintPure)
    bool GetIsReturningPlayer() const;

    UFUNCTION(Exec)
    bool GameFullyLoaded();

    UFUNCTION(Exec)
    void ForceStartGame();

    UFUNCTION(Exec)
    void ForceCrash();

    UFUNCTION()
    void FlushPendingAchievementsAndUnlocks();

    UFUNCTION(Exec)
    void EndNetworkSession();

    UFUNCTION(Exec)
    void DumpMeshSummary();

    UFUNCTION(Exec)
    void DumpMeshMemory();

    UFUNCTION(Exec)
    void DumpActorDataTXT();

    UFUNCTION(Exec)
    void DumpActorDataCSV();

    UFUNCTION(Exec)
    void DropNextNetDeformations(uint32 Count);

    UFUNCTION(Exec)
    void DeleteSaveGame(const FString &Name);

    UFUNCTION(Exec)
    void DeleteAllAutoSaves();

    UFUNCTION(BlueprintCallable)
    void DeferredDisableEscapeMenu();

    UFUNCTION(Exec)
    void DebugTeleportCoord(FVector Location);

    UFUNCTION(Exec)
    void DebugTeleport(const FString &Name, bool safe);

    UFUNCTION(Client, Reliable)
    void ClientVoxelJIPComplete();

    UFUNCTION(Client, Reliable)
    void ClientUnPossess(AAstroCharacter *oldCharacter);

private:
    UFUNCTION(Client, Unreliable)
    void ClientTerrainValidateChecksumsT2(UVoxelVolumeComponent *voxelVolume, const TArray<FTerrainNodeNetChecksum> &checksums);

public:
    UFUNCTION(Client, Reliable)
    void ClientStartChunkedTransmission(uint32 transmissionID, uint8 dataType, uint32 chunkCount, uint32 uncompressedSize, UObject *keyObject);

    UFUNCTION(Client, Reliable)
    void ClientSetSaveGameIntervalResponse(bool success, const FString &Message);

    UFUNCTION(Client, Reliable)
    void ClientSetPropertiesResponse(const FAstroClientProperties &clientCapabilities);

    UFUNCTION(Client, Reliable)
    void ClientSetPasswordResponse(bool success);

    UFUNCTION(Client, Reliable)
    void ClientSetOxygenFreeCreativeResponse(bool success, bool Enable);

    UFUNCTION(Client, Reliable)
    void ClientSetInvisibleToHazardsCreativeResponse(bool success, bool Enable);

    UFUNCTION(Client, Reliable)
    void ClientSetInvincibleCreativeResponse(bool success, bool Enable);

    UFUNCTION(Client, Reliable)
    void ClientSetFuelFreeCreativeResponse(bool success, bool Enable);

    UFUNCTION(Client, Reliable)
    void ClientSetDenyUnlistedResponse(bool success, const FString &Message);

    UFUNCTION(Client, Reliable)
    void ClientSetBackupSaveGamesIntervalResponse(bool success, const FString &Message);

    UFUNCTION(Client, Reliable)
    void ClientSetBackpackPowerUnlimitedCreativeResponse(bool success, bool Enable);

    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetAstroViewTarget(AActor *ViewTarget);

    UFUNCTION(Client, Reliable)
    void ClientSetActivityTimeoutResponse(bool success);

    UFUNCTION(Client, Reliable)
    void ClientServerStatisticsResponse(const FServerStatistics &ServerStatistics);

    UFUNCTION(Client, Reliable)
    void ClientSaveGameResponse(bool success, const FString &Name);

    UFUNCTION(Client, Reliable)
    void ClientRequestFoliageDestruction(AActor *DestructionInstigator, FVector_NetQuantize100 Location, float Radius, float MassThreshold, bool bShouldCollectResourceNuggets);

    UFUNCTION(Client, Reliable)
    void ClientRenameGameResponse(bool copySuccess, bool removeSuccess, const FString &fromName, const FString &toName);

    UFUNCTION(Client, Reliable)
    void ClientRecvPlayerState(const FInitialClientStateParams &params);

    UFUNCTION(Client, Reliable)
    void ClientRecvPlanetSeeds(const TArray<AAstroPlanet *> &Planets, const TArray<int32> &seeds, const TArray<FVector> &Offsets);

    UFUNCTION(Client, Reliable)
    void ClientRecvPlanetMaterials(AAstroPlanet *Planet, const TArray<FPackedVoxelMaterialInfo> &Materials);

    UFUNCTION(Client, Unreliable)
    void ClientRecvChunkedDataCompletionSignal(uint32 transmissionID);

    UFUNCTION(Client, Unreliable)
    void ClientRecvChunkedData(uint32 transmissionID, int32 chunkIndex, const TArray<int8> &Data, UObject *keyObject);

    UFUNCTION(Client, Reliable)
    void ClientNoInitialPlanetSignal();

    UFUNCTION(Client, Reliable)
    void ClientNewGameResponse(bool success, const FString &Name);

    UFUNCTION(Client, Reliable)
    void ClientLoadGameResponse(bool success, const FString &Name);

    UFUNCTION(Client, Reliable)
    void ClientListPlayersResponse(const FPlayerList &PlayerList);

    UFUNCTION(Client, Reliable)
    void ClientListGamesResponse(const FGameList &GameList);

    UFUNCTION(Client, Reliable)
    void ClientKickPlayerResponse(bool success);

    UFUNCTION(Client, Reliable)
    void ClientGrantItems(const TArray<FString> &ItemIds);

    UFUNCTION(Client, Reliable)
    void ClientGetPropertiesResponse(const FAstroClientProperties &clientCapabilities);

protected:
    UFUNCTION(Client, Reliable, WithValidation)
    void ClientFlushPendingUnlocks(const TArray<FString> &serverPendingUnlocks);

public:
    UFUNCTION(Client, Reliable)
    void ClientEnqueueNotification(const FAstroNotificationTagAuthoringData &AuthoringData);

    UFUNCTION(Client, Reliable)
    void ClientDoDeformation(FDeformationParamsT2 params);

    UFUNCTION(Client, Reliable)
    void ClientDeleteGameResponse(bool success, const FString &Name);

    UFUNCTION(Client, Reliable)
    void ClientCreativeModeResponse(bool success, bool Enable);

    UFUNCTION(Client, Reliable, WithValidation)
    void ClientCreateProxySession(FGuid sessionGUID);

private:
    UFUNCTION(Client, Reliable)
    void ClientBeginAuthHandshake(const FString &LobbyId);

public:
    UFUNCTION(Client, Reliable)
    void ClientBackupSaveGamesResponse(bool success);

    UFUNCTION(Client, Reliable)
    void ClientAwardAchievement(const EAstroAchievementKeys AchievementKey);

private:
    UFUNCTION(Client, Reliable)
    void ClientAuthComplete(bool bSuccess);

public:

    UFUNCTION(Exec)
    void ClearDebugLocations();

    UFUNCTION()
    void AwardAchievementOffline(const FString &AchievementName);

    UFUNCTION(BlueprintCallable)
    void AttemptEnableMultiplayer();

    UFUNCTION(BlueprintCallable)
    void AdminSetPropertiesForPlayer(const FString &PlayerGuid, const FAstroClientProperties &clientCapabilities);

    UFUNCTION(BlueprintCallable)
    void AdminKickPlayer(const FString &PlayerGuid);

    UFUNCTION(Exec)
    void AddDebugLocation(const FString &Name);

    UFUNCTION()
    void AddAchievementCollectionItem(const FItemCollectionAchievement &AchievementDef, TSubclassOf<UItemType> Item);
};
