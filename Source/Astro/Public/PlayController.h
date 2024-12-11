#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "ActorClickSignalDelegate.h"
#include "ActorOnscreenSignalDelegate.h"
#include "AstroCharacterCustomization.h"
#include "AstroNotificationToastAuthoringData.h"
#include "AstroNotificationUnlockAuthoringData.h"
#include "AstroPlayerController.h"
#include "BackpackToggledDelegateDelegate.h"
#include "BodySelectionSignalDelegate.h"
#include "ClickResult.h"
#include "ECameraMode.h"
#include "ECharacterHatCategory.h"
#include "EClickBehavior.h"
#include "EEmoteType.h"
#include "EHandState.h"
#include "EnableSignalDelegate.h"
#include "InputDeviceChangedDelegate.h"
#include "KeyboardNavigationChangedDelegate.h"
#include "MouseZoomChangedDelegate.h"
#include "PendingInGameItemRewards.h"
#include "PlayerEmoteSignalDelegate.h"
#include "SelectionWheelOption.h"
#include "SelectionWheelSignalDelegate.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "SolarBodyClickSignalDelegate.h"
#include "Templates/SubclassOf.h"
#include "UsingMouseChangedDelegate.h"
#include "PlayController.generated.h"

class AActor;
class AAstroCharacter;
class AAstroPlanet;
class ACameraRigActor;
class ACheatPlinthBase;
class ACompassActor;
class APhysicalItem;
class ASlotConnection;
class ASolarBody;
class UAstroCharacterHat;
class UAstroCharacterPalette;
class UAstroCharacterSuit;
class UAstroEmoteDefinition;
class UAstroNotificationManager;
class UAstroPopupBadgeManager;
class UAstroToastNotificationManager;
class UAstroUnlockNotificationManager;
class UAstroVisorMaterial;
class UBackpackCameraContext;
class UBiomeSamplerComponent;
class UCameraComponent;
class UControlComponent;
class UGameMenuPopoutCameraContext;
class UItemType;
class UMaterialInstanceDynamic;
class UMaterialParameterCollection;
class UMultiTool;
class UPrimitiveComponent;
class USceneComponent;
class UStaticMesh;
class UStorageChassisComponent;
class UStoreMenuCameraContext;
class UTooltipManager;
class UVirtualCursor;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USceneComponent*> HoveredFacingComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnResourceInfoHover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UVirtualCursor* VirtualCursor;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnVirtualCursorEnabledChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSelectionWheelSignal AuthorityOnEmoteWheelOpenedOrClosed;
    
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
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EmoteWheelCameraMovementCooldown;
    
public:
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
    TArray<UAstroEmoteDefinition*> EmoteSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WindGustDeltaMinIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WindGustScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 DebugWind: 1;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPlaceTetherFromBackpack;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnEmoteSelectionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerEmoteSignal AuthorityOnEmotePlayed;
    
    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorOnscreenSignal AuthorityOnActorCameOnscreenCallback;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBackpackCameraContext* BackpackCameraContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameMenuPopoutCameraContext* GameMenuPopoutCameraContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStoreMenuCameraContext* StoreMenuCameraContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<AActor*> SpawnPointStack;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D m_lastMouseLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAstroNotificationManager* AstroNotificationManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTooltipManager* TooltipManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAstroUnlockNotificationManager* AstroUnlockNotificationManger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAstroToastNotificationManager* AstroToastNotificationManger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAstroPopupBadgeManager* AstroPopupBadgeManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBiomeSamplerComponent* biomeSampler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BiomeEntryWeightThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BiomeExitWeightThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* GlobalParameterCollection;
    
public:
    APlayController(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateEmoteSelection(int32 Index, UAstroEmoteDefinition* Emote);
    
    UFUNCTION(BlueprintCallable)
    void UpdateCompass();
    
    UFUNCTION(BlueprintCallable)
    void UpdateClickableIndicators();
    
protected:
    UFUNCTION(BlueprintCallable)
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
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool TargetHasAttachParent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool TargetAllowFreeCam();
    
    UFUNCTION(BlueprintCallable)
    void StopJump();
    
    UFUNCTION(BlueprintCallable)
    APhysicalItem* SpawnActorAndAttemptPackage(UClass* ObjClass, FTransform SpawnTransform, TSubclassOf<UItemType> ItemType, bool CreativeMode, bool autoGrab);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowFadeScreen();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldShowCreativeDroneUI() const;
    
    UFUNCTION(BlueprintCallable)
    void SetVirtualCursorToggle(bool toggleValue);
    
    UFUNCTION(BlueprintCallable)
    void SetUsingMouse(bool bIsUsingMouse);
    
    UFUNCTION(BlueprintCallable)
    void SetUsingKeyboardNavigation(bool bIsUsingKeyboardNavigation);
    
    UFUNCTION(BlueprintCallable)
    void SetUsingGamepad(bool IsUsingGamepad);
    
    UFUNCTION(BlueprintCallable)
    void SetTerrainBrushLightActive(bool TerrainBrushLightActive);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void SetSuitServerInternal(UAstroCharacterSuit* NewSuit);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetSuitServer(UAstroCharacterSuit* NewSuit);
    
    UFUNCTION(BlueprintCallable)
    void SetShowCreativeDoneUI(bool shouldShowDroneUI);
    
    UFUNCTION(BlueprintCallable)
    void SetPlayerControllerID(int32 ControllerId);
    
    UFUNCTION(BlueprintCallable)
    void SetMousePosition(float X, float Y);
    
    UFUNCTION(BlueprintCallable, Exec)
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
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void SetCharacterVisorServerInternal(UAstroVisorMaterial* NewVisorMaterial);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetCharacterVisorServer(UAstroVisorMaterial* NewVisorMaterial);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void SetCharacterPaletteServerInternal(UAstroCharacterPalette* NewPalette);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetCharacterPaletteServer(UAstroCharacterPalette* NewPalette);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void SetCharacterHatServerInternal(UAstroCharacterHat* NewHat, ECharacterHatCategory Category);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetCharacterHatServer(UAstroCharacterHat* NewHat, ECharacterHatCategory Category);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void SetCharacterCustomizationServerInternal(const FAstroCharacterCustomization& NewCustomization);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetCharacterCustomizationServer(const FAstroCharacterCustomization& NewCustomization);
    
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
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerNotifyOnEmoteWheelOpenedOrClosed(bool bWheelOpened);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerNotifyOnEmotePlayed(EEmoteType EmoteType);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerNotifyOnActionWheelOpenedOrClosed(bool bWheelOpened);
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerNotifyActorOnscreenStatusChanged(AActor* monitoredActor, bool bIsOnscreen);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerCreateNavpointManagerForPlanet(AAstroPlanet* Planet);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerCompleteCustomMissionObjective(const FString& objectiveID);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerClaimNonPhysicalMissionRewards(const FName missionId);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerBranchConnectionFromActuatorRerouteNode(FSlotReference SourceSlot, int32 rerouteNodeId);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAddUnclaimedItemDrivePhysicalItemReward(const FPendingInGameItemRewards& PendingReward);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAddToCheatPlinthSelectionIndex(ACheatPlinthBase* CheatPlinth, int32 increment);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SaveGameFixup();
    
public:
    UFUNCTION(BlueprintCallable, Exec)
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
    
    UFUNCTION(BlueprintCallable)
    void ReapplySavedCharacterCustomization();
    
    UFUNCTION(BlueprintCallable)
    void PreviewCharacterCustomization(const FAstroCharacterCustomization& customizationToPreview);
    
    UFUNCTION(BlueprintCallable, Exec)
    void Ping();
    
    UFUNCTION(BlueprintCallable)
    void OpenEmoteWheel();
    
    UFUNCTION(BlueprintCallable)
    void OnReceiveUsePressed();
    
    UFUNCTION(BlueprintCallable)
    void OnReceiveToggleDeformMenuPressed();
    
    UFUNCTION(BlueprintCallable)
    void OnReceivePlaceTetherRepeat();
    
    UFUNCTION(BlueprintCallable)
    void OnReceivePlaceTetherPressed();
    
    UFUNCTION(BlueprintCallable)
    void OnReceiveDeployCreativeDronePressed();
    
    UFUNCTION(BlueprintCallable)
    void OnReceiveChangeDeformBrushStrengthModifierReleased();
    
    UFUNCTION(BlueprintCallable)
    void OnReceiveChangeDeformBrushStrengthModifierPressed();
    
    UFUNCTION(BlueprintCallable)
    void OnReceiveChangeDeformBrushSizeModifierReleased();
    
    UFUNCTION(BlueprintCallable)
    void OnReceiveChangeDeformBrushSizeModifierPressed();
    
    UFUNCTION(BlueprintCallable)
    void OnReceiveBackpackToggleInput();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnLoadScreenComplete();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnIncrementCreativeBrushSizeControllerRepeat();
    
    UFUNCTION(BlueprintCallable)
    void OnIncrementCreativeBrushIntensityControllerRepeat();
    
    UFUNCTION(BlueprintCallable)
    void OnDrivingStatusChangedInStore();
    
    UFUNCTION(BlueprintCallable)
    void OnDepartedPlanet();
    
    UFUNCTION(BlueprintCallable)
    void OnDecrementCreativeBrushIntensityControllerRepeat();
    
    UFUNCTION(BlueprintCallable)
    void OnCharacterLocalSolarBodyChanged(ASolarBody* newLocalSolarBody);
    
    UFUNCTION(BlueprintCallable)
    void OnArrivedPlanet();
    
    UFUNCTION(BlueprintCallable)
    void MouseWheelUp();
    
    UFUNCTION(BlueprintCallable)
    void MouseWheelDown();
    
    UFUNCTION(BlueprintCallable)
    void MouseWheel(float Value);
    
private:
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void LocalControllerReportWhenActorComesOnscreen(AActor* actorToMonitor);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void LocalControllerCancelReportWhenActorComesOnscreen(AActor* actorToMonitor);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void KillAstroForEmergencyRespawn();
    
    UFUNCTION(BlueprintCallable)
    void Jump();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUsingActiveGrabGamepad();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTerrainBrushLightActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCreativeShowLODAnchorRangeVisualizationEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCreativeRemoveDecoratorsWhilePaintingEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsCreativeModeDeformMenuActive();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCreativeCollectResourcesWhileDeformingDisabled() const;
    
    UFUNCTION(BlueprintCallable)
    void InitializeSpawnPointsForPlayer();
    
    UFUNCTION(BlueprintCallable)
    void IncrementHoldCounter();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideFadeScreen();
    
    UFUNCTION(BlueprintCallable)
    void HandleStoreMenuCameraContext(bool bStoreMenuEnabled);
    
    UFUNCTION(BlueprintCallable)
    void HandleLeftTriggerToggle();
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleKeyboardMouseKeyJustPressed();
    
    UFUNCTION(BlueprintCallable)
    void HandleGamepadKeyJustPressed();
    
public:
    UFUNCTION(BlueprintCallable)
    void HandleGameMenuPopoutCameraContext(bool GameMenuPopoutEnabled);
    
    UFUNCTION(BlueprintCallable)
    void HandleEmoteWheelSelection(const FSelectionWheelOption& Selection);
    
    UFUNCTION(BlueprintCallable)
    void HandleEmoteWheelReleased();
    
    UFUNCTION(BlueprintCallable)
    void HandleEmoteWheelPressed();
    
    UFUNCTION(BlueprintCallable)
    void HandleCreativeModeEnabledChanged(bool CreativeModeEnabled);
    
    UFUNCTION(BlueprintCallable)
    void HandleBackpackCameraContext(bool BackpackEnabled);
    
    UFUNCTION(BlueprintCallable)
    void HandleActionWheelSelection(const FSelectionWheelOption& Selection);
    
    UFUNCTION(BlueprintCallable)
    void HandleActionWheelReleased();
    
    UFUNCTION(BlueprintCallable)
    void HandleActionWheelPressed();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWindIntensity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetWindDirection() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAstroUnlockNotificationManager* GetUnlockNotificationManager() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetTracedActor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetTertiaryActor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USceneComponent* GetSpawnLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetSecondaryViewActor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EClickBehavior GetSecondaryBehavior();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetSecondaryActor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPrimaryViewIndicatorScale();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USceneComponent* GetPrimaryViewComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetPrimaryViewActor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EClickBehavior GetPrimaryBehavior();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetPrimaryActor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UMultiTool* GetMultitool();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASolarBody* GetLocalSolarBody() const;
    
    UFUNCTION(BlueprintCallable)
    int32 GetHoldCounter();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCursorVector(FVector& WorldLocation, FVector& WorldDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> GetConnectedControllers() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator GetCameraRotation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetCameraLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetCameraInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCameraComponent* GetCamera();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAstroCharacter* GetAstroCharacter() const;
    
    UFUNCTION(BlueprintCallable)
    void EngageUseModifier();
    
    UFUNCTION(BlueprintCallable)
    void EngageQuickSelectModifier();
    
    UFUNCTION(BlueprintCallable)
    void EnableVirtualCursor(bool CenterCursor);
    
    UFUNCTION(BlueprintCallable)
    void EnablePlanetSelection(bool Enable, ASolarBody* NewHomeBody, float planetSelectionDistance);
    
    UFUNCTION(BlueprintCallable)
    void EnableLandSelection(bool Enable, ASolarBody* Body);
    
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
    
    UFUNCTION(BlueprintCallable)
    void DoSelectionWheelSelection(const FSelectionWheelOption& Selection);
    
    UFUNCTION(BlueprintCallable)
    void DoPlayFabCatalogUnlocks();
    
    UFUNCTION(BlueprintCallable)
    void DisengageUseModifier();
    
    UFUNCTION(BlueprintCallable)
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
    
    UFUNCTION(BlueprintCallable)
    void ContextRightReleased();
    
    UFUNCTION(BlueprintCallable)
    void ContextRightPressed();
    
    UFUNCTION(BlueprintCallable)
    void ContextLeftReleased();
    
    UFUNCTION(BlueprintCallable)
    void ContextLeftPressed();
    
    UFUNCTION(BlueprintCallable)
    void CloseEmoteWheel();
    
    UFUNCTION(BlueprintCallable)
    void CloseAllSelectionWheels();
    
    UFUNCTION(BlueprintCallable)
    void CloseActionWheel();
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientPresentUnlockNotification(FAstroNotificationUnlockAuthoringData AuthoringData);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientPresentPlanetTravelNotification(FAstroNotificationToastAuthoringData AuthoringData);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientNotifyPlayerRespawned();
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientNotifyPlayerDeathBegin();
    
    UFUNCTION(BlueprintCallable)
    void ClearSaveFailedErrorData();
    
    UFUNCTION(BlueprintCallable)
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

