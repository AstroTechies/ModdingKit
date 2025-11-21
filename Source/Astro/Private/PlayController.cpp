#include "PlayController.h"
#include "AstroNotificationManager.h"
#include "AstroPopupBadgeManager.h"
#include "AstroToastNotificationManager.h"
#include "AstroUnlockNotificationManager.h"
#include "BiomeSamplerComponent.h"
#include "Templates/SubclassOf.h"
#include "TooltipManager.h"

APlayController::APlayController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAutoManageActiveCameraTarget = false;
    this->ClickEventKeys.AddDefaulted(1);
    this->RightHandState = EHandState::HS_Empty;
    this->GrabThreshold = 0.00f;
    this->SelectionOffset = 0.00f;
    this->LastRightHandAxis = 0.00f;
    this->QuickSelectionMade = false;
    this->MouseZoomTickSize = 0.00f;
    this->MouseZoomSpeed = 0.90f;
    this->bGeometricZoom = false;
    this->ToolActiveItem = NULL;
    this->CameraMode = ECameraMode::Follow;
    this->InteractingActor = NULL;
    this->CurrentTertiary = NULL;
    this->HomeBody = NULL;
    this->PlanetarySelectionDistance = 0.00f;
    this->UsingGamepad = false;
    this->UsingKeyboardNavigation = false;
    this->UsingMouse = false;
    this->CurrentClickPrimary = true;
    this->planetSelection = false;
    this->LandSelection = false;
    this->IsVirtualCursorActive = false;
    this->bApplyQuickSelectModifier = false;
    this->bApplyUseModifier = false;
    this->VirtualCursor = NULL;
    this->FreeCamClass = NULL;
    this->FreeCamRig = NULL;
    this->CompassClass = NULL;
    this->Compass = NULL;
    this->ItemSelectorMesh = NULL;
    this->GrabbedCable = NULL;
    this->ItemSelectorMat = NULL;
    this->SlottedItemSelectorMesh = NULL;
    this->SlottedItemSelectorMat = NULL;
    this->DefaultSecondarySelectorMesh = NULL;
    this->EnableClickableIndicatorsDisplay = false;
    this->CurrentMouseZoom = 0.50f;
    this->bVirtualCursorToggleOn = false;
    this->EmoteWheelCameraMovementCooldown = 0.70f;
    this->WheelOpenHoldThreshold = 0.00f;
    this->WindGustDeltaMinIntensity = 0.20f;
    this->WindGustScalar = 1.00f;
    this->DebugWind = false;
    this->BackpackCameraContext = NULL;
    this->GameMenuPopoutCameraContext = NULL;
    this->StoreMenuCameraContext = NULL;
    this->LastSecondaryViewActor = NULL;
    this->bCreativeRemoveDecoratorsWhilePainting = true;
    this->bCreativeTerrainBrushLightActive = true;
    this->bCreativeShowLODAnchorRangeVisualization = false;
    this->bCreativeDisableCollectResourcesWhileDeforming = false;
    this->bShowCreativeDroneUI = true;
    this->HoldLabelCounter = 0;
    this->AstroNotificationManager = CreateDefaultSubobject<UAstroNotificationManager>(TEXT("AstroNotificationManager"));
    this->TooltipManager = CreateDefaultSubobject<UTooltipManager>(TEXT("TooltipManager"));
    this->AstroUnlockNotificationManger = CreateDefaultSubobject<UAstroUnlockNotificationManager>(TEXT("AstroUnlockNotificationManager"));
    this->AstroToastNotificationManger = CreateDefaultSubobject<UAstroToastNotificationManager>(TEXT("AstroToastNotificationManager"));
    this->AstroPopupBadgeManager = CreateDefaultSubobject<UAstroPopupBadgeManager>(TEXT("PopupBadgeManager"));
    this->biomeSampler = CreateDefaultSubobject<UBiomeSamplerComponent>(TEXT("biomeSampler"));
    this->BiomeEntryWeightThreshold = 0.20f;
    this->BiomeExitWeightThreshold = 0.10f;
    this->GlobalParameterCollection = NULL;
}

void APlayController::UpdateEmoteSelection(int32 Index, UAstroEmoteDefinition* Emote) {
}

void APlayController::UpdateCompass() {
}

void APlayController::UpdateClickableIndicators() {
}

void APlayController::UpdateBiomeAmbienceLocal(UBiomeSamplerComponent* NewBiomeSampler) {
}


bool APlayController::TraceCursorSpoofAtPlayerFeet(FHitResult& OutHit, TEnumAsByte<ECollisionChannel> collisionChannel, FVector traceOffset, AActor* actorToIgnore, float Distance) {
    return false;
}

bool APlayController::TraceCursor(FHitResult& OutHit, TEnumAsByte<ECollisionChannel> collisionChannel, AActor* actorToIgnore, float Distance) {
    return false;
}


void APlayController::TertiaryAction() {
}

void APlayController::TeleportToCursor() {
}

bool APlayController::TargetHasAttachParent() {
    return false;
}

bool APlayController::TargetAllowFreeCam() {
    return false;
}

void APlayController::StopJump() {
}

APhysicalItem* APlayController::SpawnActorAndAttemptPackage(UClass* ObjClass, FTransform SpawnTransform, TSubclassOf<UItemType> ItemType, bool CreativeMode, bool autoGrab) {
    return NULL;
}


bool APlayController::ShouldShowCreativeDroneUI() const {
    return false;
}

void APlayController::SetVirtualCursorToggle(bool toggleValue) {
}

void APlayController::SetUsingMouse(bool bIsUsingMouse) {
}

void APlayController::SetUsingKeyboardNavigation(bool bIsUsingKeyboardNavigation) {
}

void APlayController::SetUsingGamepad(bool IsUsingGamepad) {
}

void APlayController::SetTerrainBrushLightActive(bool TerrainBrushLightActive) {
}

void APlayController::SetSuitServerInternal_Implementation(UAstroCharacterSuit* NewSuit) {
}
bool APlayController::SetSuitServerInternal_Validate(UAstroCharacterSuit* NewSuit) {
    return true;
}

void APlayController::SetSuitServer(UAstroCharacterSuit* NewSuit) {
}

void APlayController::SetShowCreativeDoneUI(bool shouldShowDroneUI) {
}

void APlayController::SetPlayerControllerID(int32 ControllerId) {
}

void APlayController::SetMousePosition(float X, float Y) {
}

void APlayController::SetGamepadLock(bool gamepadModeLocked) {
}

void APlayController::SetFreeCam() {
}

void APlayController::SetCurrentSpawnPoint(AActor* Spawn) {
}

void APlayController::SetCreativeShowLODAnchorRangeVisualizationEnabled(bool ShowLODAnchorRange) {
}

void APlayController::SetCreativeRemoveDecoratorsWhilePaintingEnabled(bool RemoveDecoratorsWhilePainting) {
}

void APlayController::SetCreativeCollectResourcesWhileDeformingDisabled(bool DisableCollectResourcesWhileDeforming) {
}

void APlayController::SetCharacterVisorServerInternal_Implementation(UAstroVisorMaterial* NewVisorMaterial) {
}
bool APlayController::SetCharacterVisorServerInternal_Validate(UAstroVisorMaterial* NewVisorMaterial) {
    return true;
}

void APlayController::SetCharacterVisorServer(UAstroVisorMaterial* NewVisorMaterial) {
}

void APlayController::SetCharacterPaletteServerInternal_Implementation(UAstroCharacterPalette* NewPalette) {
}
bool APlayController::SetCharacterPaletteServerInternal_Validate(UAstroCharacterPalette* NewPalette) {
    return true;
}

void APlayController::SetCharacterPaletteServer(UAstroCharacterPalette* NewPalette) {
}

void APlayController::SetCharacterHatServerInternal_Implementation(UAstroCharacterHat* NewHat, ECharacterHatCategory Category) {
}
bool APlayController::SetCharacterHatServerInternal_Validate(UAstroCharacterHat* NewHat, ECharacterHatCategory Category) {
    return true;
}

void APlayController::SetCharacterHatServer(UAstroCharacterHat* NewHat, ECharacterHatCategory Category) {
}

void APlayController::SetCharacterCustomizationServerInternal_Implementation(const FAstroCharacterCustomization& NewCustomization) {
}
bool APlayController::SetCharacterCustomizationServerInternal_Validate(const FAstroCharacterCustomization& NewCustomization) {
    return true;
}

void APlayController::SetCharacterCustomizationServer(const FAstroCharacterCustomization& NewCustomization) {
}

void APlayController::SetCameraZoom(float Zoom) {
}

void APlayController::ServerUnpackAnchor_Implementation(UDeployableAnchorComponent* DeployableAnchorComponent) {
}

void APlayController::ServerSpawnResourceNuggetDebug_Implementation(UClass* ObjClass) {
}
bool APlayController::ServerSpawnResourceNuggetDebug_Validate(UClass* ObjClass) {
    return true;
}

void APlayController::ServerSpawnActorDebug_Implementation(UClass* ObjClass) {
}
bool APlayController::ServerSpawnActorDebug_Validate(UClass* ObjClass) {
    return true;
}

void APlayController::ServerSpawnActorAndAttemptPackage_Implementation(UClass* ObjClass, FTransform SpawnTransform, TSubclassOf<UItemType> ItemType, bool CreativeMode, bool autoGrab) {
}
bool APlayController::ServerSpawnActorAndAttemptPackage_Validate(UClass* ObjClass, FTransform SpawnTransform, TSubclassOf<UItemType> ItemType, bool CreativeMode, bool autoGrab) {
    return true;
}

void APlayController::ServerSpawnActor_Implementation(UClass* ObjClass, FTransform SpawnTransform) {
}
bool APlayController::ServerSpawnActor_Validate(UClass* ObjClass, FTransform SpawnTransform) {
    return true;
}

void APlayController::ServerSetToolLocation_Implementation(UControlComponent* ControlComponent, FTransform Transform) {
}
bool APlayController::ServerSetToolLocation_Validate(UControlComponent* ControlComponent, FTransform Transform) {
    return true;
}

void APlayController::ServerPlayerCharacterSelectionLaunch_Implementation() {
}
bool APlayController::ServerPlayerCharacterSelectionLaunch_Validate() {
    return true;
}

void APlayController::ServerNotifyOnEmoteWheelOpenedOrClosed_Implementation(bool bWheelOpened) {
}
bool APlayController::ServerNotifyOnEmoteWheelOpenedOrClosed_Validate(bool bWheelOpened) {
    return true;
}

void APlayController::ServerNotifyOnEmotePlayed_Implementation(EEmoteType EmoteType) {
}
bool APlayController::ServerNotifyOnEmotePlayed_Validate(EEmoteType EmoteType) {
    return true;
}

void APlayController::ServerNotifyOnActionWheelOpenedOrClosed_Implementation(bool bWheelOpened) {
}
bool APlayController::ServerNotifyOnActionWheelOpenedOrClosed_Validate(bool bWheelOpened) {
    return true;
}

void APlayController::ServerNotifyActorOnscreenStatusChanged_Implementation(AActor* monitoredActor, bool bIsOnscreen) {
}
bool APlayController::ServerNotifyActorOnscreenStatusChanged_Validate(AActor* monitoredActor, bool bIsOnscreen) {
    return true;
}

void APlayController::ServerMoveOrbitalPlatformToNewPlanet_Implementation(AOrbitalPlatform* inOrbitalPlatform, ASolarBody* TargetBody) {
}

void APlayController::ServerLaunchAnchor_Implementation(AWreck* Wreck, APhysicalItem* inDestinationLandingPad) {
}
bool APlayController::ServerLaunchAnchor_Validate(AWreck* Wreck, APhysicalItem* inDestinationLandingPad) {
    return true;
}

void APlayController::ServerHandleOrbitalPlatformSpawn_Implementation(AWreck* Wreck, EPlanetIdentifier planetID) {
}

void APlayController::ServerHandleOrbitalPlatformExtraStages_Implementation(AWreck* Wreck) {
}

void APlayController::ServerHandleAnchorLoadUnload_Implementation(AWreck* Wreck, const FString& inButtonPressedName) {
}
bool APlayController::ServerHandleAnchorLoadUnload_Validate(AWreck* Wreck, const FString& inButtonPressedName) {
    return true;
}

void APlayController::ServerEjectOrbitalPlatformAnchor_Implementation(AWreck* Wreck) {
}

void APlayController::ServerCreateNavpointManagerForPlanet_Implementation(AAstroPlanet* Planet) {
}
bool APlayController::ServerCreateNavpointManagerForPlanet_Validate(AAstroPlanet* Planet) {
    return true;
}

void APlayController::ServerCompleteCustomMissionObjective_Implementation(const FString& objectiveID) {
}
bool APlayController::ServerCompleteCustomMissionObjective_Validate(const FString& objectiveID) {
    return true;
}

void APlayController::ServerClearButtonData_Implementation(AMuseum* inMuseumActor) {
}

void APlayController::ServerClaimReward_Implementation(AMuseum* inMuseumActor, const ESinkType inSinkType, const uint8 inMilestoneIndex, const FTransform inDropPosition) {
}

void APlayController::ServerClaimNonPhysicalMissionRewards_Implementation(const FName missionId) {
}
bool APlayController::ServerClaimNonPhysicalMissionRewards_Validate(const FName missionId) {
    return true;
}

void APlayController::ServerCheckAnchorCanLaunch_Implementation(AWreck* Wreck, EMegastructureType megastructureType, APhysicalItem* inDestinationLandingPad) {
}

void APlayController::ServerBranchConnectionFromActuatorRerouteNode_Implementation(FSlotReference SourceSlot, int32 rerouteNodeId) {
}
bool APlayController::ServerBranchConnectionFromActuatorRerouteNode_Validate(FSlotReference SourceSlot, int32 rerouteNodeId) {
    return true;
}

void APlayController::ServerAddUnclaimedItemDrivePhysicalItemReward_Implementation(const FPendingInGameItemRewards& PendingReward) {
}
bool APlayController::ServerAddUnclaimedItemDrivePhysicalItemReward_Validate(const FPendingInGameItemRewards& PendingReward) {
    return true;
}

void APlayController::ServerAddToCheatPlinthSelectionIndex_Implementation(ACheatPlinthBase* CheatPlinth, int32 increment) {
}
bool APlayController::ServerAddToCheatPlinthSelectionIndex_Validate(ACheatPlinthBase* CheatPlinth, int32 increment) {
    return true;
}

void APlayController::SaveGameFixup_Implementation() {
}

FString APlayController::RunScript(const FString& Script) {
    return TEXT("");
}


void APlayController::Respawn() {
}

void APlayController::ResetPlayControllerStateForRespawn() {
}

void APlayController::ResetInputMode() {
}

void APlayController::ResetCameraToSpawnPoint() {
}

void APlayController::ReapplySavedCharacterCustomization() {
}

void APlayController::PreviewCharacterCustomization(const FAstroCharacterCustomization& customizationToPreview) {
}

void APlayController::Ping() {
}

void APlayController::OpenEmoteWheel() {
}

void APlayController::OnReceiveUsePressed() {
}

void APlayController::OnReceiveToggleHeadlamp() {
}

void APlayController::OnReceiveToggleDeformMenuPressed() {
}

void APlayController::OnReceivePlaceTetherRepeat() {
}

void APlayController::OnReceivePlaceTetherPressed() {
}

void APlayController::OnReceiveDeployCreativeDronePressed() {
}

void APlayController::OnReceiveChangeDeformBrushStrengthModifierReleased() {
}

void APlayController::OnReceiveChangeDeformBrushStrengthModifierPressed() {
}

void APlayController::OnReceiveChangeDeformBrushSizeModifierReleased() {
}

void APlayController::OnReceiveChangeDeformBrushSizeModifierPressed() {
}

void APlayController::OnReceiveBackpackToggleInput() {
}

void APlayController::OnLoadScreenComplete() {
}

void APlayController::OnIncrementCreativeBrushSizeControllerRepeat() {
}

void APlayController::OnIncrementCreativeBrushIntensityControllerRepeat() {
}

void APlayController::OnDrivingStatusChangedInStore() {
}

void APlayController::OnDepartedPlanet() {
}

void APlayController::OnDecrementCreativeBrushIntensityControllerRepeat() {
}

void APlayController::OnCharacterLocalSolarBodyChanged(ASolarBody* newLocalSolarBody) {
}

void APlayController::OnArrivedPlanet() {
}

void APlayController::MouseWheelUp() {
}

void APlayController::MouseWheelDown() {
}

void APlayController::MouseWheel(float Value) {
}

void APlayController::LocalControllerReportWhenActorComesOnscreen_Implementation(AActor* actorToMonitor) {
}
bool APlayController::LocalControllerReportWhenActorComesOnscreen_Validate(AActor* actorToMonitor) {
    return true;
}

void APlayController::LocalControllerCancelReportWhenActorComesOnscreen_Implementation(AActor* actorToMonitor) {
}
bool APlayController::LocalControllerCancelReportWhenActorComesOnscreen_Validate(AActor* actorToMonitor) {
    return true;
}

void APlayController::KillAstroForEmergencyRespawn_Implementation() {
}
bool APlayController::KillAstroForEmergencyRespawn_Validate() {
    return true;
}

void APlayController::Jump() {
}

bool APlayController::IsUsingActiveGrabGamepad() {
    return false;
}

bool APlayController::IsTerrainBrushLightActive() const {
    return false;
}

bool APlayController::IsCreativeShowLODAnchorRangeVisualizationEnabled() const {
    return false;
}

bool APlayController::IsCreativeRemoveDecoratorsWhilePaintingEnabled() const {
    return false;
}


bool APlayController::IsCreativeCollectResourcesWhileDeformingDisabled() const {
    return false;
}

void APlayController::InitializeSpawnPointsForPlayer() {
}

void APlayController::IncrementHoldCounter() {
}


void APlayController::HandleStoreMenuCameraContext(bool bStoreMenuEnabled) {
}

void APlayController::HandleLeftTriggerToggle() {
}

void APlayController::HandleKeyboardMouseKeyJustPressed() {
}

void APlayController::HandleGamepadKeyJustPressed() {
}

void APlayController::HandleGameMenuPopoutCameraContext(bool GameMenuPopoutEnabled) {
}

void APlayController::HandleEmoteWheelSelection(const FSelectionWheelOption& Selection) {
}

void APlayController::HandleEmoteWheelReleased() {
}

void APlayController::HandleEmoteWheelPressed() {
}

void APlayController::HandleCreativeModeEnabledChanged(bool CreativeModeEnabled) {
}

void APlayController::HandleBackpackCameraContext(bool BackpackEnabled) {
}

void APlayController::HandleActionWheelSelection(const FSelectionWheelOption& Selection) {
}

void APlayController::HandleActionWheelReleased() {
}

void APlayController::HandleActionWheelPressed() {
}

float APlayController::GetWindIntensity() const {
    return 0.0f;
}

FVector APlayController::GetWindDirection() const {
    return FVector{};
}

UAstroUnlockNotificationManager* APlayController::GetUnlockNotificationManager() const {
    return NULL;
}

AActor* APlayController::GetTracedActor() {
    return NULL;
}

AActor* APlayController::GetTertiaryActor() {
    return NULL;
}

USceneComponent* APlayController::GetSpawnLocation() {
    return NULL;
}

AActor* APlayController::GetSecondaryViewActor() {
    return NULL;
}

EClickBehavior APlayController::GetSecondaryBehavior() {
    return EClickBehavior::None;
}

AActor* APlayController::GetSecondaryActor() {
    return NULL;
}

float APlayController::GetPrimaryViewIndicatorScale() {
    return 0.0f;
}

USceneComponent* APlayController::GetPrimaryViewComponent() {
    return NULL;
}

AActor* APlayController::GetPrimaryViewActor() {
    return NULL;
}

EClickBehavior APlayController::GetPrimaryBehavior() {
    return EClickBehavior::None;
}

AActor* APlayController::GetPrimaryActor() {
    return NULL;
}

UMultiTool* APlayController::GetMultitool() {
    return NULL;
}

ASolarBody* APlayController::GetLocalSolarBody() const {
    return NULL;
}

int32 APlayController::GetHoldCounter() {
    return 0;
}

bool APlayController::GetCursorVector(FVector& WorldLocation, FVector& WorldDirection) {
    return false;
}

TArray<int32> APlayController::GetConnectedControllers() const {
    return TArray<int32>();
}

FRotator APlayController::GetCameraRotation() {
    return FRotator{};
}

FVector APlayController::GetCameraLocation() const {
    return FVector{};
}

FVector2D APlayController::GetCameraInput() const {
    return FVector2D{};
}

UCameraComponent* APlayController::GetCamera() {
    return NULL;
}

AAstroCharacter* APlayController::GetAstroCharacter() const {
    return NULL;
}

void APlayController::EngageUseModifier() {
}

void APlayController::EngageQuickSelectModifier() {
}

void APlayController::EnableVirtualCursor(bool CenterCursor) {
}

void APlayController::EnablePlanetSelection(bool Enable, ASolarBody* NewHomeBody, float planetSelectionDistance) {
}

void APlayController::EnableLandSelection(bool Enable, ASolarBody* Body) {
}

void APlayController::EmoteTwo() {
}

void APlayController::EmoteThree() {
}

void APlayController::EmoteOne() {
}

void APlayController::EmoteFour() {
}

void APlayController::DropHeldItem() {
}

void APlayController::DoSelectionWheelSelection(const FSelectionWheelOption& Selection) {
}

void APlayController::DoPlayFabCatalogUnlocks() {
}

void APlayController::DisengageUseModifier() {
}

void APlayController::DisengageQuickSelectModifier() {
}

void APlayController::DisengageInteractionModifiers() {
}

void APlayController::DisableVirtualCursor() {
}

void APlayController::DebugFOVUp() {
}

void APlayController::DebugFOVDown() {
}

void APlayController::CycleCameraMode() {
}

void APlayController::ContextRightReleased() {
}

void APlayController::ContextRightPressed() {
}

void APlayController::ContextLeftReleased() {
}

void APlayController::ContextLeftPressed() {
}

void APlayController::CloseEmoteWheel() {
}

void APlayController::CloseAllSelectionWheels() {
}

void APlayController::CloseActionWheel() {
}

void APlayController::ClientSetTimeDilation_Implementation(float inNewSpeed) {
}
bool APlayController::ClientSetTimeDilation_Validate(float inNewSpeed) {
    return true;
}

void APlayController::ClientPresentUnlockNotification_Implementation(FAstroNotificationUnlockAuthoringData AuthoringData) {
}
bool APlayController::ClientPresentUnlockNotification_Validate(FAstroNotificationUnlockAuthoringData AuthoringData) {
    return true;
}

void APlayController::ClientPresentPlanetTravelNotification_Implementation(FAstroNotificationToastAuthoringData AuthoringData) {
}
bool APlayController::ClientPresentPlanetTravelNotification_Validate(FAstroNotificationToastAuthoringData AuthoringData) {
    return true;
}

void APlayController::ClientNotifyPlayerRespawned_Implementation() {
}
bool APlayController::ClientNotifyPlayerRespawned_Validate() {
    return true;
}

void APlayController::ClientNotifyPlayerDeathBegin_Implementation() {
}
bool APlayController::ClientNotifyPlayerDeathBegin_Validate() {
    return true;
}

void APlayController::ClearSaveFailedErrorData() {
}

void APlayController::CameraModeModifierPressed() {
}

void APlayController::AuthorityReportWhenActorComesOnscreen(AActor* actorToMonitor) {
}

void APlayController::AuthorityCancelReportWhenActorComesOnscreen(AActor* actorToMonitor) {
}

bool APlayController::AttemptToPlaceArbitaryItemInHandForHolding(APhysicalItem* Item) {
    return false;
}

bool APlayController::AttemptToDecrementCreativeBrushSizeController() {
    return false;
}


