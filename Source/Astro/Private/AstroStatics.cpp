#include "AstroStatics.h"
#include "Templates/SubclassOf.h"

UAstroStatics::UAstroStatics() {
}

FVector2D UAstroStatics::WorldLocationToScreenLocationOffset(UObject* WorldContextObject, const FVector& WorldLocation, const FVector2D& WorldOffset) {
    return FVector2D{};
}

FVector2D UAstroStatics::WorldLocationToScreenLocation(UObject* WorldContextObject, const FVector& WorldLocation) {
    return FVector2D{};
}

ESaveGameErrorType UAstroStatics::WasThereAnErrorTryingToSaveTheGame(UObject* WorldContextObject, FString& outSaveName, int32& outSaveSize) {
    return ESaveGameErrorType::NoError;
}

FVector UAstroStatics::VInterpCombo(const FVector& Current, const FVector& Target, float ConstantSpeed, float MultiplicativeSpeed, float DeltaTime) {
    return FVector{};
}

FVector UAstroStatics::VelocityAtWorldLocation(UPrimitiveComponent* Component, FVector Location) {
    return FVector{};
}

void UAstroStatics::UpdatePhysicsConstraintFrames(UPhysicsConstraintComponent* Component) {
}

UCreativeModeData* UAstroStatics::TryGetCreativeModeData(const UObject* WorldContextObject) {
    return NULL;
}

void UAstroStatics::ToggleUMGHidden(UWidget* Widget, ESlateVisibility VisibleState) {
}

void UAstroStatics::ToggleCreativeModeLodAnchorPreview(const UObject* WorldContextObject) {
}

bool UAstroStatics::SweepPrimitiveComponentMulti(UPrimitiveComponent* Component, const FVector& Start, const FVector& End, TArray<FHitResult>& OutHits) {
    return false;
}

bool UAstroStatics::SweepPrimitiveComponentByProfile(UPrimitiveComponent* Component, const FVector& Start, const FVector& End, FHitResult& OutHit, FName Profile) {
    return false;
}

bool UAstroStatics::SweepPrimitiveComponent(UPrimitiveComponent* Component, const FVector& Start, const FVector& End, FHitResult& OutHit) {
    return false;
}

int32 UAstroStatics::StringChecksum(const FString& String, int32 Hash) {
    return 0;
}

float UAstroStatics::Sinusoid(float Speed, UObject* WorldContextObject) {
    return 0.0f;
}

bool UAstroStatics::ShowSelectNetworkUI(const UObject* WorldContextObject) {
    return false;
}

void UAstroStatics::ShowLoggingUI(const UObject* WorldContextObject, const APlayerController* Controller) {
}

void UAstroStatics::ShowLodAnchorBeacons(bool doShow, UObject* WorldContextObject) {
}

void UAstroStatics::SetWeldedComponentLocation(UPrimitiveComponent* Component, const FVector& WorldLocation) {
}

void UAstroStatics::SetUIEnabled(UPrimitiveComponent* Component, bool Enable) {
}

void UAstroStatics::SetTraceEnabled(UPrimitiveComponent* Component, bool Enabled) {
}

void UAstroStatics::SetTraceAndCollisionEnabled(UPrimitiveComponent* Component, bool Enabled) {
}

FTimerHandle UAstroStatics::SetTimerFromFunctionWithDelay(UObject* Object, const FString& FunctionName, float Time, bool bLooping, float InitialDelay) {
    return FTimerHandle{};
}

void UAstroStatics::SetStateFirstAvailableSaveSlot(UObject* WorldContextObject) {
}

void UAstroStatics::SetSkeletalMeshPlaybackRatio(USkeletalMeshComponent* Mesh, float PlaybackRatio, bool bFireNotifies) {
}

void UAstroStatics::SetPostProcessVignetting(const FPostProcessSettings& InSettings, FPostProcessSettings& OutSettings, float Value) {
}

void UAstroStatics::SetPostProcessLensFlare(const FPostProcessSettings& InSettings, FPostProcessSettings& OutSettings, float Value) {
}

bool UAstroStatics::SetPlayerPropertiesForCustomGame(AAstroCustomGameManager* CustomGameManager, AAstroPlayerController* PlayerController, const FAstroClientProperties& clientProperties) {
    return false;
}

void UAstroStatics::SetNearClippingPlane(float Distance) {
}

void UAstroStatics::SetMultiplayerMode(const UObject* WorldContextObject, const bool online) {
}

void UAstroStatics::SetCuePlaying(UAudioComponent* Sound, bool Play, float Fade) {
}

void UAstroStatics::SetCreativeModeTerrainColorIndex(int32 colorIndex, EPaintIndexType Type, const UObject* WorldContextObject) {
}

void UAstroStatics::SetCollisionEnabled(UPrimitiveComponent* Component, bool Enabled) {
}

void UAstroStatics::SetChildActorPhysics(UChildActorComponent* ChildActor, bool Physics, bool Collision) {
}

int32 UAstroStatics::SetBitValue(int32 BitMask, int32 BitIndex, bool BitValue) {
    return 0;
}

void UAstroStatics::SetAllVectorParameterValue(TArray<UMaterialInstanceDynamic*> DynamicInstances, FName Parameter, FLinearColor Value) {
}

void UAstroStatics::SetAllScalarParameterValue(TArray<UMaterialInstanceDynamic*> DynamicInstances, FName Parameter, float Value) {
}

void UAstroStatics::SetAllMaterial(AActor* Actor, UMaterialInterface* Material) {
}

void UAstroStatics::SetAllComponentMaterial(UPrimitiveComponent* Component, UMaterialInterface* Material) {
}

void UAstroStatics::SetActorUp(AActor* Actor, const FVector& Forward) {
}

void UAstroStatics::SetActorTraceEnabled(AActor* Actor, bool Enabled) {
}

void UAstroStatics::SetActorSimulatePhysics(AActor* Actor, bool Simulate) {
}

void UAstroStatics::SetActorRight(AActor* Actor, const FVector& Forward) {
}

void UAstroStatics::SetActorForward(AActor* Actor, const FVector& Forward) {
}

void UAstroStatics::SetActorCollisionEnabled(AActor* Actor, bool Enabled) {
}

void UAstroStatics::SetActiveSaveFileForCustomGame(UObject* WorldContextObject, const FString& Name) {
}

void UAstroStatics::SaveGameNoCloudSave(UObject* WorldContextObject, const FString& Name, FOnAstroSaveCompletedDynamic OnCompletedDelegate) {
}

void UAstroStatics::SaveGameAuto(UObject* WorldContextObject, FOnAstroSaveCompletedDynamic OnCompletedDelegate) {
}

void UAstroStatics::SaveGame(UObject* WorldContextObject, const FString& Name, FOnAstroSaveCompletedDynamic OnCompletedDelegate) {
}

FString UAstroStatics::SanitizeSaveFileDescriptiveName(const FString& SaveFileDescriptiveName) {
    return TEXT("");
}

int32 UAstroStatics::RollIntegerIncrement(int32 Value, int32 Max) {
    return 0;
}

int32 UAstroStatics::RollIntegerDecrement(int32 Value, int32 Max) {
    return 0;
}

bool UAstroStatics::ReturnToTitleScreen(UObject* WorldContextObject, bool DisplayOutOfLivesPrompt) {
    return false;
}

bool UAstroStatics::RenameSaveFile(UObject* WorldContextObject, const FString& CurrSaveName, const FString& newDescriptiveSaveName, FOnAstroRenameSaveCompletedDynamic OnCompletedDelegate) {
    return false;
}

float UAstroStatics::ReinterpretIntToFloat(int32 Int) {
    return 0.0f;
}

int32 UAstroStatics::ReinterpretFloatToInt(float Float) {
    return 0;
}

void UAstroStatics::PreviewEmoteLocally(USkeletalMeshComponent* targetMesh, UAstroEmoteDefinition* emoteDefinition) {
}

bool UAstroStatics::PredictIfActiveSaveFileIsTooLargeToSave(UObject* WorldContextObject, FString& outSaveName, int32& outSaveSize) {
    return false;
}

void UAstroStatics::PopulateSpawnableObjects(UPanelWidget* Widget, const FString& nameFilter) {
}

void UAstroStatics::PopulateSaveGames(UPanelWidget* Widget) {
}

void UAstroStatics::PopulateResourceTypes(UPanelWidget* Widget) {
}

void UAstroStatics::PopulateLoadablePresets(UPanelWidget* Widget) {
}

void UAstroStatics::PlaySound(USoundBase* Sound, UObject* WorldContextObject) {
}

void UAstroStatics::PhysicsConstrain(UPrimitiveComponent* Target, UPrimitiveComponent* Other) {
}

void UAstroStatics::NullInspectObject(UObject* Object) {
}

void UAstroStatics::MarkPrimitiveRenderStateDirty(UPrimitiveComponent* Primitive) {
}

FVector_NetQuantizeNormal UAstroStatics::MakeVectorQuantizeNormal(const FVector& Vector) {
    return FVector_NetQuantizeNormal{};
}

FVector_NetQuantize100 UAstroStatics::MakeVectorQuantize100(const FVector& Vector) {
    return FVector_NetQuantize100{};
}

void UAstroStatics::MakeInert(AActor* Actor) {
}

int32 UAstroStatics::LogInt(int32 Val, int32 Base) {
    return 0;
}

bool UAstroStatics::LoadMapSeamless(FName MapName, const FString& Options, bool bAbsolute, UObject* WorldContextObject) {
    return false;
}

bool UAstroStatics::LoadGameFromAsset(UObject* WorldContext, const TSoftObjectPtr<UAstroSaveAsset>& saveAssetPtr) {
    return false;
}

bool UAstroStatics::LoadGame(const FString& Name, UObject* WorldContextObject) {
    return false;
}

float UAstroStatics::LerpToRange(float Min, float Max, float CurrentValue, float TargetLerp, float Alpha) {
    return 0.0f;
}

void UAstroStatics::JoinToURL(const FString& Name, const UObject* WorldContextObject) {
}

void UAstroStatics::JoinLocalGame(const UObject* WorldContextObject, const FString& GameID) {
}

bool UAstroStatics::IsWorldTearingDown(const UObject* WorldContextObject) {
    return false;
}

bool UAstroStatics::IsWorldGameWorld(const UObject* WorldContextObject) {
    return false;
}

bool UAstroStatics::IsValidAstroLinearColor(const FLinearColor& ColorToTest) {
    return false;
}

bool UAstroStatics::IsTrailerBuild(UObject* WorldContextObject) {
    return false;
}

bool UAstroStatics::IsStoreUIEnabled() {
    return false;
}

bool UAstroStatics::IsShippingBuild() {
    return false;
}

bool UAstroStatics::IsServer(const UObject* WorldContextObject) {
    return false;
}

bool UAstroStatics::IsSaveRestoreInProgress() {
    return false;
}

bool UAstroStatics::IsSavePermittedOverrideEnabled() {
    return false;
}

bool UAstroStatics::IsSaveFileDescriptiveNameTheActiveSaveFile(UObject* WorldContextObject, const FString& DescriptiveName) {
    return false;
}

bool UAstroStatics::IsReleaseBuild(UObject* WorldContextObject) {
    return false;
}

bool UAstroStatics::IsPlatformUWPOrXbox() {
    return false;
}

bool UAstroStatics::IsPlatformSwitchOrSwitchPreview() {
    return false;
}

bool UAstroStatics::IsPlatformSwitch() {
    return false;
}

bool UAstroStatics::IsPlatformPS4() {
    return false;
}

bool UAstroStatics::IsPlatformMKBEnabled() {
    return false;
}

bool UAstroStatics::IsPlatformGameConsole() {
    return false;
}

bool UAstroStatics::IsNetworkAvailable(const UObject* WorldContextObject) {
    return false;
}

bool UAstroStatics::IsLocalProfile(const UObject* WorldContextObject, const APlayerController* Controller) {
    return false;
}

bool UAstroStatics::IsLocalControlledPawn(APawn* Pawn) {
    return false;
}

bool UAstroStatics::IsLocalCommunications(const UObject* WorldContextObject, const APlayerController* Controller) {
    return false;
}

bool UAstroStatics::IsLanMatch(const UObject* WorldContextObject, const APlayerController* Controller) {
    return false;
}

bool UAstroStatics::IsDedicatedServerUIEnabled() {
    return false;
}

bool UAstroStatics::IsDedicatedServer(UObject* WorldContextObject) {
    return false;
}

bool UAstroStatics::IsCreativeMode(UObject* WorldContextObject) {
    return false;
}

bool UAstroStatics::IsConnectedToDedicatedServer(UObject* WorldContextObject) {
    return false;
}

bool UAstroStatics::IsAsyncSaveInProgress() {
    return false;
}

bool UAstroStatics::IsAnalyticsEnabled(UObject* WorldContextObject) {
    return false;
}

float UAstroStatics::InterpToRange(float Min, float Max, float CurrentValue, float TargetLerp, float DeltaTime, float Speed) {
    return 0.0f;
}

FTransform UAstroStatics::IdentityTransform() {
    return FTransform{};
}

FVector UAstroStatics::HitLocation(const FHitResult& Hit) {
    return FVector{};
}

FVector UAstroStatics::HitImpactPoint(const FHitResult& Hit) {
    return FVector{};
}

FVector UAstroStatics::HitImpactNormal(const FHitResult& Hit) {
    return FVector{};
}

UPrimitiveComponent* UAstroStatics::HitImpactComponent(const FHitResult& Hit) {
    return NULL;
}

AActor* UAstroStatics::HitImpactActor(const FHitResult& Hit) {
    return NULL;
}

bool UAstroStatics::HasOnlineFeatures(const UObject* WorldContextObject, const APlayerController* Controller) {
    return false;
}

bool UAstroStatics::HasEventualParentActorOfType(const AActor* Actor, TSubclassOf<AActor> actorType) {
    return false;
}

bool UAstroStatics::HasComponentOfType(TSubclassOf<AActor> actorType, TSubclassOf<UActorComponent> ComponentType) {
    return false;
}

FVector2D UAstroStatics::GetWidgetOuterCanvasPosition(UWidget* Widget) {
    return FVector2D{};
}

bool UAstroStatics::GetUseSplitscreen(UObject* WorldContextObject) {
    return false;
}

int32 UAstroStatics::GetTotalSizeOfAllCachedSaveFiles(UObject* WorldContextObject) {
    return 0;
}

FVector2D UAstroStatics::GetTextBoundsForFont(FText Text, FSlateFontInfo FontInfo) {
    return FVector2D{};
}

float UAstroStatics::GetSkeletalMeshPlaybackRatio(const USkeletalMeshComponent* Mesh) {
    return 0.0f;
}

FIntPoint UAstroStatics::GetScreenResolution() {
    return FIntPoint{};
}

float UAstroStatics::GetPostProcessVignetting(const FPostProcessSettings& Settings) {
    return 0.0f;
}

float UAstroStatics::GetPostProcessLensFlare(const FPostProcessSettings& Settings) {
    return 0.0f;
}

int32 UAstroStatics::GetPlatformSaveStorageLimit() {
    return 0;
}

int32 UAstroStatics::GetPlatformLowFreeStorageSpaceThreshold() {
    return 0;
}

APlayerController* UAstroStatics::GetOwnerPlayerControllerForActor(const AActor* Actor) {
    return NULL;
}

APlayerController* UAstroStatics::GetOwnerPlayerController(UActorComponent* Component) {
    return NULL;
}

APawn* UAstroStatics::GetOwnerPawnForActor(const AActor* Actor) {
    return NULL;
}

APawn* UAstroStatics::GetOwnerPawn(UActorComponent* Component) {
    return NULL;
}

AActor* UAstroStatics::GetOutermostActor(AActor* Actor) {
    return NULL;
}

bool UAstroStatics::GetNumberOfPlayersInMultiplayerSession(int32& outNumPlayersInSession) {
    return false;
}

TArray<FPlayerNicknameAndPlatform> UAstroStatics::GetNicknamesAndPlatformsOfPlayersInMultiplayerSession(bool bExcludeLocalControllingPlayer) {
    return TArray<FPlayerNicknameAndPlatform>();
}

TArray<FAstroSaveFileInformation> UAstroStatics::GetNewestSaves(UObject* WorldContextObject) {
    return TArray<FAstroSaveFileInformation>();
}

FAstroSaveFileInformation UAstroStatics::GetNewestSave(UObject* WorldContextObject) {
    return FAstroSaveFileInformation{};
}

bool UAstroStatics::GetMultiplayerSessionLeaderName(FString& OutSessionLeaderName) {
    return false;
}

APawn* UAstroStatics::GetLocalPawn(UObject* WorldContextObject) {
    return NULL;
}

TArray<FString> UAstroStatics::GetLocalGames(const UObject* WorldContextObject) {
    return TArray<FString>();
}

UObject* UAstroStatics::GetKeyImageForKey(FKey Key) {
    return NULL;
}

UObject* UAstroStatics::GetKeyImageForInteractionPrompt(UObject* WorldContextObject, FInteractionPromptEntryData PromptData, bool ForceKeyboardImage) {
    return NULL;
}

UObject* UAstroStatics::GetKeyImageForGamepadInput(UObject* WorldContextObject, FKey Key) {
    return NULL;
}

FName UAstroStatics::GetInputNameFromInputMapping(EAstroInputBindingNameMappings ActionMapping) {
    return NAME_None;
}

AAstroGameState* UAstroStatics::GetGameState(const UObject* WorldContextObject) {
    return NULL;
}

EGamePlatform UAstroStatics::GetGamePlatform() {
    return EGamePlatform::PC;
}

AAstroGameMode* UAstroStatics::GetGameMode(const UObject* WorldContextObject) {
    return NULL;
}

UAstroGameInstance* UAstroStatics::GetGameInstance(const UObject* WorldContextObject) {
    return NULL;
}

TEnumAsByte<EWindowMode::Type> UAstroStatics::GetFullscreenMode() {
    return EWindowMode::Fullscreen;
}

//UAstroDlcManager* UAstroStatics::GetDlcManager(const UObject* WorldContextObject) {
//    return NULL;
//}

FAstroDiscreteInputDefinition UAstroStatics::GetDiscreteAstroInputDefinition(EAstroDiscreteInputOptionPlayerFacing DiscretePlayerFacingInputOption) {
    return FAstroDiscreteInputDefinition{};
}

FString UAstroStatics::GetDedicatedServerUrl(const UObject* WorldContextObject) {
    return TEXT("");
}

FString UAstroStatics::GetDedicatedServerSearchName(const UObject* WorldContextObject) {
    return TEXT("");
}

bool UAstroStatics::GetCVar_Integer(const FString& cvarName, int32& outInteger) {
    return false;
}

int32 UAstroStatics::GetCvar_EnableBackpackTrickleCharge() {
    return 0;
}

int32 UAstroStatics::GetCvar_DeformTool_UseTerrainResource() {
    return 0;
}

int32 UAstroStatics::GetCvar_DeformTool_UsePowerDraw() {
    return 0;
}

EGameControllerType UAstroStatics::GetCurrentControllerType() {
    return EGameControllerType::Xbox;
}

void UAstroStatics::GetCreativeModeTerrainColors(const UObject* WorldContextObject, TArray<UMaterialInterface*>& OutMaterials, TArray<FLinearColor>& OutTerrainColors) {
}

FLinearColor UAstroStatics::GetCreativeModeTerrainColorAtIndex(int32 colorIndex, EPaintIndexType Type, const UObject* WorldContextObject) {
    return FLinearColor{};
}

FLinearColor UAstroStatics::GetCreativeModeTerrainColor(const UObject* WorldContextObject) {
    return FLinearColor{};
}

UMaterialInterface* UAstroStatics::GetCreativeModeTerrainButtonColor(const UObject* WorldContextObject) {
    return NULL;
}

void UAstroStatics::GetCreativeModeSpecialColors(TArray<FLinearColor>& OutPlanetColors, TArray<UMaterialInterface*>& OutMaterials, const UObject* WorldContextObject) {
}

void UAstroStatics::GetCreativeModePlanetColors(const AActor* forActor, TArray<FLinearColor>& OutPlanetColors, TArray<UMaterialInterface*>& OutMaterials) {
}

UCreativeModeData* UAstroStatics::GetCreativeModeData(const UObject* WorldContextObject) {
    return NULL;
}

FString UAstroStatics::GetControllingPlayerNickname() {
    return TEXT("");
}

void UAstroStatics::GetComponentsInChildren(AActor* Actor, TSubclassOf<UActorComponent> Class, TArray<UActorComponent*>& OutComponents) {
}

TArray<USceneComponent*> UAstroStatics::GetComponentParentHierarchy(USceneComponent* Component, bool Inclusive) {
    return TArray<USceneComponent*>();
}

void UAstroStatics::GetChildrenRecursive(AActor* Actor, TArray<AActor*>& OutActors, bool Inclusive) {
}

FString UAstroStatics::GetBuildVersionWithFlavor() {
    return TEXT("");
}

FString UAstroStatics::GetBuildVersion() {
    return TEXT("");
}

bool UAstroStatics::GetBitValue(int32 BitMask, int32 BitIndex) {
    return false;
}

AActor* UAstroStatics::GetAttachParentActor(AActor* Actor) {
    return NULL;
}

AAstroMissionsManager* UAstroStatics::GetAstroMissionsManager(const UObject* WorldContextObject) {
    return NULL;
}

FSlateColor UAstroStatics::GetAstroColorAsSlateColor(EAstroColor AstroColor) {
    return FSlateColor{};
}

FLinearColor UAstroStatics::GetAstroColor(EAstroColor AstroColor) {
    return FLinearColor{};
}

TArray<AActor*> UAstroStatics::GetActorParentHierarchy(AActor* Actor, bool Inclusive) {
    return TArray<AActor*>();
}

FRotator UAstroStatics::FromToRotation(const FVector& From, const FVector& To) {
    return FRotator{};
}

void UAstroStatics::ForceDestroySession(const UObject* WorldContextObject) {
}

void UAstroStatics::ForceCreateSession(const UObject* WorldContextObject) {
}

float UAstroStatics::FInterpCombo(float Current, float Target, float ConstantSpeed, float MultiplicativeSpeed, float DeltaTime) {
    return 0.0f;
}

void UAstroStatics::FindLocalGames(const UObject* WorldContextObject) {
}

UActorComponent* UAstroStatics::FindComponentByName(AActor* Actor, FName ComponentName) {
    return NULL;
}

FRotator UAstroStatics::FindBetween(FVector A, FVector B) {
    return FRotator{};
}

void UAstroStatics::EnqueueSkeletalMeshPlayRate(USkeletalMeshComponent* Mesh, float Rate) {
}

bool UAstroStatics::DuplicateSaveFile(UObject* WorldContextObject, const FString& CurrSaveName, const FString& newDescriptiveSaveName, FOnAstroSaveCompletedDynamic OnCompletedDelegate) {
    return false;
}

bool UAstroStatics::DoesSaveFileDescriptiveNameCollideWithExistingSaves(UObject* WorldContextObject, const FString& newDescriptiveSaveName) {
    return false;
}

bool UAstroStatics::DoesKeyMatchInputBinding(EAstroInputBindingNameMappings InputBinding, float AxisScale, FKey Key) {
    return false;
}

void UAstroStatics::DisplayLoadingUMG(APlayerController* PlayerController, TSubclassOf<UUserWidget> LoadingWidgetOverride) {
}

void UAstroStatics::DestroyChildActors(AActor* Actor) {
}

void UAstroStatics::DestroyActorHierarchy(AActor* Actor, bool includeSelf) {
}

bool UAstroStatics::DeleteSaveGame(UObject* WorldContextObject, const FAstroSaveFileInformation& SaveDisplayInfo) {
    return false;
}

void UAstroStatics::DeleteAllSaves(UObject* WorldContextObject) {
}

FString UAstroStatics::DateTimeToString(const FDateTime& DateTime) {
    return TEXT("");
}

UMaterialInstanceDynamic* UAstroStatics::CreatePostprocessMaterialDynamic(int32 Index, UPostProcessComponent* PostProcess) {
    return NULL;
}

TArray<UMaterialInstanceDynamic*> UAstroStatics::CreateAllDynamicMaterialInstances(AActor* Actor, UMaterialInterface* Material) {
    return TArray<UMaterialInstanceDynamic*>();
}

TArray<UMaterialInstanceDynamic*> UAstroStatics::CreateAllComponentDynamicMaterialInstances(UPrimitiveComponent* Component, UMaterialInterface* Material) {
    return TArray<UMaterialInstanceDynamic*>();
}

UMaterialInstanceDynamic* UAstroStatics::CreateAllComponentDynamicMaterialInstance(UPrimitiveComponent* Component, UMaterialInterface* Material) {
    return NULL;
}

FTransform UAstroStatics::ConvertToRelativeTransform(const FTransform& ParentTransform, const FTransform& Transform) {
    return FTransform{};
}

TArray<FText> UAstroStatics::ConvertIntegerToArrayOfText(int32 InInteger) {
    return TArray<FText>();
}

FVector UAstroStatics::ClosestPointOnLine(const FVector& LineStart, const FVector& LineEnd, const FVector& Point, float& T) {
    return FVector{};
}

void UAstroStatics::ChangeMultiplayerMode(const UObject* WorldContextObject) {
}

int32 UAstroStatics::CastPhysicalSurfaceToInteger(TEnumAsByte<EPhysicalSurface> surface) {
    return 0;
}

bool UAstroStatics::CanGetSavedGames(UObject* WorldContextObject) {
    return false;
}

void UAstroStatics::AddPostProcessBlendableMaterial(const FPostProcessSettings& InSettings, FPostProcessSettings& OutSettings, UMaterial* Material) {
}

bool UAstroStatics::ActorSimulatingPhysics(AActor* Actor) {
    return false;
}

bool UAstroStatics::ActorOnClickedBound(AActor* Actor) {
    return false;
}

void UAstroStatics::ActorCallOnClicked(AActor* Actor) {
}


