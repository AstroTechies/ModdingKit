#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroPlayerController.h"
#include "ClickResult.h"
#include "SignalDelegate.h"
#include "ECameraMode.h"
#include "EHandState.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "SelectionWheelOption.h"
#include "SelectionWheelSignalDelegate.h"
#include "BodySelectionSignalDelegate.h"
#include "AstroNotificationUnlockAuthoringData.h"
#include "SolarBodyClickSignalDelegate.h"
#include "ActorClickSignalDelegate.h"
#include "SlotReference.h"
#include "MouseZoomChangedDelegate.h"
#include "BackpackToggledDelegateDelegate.h"
#include "InputDeviceChangedDelegate.h"
#include "KeyboardNavigationChangedDelegate.h"
#include "UsingMouseChangedDelegate.h"
#include "ActorOnscreenSignalDelegate.h"
#include "EnableSignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ECollisionChannel -FallbackName=ECollisionChannel
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "PendingInGameItemRewards.h"
#include "EClickBehavior.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
#include "PlayController.generated.h"

class ASolarBody;
class AActor;
class UStorageChassisComponent;
class UItemType;
class ASlotConnection;
class UAstroPopupBadgeManager;
class USceneComponent;
class APhysicalItem;
class UVirtualCursor;
class UAstroToastNotificationManager;
class UMultiTool;
class UMaterialParameterCollection;
class ACameraRigActor;
class ACompassActor;
class UStaticMesh;
class UMaterialInstanceDynamic;
class UPrimitiveComponent;
class ACheatPlinthBase;
class UBackpackCameraContext;
class UGameMenuPopoutCameraContext;
class UAstroNotificationManager;
class UTooltipManager;
class UAstroUnlockNotificationManager;
class UBiomeSamplerComponent;
class UAstroCharacterSuit;
class UControlComponent;
class AAstroPlanet;
class UCameraComponent;
class AAstroCharacter;

UCLASS(Blueprintable)
class ASTRO_API APlayController : public AAstroPlayerController {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnClickUnhandled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHandState RightHandState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GrabThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SelectionOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LastRightHandAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool QuickSelectionMade;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TargetMultitoolLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MouseZoomTickSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MouseZoomSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bGeometricZoom: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* ToolActiveItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraMode CameraMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AActor* InteractingActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStorageChassisComponent* CurrentTertiary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASolarBody* HomeBody;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float PlanetarySelectionDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 UsingGamepad: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 UsingKeyboardNavigation: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 UsingMouse: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 CurrentClickPrimary: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 planetSelection: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 LandSelection: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 IsVirtualCursorActive: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bApplyQuickSelectModifier: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bApplyUseModifier: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClickResult CurrentClick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHitResult CurrentCursorHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHitResult LastCursorFullRangeHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CachedNonzeroMoveDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CachedMoveDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<USceneComponent*> HoveredFacingComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnResourceInfoHover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UVirtualCursor* VirtualCursor;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnVirtualCursorEnabledChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSelectionWheelSignal AuthorityOnActionWheelOpenedOrClosed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACameraRigActor> FreeCamClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACameraRigActor* FreeCamRig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACompassActor> CompassClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACompassActor* Compass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* ItemSelectorMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSelectionWheelOption> ActionWheelOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASlotConnection* GrabbedCable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* ItemSelectorMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SlottedItemSelectorMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* SlottedItemSelectorMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* DefaultSecondarySelectorMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableClickableIndicatorsDisplay;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBodySelectionSignal OnPlanetSelectionBegin;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPlanetSelectionEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBodySelectionSignal OnLandSelectionBegin;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnLandSelectionEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSolarBodyClickSignal OnSolarBodyClick;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorClickSignal OnLandClick;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnLandBeginHover;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnLandEndHover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSlotReference LastPickedSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float CurrentMouseZoom;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMouseZoomChanged OnMouseZoomChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bVirtualCursorToggleOn: 1;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBackpackToggledDelegate OnBackpackToggled;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInputDeviceChanged OnInputDeviceChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FKeyboardNavigationChanged OnKeyboardNavigationChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUsingMouseChanged OnUsingMouseChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBodySelectionSignal OnLocalSolarBodyChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPreviouslyFailedSaveSucceeded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSaveGameFailed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnCreativeShowCreativeDroneUIChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnCreativeShowLODAnchorRangeVisualizationChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnCreativeTerrainBrushLightChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPlayerDeathBegin;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPlayerRespawned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WheelOpenHoldThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WindGustDeltaMinIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WindGustScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 DebugWind: 1;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPlaceTetherFromBackpack;
    
    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorOnscreenSignal AuthorityOnActorCameOnscreenCallback;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UBackpackCameraContext* BackpackCameraContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UGameMenuPopoutCameraContext* GameMenuPopoutCameraContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<AActor*> SpawnPointStack;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D m_lastMouseLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPrimitiveComponent*> LastPrimaryViewPrimitives;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* LastSecondaryViewActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bCreativeRemoveDecoratorsWhilePainting: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bCreativeTerrainBrushLightActive: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bCreativeShowLODAnchorRangeVisualization: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bCreativeDisableCollectResourcesWhileDeforming: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bShowCreativeDroneUI: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 HoldLabelCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UAstroNotificationManager* AstroNotificationManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UTooltipManager* TooltipManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAstroUnlockNotificationManager* AstroUnlockNotificationManger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAstroToastNotificationManager* AstroToastNotificationManger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UAstroPopupBadgeManager* AstroPopupBadgeManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UBiomeSamplerComponent* biomeSampler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BiomeEntryWeightThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BiomeExitWeightThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* GlobalParameterCollection;
    
public:
    APlayController();
    UFUNCTION(BlueprintCallable)
    void UpdateCompass();
    
    UFUNCTION(BlueprintCallable)
    void UpdateClickableIndicators();
    
protected:
    UFUNCTION()
    void UpdateBiomeAmbienceLocal(UBiomeSamplerComponent* NewBiomeSampler);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool TransferCurrentQuickItemIntoHandForHolding();
    
    UFUNCTION(BlueprintCallable)
    bool TraceCursorSpoofAtPlayerFeet(FHitResult& OutHit, TEnumAsByte<ECollisionChannel> collisionChannel, FVector traceOffset, AActor* actorToIgnore, float Distance);
    
    UFUNCTION(BlueprintCallable)
    bool TraceCursor(FHitResult& OutHit, TEnumAsByte<ECollisionChannel> collisionChannel, AActor* actorToIgnore, float Distance);
    
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
    APhysicalItem* SpawnActorAndAttemptPackage(UClass* ObjClass, FTransform SpawnTransform, TSubclassOf<UItemType> ItemType, bool CreativeMode, bool autoGrab);
    
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
    void SetCurrentSpawnPoint(AActor* Spawn);
    
    UFUNCTION(BlueprintCallable)
    void SetCreativeShowLODAnchorRangeVisualizationEnabled(bool ShowLODAnchorRange);
    
    UFUNCTION(BlueprintCallable)
    void SetCreativeRemoveDecoratorsWhilePaintingEnabled(bool RemoveDecoratorsWhilePainting);
    
    UFUNCTION(BlueprintCallable)
    void SetCreativeCollectResourcesWhileDeformingDisabled(bool DisableCollectResourcesWhileDeforming);
    
protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void SetCharacterVisorServerInternal();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetCharacterVisorServer();
    
    UFUNCTION(BlueprintCallable)
    void SetCameraZoom(float zoom);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSpawnResourceNuggetDebug(UClass* ObjClass);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSpawnActorDebug(UClass* ObjClass);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSpawnActorAndAttemptPackage(UClass* ObjClass, FTransform SpawnTransform, TSubclassOf<UItemType> ItemType, bool CreativeMode, bool autoGrab);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSpawnActor(UClass* ObjClass, FTransform SpawnTransform);
    
    UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation)
    void ServerSetToolLocation(UControlComponent* ControlComponent, FTransform Transform);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerPlayerCharacterSelectionLaunch();
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerNotifyOnActionWheelOpenedOrClosed(bool bWheelOpened);
    
private:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerNotifyActorOnscreenStatusChanged(AActor* monitoredActor, bool bIsOnscreen);
    
public:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerCreateNavpointManagerForPlanet(AAstroPlanet* Planet);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerClaimNonPhysicalMissionRewards(const FName missionId);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerBranchConnectionFromActuatorRerouteNode(FSlotReference SourceSlot, int32 rerouteNodeId);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerAddUnclaimedItemDrivePhysicalItemReward(const FPendingInGameItemRewards& PendingReward);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerAddToCheatPlinthSelectionIndex(ACheatPlinthBase* CheatPlinth, int32 increment);
    
protected:
    UFUNCTION(BlueprintNativeEvent)
    void SaveGameFixup();
    
public:
    UFUNCTION(Exec)
    FString RunScript(const FString& Script);
    
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
    
    UFUNCTION(Exec)
    void Ping();
    
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
    void OnCharacterLocalSolarBodyChanged(ASolarBody* newLocalSolarBody);
    
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
    void LocalControllerReportWhenActorComesOnscreen(AActor* actorToMonitor);
    
    UFUNCTION(Client, Reliable, WithValidation)
    void LocalControllerCancelReportWhenActorComesOnscreen(AActor* actorToMonitor);
    
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
    void HandleCreativeModeEnabledChanged(bool CreativeModeEnabled);
    
    UFUNCTION(BlueprintCallable)
    void HandleBackpackCameraContext(bool BackpackEnabled);
    
    UFUNCTION()
    void HandleActionWheelSelection(const FSelectionWheelOption& Selection);
    
    UFUNCTION()
    void HandleActionWheelReleased();
    
    UFUNCTION()
    void HandleActionWheelPressed();
    
    UFUNCTION(BlueprintPure)
    float GetWindIntensity() const;
    
    UFUNCTION(BlueprintPure)
    FVector GetWindDirection() const;
    
    UFUNCTION(BlueprintPure)
    UAstroUnlockNotificationManager* GetUnlockNotificationManager() const;
    
    UFUNCTION(BlueprintPure)
    AActor* GetTracedActor();
    
    UFUNCTION(BlueprintPure)
    AActor* GetTertiaryActor();
    
    UFUNCTION(BlueprintPure)
    USceneComponent* GetSpawnLocation();
    
    UFUNCTION(BlueprintPure)
    AActor* GetSecondaryViewActor();
    
    UFUNCTION(BlueprintPure)
    EClickBehavior GetSecondaryBehavior();
    
    UFUNCTION(BlueprintPure)
    AActor* GetSecondaryActor();
    
    UFUNCTION(BlueprintPure)
    float GetPrimaryViewIndicatorScale();
    
    UFUNCTION(BlueprintPure)
    USceneComponent* GetPrimaryViewComponent();
    
    UFUNCTION(BlueprintPure)
    AActor* GetPrimaryViewActor();
    
    UFUNCTION(BlueprintPure)
    EClickBehavior GetPrimaryBehavior();
    
    UFUNCTION(BlueprintPure)
    AActor* GetPrimaryActor();
    
    UFUNCTION(BlueprintPure)
    UMultiTool* GetMultitool();
    
    UFUNCTION(BlueprintPure)
    ASolarBody* GetLocalSolarBody() const;
    
    UFUNCTION(BlueprintCallable)
    int32 GetHoldCounter();
    
    UFUNCTION(BlueprintPure)
    bool GetCursorVector(FVector& WorldLocation, FVector& WorldDirection);
    
    UFUNCTION(BlueprintPure)
    TArray<int32> GetConnectedControllers() const;
    
    UFUNCTION(BlueprintPure)
    FRotator GetCameraRotation();
    
    UFUNCTION(BlueprintPure)
    FVector GetCameraLocation() const;
    
    UFUNCTION(BlueprintPure)
    FVector2D GetCameraInput() const;
    
    UFUNCTION(BlueprintPure)
    UCameraComponent* GetCamera();
    
    UFUNCTION(BlueprintPure)
    AAstroCharacter* GetAstroCharacter() const;
    
    UFUNCTION()
    void EngageUseModifier();
    
    UFUNCTION()
    void EngageQuickSelectModifier();
    
    UFUNCTION(BlueprintCallable)
    void EnableVirtualCursor(bool CenterCursor);
    
    UFUNCTION(BlueprintCallable)
    void EnablePlanetSelection(bool Enable, ASolarBody* NewHomeBody, float planetSelectionDistance);
    
    UFUNCTION(BlueprintCallable)
    void EnableLandSelection(bool Enable, ASolarBody* Body);
    
    UFUNCTION(BlueprintCallable)
    void DropHeldItem();
    
    UFUNCTION()
    void DoSelectionWheelSelection(const FSelectionWheelOption& Selection);
    
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
    void AuthorityReportWhenActorComesOnscreen(AActor* actorToMonitor);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityCancelReportWhenActorComesOnscreen(AActor* actorToMonitor);
    
    UFUNCTION(BlueprintCallable)
    bool AttemptToPlaceArbitaryItemInHandForHolding(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    bool AttemptToDecrementCreativeBrushSizeController();
    
};

