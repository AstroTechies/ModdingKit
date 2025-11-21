#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=uint8 -FallbackName=uint8
#include "GameFramework/GameUserSettings.h"
#include "Engine/EngineTypes.h"
#include "Engine/Scene.h"
#include "Engine/EngineTypes.h"
#include "Engine/NetSerialization.h"
#include "Engine/NetSerialization.h"
#include "InputCoreTypes.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Styling/SlateColor.h"
#include "Fonts/SlateFontInfo.h"
#include "Components/SlateWrapperTypes.h"
#include "AstroActivityData.h"
#include "AstroClientProperties.h"
#include "AstroDiscreteInputDefinition.h"
#include "AstroLightBarData.h"
#include "AstroSaveFileInformation.h"
#include "EAstroColor.h"
#include "EAstroDiscreteInputOptionPlayerFacing.h"
#include "EAstroInputBindingNameMappings.h"
#include "EAstroLightBar.h"
#include "EAstroPSActivity.h"
#include "EAstroWwiseDevice.h"
#include "EGameControllerType.h"
#include "EGamePlatform.h"
#include "EPaintIndexType.h"
#include "EPlanetIdentifier.h"
#include "ESaveGameErrorType.h"
#include "InteractionPromptEntryData.h"
#include "OnAstroRenameSaveCompletedDynamicDelegate.h"
#include "OnAstroSaveCompletedDynamicDelegate.h"
#include "PlayerNicknameAndPlatform.h"
#include "Templates/SubclassOf.h"
#include "AstroStatics.generated.h"

class AActor;
class AAstroCustomGameManager;
class AAstroGameMode;
class AAstroGameState;
class AAstroMissionsManager;
class AAstroPlayerController;
class APawn;
class APlayController;
class APlayerController;
class UActorComponent;
//class UAstroDlcManager;
class UAstroEmoteDefinition;
class UAstroGameInstance;
class UAstroPSActivitiesDatabase;
class UAstroSaveAsset;
class UAudioComponent;
class UChildActorComponent;
class UCreativeModeData;
class ULightBarManager;
class UMaterial;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UObject;
class UPSActivitiesManager;
class UPanelWidget;
class UPhysicsConstraintComponent;
class UPostProcessComponent;
class UPrimitiveComponent;
class USceneComponent;
class USkeletalMeshComponent;
class USoundBase;
class UUserWidget;
class UWidget;

UCLASS(Blueprintable)
class ASTRO_API UAstroStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAstroStatics();

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FVector2D WorldLocationToScreenLocationOffset(UObject* WorldContextObject, const FVector& WorldLocation, const FVector2D& WorldOffset);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FVector2D WorldLocationToScreenLocation(UObject* WorldContextObject, const FVector& WorldLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static ESaveGameErrorType WasThereAnErrorTryingToSaveTheGame(UObject* WorldContextObject, FString& outSaveName, int32& outSaveSize);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector VInterpCombo(const FVector& Current, const FVector& Target, float ConstantSpeed, float MultiplicativeSpeed, float DeltaTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector VelocityAtWorldLocation(UPrimitiveComponent* Component, FVector Location);
    
    UFUNCTION(BlueprintCallable)
    static void UpdatePhysicsConstraintFrames(UPhysicsConstraintComponent* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UPSActivitiesManager* TryGetPSActivitiesManager(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static ULightBarManager* TryGetLightBarManager(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UCreativeModeData* TryGetCreativeModeData(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void ToggleUMGHidden(UWidget* Widget, ESlateVisibility VisibleState);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ToggleCreativeModeLodAnchorPreview(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static bool SweepPrimitiveComponentMulti(UPrimitiveComponent* Component, const FVector& Start, const FVector& End, TArray<FHitResult>& OutHits);
    
    UFUNCTION(BlueprintCallable)
    static bool SweepPrimitiveComponentByProfile(UPrimitiveComponent* Component, const FVector& Start, const FVector& End, FHitResult& OutHit, FName Profile);
    
    UFUNCTION(BlueprintCallable)
    static bool SweepPrimitiveComponent(UPrimitiveComponent* Component, const FVector& Start, const FVector& End, FHitResult& OutHit);
    
    UFUNCTION(BlueprintCallable)
    static int32 StringChecksum(const FString& String, int32 Hash);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static float Sinusoid(float Speed, UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool ShowSelectNetworkUI(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ShowLoggingUI(const UObject* WorldContextObject, const APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ShowLodAnchorBeacons(bool doShow, UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void SetWeldedComponentLocation(UPrimitiveComponent* Component, const FVector& WorldLocation);
    
    UFUNCTION(BlueprintCallable)
    static void SetUIEnabled(UPrimitiveComponent* Component, bool Enable);
    
    UFUNCTION(BlueprintCallable)
    static void SetTraceEnabled(UPrimitiveComponent* Component, bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    static void SetTraceAndCollisionEnabled(UPrimitiveComponent* Component, bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    static FTimerHandle SetTimerFromFunctionWithDelay(UObject* Object, const FString& FunctionName, float Time, bool bLooping, float InitialDelay);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetStateFirstAvailableSaveSlot(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static APlayController* SetSolarSelection_PlanetOnly(UObject* WorldContextObject, const bool bInEnabled);
    
    UFUNCTION(BlueprintCallable)
    static void SetSkeletalMeshPlaybackRatio(USkeletalMeshComponent* Mesh, float PlaybackRatio, bool bFireNotifies);
    
    UFUNCTION(BlueprintCallable)
    static void SetPostProcessVignetting(const FPostProcessSettings& InSettings, FPostProcessSettings& OutSettings, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetPostProcessLensFlare(const FPostProcessSettings& InSettings, FPostProcessSettings& OutSettings, float Value);
    
    UFUNCTION(BlueprintCallable)
    static bool SetPlayerPropertiesForCustomGame(AAstroCustomGameManager* CustomGameManager, AAstroPlayerController* PlayerController, const FAstroClientProperties& clientProperties);
    
    UFUNCTION(BlueprintCallable)
    static void SetNearClippingPlane(float Distance);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetMultiplayerMode(const UObject* WorldContextObject, const bool online);
    
    UFUNCTION(BlueprintCallable)
    static void SetCuePlaying(UAudioComponent* Sound, bool Play, float Fade);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetCreativeModeTerrainColorIndex(int32 colorIndex, EPaintIndexType Type, const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void SetCollisionEnabled(UPrimitiveComponent* Component, bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    static void SetChildActorPhysics(UChildActorComponent* ChildActor, bool Physics, bool Collision);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 SetBitValue(int32 BitMask, int32 BitIndex, bool BitValue);
    
    UFUNCTION(BlueprintCallable)
    static void SetAllVectorParameterValue(TArray<UMaterialInstanceDynamic*> DynamicInstances, FName Parameter, FLinearColor Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetAllScalarParameterValue(TArray<UMaterialInstanceDynamic*> DynamicInstances, FName Parameter, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetAllMaterial(AActor* Actor, UMaterialInterface* Material);
    
    UFUNCTION(BlueprintCallable)
    static void SetAllComponentMaterial(UPrimitiveComponent* Component, UMaterialInterface* Material);
    
    UFUNCTION(BlueprintCallable)
    static void SetActorUp(AActor* Actor, const FVector& Forward);
    
    UFUNCTION(BlueprintCallable)
    static void SetActorTraceEnabled(AActor* Actor, bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    static void SetActorSimulatePhysics(AActor* Actor, bool Simulate);
    
    UFUNCTION(BlueprintCallable)
    static void SetActorRight(AActor* Actor, const FVector& Forward);
    
    UFUNCTION(BlueprintCallable)
    static void SetActorForward(AActor* Actor, const FVector& Forward);
    
    UFUNCTION(BlueprintCallable)
    static void SetActorCollisionEnabled(AActor* Actor, bool Enabled);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetActiveSaveFileForCustomGame(UObject* WorldContextObject, const FString& Name);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SaveGameNoCloudSave(UObject* WorldContextObject, const FString& Name, FOnAstroSaveCompletedDynamic OnCompletedDelegate);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SaveGameAuto(UObject* WorldContextObject, FOnAstroSaveCompletedDynamic OnCompletedDelegate);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SaveGame(UObject* WorldContextObject, const FString& Name, FOnAstroSaveCompletedDynamic OnCompletedDelegate);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString SanitizeSaveFileDescriptiveName(const FString& SaveFileDescriptiveName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 RollIntegerIncrement(int32 Value, int32 Max);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 RollIntegerDecrement(int32 Value, int32 Max);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool ReturnToTitleScreen(UObject* WorldContextObject, bool DisplayOutOfLivesPrompt);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool RenameSaveFile(UObject* WorldContextObject, const FString& CurrSaveName, const FString& newDescriptiveSaveName, FOnAstroRenameSaveCompletedDynamic OnCompletedDelegate);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float ReinterpretIntToFloat(int32 Int);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 ReinterpretFloatToInt(float Float);
    
    UFUNCTION(BlueprintCallable)
    static void PreviewEmoteLocally(USkeletalMeshComponent* targetMesh, UAstroEmoteDefinition* emoteDefinition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool PredictIfActiveSaveFileIsTooLargeToSave(UObject* WorldContextObject, FString& outSaveName, int32& outSaveSize);
    
    UFUNCTION(BlueprintCallable)
    static void PopulateSpawnableObjects(UPanelWidget* Widget, const FString& nameFilter);
    
    UFUNCTION(BlueprintCallable)
    static void PopulateSaveGames(UPanelWidget* Widget);
    
    UFUNCTION(BlueprintCallable)
    static void PopulateResourceTypes(UPanelWidget* Widget);
    
    UFUNCTION(BlueprintCallable)
    static void PopulateLoadablePresets(UPanelWidget* Widget);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PlaySound(USoundBase* Sound, UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void PhysicsConstrain(UPrimitiveComponent* Target, UPrimitiveComponent* Other);
    
    UFUNCTION(BlueprintCallable)
    static void NullInspectObject(UObject* Object);
    
    UFUNCTION(BlueprintCallable)
    static void MarkPrimitiveRenderStateDirty(UPrimitiveComponent* Primitive);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector_NetQuantizeNormal MakeVectorQuantizeNormal(const FVector& Vector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector_NetQuantize100 MakeVectorQuantize100(const FVector& Vector);
    
    UFUNCTION(BlueprintCallable)
    static void MakeInert(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 LogInt(int32 Val, int32 Base);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool LoadMapSeamless(FName MapName, const FString& Options, bool bAbsolute, UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static bool LoadGameFromAsset(UObject* WorldContext, const TSoftObjectPtr<UAstroSaveAsset>& saveAssetPtr);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool LoadGame(const FString& Name, UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float LerpToRange(float Min, float Max, float CurrentValue, float TargetLerp, float Alpha);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void JoinToURL(const FString& Name, const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void JoinLocalGame(const UObject* WorldContextObject, const FString& GameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsWorldTearingDown(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsWorldGameWorld(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsValidAstroLinearColor(const FLinearColor& ColorToTest);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsTrailerBuild(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsStoreUIEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsShippingBuild();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsServer(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSaveRestoreInProgress();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSavePermittedOverrideEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsSaveFileDescriptiveNameTheActiveSaveFile(UObject* WorldContextObject, const FString& DescriptiveName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsReleaseBuild(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlatformUWPOrXbox();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlatformSwitchOrSwitchPreview();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlatformSwitch();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlatformPS5();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlatformPS4();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlatformPS();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlatformMKBEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlatformGameConsole();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsNetworkAvailable(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsLocalProfile(const UObject* WorldContextObject, const APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsLocalControlledPawn(APawn* Pawn);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsLocalCommunications(const UObject* WorldContextObject, const APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsLanMatch(const UObject* WorldContextObject, const APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDedicatedServerUIEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsDedicatedServer(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsCreativeMode(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsConnectedToDedicatedServer(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsAsyncSaveInProgress();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsAnalyticsEnabled(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float InterpToRange(float Min, float Max, float CurrentValue, float TargetLerp, float DeltaTime, float Speed);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static uint8 ImportPS4SaveDataToPS5(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FTransform IdentityTransform();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector HitLocation(const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector HitImpactPoint(const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector HitImpactNormal(const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UPrimitiveComponent* HitImpactComponent(const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static AActor* HitImpactActor(const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool HasOnlineFeatures(const UObject* WorldContextObject, const APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasEventualParentActorOfType(const AActor* Actor, TSubclassOf<AActor> actorType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasComponentOfType(TSubclassOf<AActor> actorType, TSubclassOf<UActorComponent> ComponentType);
    
    UFUNCTION(BlueprintCallable)
    static FVector2D GetWidgetOuterCanvasPosition(UWidget* Widget);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool GetUseSplitscreen(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static int32 GetTotalSizeOfAllCachedSaveFiles(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector2D GetTextBoundsForFont(FText Text, FSlateFontInfo FontInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetSkeletalMeshPlaybackRatio(const USkeletalMeshComponent* Mesh);
    
    UFUNCTION(BlueprintCallable)
    static FIntPoint GetScreenResolution();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetPostProcessVignetting(const FPostProcessSettings& Settings);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetPostProcessLensFlare(const FPostProcessSettings& Settings);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetPlatformSaveStorageLimit();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetPlatformLowFreeStorageSpaceThreshold();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static AActor* GetParentOfType(const AActor* Parent, const TSubclassOf<AActor> InClass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static APlayerController* GetOwnerPlayerControllerForActor(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static APlayerController* GetOwnerPlayerController(UActorComponent* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static APawn* GetOwnerPawnForActor(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static APawn* GetOwnerPawn(UActorComponent* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static AActor* GetOutermostActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetNumberOfPlayersInMultiplayerSession(int32& outNumPlayersInSession);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FPlayerNicknameAndPlatform> GetNicknamesAndPlatformsOfPlayersInMultiplayerSession(bool bExcludeLocalControllingPlayer);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static TArray<FAstroSaveFileInformation> GetNewestSaves(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FAstroSaveFileInformation GetNewestSave(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetMultiplayerSessionLeaderName(FString& OutSessionLeaderName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static APawn* GetLocalPawn(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static TArray<FString> GetLocalGames(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UObject* GetKeyImageForKey(FKey Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UObject* GetKeyImageForInteractionPrompt(UObject* WorldContextObject, FInteractionPromptEntryData PromptData, bool ForceKeyboardImage);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UObject* GetKeyImageForGamepadInput(UObject* WorldContextObject, FKey Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetInputNameFromInputMapping(EAstroInputBindingNameMappings ActionMapping);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static AAstroGameState* GetGameState(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EGamePlatform GetGamePlatform();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static AAstroGameMode* GetGameMode(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UAstroGameInstance* GetGameInstance(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<EWindowMode::Type> GetFullscreenMode();
    
//    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
//    static UAstroDlcManager* GetDlcManager(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FAstroDiscreteInputDefinition GetDiscreteAstroInputDefinition(EAstroDiscreteInputOptionPlayerFacing DiscretePlayerFacingInputOption);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static FString GetDedicatedServerUrl(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static FString GetDedicatedServerSearchName(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetCVar_Integer(const FString& CVarName, int32& outInteger);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCvar_EnableBackpackTrickleCharge();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCvar_DeformTool_UseTerrainResource();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCvar_DeformTool_UsePowerDraw();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EGameControllerType GetCurrentControllerType();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetCreativeModeTerrainColors(const UObject* WorldContextObject, TArray<UMaterialInterface*>& OutMaterials, TArray<FLinearColor>& OutTerrainColors);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FLinearColor GetCreativeModeTerrainColorAtIndex(int32 colorIndex, EPaintIndexType Type, const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FLinearColor GetCreativeModeTerrainColor(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UMaterialInterface* GetCreativeModeTerrainButtonColor(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetCreativeModeSpecialColors(TArray<FLinearColor>& OutPlanetColors, TArray<UMaterialInterface*>& OutMaterials, const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetCreativeModePlanetColors(const AActor* forActor, TArray<FLinearColor>& OutPlanetColors, TArray<UMaterialInterface*>& OutMaterials);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UCreativeModeData* GetCreativeModeData(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetControllingPlayerNickname();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetComponentsInChildren(AActor* Actor, TSubclassOf<UActorComponent> Class, TArray<UActorComponent*>& OutComponents);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<USceneComponent*> GetComponentParentHierarchy(USceneComponent* Component, bool Inclusive);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetChildrenRecursive(AActor* Actor, TArray<AActor*>& OutActors, bool Inclusive);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetBuildVersionWithFlavor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetBuildVersion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetBitValue(int32 BitMask, int32 BitIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static AActor* GetAttachParentActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FAstroActivityData GetAstroPSActivityData(EAstroPSActivity AstroPSActivity);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UAstroPSActivitiesDatabase* GetAstroPSActivitiesDatabase();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static AAstroMissionsManager* GetAstroMissionsManager(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FAstroLightBarData GetAstroLightBarData(EAstroLightBar AstroLightBar);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetAstroGamepadWwiseDevice(EAstroWwiseDevice AstroWwiseDevice);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSlateColor GetAstroColorAsSlateColor(EAstroColor AstroColor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FLinearColor GetAstroColor(EAstroColor AstroColor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<AActor*> GetActorParentHierarchy(AActor* Actor, bool Inclusive);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FRotator FromToRotation(const FVector& From, const FVector& To);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ForceDestroySession(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ForceCreateSession(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float FInterpCombo(float Current, float Target, float ConstantSpeed, float MultiplicativeSpeed, float DeltaTime);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void FindLocalGames(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UActorComponent* FindComponentByName(AActor* Actor, FName ComponentName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FRotator FindBetween(FVector A, FVector B);
    
    UFUNCTION(BlueprintCallable)
    static void EnqueueSkeletalMeshPlayRate(USkeletalMeshComponent* Mesh, float Rate);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool DuplicateSaveFile(UObject* WorldContextObject, const FString& CurrSaveName, const FString& newDescriptiveSaveName, FOnAstroSaveCompletedDynamic OnCompletedDelegate);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool DoesSaveFileDescriptiveNameCollideWithExistingSaves(UObject* WorldContextObject, const FString& newDescriptiveSaveName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool DoesKeyMatchInputBinding(EAstroInputBindingNameMappings InputBinding, float AxisScale, FKey Key);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void DisplayLoadingUMG(APlayerController* PlayerController, TSubclassOf<UUserWidget> LoadingWidgetOverride);
    
    UFUNCTION(BlueprintCallable)
    static void DestroyChildActors(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static void DestroyActorHierarchy(AActor* Actor, bool includeSelf);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool DeleteSaveGame(UObject* WorldContextObject, const FAstroSaveFileInformation& SaveDisplayInfo);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DeleteAllSaves(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString DateTimeToString(const FDateTime& DateTime);
    
    UFUNCTION(BlueprintCallable)
    static UMaterialInstanceDynamic* CreatePostprocessMaterialDynamic(int32 Index, UPostProcessComponent* PostProcess);
    
    UFUNCTION(BlueprintCallable)
    static UPrimitiveComponent* CreateIndicatorMeshFromComponent(USceneComponent* Component, AActor* indicatorOwner, FTransform IndicatorTransform, bool& bOutRequireCollision);
    
    UFUNCTION(BlueprintCallable)
    static TArray<UMaterialInstanceDynamic*> CreateAllDynamicMaterialInstances(AActor* Actor, UMaterialInterface* Material);
    
    UFUNCTION(BlueprintCallable)
    static TArray<UMaterialInstanceDynamic*> CreateAllComponentDynamicMaterialInstances(UPrimitiveComponent* Component, UMaterialInterface* Material);
    
    UFUNCTION(BlueprintCallable)
    static UMaterialInstanceDynamic* CreateAllComponentDynamicMaterialInstance(UPrimitiveComponent* Component, UMaterialInterface* Material);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FTransform ConvertToRelativeTransform(const FTransform& ParentTransform, const FTransform& Transform);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FText> ConvertIntegerToArrayOfText(int32 InInteger);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector ClosestPointOnLine(const FVector& LineStart, const FVector& LineEnd, const FVector& Point, float& T);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ChangeMultiplayerMode(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 CastPhysicalSurfaceToInteger(TEnumAsByte<EPhysicalSurface> Surface);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool CanGetSavedGames(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void AuthoritySpawnOrbitalPlatform(const UObject* WorldContextObject, const EPlanetIdentifier inPlanetId);
    
    UFUNCTION(BlueprintCallable)
    static void AddPostProcessBlendableMaterial(const FPostProcessSettings& InSettings, FPostProcessSettings& OutSettings, UMaterial* Material);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool ActorSimulatingPhysics(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool ActorOnClickedBound(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static void ActorCallOnClicked(AActor* Actor);
    
};

