#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Quat -FallbackName=Quat
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Pawn -FallbackName=Pawn
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Vector_NetQuantize10 -FallbackName=Vector_NetQuantize10
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Vector_NetQuantizeNormal -FallbackName=Vector_NetQuantizeNormal
#include "EDroneControlState.h"
#include "LightValuesChangedDelegate.h"
#include "OnCreativeDroneFlightStateChangedDelegate.h"
#include "OnLandedOnGroundDelegate.h"
#include "OneTimeTooltipList.h"
#include "DeformableInterfaceT2.h"
#include "VoxelMaterial.h"
#include "OnlineNicknameStateChangedDelegate.h"
#include "OxygenLevelThresholdChangedDelegate.h"
#include "PoweredStateChangedDelegate.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "SolarBodyEventDelegate.h"
#include "SuffocatingStateChangedDelegate.h"
#include "Templates/SubclassOf.h"
#include "AstroCharacter.generated.h"

class AActor;
class AAstroPlanet;
class ABackpack;
class ADeformTool;
class ADroneBase;
class APhysicalItem;
class APlayController;
class AReroutePlacementHelper;
class ASolarBody;
class UAstroActionComponent;
class UAstroCharacterMovementComponent;
class UAstroPlayMontageAction;
class UCapsuleComponent;
class UChildActorComponent;
class UChildSlotComponent;
class UControlSymbol;
class UItemType;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UParticleSystemComponent;
class UPrimitiveComponent;
class USceneComponent;
class USkeletalMeshComponent;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ASTRO_API AAstroCharacter : public APawn, public IDeformableInterfaceT2 {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* MeshUsedAsIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FallDampening;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float CurrentSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FVector CurrentVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LastTerrainNormal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Driving;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Dying;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Walking;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SwappingItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* DrivingActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* AttachOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference HeavyCarryingSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool Jumped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool JumpInputReceived;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDrivingStatusChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Sprinting;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSolarBodyEvent OnLocalSolarBodyChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPlayerIndexUpdated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* HoldingIndicatorMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* HoldingIndicatorMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* HoldingIndicatorDirMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* HoldingIndicatorDirMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AReroutePlacementHelper* ActuatorRerouteHelper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* HoldingIndicatorMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* HoldingIndicatorDirMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=UpdateHeldItem, meta=(AllowPrivateAccess=true))
    AActor* HeldItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPrimitiveComponent*> HeldItemViewPrimitives;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float grabAnimSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform InteractingCrackableClientTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Focusing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FocusingRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PingFocusing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableHeadlook;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HoldingTool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsHeavyCarrying;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool BackpackRaised;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector FocusLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=UpdatePlayerIndex, meta=(AllowPrivateAccess=true))
    uint8 AccentMaterialIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator LookAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LastGestureTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAstroCharacterMovementComponent* AstroMovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* CapsuleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* MeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* WindParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* ItemSpawnPreviewLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UChildSlotComponent* ItemSpawnPreviewSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CreativeDroneLaunchPointLocalPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CreativeDroneLaunchPointLocalRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector BaseTranslationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuat BaseRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FVector_NetQuantize10 ReplicatedVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 ReplicatedMovementMode;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnOneTimeTooltipListUpdated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FoliageSoundCollisionRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DamageImpactSoundEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCreativeDroneFlightStateChanged OnCreativeDroneFlightStateChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DisableLight;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_LocalSolarBody, meta=(AllowPrivateAccess=true))
    ASolarBody* LocalSolarBody;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UChildActorComponent* backpackChildActorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* LastHeldItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroActionComponent* ActionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroPlayMontageAction> PointActionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* AddBrushIndicator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SubtractBrushIndicator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* FlattenBrushIndicator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* ColorPickerIndicator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* PaintBrushIndicator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* BrushIndicatorMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SkipSerialization, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* BrushIndicatorMID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SkipSerialization, Transient, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* BrushIndicatorMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform BrushIndicatorRelativeTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FName> MissionsSeen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FName> MissionsTracked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FName> DataLogEntriesSeen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_OneTimeTooltipList, meta=(AllowPrivateAccess=true))
    TArray<FOneTimeTooltipList> TriggeredOneTimeItemTooltips;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLandedOnGround OnLanded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSkeletalMeshSet;
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOxygenLevelThresholdChanged OnOxygenThresholdChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSuffocatingStateChanged OnSuffocatingChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPoweredStateChanged OnPowerStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightValuesChanged OnLightStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnlineNicknameStateChanged OnOnlineNicknameChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 bIsOxygenFilling: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 bIsTired: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 bHaveLifeSupport: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 bBreathing: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 bIsSuffocating: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 bIsAlive: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsPowered, meta=(AllowPrivateAccess=true))
    uint8 bIsPowered: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 bIsLightsOn: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bInvincible: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsImmuneToDamage, meta=(AllowPrivateAccess=true))
    uint8 bIsImmuneToDamage: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 bSimulationStarted: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_FreeOxygen, meta=(AllowPrivateAccess=true))
    uint8 bFreeOxygen: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 bOnHoverboard: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OxygenUseMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float FatigueLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float OxygenLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Health, meta=(AllowPrivateAccess=true))
    float Health;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxHealth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 DeathAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float StormEncumbrance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LightIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSlotReference TetherSlotRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> FilterBundleType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> StoredOxygenType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> OxygenType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SafeZoneRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> RelativeBackpackUnbundleRayCastOrigins;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<AActor*> DamageImmunityInitiators;
    
public:
    AAstroCharacter();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void UpdatePlayerIndex();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateHeldItem();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ToggleDeformTool();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SlotIndicatorClickedView();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SlotIndicatorClicked(const FSlotReference& Slot, TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintCallable)
    void SetSprinting(bool Sprint);
    
    UFUNCTION(BlueprintCallable)
    void SetPlayerIndex(uint8 Index);
    
    UFUNCTION(BlueprintCallable)
    void SetItemSpawnPreviewActive(bool bIsActive);
    
    UFUNCTION(BlueprintCallable)
    void SetHoverDown(bool hover);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetFreeOxygen(bool bNewFreeOxygen);
    
    UFUNCTION(BlueprintCallable)
    void SetBackpackChildActorComponent(UChildActorComponent* NewBackpackChildActorComponent);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetOneTimeItemTooltipTriggered(TSubclassOf<UItemType> Item, FName tooltipID, bool bTriggered);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetMissionTracked(const FName missionId, bool bTracked);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetMissionSeen(const FName missionId, bool bSeen);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetDataLogEntrySeen(const FName dataEntryID, bool bSeen);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetCreativeDroneDeployed(bool IsDeployed);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDropHeavyCarriedItems();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void QuickItemClickView(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool QuickItemClick(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void PointItem(TSubclassOf<UItemType> ItemType, TSubclassOf<UControlSymbol> PingSymbol, const FVector& Location, const FVector& Normal);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void PlayDamageSound();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlaceTetherFromBackpack();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRep_OnHoverboard();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnRep_OneTimeTooltipList();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_LocalSolarBody(ASolarBody* oldSolarBody);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_IsPowered();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRep_IsImmuneToDamage();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Health();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRep_FreeOxygen();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnParentAttach(AActor* Parent, bool Entering);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnImmunityInitiatorDestroyed(AActor* destroyedInitiator);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnGameplayStarted();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool OneTimeItemTooltipTriggered(TSubclassOf<UItemType> Item, const FName tooltipID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBrushColorChanged(const FVoxelMaterial& TerrainMaterial);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void NotifyPlayerDeathBegin();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void MulticastPointItem(TSubclassOf<UItemType> ItemType, TSubclassOf<UControlSymbol> PingSymbol, const FVector& Location, const FVector_NetQuantizeNormal& Normal);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool MissionTracked(const FName missionId) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool MissionSeen(const FName missionId) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCreativeDroneCameraPerspectiveActive() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleOnGameplayStartedEvent(bool StartedInExistingSavedGame);
    
public:
    UFUNCTION(BlueprintCallable)
    bool GetSprinting();
    
    UFUNCTION(BlueprintCallable)
    FTransform GetSpawnPreviewTransform();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APlayController* GetPlayController();
    
    UFUNCTION(BlueprintCallable)
    FString GetOnlinePlayerName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetOnHoverboard() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASolarBody* GetLocalSolarBody() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAstroPlanet* GetLocalPlanet() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetHoverDown();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FVector GetHeadLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EDroneControlState GetDroneControlState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    ADeformTool* GetDeformTool() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ADroneBase* GetCreativeDrone() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ABackpack* GetBackpack() const;
    
    UFUNCTION(BlueprintCallable)
    void Focus(const FVector& Location, bool rotationOnly);
    
    UFUNCTION(BlueprintCallable)
    void EndFocus();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DoJump();
    
    UFUNCTION(BlueprintCallable)
    void DetachFromSeat(bool bImmediate, bool bForce);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DataLogEntrySeen(const FName dataEntryID) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool CanSprint();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CancelIdle();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetOnHoverboard(bool bNewOnHoverboard);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetLocalSolarBody(ASolarBody* SolarBody);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetIsImmuneToDamage(bool bNewIsImmuneToDamage, AActor* immunityInitiator);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void AuthorityForceKillAstro();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float ApplyPowerExternal(int32 Amount);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    int32 ApplyOxygenExternal(int32 Amount);
    
    
    // Fix for true pure virtual functions not being implemented
};

