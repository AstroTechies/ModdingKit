#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
#include "EAstroColor.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "InteractionPromptEntryData.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "ESaveGameErrorType.h"
#include "AstroDiscreteInputDefinition.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=ESlateVisibility -FallbackName=ESlateVisibility
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerHandle -FallbackName=TimerHandle
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=PostProcessSettings -FallbackName=PostProcessSettings
#include "EPaintIndexType.h"
#include "OnAstroSaveCompletedDynamicDelegate.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=DateTime -FallbackName=DateTime
#include "EGameControllerType.h"
#include "OnAstroRenameSaveCompletedDynamicDelegate.h"
#include "EGamePlatform.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Vector_NetQuantizeNormal -FallbackName=Vector_NetQuantizeNormal
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Vector_NetQuantize100 -FallbackName=Vector_NetQuantize100
// CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=SlateColor -FallbackName=SlateColor
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
// CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=SlateFontInfo -FallbackName=SlateFontInfo
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EPhysicalSurface -FallbackName=EPhysicalSurface
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=IntPoint -FallbackName=IntPoint
#include "PlayerNicknameAndPlatform.h"
#include "AstroSaveFileInformation.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include "EAstroInputBindingNameMappings.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EWindowMode -FallbackName=EWindowMode
#include "EAstroDiscreteInputOptionPlayerFacing.h"
#include "AstroStatics.generated.h"

class UPrimitiveComponent;
class AActor;
class UAstroGameInstance;
class UObject;
class AAstroGameMode;
class UPhysicsConstraintComponent;
class UCreativeModeData;
class APlayerController;
class UWidget;
class USkeletalMeshComponent;
class UAudioComponent;
class UChildActorComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UPanelWidget;
class USoundBase;
class USceneComponent;
class UAstroSaveAsset;
class APawn;
class AAstroMissionsManager;
class UActorComponent;
class UUserWidget;
class UPostProcessComponent;
class AAstroGameState;
class UMaterial;

UCLASS(Blueprintable)
class ASTRO_API UAstroStatics : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UAstroStatics();
    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static FVector2D WorldLocationToScreenLocationOffset(UObject *WorldContextObject, const FVector &WorldLocation, const FVector2D &WorldOffset);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static FVector2D WorldLocationToScreenLocation(UObject *WorldContextObject, const FVector &WorldLocation);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static ESaveGameErrorType WasThereAnErrorTryingToSaveTheGame(UObject *WorldContextObject, FString &outSaveName, int32 &outSaveSize);

    UFUNCTION(BlueprintPure)
    static FVector VInterpCombo(const FVector &Current, const FVector &Target, float ConstantSpeed, float MultiplicativeSpeed, float DeltaTime);

    UFUNCTION(BlueprintPure)
    static FVector VelocityAtWorldLocation(UPrimitiveComponent *Component, FVector Location);

    UFUNCTION(BlueprintCallable)
    static void UpdatePhysicsConstraintFrames(UPhysicsConstraintComponent *Component);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static UCreativeModeData *TryGetCreativeModeData(const UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static void ToggleUMGHidden(UWidget *Widget, ESlateVisibility VisibleState);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void ToggleCreativeModeLodAnchorPreview(const UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static bool SweepPrimitiveComponentMulti(UPrimitiveComponent *Component, const FVector &Start, const FVector &End, TArray<FHitResult> &OutHits);

    UFUNCTION(BlueprintCallable)
    static bool SweepPrimitiveComponentByProfile(UPrimitiveComponent *Component, const FVector &Start, const FVector &End, FHitResult &OutHit, FName Profile);

    UFUNCTION(BlueprintCallable)
    static bool SweepPrimitiveComponent(UPrimitiveComponent *Component, const FVector &Start, const FVector &End, FHitResult &OutHit);

    UFUNCTION(BlueprintCallable)
    static int32 StringChecksum(const FString &String, int32 Hash);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static float Sinusoid(float Speed, UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static bool ShowSelectNetworkUI(const UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void ShowLoggingUI(const UObject *WorldContextObject, const APlayerController *Controller);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void ShowLodAnchorBeacons(bool doShow, UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static void SetWeldedComponentLocation(UPrimitiveComponent *Component, const FVector &WorldLocation);

    UFUNCTION(BlueprintCallable)
    static void SetUIEnabled(UPrimitiveComponent *Component, bool Enable);

    UFUNCTION(BlueprintCallable)
    static void SetTraceEnabled(UPrimitiveComponent *Component, bool Enabled);

    UFUNCTION(BlueprintCallable)
    static void SetTraceAndCollisionEnabled(UPrimitiveComponent *Component, bool Enabled);

    UFUNCTION(BlueprintCallable)
    static FTimerHandle SetTimerFromFunctionWithDelay(UObject *Object, const FString &FunctionName, float Time, bool bLooping, float InitialDelay);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void SetStateFirstAvailableSaveSlot(UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static void SetSkeletalMeshPlaybackRatio(USkeletalMeshComponent *Mesh, float PlaybackRatio, bool bFireNotifies);

    UFUNCTION(BlueprintCallable)
    static void SetPostProcessVignetting(const FPostProcessSettings &InSettings, FPostProcessSettings &OutSettings, float Value);

    UFUNCTION(BlueprintCallable)
    static void SetPostProcessLensFlare(const FPostProcessSettings &InSettings, FPostProcessSettings &OutSettings, float Value);

    UFUNCTION(BlueprintCallable)
    static void SetNearClippingPlane(float Distance);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void SetMultiplayerMode(const UObject *WorldContextObject, const bool online);

    UFUNCTION(BlueprintCallable)
    static void SetCuePlaying(UAudioComponent *Sound, bool Play, float Fade);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void SetCreativeModeTerrainColorIndex(int32 colorIndex, EPaintIndexType Type, const UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static void SetCollisionEnabled(UPrimitiveComponent *Component, bool Enabled);

    UFUNCTION(BlueprintCallable)
    static void SetChildActorPhysics(UChildActorComponent *ChildActor, bool Physics, bool Collision);

    UFUNCTION(BlueprintPure)
    static int32 SetBitValue(int32 BitMask, int32 BitIndex, bool BitValue);

    UFUNCTION(BlueprintCallable)
    static void SetAllVectorParameterValue(TArray<UMaterialInstanceDynamic *> DynamicInstances, FName Parameter, FLinearColor Value);

    UFUNCTION(BlueprintCallable)
    static void SetAllScalarParameterValue(TArray<UMaterialInstanceDynamic *> DynamicInstances, FName Parameter, float Value);

    UFUNCTION(BlueprintCallable)
    static void SetAllMaterial(AActor *Actor, UMaterialInterface *Material);

    UFUNCTION(BlueprintCallable)
    static void SetAllComponentMaterial(UPrimitiveComponent *Component, UMaterialInterface *Material);

    UFUNCTION(BlueprintCallable)
    static void SetActorUp(AActor *Actor, const FVector &Forward);

    UFUNCTION(BlueprintCallable)
    static void SetActorTraceEnabled(AActor *Actor, bool Enabled);

    UFUNCTION(BlueprintCallable)
    static void SetActorSimulatePhysics(AActor *Actor, bool Simulate);

    UFUNCTION(BlueprintCallable)
    static void SetActorRight(AActor *Actor, const FVector &Forward);

    UFUNCTION(BlueprintCallable)
    static void SetActorForward(AActor *Actor, const FVector &Forward);

    UFUNCTION(BlueprintCallable)
    static void SetActorCollisionEnabled(AActor *Actor, bool Enabled);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void SaveGameNoCloudSave(UObject *WorldContextObject, const FString &Name, FOnAstroSaveCompletedDynamic OnCompletedDelegate);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void SaveGameAuto(UObject *WorldContextObject, FOnAstroSaveCompletedDynamic OnCompletedDelegate);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void SaveGame(UObject *WorldContextObject, const FString &Name, FOnAstroSaveCompletedDynamic OnCompletedDelegate);

    UFUNCTION(BlueprintPure)
    static FString SanitizeSaveFileDescriptiveName(const FString &SaveFileDescriptiveName);

    UFUNCTION(BlueprintPure)
    static int32 RollIntegerIncrement(int32 Value, int32 Max);

    UFUNCTION(BlueprintPure)
    static int32 RollIntegerDecrement(int32 Value, int32 Max);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static bool ReturnToTitleScreen(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static bool RenameSaveFile(UObject *WorldContextObject, const FString &CurrSaveName, const FString &newDescriptiveSaveName, FOnAstroRenameSaveCompletedDynamic OnCompletedDelegate);

    UFUNCTION(BlueprintPure)
    static float ReinterpretIntToFloat(int32 Int);

    UFUNCTION(BlueprintPure)
    static int32 ReinterpretFloatToInt(float Float);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool PredictIfActiveSaveFileIsTooLargeToSave(UObject *WorldContextObject, FString &outSaveName, int32 &outSaveSize);

    UFUNCTION(BlueprintCallable)
    static void PopulateSpawnableObjects(UPanelWidget *Widget, const FString &nameFilter);

    UFUNCTION(BlueprintCallable)
    static void PopulateSaveGames(UPanelWidget *Widget);

    UFUNCTION(BlueprintCallable)
    static void PopulateResourceTypes(UPanelWidget *Widget);

    UFUNCTION(BlueprintCallable)
    static void PopulateLoadablePresets(UPanelWidget *Widget);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void PlaySound(USoundBase *Sound, UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static void PhysicsConstrain(UPrimitiveComponent *Target, UPrimitiveComponent *Other);

    UFUNCTION(BlueprintCallable)
    static void NullInspectObject(UObject *Object);

    UFUNCTION(BlueprintCallable)
    static void MarkPrimitiveRenderStateDirty(UPrimitiveComponent *Primitive);

    UFUNCTION(BlueprintPure)
    static FVector_NetQuantizeNormal MakeVectorQuantizeNormal(const FVector &Vector);

    UFUNCTION(BlueprintPure)
    static FVector_NetQuantize100 MakeVectorQuantize100(const FVector &Vector);

    UFUNCTION(BlueprintCallable)
    static void MakeInert(AActor *Actor);

    UFUNCTION(BlueprintPure)
    static int32 LogInt(int32 Val, int32 Base);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static bool LoadMapSeamless(FName MapName, const FString &Options, bool bAbsolute, UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static bool LoadGameFromAsset(UObject *WorldContext, const TSoftObjectPtr<UAstroSaveAsset> &saveAssetPtr);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static bool LoadGame(const FString &Name, UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static float LerpToRange(float Min, float Max, float CurrentValue, float TargetLerp, float Alpha);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void JoinToURL(const FString &Name, const UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void JoinLocalGame(const UObject *WorldContextObject, const FString &GameID);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool IsWorldTearingDown(const UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool IsWorldGameWorld(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool IsValidAstroLinearColor(const FLinearColor &ColorToTest);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool IsTrailerBuild(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool IsStoreUIEnabled();

    UFUNCTION(BlueprintPure)
    static bool IsShippingBuild();

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool IsServer(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool IsSaveRestoreInProgress();

    UFUNCTION(BlueprintPure)
    static bool IsSavePermittedOverrideEnabled();

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool IsSaveFileDescriptiveNameTheActiveSaveFile(UObject *WorldContextObject, const FString &DescriptiveName);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool IsReleaseBuild(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool IsPlatformUWPOrXbox();

    UFUNCTION(BlueprintPure)
    static bool IsPlatformSwitchOrSwitchPreview();

    UFUNCTION(BlueprintPure)
    static bool IsPlatformSwitch();

    UFUNCTION(BlueprintPure)
    static bool IsPlatformPS4();

    UFUNCTION(BlueprintPure)
    static bool IsPlatformMKBEnabled();

    UFUNCTION(BlueprintPure)
    static bool IsPlatformGameConsole();

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool IsNetworkAvailable(const UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool IsLocalProfile(const UObject *WorldContextObject, const APlayerController *Controller);

    UFUNCTION(BlueprintPure)
    static bool IsLocalControlledPawn(APawn *Pawn);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool IsLocalCommunications(const UObject *WorldContextObject, const APlayerController *Controller);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool IsLanMatch(const UObject *WorldContextObject, const APlayerController *Controller);

    UFUNCTION(BlueprintPure)
    static bool IsDedicatedServerUIEnabled();

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool IsDedicatedServer(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool IsCreativeMode(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool IsConnectedToDedicatedServer(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool IsAsyncSaveInProgress();

    UFUNCTION(BlueprintPure)
    static float InterpToRange(float Min, float Max, float CurrentValue, float TargetLerp, float DeltaTime, float Speed);

    UFUNCTION(BlueprintPure)
    static FTransform IdentityTransform();

    UFUNCTION(BlueprintPure)
    static FVector HitLocation(const FHitResult &Hit);

    UFUNCTION(BlueprintPure)
    static FVector HitImpactPoint(const FHitResult &Hit);

    UFUNCTION(BlueprintPure)
    static FVector HitImpactNormal(const FHitResult &Hit);

    UFUNCTION(BlueprintPure)
    static UPrimitiveComponent *HitImpactComponent(const FHitResult &Hit);

    UFUNCTION(BlueprintPure)
    static AActor *HitImpactActor(const FHitResult &Hit);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool HasOnlineFeatures(const UObject *WorldContextObject, const APlayerController *Controller);

    UFUNCTION(BlueprintPure)
    static bool HasEventualParentActorOfType(const AActor *Actor, TSubclassOf<AActor> actorType);

    UFUNCTION(BlueprintPure)
    static bool HasComponentOfType(TSubclassOf<AActor> actorType, TSubclassOf<UActorComponent> ComponentType);

    UFUNCTION(BlueprintCallable)
    static FVector2D GetWidgetOuterCanvasPosition(UWidget *Widget);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool GetUseSplitscreen(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static int32 GetTotalSizeOfAllCachedSaveFiles(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static FVector2D GetTextBoundsForFont(FText Text, FSlateFontInfo FontInfo);

    UFUNCTION(BlueprintPure)
    static float GetSkeletalMeshPlaybackRatio(const USkeletalMeshComponent *Mesh);

    UFUNCTION(BlueprintCallable)
    static FIntPoint GetScreenResolution();

    UFUNCTION(BlueprintPure)
    static float GetPostProcessVignetting(const FPostProcessSettings &Settings);

    UFUNCTION(BlueprintPure)
    static float GetPostProcessLensFlare(const FPostProcessSettings &Settings);

    UFUNCTION(BlueprintPure)
    static int32 GetPlatformSaveStorageLimit();

    UFUNCTION(BlueprintPure)
    static int32 GetPlatformLowFreeStorageSpaceThreshold();

    UFUNCTION(BlueprintPure)
    static APlayerController *GetOwnerPlayerControllerForActor(const AActor *Actor);

    UFUNCTION(BlueprintPure)
    static APlayerController *GetOwnerPlayerController(UActorComponent *Component);

    UFUNCTION(BlueprintPure)
    static APawn *GetOwnerPawnForActor(const AActor *Actor);

    UFUNCTION(BlueprintPure)
    static APawn *GetOwnerPawn(UActorComponent *Component);

    UFUNCTION(BlueprintPure)
    static AActor *GetOutermostActor(AActor *Actor);

    UFUNCTION(BlueprintPure)
    static bool GetNumberOfPlayersInMultiplayerSession(int32 &outNumPlayersInSession);

    UFUNCTION(BlueprintPure)
    static TArray<FPlayerNicknameAndPlatform> GetNicknamesAndPlatformsOfPlayersInMultiplayerSession(bool bExcludeLocalControllingPlayer);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static TArray<FAstroSaveFileInformation> GetNewestSaves(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static FAstroSaveFileInformation GetNewestSave(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool GetMultiplayerSessionLeaderName(FString &OutSessionLeaderName);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static APawn *GetLocalPawn(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static TArray<FString> GetLocalGames(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static UObject *GetKeyImageForKey(FKey Key);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static UObject *GetKeyImageForInteractionPrompt(UObject *WorldContextObject, FInteractionPromptEntryData PromptData, bool ForceKeyboardImage);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static UObject *GetKeyImageForGamepadInput(UObject *WorldContextObject, FKey Key);

    UFUNCTION(BlueprintPure)
    static FName GetInputNameFromInputMapping(EAstroInputBindingNameMappings ActionMapping);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static AAstroGameState *GetGameState(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static EGamePlatform GetGamePlatform();

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static AAstroGameMode *GetGameMode(const UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static UAstroGameInstance *GetGameInstance(const UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<EWindowMode::Type> GetFullscreenMode();

    UFUNCTION(BlueprintPure)
    static FAstroDiscreteInputDefinition GetDiscreteAstroInputDefinition(EAstroDiscreteInputOptionPlayerFacing DiscretePlayerFacingInputOption);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static FString GetDedicatedServerUrl(const UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static FString GetDedicatedServerSearchName(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool GetCVar_Integer(const FString &cvarName, int32 &outInteger);

    UFUNCTION(BlueprintPure)
    static int32 GetCvar_EnableBackpackTrickleCharge();

    UFUNCTION(BlueprintPure)
    static int32 GetCvar_DeformTool_UseTerrainResource();

    UFUNCTION(BlueprintPure)
    static int32 GetCvar_DeformTool_UsePowerDraw();

    UFUNCTION(BlueprintPure)
    static EGameControllerType GetCurrentControllerType();

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static void GetCreativeModeTerrainColors(const UObject *WorldContextObject, TArray<UMaterialInterface *> &OutMaterials, TArray<FLinearColor> &OutTerrainColors);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static FLinearColor GetCreativeModeTerrainColorAtIndex(int32 colorIndex, EPaintIndexType Type, const UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static FLinearColor GetCreativeModeTerrainColor(const UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static UMaterialInterface *GetCreativeModeTerrainButtonColor(const UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static void GetCreativeModeSpecialColors(TArray<FLinearColor> &OutPlanetColors, TArray<UMaterialInterface *> &OutMaterials, const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static void GetCreativeModePlanetColors(const AActor *forActor, TArray<FLinearColor> &OutPlanetColors, TArray<UMaterialInterface *> &OutMaterials);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static UCreativeModeData *GetCreativeModeData(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static FString GetControllingPlayerNickname();

    UFUNCTION(BlueprintPure)
    static void GetComponentsInChildren(AActor *Actor, TSubclassOf<UActorComponent> Class, TArray<UActorComponent *> &OutComponents);

    UFUNCTION(BlueprintPure)
    static TArray<USceneComponent *> GetComponentParentHierarchy(USceneComponent *Component, bool Inclusive);

    UFUNCTION(BlueprintPure)
    static void GetChildrenRecursive(AActor *Actor, TArray<AActor *> &OutActors, bool Inclusive);

    UFUNCTION(BlueprintPure)
    static FString GetBuildVersionWithFlavor();

    UFUNCTION(BlueprintPure)
    static FString GetBuildVersion();

    UFUNCTION(BlueprintPure)
    static bool GetBitValue(int32 BitMask, int32 BitIndex);

    UFUNCTION(BlueprintPure)
    static AActor *GetAttachParentActor(AActor *Actor);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static AAstroMissionsManager *GetAstroMissionsManager(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static FSlateColor GetAstroColorAsSlateColor(EAstroColor AstroColor);

    UFUNCTION(BlueprintPure)
    static FLinearColor GetAstroColor(EAstroColor AstroColor);

    UFUNCTION(BlueprintPure)
    static TArray<AActor *> GetActorParentHierarchy(AActor *Actor, bool Inclusive);

    UFUNCTION(BlueprintPure)
    static FRotator FromToRotation(const FVector &From, const FVector &To);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void ForceDestroySession(const UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void ForceCreateSession(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static float FInterpCombo(float Current, float Target, float ConstantSpeed, float MultiplicativeSpeed, float DeltaTime);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void FindLocalGames(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static UActorComponent *FindComponentByName(AActor *Actor, FName ComponentName);

    UFUNCTION(BlueprintPure)
    static FRotator FindBetween(FVector A, FVector B);

    UFUNCTION(BlueprintCallable)
    static void EnqueueSkeletalMeshPlayRate(USkeletalMeshComponent *Mesh, float Rate);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static bool DuplicateSaveFile(UObject *WorldContextObject, const FString &CurrSaveName, const FString &newDescriptiveSaveName, FOnAstroSaveCompletedDynamic OnCompletedDelegate);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool DoesSaveFileDescriptiveNameCollideWithExistingSaves(UObject *WorldContextObject, const FString &newDescriptiveSaveName);

    UFUNCTION(BlueprintPure)
    static bool DoesKeyMatchInputBinding(EAstroInputBindingNameMappings InputBinding, float AxisScale, FKey Key);

    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void DisplayLoadingUMG(APlayerController *PlayerController, TSubclassOf<UUserWidget> LoadingWidgetOverride);

    UFUNCTION(BlueprintCallable)
    static void DestroyChildActors(AActor *Actor);

    UFUNCTION(BlueprintCallable)
    static void DestroyActorHierarchy(AActor *Actor, bool includeSelf);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static bool DeleteSaveGame(UObject *WorldContextObject, const FAstroSaveFileInformation &SaveDisplayInfo);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void DeleteAllSaves(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static FString DateTimeToString(const FDateTime &DateTime);

    UFUNCTION(BlueprintCallable)
    static UMaterialInstanceDynamic *CreatePostprocessMaterialDynamic(int32 Index, UPostProcessComponent *PostProcess);

    UFUNCTION(BlueprintCallable)
    static TArray<UMaterialInstanceDynamic *> CreateAllDynamicMaterialInstances(AActor *Actor, UMaterialInterface *Material);

    UFUNCTION(BlueprintCallable)
    static TArray<UMaterialInstanceDynamic *> CreateAllComponentDynamicMaterialInstances(UPrimitiveComponent *Component, UMaterialInterface *Material);

    UFUNCTION(BlueprintCallable)
    static UMaterialInstanceDynamic *CreateAllComponentDynamicMaterialInstance(UPrimitiveComponent *Component, UMaterialInterface *Material);

    UFUNCTION(BlueprintPure)
    static FTransform ConvertToRelativeTransform(const FTransform &ParentTransform, const FTransform &Transform);

    UFUNCTION(BlueprintPure)
    static TArray<FText> ConvertIntegerToArrayOfText(int32 InInteger);

    UFUNCTION(BlueprintPure)
    static FVector ClosestPointOnLine(const FVector &LineStart, const FVector &LineEnd, const FVector &Point, float &T);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static void ChangeMultiplayerMode(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static int32 CastPhysicalSurfaceToInteger(TEnumAsByte<EPhysicalSurface> surface);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool CanGetSavedGames(UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static void AddPostProcessBlendableMaterial(const FPostProcessSettings &InSettings, FPostProcessSettings &OutSettings, UMaterial *Material);

    UFUNCTION(BlueprintPure)
    static bool ActorSimulatingPhysics(AActor *Actor);

    UFUNCTION(BlueprintPure)
    static bool ActorOnClickedBound(AActor *Actor);

    UFUNCTION(BlueprintCallable)
    static void ActorCallOnClicked(AActor *Actor);
};
