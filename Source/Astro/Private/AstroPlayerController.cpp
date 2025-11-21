#include "AstroPlayerController.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

AAstroPlayerController::AAstroPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAttachToPawn = true;
    this->ClickEventKeys.AddDefaulted(1);
    this->EnableEscapeMenuToggle = true;
    this->CurrentHelpMenu = NULL;
    this->FireworksAchievementLaunchCountKey = TEXT("LaunchCount");
    this->FireworksAchievementLaunchWindowKey = TEXT("LaunchWindow");
    this->ControlledVehicle = NULL;
    this->PersistentLocalData = NULL;
    this->HasGlitchwalkersEntitlement = false;
    this->MotionBlurQuality = 4;
    this->CurrentDebugMenu = NULL;
}

void AAstroPlayerController::WouldCompleteCollection_RespondToServer_Implementation(bool response, int32 RequestId) {
}
bool AAstroPlayerController::WouldCompleteCollection_RespondToServer_Validate(bool response, int32 RequestId) {
    return true;
}

void AAstroPlayerController::WouldCompleteCollection_RequestFromClient_Implementation(EAstroAchievementKeys collectionAchievement, TSubclassOf<UItemType> newCollectionItem, int32 RequestId) {
}
bool AAstroPlayerController::WouldCompleteCollection_RequestFromClient_Validate(EAstroAchievementKeys collectionAchievement, TSubclassOf<UItemType> newCollectionItem, int32 RequestId) {
    return true;
}

void AAstroPlayerController::VoxelGenAuditToggleDebugMarkers(const FString& Name) {
}

void AAstroPlayerController::VoxelGenAuditStop() {
}

void AAstroPlayerController::VoxelGenAuditStart(const int8 maxDepth) {
}

void AAstroPlayerController::VoxelGenAuditDumpOutput(uint8 writeToFiles) {
}

void AAstroPlayerController::TravelToDedicatedServerByURL(const FString& ServerURL, const FString& Password, const FDSTravelInitiatedDelegate& TravelInitiated) {
}

void AAstroPlayerController::TrackFireworkLaunchedForAchievementProgress() {
}

void AAstroPlayerController::ToggleProxyVisibility() {
}

void AAstroPlayerController::ToggleEscapeMenu() {
}

void AAstroPlayerController::ToggleAstropediaMenu() {
}

void AAstroPlayerController::TestSwitchProfilesPopup() {
}

void AAstroPlayerController::TestPurchase() {
}

void AAstroPlayerController::TestMountEncryptedPak() {
}

void AAstroPlayerController::TestListStoreItems() {
}

void AAstroPlayerController::TestListCatalogItems() {
}

void AAstroPlayerController::TestGetPrices() {
}

void AAstroPlayerController::TestDumpDSSessionMembership() {
}

void AAstroPlayerController::TestDumpDSProxyState() {
}

void AAstroPlayerController::T2Raycast(float Distance) {
}

void AAstroPlayerController::StartNetworkSession() {
}

void AAstroPlayerController::SetSolarTime(double Time) {
}

void AAstroPlayerController::SetMotionBlurEnabled(bool Enable) {
}

void AAstroPlayerController::SetItemForInitialSelection(APhysicalItem* Item) {
}

void AAstroPlayerController::ServerUseActor_Implementation(AActor* Actor, FName Action, EInputEvent KeyEvent, EUseType useType) {
}
bool AAstroPlayerController::ServerUseActor_Validate(AActor* Actor, FName Action, EInputEvent KeyEvent, EUseType useType) {
    return true;
}

void AAstroPlayerController::ServerSyncPlayfabBackendID_Implementation(const FString& BackendPlayerId) {
}
bool AAstroPlayerController::ServerSyncPlayfabBackendID_Validate(const FString& BackendPlayerId) {
    return true;
}

void AAstroPlayerController::ServerSyncOneTimeTooltipSystemState_Implementation() {
}

void AAstroPlayerController::ServerStartPrint_Implementation(UPrinterComponent* Component) {
}
bool AAstroPlayerController::ServerStartPrint_Validate(UPrinterComponent* Component) {
    return true;
}

void AAstroPlayerController::ServerSetSolarTimeScaleMultiplierCreative_Implementation(float Scale) {
}
bool AAstroPlayerController::ServerSetSolarTimeScaleMultiplierCreative_Validate(float Scale) {
    return true;
}

void AAstroPlayerController::ServerSetPlayerOwnsMegaTech_Implementation(bool ownsMegatech) {
}

void AAstroPlayerController::ServerSetPlayerOwnsGlitchwalkers_Implementation(bool ownsGlitchWalkers) {
}

void AAstroPlayerController::ServerSetNormalizedTimeOfDayCreative_Implementation(float Scale) {
}
bool AAstroPlayerController::ServerSetNormalizedTimeOfDayCreative_Validate(float Scale) {
    return true;
}

void AAstroPlayerController::ServerSetNormalizedSunOrbitCreative_Implementation(float normalizedSunOrbit) {
}
bool AAstroPlayerController::ServerSetNormalizedSunOrbitCreative_Validate(float normalizedSunOrbit) {
    return true;
}

void AAstroPlayerController::ServerSetCharacterCustomization_Implementation(const FAstroCharacterCustomization& Customization) {
}
bool AAstroPlayerController::ServerSetCharacterCustomization_Validate(const FAstroCharacterCustomization& Customization) {
    return true;
}

void AAstroPlayerController::ServerResetGameStateAchievementProgress_Implementation() {
}
bool AAstroPlayerController::ServerResetGameStateAchievementProgress_Validate() {
    return true;
}

void AAstroPlayerController::ServerRequestUnlockItem_Implementation(TSubclassOf<UItemType> ItemTypeToUnlock, bool bAllowPlayFabBinding) {
}
bool AAstroPlayerController::ServerRequestUnlockItem_Validate(TSubclassOf<UItemType> ItemTypeToUnlock, bool bAllowPlayFabBinding) {
    return true;
}

void AAstroPlayerController::ServerRequestTerrainCorrection_Implementation(UVoxelVolumeComponent* voxelVolume, const TArray<uint64>& Nodes) {
}
bool AAstroPlayerController::ServerRequestTerrainCorrection_Validate(UVoxelVolumeComponent* voxelVolume, const TArray<uint64>& Nodes) {
    return true;
}

void AAstroPlayerController::ServerRequestOrbitalPlatformSeed_Implementation() {
}

void AAstroPlayerController::ServerRequestFoliageDestruction_Implementation(AActor* DestructionInstigator, FVector_NetQuantize100 Location, float Radius, float MassThreshold, bool bShouldCollectResourceNuggets) {
}
bool AAstroPlayerController::ServerRequestFoliageDestruction_Validate(AActor* DestructionInstigator, FVector_NetQuantize100 Location, float Radius, float MassThreshold, bool bShouldCollectResourceNuggets) {
    return true;
}

void AAstroPlayerController::ServerRemoveDebugLocation_Implementation(const FString& Name) {
}

void AAstroPlayerController::ServerRemote_Implementation(const FString& consoleCommand) {
}
bool AAstroPlayerController::ServerRemote_Validate(const FString& consoleCommand) {
    return true;
}

void AAstroPlayerController::ServerRedeemPlayerTicket_Implementation(const FString& Ticket) {
}
bool AAstroPlayerController::ServerRedeemPlayerTicket_Validate(const FString& Ticket) {
    return true;
}

void AAstroPlayerController::ServerPointItem_Implementation(TSubclassOf<UItemType> ItemType, TSubclassOf<UControlSymbol> PingSymbol, const FVector& Location, const FVector_NetQuantizeNormal& Normal) {
}
bool AAstroPlayerController::ServerPointItem_Validate(TSubclassOf<UItemType> ItemType, TSubclassOf<UControlSymbol> PingSymbol, const FVector& Location, const FVector_NetQuantizeNormal& Normal) {
    return true;
}

void AAstroPlayerController::ServerNotifyJoinMenuComplete_Implementation() {
}
bool AAstroPlayerController::ServerNotifyJoinMenuComplete_Validate() {
    return true;
}

void AAstroPlayerController::ServerNotifyClientFullyJoined_Implementation() {
}
bool AAstroPlayerController::ServerNotifyClientFullyJoined_Validate() {
    return true;
}

void AAstroPlayerController::ServerNakDataChunk_Implementation(uint32 transmissionID, uint32 missingChunkStart, uint32 missingChunkCount) {
}
bool AAstroPlayerController::ServerNakDataChunk_Validate(uint32 transmissionID, uint32 missingChunkStart, uint32 missingChunkCount) {
    return true;
}

void AAstroPlayerController::ServerIncrementPrinterBlueprintRow_Implementation(UPrinterComponent* Component, int32 increment) {
}
bool AAstroPlayerController::ServerIncrementPrinterBlueprintRow_Validate(UPrinterComponent* Component, int32 increment) {
    return true;
}

void AAstroPlayerController::ServerIncrementPrinterBlueprint_Implementation(UPrinterComponent* Component, int32 increment) {
}
bool AAstroPlayerController::ServerIncrementPrinterBlueprint_Validate(UPrinterComponent* Component, int32 increment) {
    return true;
}

void AAstroPlayerController::ServerGetServerStatistics_Implementation() {
}
bool AAstroPlayerController::ServerGetServerStatistics_Validate() {
    return true;
}

void AAstroPlayerController::ServerFlushPendingUnlocks_Implementation() {
}
bool AAstroPlayerController::ServerFlushPendingUnlocks_Validate() {
    return true;
}

void AAstroPlayerController::ServerFlushPendingAchievements_Implementation() {
}
bool AAstroPlayerController::ServerFlushPendingAchievements_Validate() {
    return true;
}

void AAstroPlayerController::ServerDumpProxyState_Implementation() {
}
bool AAstroPlayerController::ServerDumpProxyState_Validate() {
    return true;
}

void AAstroPlayerController::ServerDoDeformation_Implementation(FDeformationParamsT2 params) {
}
bool AAstroPlayerController::ServerDoDeformation_Validate(FDeformationParamsT2 params) {
    return true;
}

void AAstroPlayerController::ServerDoControlSystemInput_Implementation(FVector_NetQuantize10 Input, FVector_NetQuantizeNormal cameraForward) {
}
bool AAstroPlayerController::ServerDoControlSystemInput_Validate(FVector_NetQuantize10 Input, FVector_NetQuantizeNormal cameraForward) {
    return true;
}

void AAstroPlayerController::ServerCreateProxySessionResult_Implementation(FGuid sessionGUID, bool success) {
}
bool AAstroPlayerController::ServerCreateProxySessionResult_Validate(FGuid sessionGUID, bool success) {
    return true;
}

void AAstroPlayerController::ServerClickSlotIndicator_Implementation(FSlotReference Slot, TSubclassOf<UItemType> Type) {
}
bool AAstroPlayerController::ServerClickSlotIndicator_Validate(FSlotReference Slot, TSubclassOf<UItemType> Type) {
    return true;
}

void AAstroPlayerController::ServerClickSlot_Implementation(FSlotReference Slot) {
}
bool AAstroPlayerController::ServerClickSlot_Validate(FSlotReference Slot) {
    return true;
}

void AAstroPlayerController::ServerClickActor_Implementation(AActor* Actor, FTransform CameraTransform) {
}
bool AAstroPlayerController::ServerClickActor_Validate(AActor* Actor, FTransform CameraTransform) {
    return true;
}

void AAstroPlayerController::ServerClick_Implementation(UPrimitiveComponent* Primitive, FTransform CameraTransform) {
}
bool AAstroPlayerController::ServerClick_Validate(UPrimitiveComponent* Primitive, FTransform CameraTransform) {
    return true;
}

void AAstroPlayerController::ServerClearStormEffects_Implementation() {
}

void AAstroPlayerController::ServerClearStatusModifiers_Implementation() {
}

void AAstroPlayerController::ServerClearDebugLocations_Implementation() {
}

void AAstroPlayerController::ServerCancelPrint_Implementation(UPrinterComponent* Component) {
}
bool AAstroPlayerController::ServerCancelPrint_Validate(UPrinterComponent* Component) {
    return true;
}

void AAstroPlayerController::ServerAuxOverrideUseItem_Implementation(APhysicalItem* Item, EInputEvent InputEvent) {
}
bool AAstroPlayerController::ServerAuxOverrideUseItem_Validate(APhysicalItem* Item, EInputEvent InputEvent) {
    return true;
}

void AAstroPlayerController::ServerAdminSetSaveGameInterval_Implementation(const FString& Seconds) {
}
bool AAstroPlayerController::ServerAdminSetSaveGameInterval_Validate(const FString& Seconds) {
    return true;
}

void AAstroPlayerController::ServerAdminSetProperties_Implementation(uint64 PlayerGuid, const FAstroClientProperties& clientCapabilities, const FAstroClientProperties& Mask) {
}
bool AAstroPlayerController::ServerAdminSetProperties_Validate(uint64 PlayerGuid, const FAstroClientProperties& clientCapabilities, const FAstroClientProperties& Mask) {
    return true;
}

void AAstroPlayerController::ServerAdminSetPassword_Implementation(const FString& Password) {
}
bool AAstroPlayerController::ServerAdminSetPassword_Validate(const FString& Password) {
    return true;
}

void AAstroPlayerController::ServerAdminSetOxygenFreeCreative_Implementation(bool Enable) {
}
bool AAstroPlayerController::ServerAdminSetOxygenFreeCreative_Validate(bool Enable) {
    return true;
}

void AAstroPlayerController::ServerAdminSetInvisibleToHazardsCreative_Implementation(bool Enable) {
}
bool AAstroPlayerController::ServerAdminSetInvisibleToHazardsCreative_Validate(bool Enable) {
    return true;
}

void AAstroPlayerController::ServerAdminSetInvincibleCreative_Implementation(bool Enable) {
}
bool AAstroPlayerController::ServerAdminSetInvincibleCreative_Validate(bool Enable) {
    return true;
}

void AAstroPlayerController::ServerAdminSetFuelFreeCreative_Implementation(bool Enable) {
}
bool AAstroPlayerController::ServerAdminSetFuelFreeCreative_Validate(bool Enable) {
    return true;
}

void AAstroPlayerController::ServerAdminSetDenyUnlisted_Implementation(const FString& Enable) {
}
bool AAstroPlayerController::ServerAdminSetDenyUnlisted_Validate(const FString& Enable) {
    return true;
}

void AAstroPlayerController::ServerAdminSetCategoryForPlayerName_Implementation(const FString& PlayerName, EPlayerCategory PlayerCategory) {
}
bool AAstroPlayerController::ServerAdminSetCategoryForPlayerName_Validate(const FString& PlayerName, EPlayerCategory PlayerCategory) {
    return true;
}

void AAstroPlayerController::ServerAdminSetBackupSaveGamesInterval_Implementation(const FString& Seconds) {
}
bool AAstroPlayerController::ServerAdminSetBackupSaveGamesInterval_Validate(const FString& Seconds) {
    return true;
}

void AAstroPlayerController::ServerAdminSetBackpackPowerUnlimitedCreative_Implementation(bool Enable) {
}
bool AAstroPlayerController::ServerAdminSetBackpackPowerUnlimitedCreative_Validate(bool Enable) {
    return true;
}

void AAstroPlayerController::ServerAdminSetActivityTimeout_Implementation(const FString& Seconds) {
}
bool AAstroPlayerController::ServerAdminSetActivityTimeout_Validate(const FString& Seconds) {
    return true;
}

void AAstroPlayerController::ServerAdminServerShutdown_Implementation() {
}
bool AAstroPlayerController::ServerAdminServerShutdown_Validate() {
    return true;
}

void AAstroPlayerController::ServerAdminSaveGame_Implementation(const FString& Name) {
}
bool AAstroPlayerController::ServerAdminSaveGame_Validate(const FString& Name) {
    return true;
}

void AAstroPlayerController::ServerAdminRenameGame_Implementation(const FString& fromName, const FString& toName) {
}
bool AAstroPlayerController::ServerAdminRenameGame_Validate(const FString& fromName, const FString& toName) {
    return true;
}

void AAstroPlayerController::ServerAdminNewGame_Implementation(const FString& Name, bool newGlitchWalkersGame) {
}
bool AAstroPlayerController::ServerAdminNewGame_Validate(const FString& Name, bool newGlitchWalkersGame) {
    return true;
}

//void AAstroPlayerController::ServerAdminNewCustomGame_Implementation(const FAstroCGMLibraryConfigEntryMetaData& MetaData) {
//}
//bool AAstroPlayerController::ServerAdminNewCustomGame_Validate(const FAstroCGMLibraryConfigEntryMetaData& MetaData) {
//    return true;
//}

void AAstroPlayerController::ServerAdminLoadGame_Implementation(const FString& Name) {
}
bool AAstroPlayerController::ServerAdminLoadGame_Validate(const FString& Name) {
    return true;
}

void AAstroPlayerController::ServerAdminListPlayers_Implementation() {
}
bool AAstroPlayerController::ServerAdminListPlayers_Validate() {
    return true;
}

void AAstroPlayerController::ServerAdminListGames_Implementation() {
}
bool AAstroPlayerController::ServerAdminListGames_Validate() {
    return true;
}

void AAstroPlayerController::ServerAdminKickPlayer_Implementation(uint64 PlayerGuid) {
}
bool AAstroPlayerController::ServerAdminKickPlayer_Validate(uint64 PlayerGuid) {
    return true;
}

void AAstroPlayerController::ServerAdminGetProperties_Implementation() {
}
bool AAstroPlayerController::ServerAdminGetProperties_Validate() {
    return true;
}

void AAstroPlayerController::ServerAdminDeleteGame_Implementation(const FString& Name) {
}
bool AAstroPlayerController::ServerAdminDeleteGame_Validate(const FString& Name) {
    return true;
}

void AAstroPlayerController::ServerAdminCreativeMode_Implementation(bool Enable) {
}
bool AAstroPlayerController::ServerAdminCreativeMode_Validate(bool Enable) {
    return true;
}

void AAstroPlayerController::ServerAdminBackupSaveGames_Implementation() {
}
bool AAstroPlayerController::ServerAdminBackupSaveGames_Validate() {
    return true;
}

void AAstroPlayerController::ServerAddProxySessionReservationResult_Implementation(FGuid sessionGUID, const TArray<FString>& userIdsToAdd, bool success) {
}
bool AAstroPlayerController::ServerAddProxySessionReservationResult_Validate(FGuid sessionGUID, const TArray<FString>& userIdsToAdd, bool success) {
    return true;
}

void AAstroPlayerController::ServerAddDebugLocation_Implementation(const FString& Name, FVector Location, FQuat Rotation) {
}

void AAstroPlayerController::ServerActuatorOverrideUseItem_Implementation(APhysicalItem* Item, EInputEvent InputEvent) {
}
bool AAstroPlayerController::ServerActuatorOverrideUseItem_Validate(APhysicalItem* Item, EInputEvent InputEvent) {
    return true;
}

void AAstroPlayerController::ServerAckChunkedDataFinished_Implementation(uint32 transmissionID) {
}
bool AAstroPlayerController::ServerAckChunkedDataFinished_Validate(uint32 transmissionID) {
    return true;
}

void AAstroPlayerController::SaveGameAsAsset(const FString& Name) {
}

void AAstroPlayerController::SaveGame(const FString& Name) {
}

void AAstroPlayerController::ResetPersistentLocalPlayerData() {
}

void AAstroPlayerController::ResetInactivePlayerTimeout() {
}

void AAstroPlayerController::ResetAllUnlocks() {
}

void AAstroPlayerController::ResetAllAchievements() {
}

void AAstroPlayerController::ReportAchievementProgress(const EAstroAchievementKeys AchievementKey, float Progress, float NeededCount) {
}

void AAstroPlayerController::RemoveDebugLocation(const FString& Name) {
}

void AAstroPlayerController::RebuildNodeWithLoggingBM(const FString& locationCode) {
}

void AAstroPlayerController::RebuildNodeWithLogging(const FString& locationCode) {
}

void AAstroPlayerController::PushPendingItemUnlock(const FString& itemUnlock) {
}

void AAstroPlayerController::PublishCGMConfigFromGameState() {
}

void AAstroPlayerController::PrintDebugLocations() {
}

void AAstroPlayerController::PersistCharacterCustomization() {
}

void AAstroPlayerController::OnRep_AchievementProgress() {
}

void AAstroPlayerController::OnPersistentLocalPlayerDataSaveCooldownExpired() {
}

void AAstroPlayerController::OnPersistentLocalPlayerDataDirtied() {
}

void AAstroPlayerController::OnInactivePlayerTimeout() {
}

void AAstroPlayerController::OnClientTitleMenuComplete() {
}

void AAstroPlayerController::OnClientLoadingScreenComplete() {
}

void AAstroPlayerController::LogTerrainDataForNode(const FString& locationCode) {
}

void AAstroPlayerController::LoadSeamless(const FString& FURL) {
}

void AAstroPlayerController::LoadGameFromAsset(const FString& Name) {
}

void AAstroPlayerController::LoadGame(const FString& Name) {
}

bool AAstroPlayerController::IsTerrainToolCreativeMenuBlocked() const {
    return false;
}

bool AAstroPlayerController::IsMultiplayerDisabled() const {
    return false;
}

bool AAstroPlayerController::IsMainController() {
    return false;
}

bool AAstroPlayerController::IsHelpMenuVisible() const {
    return false;
}

bool AAstroPlayerController::IsEscapeMenuVisible() const {
    return false;
}

bool AAstroPlayerController::IsControllerJoined() const {
    return false;
}

bool AAstroPlayerController::IsConnectionClosing() const {
    return false;
}

void AAstroPlayerController::IncrementAchievementProgress(const FCountAchievement& AchievementDef, int32 AddedProgress) {
}

void AAstroPlayerController::IncrementAchievementFloatProgress(const FFloatCountAchievement& AchievementDef, float AddedProgress) {
}

void AAstroPlayerController::HidePlayerNames(bool hide) {
}

void AAstroPlayerController::HideBeacons(bool hide) {
}

bool AAstroPlayerController::HasAdminAccess() {
    return false;
}

void AAstroPlayerController::GrantAllUnlocks() {
}

void AAstroPlayerController::GrantAchievement(const FString& AchievementName) {
}

float AAstroPlayerController::GetStatusModifierValue(EStatusModifierType statusModifierType) {
    return 0.0f;
}

bool AAstroPlayerController::GetIsReturningPlayer() const {
    return false;
}

bool AAstroPlayerController::GameFullyLoaded() {
    return false;
}

void AAstroPlayerController::ForceStartGame() {
}

void AAstroPlayerController::ForceCrash() {
}

void AAstroPlayerController::FlushPendingAchievementsAndUnlocks() {
}

void AAstroPlayerController::EndNetworkSession() {
}

void AAstroPlayerController::DumpMeshSummary() {
}

void AAstroPlayerController::DumpMeshMemory() {
}

void AAstroPlayerController::DumpActorDataTXT() {
}

void AAstroPlayerController::DumpActorDataCSV() {
}

void AAstroPlayerController::DropNextNetDeformations(uint32 Count) {
}

void AAstroPlayerController::DeleteSaveGame(const FString& Name) {
}

void AAstroPlayerController::DeleteAllAutoSaves() {
}

void AAstroPlayerController::DeferredDisableEscapeMenu() {
}

void AAstroPlayerController::DebugTeleportCoord(FVector Location) {
}

void AAstroPlayerController::DebugTeleport(const FString& Name, bool safe) {
}

void AAstroPlayerController::ClientVoxelJIPComplete_Implementation() {
}

void AAstroPlayerController::ClientUnPossess_Implementation(AAstroCharacter* oldCharacter) {
}

void AAstroPlayerController::ClientTerrainValidateChecksumsT2_Implementation(UVoxelVolumeComponent* voxelVolume, const TArray<FTerrainNodeNetChecksum>& checksums) {
}

void AAstroPlayerController::ClientSyncStateFromServer_Implementation(const FAstroCustomGameState& customGameState) {
}

void AAstroPlayerController::ClientSyncSettingsFromServer_Implementation(const bool IsCustomGame, const FAstroCustomGameSettings& CustomGameSettings, const FAstroCustomGameState& customGameState, const TArray<ASolarBody*>& solarBodies, const TArray<FVector>& planetOffsets) {
}

void AAstroPlayerController::ClientSyncOneTimeTooltipSystemState_Implementation(const FAstroOneTimeTooltipState& stateToSync) {
}

void AAstroPlayerController::ClientStartChunkedTransmission_Implementation(uint32 transmissionID, uint8 dataType, uint32 chunkCount, uint32 uncompressedSize, UObject* keyObject) {
}

void AAstroPlayerController::ClientSetSaveGameIntervalResponse_Implementation(bool success, const FString& Message) {
}

void AAstroPlayerController::ClientSetPropertiesResponse_Implementation(const FAstroClientProperties& clientCapabilities) {
}

void AAstroPlayerController::ClientSetPasswordResponse_Implementation(bool success) {
}

void AAstroPlayerController::ClientSetOxygenFreeCreativeResponse_Implementation(bool success, bool Enable) {
}

void AAstroPlayerController::ClientSetInvisibleToHazardsCreativeResponse_Implementation(bool success, bool Enable) {
}

void AAstroPlayerController::ClientSetInvincibleCreativeResponse_Implementation(bool success, bool Enable) {
}

void AAstroPlayerController::ClientSetFuelFreeCreativeResponse_Implementation(bool success, bool Enable) {
}

void AAstroPlayerController::ClientSetDenyUnlistedResponse_Implementation(bool success, const FString& Message) {
}

void AAstroPlayerController::ClientSetBackupSaveGamesIntervalResponse_Implementation(bool success, const FString& Message) {
}

void AAstroPlayerController::ClientSetBackpackPowerUnlimitedCreativeResponse_Implementation(bool success, bool Enable) {
}

void AAstroPlayerController::ClientSetAstroViewTarget_Implementation(AActor* ViewTarget) {
}

void AAstroPlayerController::ClientSetActivityTimeoutResponse_Implementation(bool success) {
}

void AAstroPlayerController::ClientServerStatisticsResponse_Implementation(const FServerStatistics& ServerStatistics) {
}

void AAstroPlayerController::ClientSaveGameResponse_Implementation(bool success, const FString& Name) {
}

void AAstroPlayerController::ClientRequestFoliageDestruction_Implementation(AActor* DestructionInstigator, FVector_NetQuantize100 Location, float Radius, float MassThreshold, bool bShouldCollectResourceNuggets) {
}

void AAstroPlayerController::ClientRenameGameResponse_Implementation(bool copySuccess, bool removeSuccess, const FString& fromName, const FString& toName) {
}

void AAstroPlayerController::ClientRecvSeeds_Implementation(const TArray<ASolarBody*>& solarBodies, const TArray<int32>& seeds, const TArray<FVector>& Offsets) {
}

void AAstroPlayerController::ClientRecvPlayerState_Implementation(const FInitialClientStateParams& params) {
}

void AAstroPlayerController::ClientRecvPlanetMaterials_Implementation(ASolarBody* Planet, const TArray<FPackedVoxelMaterialInfo>& Materials, const FVector& InLocation) {
}

void AAstroPlayerController::ClientRecvOrbitalPlatformSeed_Implementation(const int32 Seed) {
}

void AAstroPlayerController::ClientRecvChunkedDataCompletionSignal_Implementation(uint32 transmissionID) {
}

void AAstroPlayerController::ClientRecvChunkedData_Implementation(uint32 transmissionID, int32 chunkIndex, const TArray<int8>& Data, UObject* keyObject) {
}

//void AAstroPlayerController::ClientRecordPlayerEventWithCallback_Implementation(const FString& EventName, const TArray<FAnalyticsEventAttr>& Attributes) {
//}

//void AAstroPlayerController::ClientRecordPlayerEvent_Implementation(const FString& EventName, const TArray<FAnalyticsEventAttr>& Attributes) {
//}

void AAstroPlayerController::ClientNotifyPlayerMadeLandfall_Implementation(const FText& PlayerName, EPlanetIdentifier planetID) {
}

void AAstroPlayerController::ClientNotifyPlayerLeftSession_Implementation(const FText& PlayerName) {
}

void AAstroPlayerController::ClientNotifyPlayerJoinedSession_Implementation(const FText& PlayerName) {
}

void AAstroPlayerController::ClientNoInitialPlanetSignal_Implementation() {
}

void AAstroPlayerController::ClientNewGameResponse_Implementation(bool success, const FString& Name) {
}

void AAstroPlayerController::ClientLoadGameResponse_Implementation(bool success, const FString& Name) {
}

void AAstroPlayerController::ClientListPlayersResponse_Implementation(const FPlayerList& PlayerList) {
}

void AAstroPlayerController::ClientListGamesResponse_Implementation(const FGameList& GameList) {
}

void AAstroPlayerController::ClientKickPlayerResponse_Implementation(bool success) {
}

void AAstroPlayerController::ClientJoinedDedicatedServer_Implementation() {
}

void AAstroPlayerController::ClientGrantItems_Implementation(const TArray<FString>& ItemIds) {
}

void AAstroPlayerController::ClientGetPropertiesResponse_Implementation(const FAstroClientProperties& clientCapabilities) {
}

void AAstroPlayerController::ClientFlushPendingUnlocks_Implementation(const TArray<FString>& serverPendingUnlocks) {
}
bool AAstroPlayerController::ClientFlushPendingUnlocks_Validate(const TArray<FString>& serverPendingUnlocks) {
    return true;
}

void AAstroPlayerController::ClientEnqueueNotification_Implementation(const FAstroNotificationTagAuthoringData& AuthoringData) {
}

void AAstroPlayerController::ClientDoDeformation_Implementation(FDeformationParamsT2 params) {
}

void AAstroPlayerController::ClientDeleteGameResponse_Implementation(bool success, const FString& Name) {
}

void AAstroPlayerController::ClientCreativeModeResponse_Implementation(bool success, bool Enable) {
}

void AAstroPlayerController::ClientCreateProxySession_Implementation(FGuid sessionGUID) {
}
bool AAstroPlayerController::ClientCreateProxySession_Validate(FGuid sessionGUID) {
    return true;
}

void AAstroPlayerController::ClientBeginAuthHandshake_Implementation(const FString& LobbyId) {
}

void AAstroPlayerController::ClientBackupSaveGamesResponse_Implementation(bool success) {
}

void AAstroPlayerController::ClientAwardAchievement_Implementation(const EAstroAchievementKeys AchievementKey) {
}

void AAstroPlayerController::ClientAuthComplete_Implementation(bool bSuccess) {
}

void AAstroPlayerController::ClientAddProxySessionReservations_Implementation(const TArray<FString>& userIdsToAdd) {
}
bool AAstroPlayerController::ClientAddProxySessionReservations_Validate(const TArray<FString>& userIdsToAdd) {
    return true;
}

void AAstroPlayerController::ClientAddPlayFabCatalogItem_Implementation(const FString& unlockedItem) const {
}

void AAstroPlayerController::ClearDebugLocations() {
}

void AAstroPlayerController::AwardAchievementOffline(const FString& AchievementName) {
}

void AAstroPlayerController::AuthoritySetStatusModifier(EStatusModifierType statusModifierType, float _value) {
}

void AAstroPlayerController::AttemptEnableMultiplayer() {
}

void AAstroPlayerController::AdminSetPropertiesForPlayer(const FString& PlayerGuid, const FAstroClientProperties& clientCapabilities) {
}

void AAstroPlayerController::AdminKickPlayer(const FString& PlayerGuid) {
}

void AAstroPlayerController::AddDebugLocation(const FString& Name) {
}

void AAstroPlayerController::AddAchievementCollectionItem(const FItemCollectionAchievement& AchievementDef, TSubclassOf<UItemType> Item) {
}

void AAstroPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAstroPlayerController, AchievementReplicationData);
    DOREPLIFETIME(AAstroPlayerController, ControlledVehicle);
    DOREPLIFETIME(AAstroPlayerController, HasGlitchwalkersEntitlement);
    DOREPLIFETIME(AAstroPlayerController, PendingSelectionActor);
}


