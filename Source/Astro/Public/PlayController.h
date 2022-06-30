#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroPlayerController.h"
#include "SignalDelegate.h"
#include "UObject/NoExportTypes.h"
#include "EHandState.h"
#include "KeyboardNavigationChangedDelegate.h"
#include "ECameraMode.h"
#include "BackpackToggledDelegateDelegate.h"
#include "ClickResult.h"
#include "Engine/EngineTypes.h"
#include "SelectionWheelOption.h"
#include "EnableSignalDelegate.h"
#include "SlotReference.h"
#include "SelectionWheelSignalDelegate.h"
#include "UObject/NoExportTypes.h"
#include "BodySelectionSignalDelegate.h"
#include "SolarBodyClickSignalDelegate.h"
#include "ActorClickSignalDelegate.h"
#include "MouseZoomChangedDelegate.h"
#include "InputDeviceChangedDelegate.h"
#include "UsingMouseChangedDelegate.h"
#include "ActorOnscreenSignalDelegate.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "ECharacterHatCategory.h"
#include "EEmoteType.h"
#include "PendingInGameItemRewards.h"
#include "EClickBehavior.h"
#include "AstroNotificationUnlockAuthoringData.h"
#include "PlayController.generated.h"

class UBiomeSamplerComponent;
class AActor;
class UTooltipManager;
class UMaterialInstanceDynamic;
class UStaticMesh;
class UStorageChassisComponent;
class ASolarBody;
class UControlComponent;
class APhysicalItem;
class UBackpackCameraContext;
class USceneComponent;
class UVirtualCursor;
class AAstroCharacter;
class ACameraRigActor;
class UCameraComponent;
class ACompassActor;
class ASlotConnection;
class UAstroNotificationManager;
class UGameMenuPopoutCameraContext;
class UMaterialParameterCollection;
class UAstroCharacterPalette;
class UStoreMenuCameraContext;
class UPrimitiveComponent;
class UItemType;
class UAstroUnlockNotificationManager;
class UAstroToastNotificationManager;
class UAstroPopupBadgeManager;
class UMultiTool;
class UAstroCharacterHat;
class AAstroPlanet;
class ACheatPlinthBase;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API APlayController : public AAstroPlayerController
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnClickUnhandled;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    EHandState RightHandState;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float GrabThreshold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SelectionOffset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LastRightHandAxis;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool QuickSelectionMade;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector TargetMultitoolLocation;

    UPROPERTY(EditAnywhere)
    float MouseZoomTickSize;

    UPROPERTY(EditAnywhere)
    float MouseZoomSpeed;

    UPROPERTY(EditAnywhere)
    uint8 bGeometricZoom : 1;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    AActor *ToolActiveItem;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    ECameraMode CameraMode;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    AActor *InteractingActor;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UStorageChassisComponent *CurrentTertiary;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    ASolarBody *HomeBody;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    float PlanetarySelectionDistance;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    uint8 UsingGamepad : 1;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    uint8 UsingKeyboardNavigation : 1;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    uint8 UsingMouse : 1;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    uint8 CurrentClickPrimary : 1;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    uint8 planetSelection : 1;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    uint8 LandSelection : 1;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    uint8 IsVirtualCursorActive : 1;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    uint8 bApplyQuickSelectModifier : 1;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    uint8 bApplyUseModifier : 1;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FClickResult CurrentClick;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FHitResult CurrentCursorHit;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FHitResult LastCursorFullRangeHit;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector CachedNonzeroMoveDirection;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector CachedMoveDirection;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    TArray<USceneComponent *> HoveredFacingComponents;

    UPROPERTY()
    FSignal OnResourceInfoHover;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    UVirtualCursor *VirtualCursor;

    UPROPERTY(BlueprintAssignable)
    FSignal OnVirtualCursorEnabledChanged;

    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly)
    FSelectionWheelSignal AuthorityOnEmoteWheelOpenedOrClosed;

    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly)
    FSelectionWheelSignal AuthorityOnActionWheelOpenedOrClosed;

    UPROPERTY(EditAnywhere)
    TSubclassOf<ACameraRigActor> FreeCamClass;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    ACameraRigActor *FreeCamRig;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ACompassActor> CompassClass;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    ACompassActor *Compass;

    UPROPERTY(EditAnywhere)
    UStaticMesh *ItemSelectorMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FSelectionWheelOption> ActionWheelOptions;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    ASlotConnection *GrabbedCable;

    UPROPERTY(Transient)
    UMaterialInstanceDynamic *ItemSelectorMat;

    UPROPERTY(EditAnywhere)
    UStaticMesh *SlottedItemSelectorMesh;

    UPROPERTY(Transient)
    UMaterialInstanceDynamic *SlottedItemSelectorMat;

    UPROPERTY(EditAnywhere)
    UStaticMesh *DefaultSecondarySelectorMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool EnableClickableIndicatorsDisplay;

    UPROPERTY(BlueprintAssignable)
    FBodySelectionSignal OnPlanetSelectionBegin;

    UPROPERTY(BlueprintAssignable)
    FSignal OnPlanetSelectionEnd;

    UPROPERTY(BlueprintAssignable)
    FBodySelectionSignal OnLandSelectionBegin;

    UPROPERTY(BlueprintAssignable)
    FSignal OnLandSelectionEnd;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FSolarBodyClickSignal OnSolarBodyClick;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FActorClickSignal OnLandClick;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FSignal OnLandBeginHover;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FSignal OnLandEndHover;

    UPROPERTY(Transient)
    FSlotReference LastPickedSlot;

    UPROPERTY(SaveGame)
    float CurrentMouseZoom;

    UPROPERTY(BlueprintAssignable)
    FMouseZoomChanged OnMouseZoomChanged;

    UPROPERTY(Transient)
    uint8 bVirtualCursorToggleOn : 1;

protected:
    UPROPERTY(EditDefaultsOnly)
    float EmoteWheelCameraMovementCooldown;

public:
    UPROPERTY(BlueprintAssignable)
    FBackpackToggledDelegate OnBackpackToggled;

    UPROPERTY(BlueprintAssignable)
    FInputDeviceChanged OnInputDeviceChanged;

    UPROPERTY(BlueprintAssignable)
    FKeyboardNavigationChanged OnKeyboardNavigationChanged;

    UPROPERTY(BlueprintAssignable)
    FUsingMouseChanged OnUsingMouseChanged;

    UPROPERTY(BlueprintAssignable)
    FBodySelectionSignal OnLocalSolarBodyChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnPreviouslyFailedSaveSucceeded;

    UPROPERTY(BlueprintAssignable)
    FSignal OnSaveGameFailed;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnCreativeShowCreativeDroneUIChanged;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnCreativeShowLODAnchorRangeVisualizationChanged;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnCreativeTerrainBrushLightChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnPlayerDeathBegin;

    UPROPERTY(BlueprintAssignable)
    FSignal OnPlayerRespawned;

    UPROPERTY(EditDefaultsOnly)
    float WheelOpenHoldThreshold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WindGustDeltaMinIntensity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WindGustScalar;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 DebugWind : 1;

    UPROPERTY(BlueprintAssignable)
    FSignal OnPlaceTetherFromBackpack;

    UPROPERTY(BlueprintAssignable)
    FSignal OnEmoteSelectionChanged;

    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly)
    FActorOnscreenSignal AuthorityOnActorCameOnscreenCallback;

protected:
    UPROPERTY(Export)
    UBackpackCameraContext *BackpackCameraContext;

    UPROPERTY(Export)
    UGameMenuPopoutCameraContext *GameMenuPopoutCameraContext;

    UPROPERTY(Export)
    UStoreMenuCameraContext *StoreMenuCameraContext;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    TArray<AActor *> SpawnPointStack;

private:
    UPROPERTY()
    FVector2D m_lastMouseLocation;

    UPROPERTY(Export, Transient)
    TArray<UPrimitiveComponent *> LastPrimaryViewPrimitives;

    UPROPERTY()
    AActor *LastSecondaryViewActor;

    UPROPERTY(SaveGame)
    uint8 bCreativeRemoveDecoratorsWhilePainting : 1;

    UPROPERTY(SaveGame)
    uint8 bCreativeTerrainBrushLightActive : 1;

    UPROPERTY(SaveGame)
    uint8 bCreativeShowLODAnchorRangeVisualization : 1;

    UPROPERTY(SaveGame)
    uint8 bCreativeDisableCollectResourcesWhileDeforming : 1;

    UPROPERTY(SaveGame)
    uint8 bShowCreativeDroneUI : 1;

    UPROPERTY(SaveGame)
    int32 HoldLabelCounter;

    UPROPERTY(Export, Transient)
    UAstroNotificationManager *AstroNotificationManager;

    UPROPERTY(Export, Transient)
    UTooltipManager *TooltipManager;

    UPROPERTY(Transient)
    UAstroUnlockNotificationManager *AstroUnlockNotificationManger;

    UPROPERTY(Transient)
    UAstroToastNotificationManager *AstroToastNotificationManger;

    UPROPERTY(Export, Transient)
    UAstroPopupBadgeManager *AstroPopupBadgeManager;

    UPROPERTY(Export)
    UBiomeSamplerComponent *biomeSampler;

    UPROPERTY(EditAnywhere)
    float BiomeEntryWeightThreshold;

    UPROPERTY(EditAnywhere)
    float BiomeExitWeightThreshold;

    UPROPERTY(Transient)
    UMaterialParameterCollection *GlobalParameterCollection;

public:
    APlayController();

    UFUNCTION(BlueprintCallable)
    void UpdateCompass();

    UFUNCTION(BlueprintCallable)
    void UpdateClickableIndicators();

protected:
    UFUNCTION()
    void UpdateBiomeAmbienceLocal(UBiomeSamplerComponent *NewBiomeSampler);

public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool TransferCurrentQuickItemIntoHandForHolding();

    UFUNCTION(BlueprintCallable)
    bool TraceCursorSpoofAtPlayerFeet(FHitResult &OutHit, TEnumAsByte<ECollisionChannel> collisionChannel, FVector traceOffset, AActor *actorToIgnore, float Distance);

    UFUNCTION(BlueprintCallable)
    bool TraceCursor(FHitResult &OutHit, TEnumAsByte<ECollisionChannel> collisionChannel, AActor *actorToIgnore, float Distance);

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool ToggleCreativeModeDeformMenu(bool bIgnoreToolState);

public:
    UFUNCTION(BlueprintCallable)
    void TertiaryAction();

    UFUNCTION(BlueprintCallable)
    void TeleportToCursor();

    UFUNCTION(BlueprintPure)
    bool TargetHasAttachParent();

    UFUNCTION(BlueprintPure)
    bool TargetAllowFreeCam();

    UFUNCTION()
    void StopJump();

    UFUNCTION(BlueprintCallable)
    APhysicalItem *SpawnActorAndAttemptPackage(UClass *ObjClass, FTransform SpawnTransform, TSubclassOf<UItemType> ItemType, bool CreativeMode, bool autoGrab);

    UFUNCTION(BlueprintImplementableEvent)
    void ShowFadeScreen();

    UFUNCTION(BlueprintPure)
    bool ShouldShowCreativeDroneUI() const;

    UFUNCTION(BlueprintCallable)
    void SetVirtualCursorToggle(bool toggleValue);

    UFUNCTION(BlueprintCallable)
    void SetUsingKeyboardNavigation(bool bIsUsingKeyboardNavigation);

    UFUNCTION(BlueprintCallable)
    void SetUsingGamepad(bool IsUsingGamepad);

    UFUNCTION(BlueprintCallable)
    void SetTerrainBrushLightActive(bool TerrainBrushLightActive);

public:
    UFUNCTION(BlueprintCallable)
    void SetShowCreativeDoneUI(bool shouldShowDroneUI);

    UFUNCTION(BlueprintCallable)
    void SetPlayerControllerID(int32 ControllerId);

    UFUNCTION(BlueprintCallable)
    void SetMousePosition(float X, float Y);

    UFUNCTION(Exec)
    void SetGamepadLock(bool gamepadModeLocked);

    UFUNCTION(BlueprintCallable, Exec)
    void SetFreeCam();

    UFUNCTION(BlueprintCallable)
    void SetCurrentSpawnPoint(AActor *Spawn);

    UFUNCTION(BlueprintCallable)
    void SetCreativeShowLODAnchorRangeVisualizationEnabled(bool ShowLODAnchorRange);

    UFUNCTION(BlueprintCallable)
    void SetCreativeRemoveDecoratorsWhilePaintingEnabled(bool RemoveDecoratorsWhilePainting);

    UFUNCTION(BlueprintCallable)
    void SetCreativeCollectResourcesWhileDeformingDisabled(bool DisableCollectResourcesWhileDeforming);

public:
    UFUNCTION(BlueprintCallable)
    void SetCameraZoom(float zoom);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSpawnResourceNuggetDebug(UClass *ObjClass);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSpawnActorDebug(UClass *ObjClass);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSpawnActorAndAttemptPackage(UClass *ObjClass, FTransform SpawnTransform, TSubclassOf<UItemType> ItemType, bool CreativeMode, bool autoGrab);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSpawnActor(UClass *ObjClass, FTransform SpawnTransform);

    UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation)
    void ServerSetToolLocation(UControlComponent *ControlComponent, FTransform Transform);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerPlayerCharacterSelectionLaunch();

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerNotifyOnEmoteWheelOpenedOrClosed(bool bWheelOpened);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerNotifyOnEmotePlayed(EEmoteType EmoteType);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerNotifyOnActionWheelOpenedOrClosed(bool bWheelOpened);

private:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerNotifyActorOnscreenStatusChanged(AActor *monitoredActor, bool bIsOnscreen);

public:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerCreateNavpointManagerForPlanet(AAstroPlanet *Planet);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerClaimNonPhysicalMissionRewards(const FName missionId);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerBranchConnectionFromActuatorRerouteNode(FSlotReference SourceSlot, int32 rerouteNodeId);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerAddUnclaimedItemDrivePhysicalItemReward(const FPendingInGameItemRewards &PendingReward);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerAddToCheatPlinthSelectionIndex(ACheatPlinthBase *CheatPlinth, int32 increment);

protected:
    UFUNCTION(BlueprintNativeEvent)
    void SaveGameFixup();

public:
    UFUNCTION(Exec)
    FString RunScript(const FString &Script);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RestoreAudioListener();

    UFUNCTION(BlueprintCallable)
    void Respawn();

    UFUNCTION(BlueprintCallable)
    void ResetPlayControllerStateForRespawn();

    UFUNCTION(BlueprintCallable)
    void ResetInputMode();

    UFUNCTION(BlueprintCallable)
    void ResetCameraToSpawnPoint();

    UFUNCTION(BlueprintCallable)
    void ReapplySavedCharacterCustomization();

    UFUNCTION(Exec)
    void Ping();

    UFUNCTION()
    void OpenEmoteWheel();

    UFUNCTION()
    void OnReceiveUsePressed();

    UFUNCTION()
    void OnReceiveToggleDeformMenuPressed();

    UFUNCTION()
    void OnReceivePlaceTetherRepeat();

    UFUNCTION()
    void OnReceivePlaceTetherPressed();

    UFUNCTION()
    void OnReceiveDeployCreativeDronePressed();

    UFUNCTION()
    void OnReceiveChangeDeformBrushStrengthModifierReleased();

    UFUNCTION()
    void OnReceiveChangeDeformBrushStrengthModifierPressed();

    UFUNCTION()
    void OnReceiveChangeDeformBrushSizeModifierReleased();

    UFUNCTION()
    void OnReceiveChangeDeformBrushSizeModifierPressed();

    UFUNCTION()
    void OnReceiveBackpackToggleInput();

private:
    UFUNCTION()
    void OnLoadScreenComplete();

public:
    UFUNCTION()
    void OnIncrementCreativeBrushSizeControllerRepeat();

    UFUNCTION()
    void OnIncrementCreativeBrushIntensityControllerRepeat();

    UFUNCTION()
    void OnDrivingStatusChangedInStore();

    UFUNCTION(BlueprintCallable)
    void OnDepartedPlanet();

    UFUNCTION()
    void OnDecrementCreativeBrushIntensityControllerRepeat();

    UFUNCTION()
    void OnCharacterLocalSolarBodyChanged(ASolarBody *newLocalSolarBody);

    UFUNCTION(BlueprintCallable)
    void OnArrivedPlanet();

    UFUNCTION()
    void MouseWheelUp();

    UFUNCTION()
    void MouseWheelDown();

    UFUNCTION()
    void MouseWheel(float Value);

private:
    UFUNCTION(Client, Reliable, WithValidation)
    void LocalControllerReportWhenActorComesOnscreen(AActor *actorToMonitor);

    UFUNCTION(Client, Reliable, WithValidation)
    void LocalControllerCancelReportWhenActorComesOnscreen(AActor *actorToMonitor);

public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void KillAstroForEmergencyRespawn();

    UFUNCTION()
    void Jump();

    UFUNCTION(BlueprintPure)
    bool IsUsingActiveGrabGamepad();

    UFUNCTION(BlueprintPure)
    bool IsTerrainBrushLightActive() const;

    UFUNCTION(BlueprintPure)
    bool IsCreativeShowLODAnchorRangeVisualizationEnabled() const;

    UFUNCTION(BlueprintPure)
    bool IsCreativeRemoveDecoratorsWhilePaintingEnabled() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    bool IsCreativeModeDeformMenuActive();

    UFUNCTION(BlueprintPure)
    bool IsCreativeCollectResourcesWhileDeformingDisabled() const;

    UFUNCTION(BlueprintCallable)
    void InitializeSpawnPointsForPlayer();

    UFUNCTION(BlueprintCallable)
    void IncrementHoldCounter();

    UFUNCTION(BlueprintImplementableEvent)
    void HideFadeScreen();

    UFUNCTION(BlueprintCallable)
    void HandleStoreMenuCameraContext(bool bStoreMenuEnabled);

    UFUNCTION()
    void HandleLeftTriggerToggle();

protected:
    UFUNCTION()
    void HandleKeyboardMouseKeyJustPressed();

    UFUNCTION()
    void HandleGamepadKeyJustPressed();

public:
    UFUNCTION(BlueprintCallable)
    void HandleGameMenuPopoutCameraContext(bool GameMenuPopoutEnabled);

    UFUNCTION()
    void HandleEmoteWheelSelection(const FSelectionWheelOption &Selection);

    UFUNCTION()
    void HandleEmoteWheelReleased();

    UFUNCTION()
    void HandleEmoteWheelPressed();

    UFUNCTION()
    void HandleCreativeModeEnabledChanged(bool CreativeModeEnabled);

    UFUNCTION(BlueprintCallable)
    void HandleBackpackCameraContext(bool BackpackEnabled);

    UFUNCTION()
    void HandleActionWheelSelection(const FSelectionWheelOption &Selection);

    UFUNCTION()
    void HandleActionWheelReleased();

    UFUNCTION()
    void HandleActionWheelPressed();

    UFUNCTION(BlueprintPure)
    float GetWindIntensity() const;

    UFUNCTION(BlueprintPure)
    FVector GetWindDirection() const;

    UFUNCTION(BlueprintPure)
    UAstroUnlockNotificationManager *GetUnlockNotificationManager() const;

    UFUNCTION(BlueprintPure)
    AActor *GetTracedActor();

    UFUNCTION(BlueprintPure)
    AActor *GetTertiaryActor();

    UFUNCTION(BlueprintPure)
    USceneComponent *GetSpawnLocation();

    UFUNCTION(BlueprintPure)
    AActor *GetSecondaryViewActor();

    UFUNCTION(BlueprintPure)
    EClickBehavior GetSecondaryBehavior();

    UFUNCTION(BlueprintPure)
    AActor *GetSecondaryActor();

    UFUNCTION(BlueprintPure)
    float GetPrimaryViewIndicatorScale();

    UFUNCTION(BlueprintPure)
    USceneComponent *GetPrimaryViewComponent();

    UFUNCTION(BlueprintPure)
    AActor *GetPrimaryViewActor();

    UFUNCTION(BlueprintPure)
    EClickBehavior GetPrimaryBehavior();

    UFUNCTION(BlueprintPure)
    AActor *GetPrimaryActor();

    UFUNCTION(BlueprintPure)
    UMultiTool *GetMultitool();

    UFUNCTION(BlueprintPure)
    ASolarBody *GetLocalSolarBody() const;

    UFUNCTION(BlueprintCallable)
    int32 GetHoldCounter();

    UFUNCTION(BlueprintPure)
    bool GetCursorVector(FVector &WorldLocation, FVector &WorldDirection);

    UFUNCTION(BlueprintPure)
    TArray<int32> GetConnectedControllers() const;

    UFUNCTION(BlueprintPure)
    FRotator GetCameraRotation();

    UFUNCTION(BlueprintPure)
    FVector GetCameraLocation() const;

    UFUNCTION(BlueprintPure)
    FVector2D GetCameraInput() const;

    UFUNCTION(BlueprintPure)
    UCameraComponent *GetCamera();

    UFUNCTION(BlueprintPure)
    AAstroCharacter *GetAstroCharacter() const;

    UFUNCTION()
    void EngageUseModifier();

    UFUNCTION()
    void EngageQuickSelectModifier();

    UFUNCTION(BlueprintCallable)
    void EnableVirtualCursor(bool CenterCursor);

    UFUNCTION(BlueprintCallable)
    void EnablePlanetSelection(bool Enable, ASolarBody *NewHomeBody, float planetSelectionDistance);

    UFUNCTION(BlueprintCallable)
    void EnableLandSelection(bool Enable, ASolarBody *Body);

    UFUNCTION(BlueprintCallable)
    void EmoteTwo();

    UFUNCTION(BlueprintCallable)
    void EmoteThree();

    UFUNCTION(BlueprintCallable)
    void EmoteOne();

    UFUNCTION(BlueprintCallable)
    void EmoteFour();

    UFUNCTION(BlueprintCallable)
    void DropHeldItem();

    UFUNCTION()
    void DoSelectionWheelSelection(const FSelectionWheelOption &Selection);

    UFUNCTION()
    void DisengageUseModifier();

    UFUNCTION()
    void DisengageQuickSelectModifier();

    UFUNCTION(BlueprintCallable)
    void DisengageInteractionModifiers();

    UFUNCTION(BlueprintCallable)
    void DisableVirtualCursor();

    UFUNCTION(BlueprintCallable)
    void DebugFOVUp();

    UFUNCTION(BlueprintCallable)
    void DebugFOVDown();

    UFUNCTION(BlueprintCallable, Exec)
    void CycleCameraMode();

    UFUNCTION()
    void ContextRightReleased();

    UFUNCTION()
    void ContextRightPressed();

    UFUNCTION()
    void ContextLeftReleased();

    UFUNCTION()
    void ContextLeftPressed();

    UFUNCTION(BlueprintCallable)
    void CloseEmoteWheel();

    UFUNCTION(BlueprintCallable)
    void CloseAllSelectionWheels();

    UFUNCTION(BlueprintCallable)
    void CloseActionWheel();

    UFUNCTION(Client, Reliable, WithValidation)
    void ClientPresentUnlockNotification(FAstroNotificationUnlockAuthoringData AuthoringData);

    UFUNCTION(Client, Reliable, WithValidation)
    void ClientNotifyPlayerRespawned();

    UFUNCTION(Client, Reliable, WithValidation)
    void ClientNotifyPlayerDeathBegin();

    UFUNCTION(BlueprintCallable)
    void ClearSaveFailedErrorData();

    UFUNCTION()
    void CameraModeModifierPressed();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityReportWhenActorComesOnscreen(AActor *actorToMonitor);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityCancelReportWhenActorComesOnscreen(AActor *actorToMonitor);

    UFUNCTION(BlueprintCallable)
    bool AttemptToPlaceArbitaryItemInHandForHolding(APhysicalItem *Item);

    UFUNCTION(BlueprintCallable)
    bool AttemptToDecrementCreativeBrushSizeController();
};
