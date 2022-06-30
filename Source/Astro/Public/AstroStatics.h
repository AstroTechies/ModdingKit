#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EAstroDiscreteInputOptionPlayerFacing.h"
#include "PlayerNicknameAndPlatform.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InputCoreTypes.h"
#include "UObject/NoExportTypes.h"
#include "OnAstroRenameSaveCompletedDynamicDelegate.h"
#include "UObject/NoExportTypes.h"
#include "EGamePlatform.h"
#include "ESaveGameErrorType.h"
#include "Components/SlateWrapperTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/Scene.h"
#include "EPaintIndexType.h"
#include "Styling/SlateColor.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "OnAstroSaveCompletedDynamicDelegate.h"
#include "Engine/EngineTypes.h"
#include "Engine/NetSerialization.h"
#include "Engine/NetSerialization.h"
#include "UObject/NoExportTypes.h"
#include "Fonts/SlateFontInfo.h"
#include "UObject/NoExportTypes.h"
#include "AstroSaveFileInformation.h"
#include "InteractionPromptEntryData.h"
#include "EAstroInputBindingNameMappings.h"
#include "GameFramework/GameUserSettings.h"
#include "AstroDiscreteInputDefinition.h"
#include "EGameControllerType.h"
#include "EAstroColor.h"
#include "UObject/NoExportTypes.h"
#include "AstroStatics.generated.h"

class AActor;
class AAstroMissionsManager;
class UPhysicsConstraintComponent;
class UPrimitiveComponent;
class UObject;
class APawn;
class UAstroSaveAsset;
class UCreativeModeData;
class UWidget;
class APlayerController;
class UActorComponent;
class USkeletalMeshComponent;
class UAudioComponent;
class UChildActorComponent;
class USoundBase;
class UPanelWidget;
class UMaterialInstanceDynamic;
class AAstroGameMode;
class UMaterialInterface;
class UMaterial;
class AAstroGameState;
class UAstroGameInstance;
class USceneComponent;
class UUserWidget;
class UPostProcessComponent;

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API UAstroStatics : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UAstroStatics();
    UFUNCTION(BlueprintPure)
    static FVector2D WorldLocationToScreenLocationOffset(UObject *WorldContextObject, const FVector &WorldLocation, const FVector2D &WorldOffset);

    UFUNCTION(BlueprintPure)
    static FVector2D WorldLocationToScreenLocation(UObject *WorldContextObject, const FVector &WorldLocation);

    UFUNCTION(BlueprintPure)
    static ESaveGameErrorType WasThereAnErrorTryingToSaveTheGame(UObject *WorldContextObject, FString &outSaveName, int32 &outSaveSize);

    UFUNCTION(BlueprintPure)
    static FVector VInterpCombo(const FVector &Current, const FVector &Target, float ConstantSpeed, float MultiplicativeSpeed, float DeltaTime);

    UFUNCTION(BlueprintPure)
    static FVector VelocityAtWorldLocation(UPrimitiveComponent *Component, FVector Location);

    UFUNCTION(BlueprintCallable)
    static void UpdatePhysicsConstraintFrames(UPhysicsConstraintComponent *Component);

    UFUNCTION(BlueprintPure)
    static UCreativeModeData *TryGetCreativeModeData(const UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static void ToggleUMGHidden(UWidget *Widget, ESlateVisibility VisibleState);

    UFUNCTION(BlueprintCallable)
    static void ToggleCreativeModeLodAnchorPreview(const UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static bool SweepPrimitiveComponentMulti(UPrimitiveComponent *Component, const FVector &Start, const FVector &End, TArray<FHitResult> &OutHits);

    UFUNCTION(BlueprintCallable)
    static bool SweepPrimitiveComponentByProfile(UPrimitiveComponent *Component, const FVector &Start, const FVector &End, FHitResult &OutHit, FName Profile);

    UFUNCTION(BlueprintCallable)
    static bool SweepPrimitiveComponent(UPrimitiveComponent *Component, const FVector &Start, const FVector &End, FHitResult &OutHit);

    UFUNCTION(BlueprintCallable)
    static int32 StringChecksum(const FString &String, int32 Hash);

    UFUNCTION(BlueprintPure)
    static float Sinusoid(float Speed, UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static bool ShowSelectNetworkUI(const UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static void ShowLoggingUI(const UObject *WorldContextObject, const APlayerController *Controller);

    UFUNCTION(BlueprintCallable)
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

    UFUNCTION(BlueprintCallable)
    static void SetStateFirstAvailableSaveSlot(UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static void SetSkeletalMeshPlaybackRatio(USkeletalMeshComponent *Mesh, float PlaybackRatio, bool bFireNotifies);

    UFUNCTION(BlueprintCallable)
    static void SetPostProcessVignetting(const FPostProcessSettings &InSettings, FPostProcessSettings &OutSettings, float Value);

    UFUNCTION(BlueprintCallable)
    static void SetPostProcessLensFlare(const FPostProcessSettings &InSettings, FPostProcessSettings &OutSettings, float Value);

    UFUNCTION(BlueprintCallable)
    static void SetNearClippingPlane(float Distance);

    UFUNCTION(BlueprintCallable)
    static void SetMultiplayerMode(const UObject *WorldContextObject, const bool online);

    UFUNCTION(BlueprintCallable)
    static void SetCuePlaying(UAudioComponent *Sound, bool Play, float Fade);

    UFUNCTION(BlueprintCallable)
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

    UFUNCTION(BlueprintCallable)
    static void SaveGameNoCloudSave(UObject *WorldContextObject, const FString &Name, FOnAstroSaveCompletedDynamic OnCompletedDelegate);

    UFUNCTION(BlueprintCallable)
    static void SaveGameAuto(UObject *WorldContextObject, FOnAstroSaveCompletedDynamic OnCompletedDelegate);

    UFUNCTION(BlueprintCallable)
    static void SaveGame(UObject *WorldContextObject, const FString &Name, FOnAstroSaveCompletedDynamic OnCompletedDelegate);

    UFUNCTION(BlueprintPure)
    static FString SanitizeSaveFileDescriptiveName(const FString &SaveFileDescriptiveName);

    UFUNCTION(BlueprintPure)
    static int32 RollIntegerIncrement(int32 Value, int32 Max);

    UFUNCTION(BlueprintPure)
    static int32 RollIntegerDecrement(int32 Value, int32 Max);

    UFUNCTION(BlueprintCallable)
    static bool ReturnToTitleScreen(UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static bool RenameSaveFile(UObject *WorldContextObject, const FString &CurrSaveName, const FString &newDescriptiveSaveName, FOnAstroRenameSaveCompletedDynamic OnCompletedDelegate);

    UFUNCTION(BlueprintPure)
    static float ReinterpretIntToFloat(int32 Int);

    UFUNCTION(BlueprintPure)
    static int32 ReinterpretFloatToInt(float Float);

    UFUNCTION(BlueprintPure)
    static bool PredictIfActiveSaveFileIsTooLargeToSave(UObject *WorldContextObject, FString &outSaveName, int32 &outSaveSize);

    UFUNCTION(BlueprintCallable)
    static void PopulateSpawnableObjects(UPanelWidget *Widget, const FString &nameFilter);

    UFUNCTION(BlueprintCallable)
    static void PopulateSaveGames(UPanelWidget *Widget);

    UFUNCTION(BlueprintCallable)
    static void PopulateResourceTypes(UPanelWidget *Widget);

    UFUNCTION(BlueprintCallable)
    static void PopulateLoadablePresets(UPanelWidget *Widget);

    UFUNCTION(BlueprintCallable)
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

    UFUNCTION(BlueprintCallable)
    static bool LoadMapSeamless(FName MapName, const FString &Options, bool bAbsolute, UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static bool LoadGameFromAsset(UObject *WorldContext, const TSoftObjectPtr<UAstroSaveAsset> &saveAssetPtr);

    UFUNCTION(BlueprintCallable)
    static bool LoadGame(const FString &Name, UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static float LerpToRange(float Min, float Max, float CurrentValue, float TargetLerp, float Alpha);

    UFUNCTION(BlueprintCallable)
    static void JoinToURL(const FString &Name, const UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static void JoinLocalGame(const UObject *WorldContextObject, const FString &GameID);

    UFUNCTION(BlueprintPure)
    static bool IsWorldTearingDown(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool IsWorldGameWorld(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool IsValidAstroLinearColor(const FLinearColor &ColorToTest);

    UFUNCTION(BlueprintPure)
    static bool IsTrailerBuild(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool IsStoreUIEnabled();

    UFUNCTION(BlueprintPure)
    static bool IsShippingBuild();

    UFUNCTION(BlueprintPure)
    static bool IsServer(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool IsSaveRestoreInProgress();

    UFUNCTION(BlueprintPure)
    static bool IsSavePermittedOverrideEnabled();

    UFUNCTION(BlueprintPure)
    static bool IsSaveFileDescriptiveNameTheActiveSaveFile(UObject *WorldContextObject, const FString &DescriptiveName);

    UFUNCTION(BlueprintPure)
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

    UFUNCTION(BlueprintPure)
    static bool IsNetworkAvailable(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool IsLocalProfile(const UObject *WorldContextObject, const APlayerController *Controller);

    UFUNCTION(BlueprintPure)
    static bool IsLocalControlledPawn(APawn *Pawn);

    UFUNCTION(BlueprintPure)
    static bool IsLocalCommunications(const UObject *WorldContextObject, const APlayerController *Controller);

    UFUNCTION(BlueprintPure)
    static bool IsLanMatch(const UObject *WorldContextObject, const APlayerController *Controller);

    UFUNCTION(BlueprintPure)
    static bool IsDedicatedServerUIEnabled();

    UFUNCTION(BlueprintPure)
    static bool IsDedicatedServer(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool IsCreativeMode(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool IsConnectedToDedicatedServer(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool IsAsyncSaveInProgress();

    UFUNCTION(BlueprintPure)
    static bool IsAnalyticsEnabled(UObject *WorldContextObject);

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

    UFUNCTION(BlueprintPure)
    static bool HasOnlineFeatures(const UObject *WorldContextObject, const APlayerController *Controller);

    UFUNCTION(BlueprintPure)
    static bool HasEventualParentActorOfType(const AActor *Actor, TSubclassOf<AActor> actorType);

    UFUNCTION(BlueprintPure)
    static bool HasComponentOfType(TSubclassOf<AActor> actorType, TSubclassOf<UActorComponent> ComponentType);

    UFUNCTION(BlueprintCallable)
    static FVector2D GetWidgetOuterCanvasPosition(UWidget *Widget);

    UFUNCTION(BlueprintPure)
    static bool GetUseSplitscreen(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
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

    UFUNCTION(BlueprintPure)
    static TArray<FAstroSaveFileInformation> GetNewestSaves(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static FAstroSaveFileInformation GetNewestSave(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static bool GetMultiplayerSessionLeaderName(FString &OutSessionLeaderName);

    UFUNCTION(BlueprintPure)
    static APawn *GetLocalPawn(UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static TArray<FString> GetLocalGames(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static UObject *GetKeyImageForKey(FKey Key);

    UFUNCTION(BlueprintPure)
    static UObject *GetKeyImageForInteractionPrompt(UObject *WorldContextObject, FInteractionPromptEntryData PromptData, bool ForceKeyboardImage);

    UFUNCTION(BlueprintPure)
    static UObject *GetKeyImageForGamepadInput(UObject *WorldContextObject, FKey Key);

    UFUNCTION(BlueprintPure)
    static FName GetInputNameFromInputMapping(EAstroInputBindingNameMappings ActionMapping);

    UFUNCTION(BlueprintPure)
    static AAstroGameState *GetGameState(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static EGamePlatform GetGamePlatform();

    UFUNCTION(BlueprintPure)
    static AAstroGameMode *GetGameMode(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static UAstroGameInstance *GetGameInstance(const UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<EWindowMode::Type> GetFullscreenMode();

    UFUNCTION(BlueprintPure)
    static FAstroDiscreteInputDefinition GetDiscreteAstroInputDefinition(EAstroDiscreteInputOptionPlayerFacing DiscretePlayerFacingInputOption);

    UFUNCTION(BlueprintCallable)
    static FString GetDedicatedServerUrl(const UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
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

    UFUNCTION(BlueprintPure)
    static void GetCreativeModeTerrainColors(const UObject *WorldContextObject, TArray<UMaterialInterface *> &OutMaterials, TArray<FLinearColor> &OutTerrainColors);

    UFUNCTION(BlueprintPure)
    static FLinearColor GetCreativeModeTerrainColorAtIndex(int32 colorIndex, EPaintIndexType Type, const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static FLinearColor GetCreativeModeTerrainColor(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static UMaterialInterface *GetCreativeModeTerrainButtonColor(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static void GetCreativeModeSpecialColors(TArray<FLinearColor> &OutPlanetColors, TArray<UMaterialInterface *> &OutMaterials, const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static void GetCreativeModePlanetColors(const AActor *forActor, TArray<FLinearColor> &OutPlanetColors, TArray<UMaterialInterface *> &OutMaterials);

    UFUNCTION(BlueprintPure)
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

    UFUNCTION(BlueprintPure)
    static AAstroMissionsManager *GetAstroMissionsManager(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static FSlateColor GetAstroColorAsSlateColor(EAstroColor AstroColor);

    UFUNCTION(BlueprintPure)
    static FLinearColor GetAstroColor(EAstroColor AstroColor);

    UFUNCTION(BlueprintPure)
    static TArray<AActor *> GetActorParentHierarchy(AActor *Actor, bool Inclusive);

    UFUNCTION(BlueprintPure)
    static FRotator FromToRotation(const FVector &From, const FVector &To);

    UFUNCTION(BlueprintCallable)
    static void ForceDestroySession(const UObject *WorldContextObject);

    UFUNCTION(BlueprintCallable)
    static void ForceCreateSession(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static float FInterpCombo(float Current, float Target, float ConstantSpeed, float MultiplicativeSpeed, float DeltaTime);

    UFUNCTION(BlueprintCallable)
    static void FindLocalGames(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static UActorComponent *FindComponentByName(AActor *Actor, FName ComponentName);

    UFUNCTION(BlueprintPure)
    static FRotator FindBetween(FVector A, FVector B);

    UFUNCTION(BlueprintCallable)
    static void EnqueueSkeletalMeshPlayRate(USkeletalMeshComponent *Mesh, float Rate);

    UFUNCTION(BlueprintCallable)
    static bool DuplicateSaveFile(UObject *WorldContextObject, const FString &CurrSaveName, const FString &newDescriptiveSaveName, FOnAstroSaveCompletedDynamic OnCompletedDelegate);

    UFUNCTION(BlueprintPure)
    static bool DoesSaveFileDescriptiveNameCollideWithExistingSaves(UObject *WorldContextObject, const FString &newDescriptiveSaveName);

    UFUNCTION(BlueprintPure)
    static bool DoesKeyMatchInputBinding(EAstroInputBindingNameMappings InputBinding, float AxisScale, FKey Key);

    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void DisplayLoadingUMG(APlayerController *PlayerController, TSubclassOf<UUserWidget> LoadingWidgetOverride);

    UFUNCTION(BlueprintCallable)
    static void DestroyChildActors(AActor *Actor);

    UFUNCTION(BlueprintCallable)
    static void DestroyActorHierarchy(AActor *Actor, bool includeSelf);

    UFUNCTION(BlueprintCallable)
    static bool DeleteSaveGame(UObject *WorldContextObject, const FAstroSaveFileInformation &SaveDisplayInfo);

    UFUNCTION(BlueprintCallable)
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

    UFUNCTION(BlueprintCallable)
    static void ChangeMultiplayerMode(const UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static int32 CastPhysicalSurfaceToInteger(TEnumAsByte<EPhysicalSurface> surface);

    UFUNCTION(BlueprintPure)
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
