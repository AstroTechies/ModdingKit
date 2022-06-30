#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Pawn.h"
#include "UObject/NoExportTypes.h"
#include "DeformableInterfaceT2.h"
#include "SlotReference.h"
#include "SolarBodyEventDelegate.h"
#include "SignalDelegate.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ECharacterHatCategory.h"
#include "OxygenLevelThresholdChangedDelegate.h"
#include "UObject/NoExportTypes.h"
#include "Engine/NetSerialization.h"
#include "OnCreativeDroneFlightStateChangedDelegate.h"
#include "SuffocatingStateChangedDelegate.h"
#include "OnLandedOnGroundDelegate.h"
#include "PoweredStateChangedDelegate.h"
#include "LightValuesChangedDelegate.h"
#include "OnlineNicknameStateChangedDelegate.h"
#include "VoxelMaterial.h"
#include "Engine/NetSerialization.h"
#include "EDroneControlState.h"
#include "AstroCharacter.generated.h"

class UMaterialInstanceDynamic;
class UStaticMesh;
class AActor;
class UParticleSystemComponent;
class UMaterialInterface;
class UAstroCharacterPalette;
class AReroutePlacementHelper;
class UStaticMeshComponent;
class UPrimitiveComponent;
class APlayController;
class UAstroCharacterMovementComponent;
class UCapsuleComponent;
class USkeletalMeshComponent;
class APhysicalItem;
class USceneComponent;
class UChildSlotComponent;
class UControlSymbol;
class UAstroCharacterOverlayPattern;
class UAstroPlayMontageAction;
class ASolarBody;
class ABackpack;
class UChildActorComponent;
class UItemType;
class UAstroActionComponent;
class AAstroPlanet;
class ADeformTool;
class ADroneBase;
class UAstroCharacterSuit;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AAstroCharacter : public APawn, public IDeformableInterfaceT2
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    UStaticMesh *MeshUsedAsIcon;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FallDampening;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    float CurrentSpeed;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    FVector CurrentVelocity;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector LastTerrainNormal;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool Driving;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool Dying;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool Walking;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool SwappingItem;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    AActor *DrivingActor;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    AActor *AttachOwner;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FSlotReference HeavyCarryingSlot;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    bool Jumped;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool JumpInputReceived;

    UPROPERTY(BlueprintAssignable)
    FSignal OnCharacterCustomizationChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnDrivingStatusChanged;

protected:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool Sprinting;

public:
    UPROPERTY()
    FSolarBodyEvent OnLocalSolarBodyChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnPlayerIndexUpdated;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMesh *HoldingIndicatorMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UMaterialInterface *HoldingIndicatorMaterial;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMesh *HoldingIndicatorDirMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UMaterialInterface *HoldingIndicatorDirMaterial;

    UPROPERTY(Replicated)
    AReroutePlacementHelper *ActuatorRerouteHelper;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UStaticMeshComponent *HoldingIndicatorMeshComponent;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UStaticMeshComponent *HoldingIndicatorDirMeshComponent;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = UpdateHeldItem, meta = (AllowPrivateAccess = true))
    AActor *HeldItem;

    UPROPERTY(Export, Transient)
    TArray<UPrimitiveComponent *> HeldItemViewPrimitives;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float grabAnimSpeed;

    UPROPERTY()
    FTransform InteractingCrackableClientTransform;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool Focusing;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool FocusingRotation;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool bEnableHeadlook;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool HoldingTool;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool IsHeavyCarrying;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool BackpackRaised;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector FocusLocation;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = UpdatePlayerIndex, meta = (AllowPrivateAccess = true))
    uint8 AccentMaterialIndex;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FRotator LookAngle;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float LastGestureTime;

    UPROPERTY(BlueprintReadWrite, Export, Transient, meta = (AllowPrivateAccess = true))
    UAstroCharacterMovementComponent *AstroMovementComponent;

    UPROPERTY(BlueprintReadWrite, Export, VisibleDefaultsOnly, meta = (AllowPrivateAccess = true))
    UCapsuleComponent *CapsuleComponent;

    UPROPERTY(BlueprintReadWrite, Export, Transient, meta = (AllowPrivateAccess = true))
    USkeletalMeshComponent *MeshComponent;

    UPROPERTY(BlueprintReadWrite, Export, Transient, meta = (AllowPrivateAccess = true))
    UParticleSystemComponent *WindParticles;

    UPROPERTY(BlueprintReadWrite, Export, Transient, meta = (AllowPrivateAccess = true))
    USceneComponent *ItemSpawnPreviewLocation;

    UPROPERTY(BlueprintReadWrite, Export, Transient, meta = (AllowPrivateAccess = true))
    UChildSlotComponent *ItemSpawnPreviewSlot;

    UPROPERTY(EditDefaultsOnly)
    FVector CreativeDroneLaunchPointLocalPosition;

    UPROPERTY(EditDefaultsOnly)
    FVector CreativeDroneLaunchPointLocalRotation;

    UPROPERTY()
    FVector BaseTranslationOffset;

    UPROPERTY()
    FQuat BaseRotationOffset;

    UPROPERTY(Replicated)
    FVector_NetQuantize10 ReplicatedVelocity;

    UPROPERTY(Replicated)
    uint8 ReplicatedMovementMode;

    UPROPERTY(EditDefaultsOnly)
    float FoliageSoundCollisionRadius;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FString DamageImpactSoundEvent;

    UPROPERTY(BlueprintAssignable)
    FOnCreativeDroneFlightStateChanged OnCreativeDroneFlightStateChanged;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool DisableLight;

protected:
    UPROPERTY(ReplicatedUsing = OnRep_LocalSolarBody)
    ASolarBody *LocalSolarBody;

    UPROPERTY(Export)
    UChildActorComponent *backpackChildActorComponent;

    UPROPERTY(Transient)
    AActor *LastHeldItem;

    UPROPERTY(BlueprintReadWrite, Export, VisibleDefaultsOnly, meta = (AllowPrivateAccess = true))
    UAstroActionComponent *ActionComponent;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UAstroPlayMontageAction> PointActionType;

    UPROPERTY(EditDefaultsOnly)
    UStaticMesh *AddBrushIndicator;

    UPROPERTY(EditDefaultsOnly)
    UStaticMesh *SubtractBrushIndicator;

    UPROPERTY(EditDefaultsOnly)
    UStaticMesh *FlattenBrushIndicator;

    UPROPERTY(EditDefaultsOnly)
    UStaticMesh *ColorPickerIndicator;

    UPROPERTY(EditDefaultsOnly)
    UStaticMesh *PaintBrushIndicator;

    UPROPERTY(EditDefaultsOnly)
    UMaterialInterface *BrushIndicatorMaterial;

    UPROPERTY(BlueprintReadWrite, SkipSerialization, Transient, meta = (AllowPrivateAccess = true))
    UMaterialInstanceDynamic *BrushIndicatorMID;

    UPROPERTY(Export, SkipSerialization, Transient)
    UStaticMeshComponent *BrushIndicatorMeshComponent;

    UPROPERTY()
    FTransform BrushIndicatorRelativeTransform;

    UPROPERTY(Replicated, SaveGame)
    TArray<FName> MissionsSeen;

    UPROPERTY(Replicated, SaveGame)
    TArray<FName> MissionsTracked;

public:
    UPROPERTY(BlueprintAssignable)
    FOnLandedOnGround OnLanded;

    UPROPERTY(BlueprintAssignable)
    FSignal OnSkeletalMeshSet;

protected:
    UPROPERTY(BlueprintAssignable)
    FOxygenLevelThresholdChanged OnOxygenThresholdChanged;

    UPROPERTY(BlueprintAssignable)
    FSuffocatingStateChanged OnSuffocatingChanged;

    UPROPERTY(BlueprintAssignable)
    FPoweredStateChanged OnPowerStateChanged;

    UPROPERTY(BlueprintAssignable)
    FLightValuesChanged OnLightStateChanged;

    UPROPERTY(BlueprintAssignable)
    FOnlineNicknameStateChanged OnOnlineNicknameChanged;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    uint8 bIsOxygenFilling : 1;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    uint8 bIsTired : 1;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    uint8 bHaveLifeSupport : 1;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    uint8 bBreathing : 1;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    uint8 bIsSuffocating : 1;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    uint8 bIsAlive : 1;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_IsPowered, meta = (AllowPrivateAccess = true))
    uint8 bIsPowered : 1;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    uint8 bIsLightsOn : 1;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    uint8 bInvincible : 1;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_IsImmuneToDamage, meta = (AllowPrivateAccess = true))
    uint8 bIsImmuneToDamage : 1;

    UPROPERTY(Replicated)
    uint8 bSimulationStarted : 1;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_FreeOxygen, meta = (AllowPrivateAccess = true))
    uint8 bFreeOxygen : 1;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    uint8 bOnHoverboard : 1;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float OxygenUseMultiplier;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    float FatigueLevel;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    float OxygenLevel;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_Health, meta = (AllowPrivateAccess = true))
    float Health;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float MaxHealth;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    int32 DeathAnim;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    float StormEncumbrance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LightIntensity;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    FSlotReference TetherSlotRef;

    UPROPERTY(EditAnywhere)
    TSubclassOf<AActor> FilterBundleType;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UItemType> StoredOxygenType;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UItemType> OxygenType;

    UPROPERTY(EditAnywhere)
    float SafeZoneRadius;

    UPROPERTY()
    TArray<FVector> RelativeBackpackUnbundleRayCastOrigins;

    UPROPERTY(Transient)
    TSet<AActor *> DamageImmunityInitiators;

public:
    AAstroCharacter();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void UpdatePlayerIndex();

    UFUNCTION(BlueprintNativeEvent)
    void UpdateHeldItem();

public:
    UFUNCTION(BlueprintImplementableEvent)
    void ToggleDeformTool();

    UFUNCTION(BlueprintImplementableEvent)
    void SlotIndicatorClickedView();

    UFUNCTION(BlueprintImplementableEvent)
    void SlotIndicatorClicked(const FSlotReference &Slot, TSubclassOf<UItemType> Type);

    UFUNCTION()
    void SetSprinting(bool Sprint);

    UFUNCTION(BlueprintCallable)
    void SetPlayerIndex(uint8 Index);

    UFUNCTION(BlueprintCallable)
    void SetItemSpawnPreviewActive(bool bIsActive);

    UFUNCTION()
    void SetHoverDown(bool hover);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetFreeOxygen(bool bNewFreeOxygen);

    UFUNCTION(BlueprintCallable)
    void SetBackpackChildActorComponent(UChildActorComponent *NewBackpackChildActorComponent);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetMissionTracked(const FName missionId, bool bTracked);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetMissionSeen(const FName missionId, bool bSeen);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetCreativeDroneDeployed(bool IsDeployed);

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDropHeavyCarriedItems();

    UFUNCTION(BlueprintCallable)
    void ReapplySavedCharacterCustomization();

    UFUNCTION(BlueprintImplementableEvent)
    void QuickItemClickView(APhysicalItem *Item);

    UFUNCTION(BlueprintImplementableEvent)
    bool QuickItemClick(APhysicalItem *Item);

    UFUNCTION(BlueprintCallable)
    void PointItem(TSubclassOf<UItemType> ItemType, TSubclassOf<UControlSymbol> PingSymbol, const FVector &Location, const FVector &Normal);

    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void PlayDamageSound();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlaceTetherFromBackpack();

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnRep_OnHoverboard();

    UFUNCTION()
    void OnRep_LocalSolarBody(ASolarBody *oldSolarBody);

    UFUNCTION()
    void OnRep_IsPowered();

    UFUNCTION(BlueprintImplementableEvent)
    void OnRep_IsImmuneToDamage();

    UFUNCTION()
    void OnRep_Health();

    UFUNCTION(BlueprintImplementableEvent)
    void OnRep_FreeOxygen();

    UFUNCTION()
    void OnRep_CharacterCustomization();

public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnParentAttach(AActor *Parent, bool Entering);

protected:
    UFUNCTION()
    void OnImmunityInitiatorDestroyed(AActor *destroyedInitiator);

public:
    UFUNCTION()
    void OnGameplayStarted();

    UFUNCTION(BlueprintImplementableEvent)
    void OnBrushColorChanged(const FVoxelMaterial &TerrainMaterial);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void NotifyPlayerDeathBegin();

    UFUNCTION(NetMulticast, Unreliable)
    void MulticastPointItem(TSubclassOf<UItemType> ItemType, TSubclassOf<UControlSymbol> PingSymbol, const FVector &Location, const FVector_NetQuantizeNormal &Normal);

    UFUNCTION(BlueprintPure)
    bool MissionTracked(const FName missionId) const;

    UFUNCTION(BlueprintPure)
    bool MissionSeen(const FName missionId) const;

    UFUNCTION(BlueprintPure)
    bool IsCreativeDroneCameraPerspectiveActive() const;

protected:
    UFUNCTION()
    void HandleOnGameplayStartedEvent(bool StartedInExistingSavedGame);

public:
    UFUNCTION()
    bool GetSprinting();

    UFUNCTION(BlueprintCallable)
    FTransform GetSpawnPreviewTransform();

    UFUNCTION(BlueprintPure)
    APlayController *GetPlayController();

    UFUNCTION(BlueprintCallable)
    FString GetOnlinePlayerName();

    UFUNCTION(BlueprintPure)
    bool GetOnHoverboard() const;

    UFUNCTION(BlueprintPure)
    ASolarBody *GetLocalSolarBody() const;

    UFUNCTION(BlueprintPure)
    AAstroPlanet *GetLocalPlanet() const;

    UFUNCTION()
    bool GetHoverDown();

    UFUNCTION(BlueprintImplementableEvent)
    FVector GetHeadLocation();

    UFUNCTION(BlueprintPure)
    EDroneControlState GetDroneControlState() const;

    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    ADeformTool *GetDeformTool() const;

    UFUNCTION(BlueprintPure)
    ADroneBase *GetCreativeDrone() const;

    UFUNCTION(BlueprintPure)
    ABackpack *GetBackpack() const;

    UFUNCTION()
    void Focus(const FVector &Location, bool rotationOnly);

    UFUNCTION()
    void EndFocus();

    UFUNCTION(BlueprintImplementableEvent)
    void DoJump();

    UFUNCTION(BlueprintCallable)
    void DetachFromSeat(bool bImmediate, bool bForce);

protected:
    UFUNCTION(BlueprintImplementableEvent)
    bool CanSprint();

public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CancelIdle();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetOnHoverboard(bool bNewOnHoverboard);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetLocalSolarBody(ASolarBody *SolarBody);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetIsImmuneToDamage(bool bNewIsImmuneToDamage, AActor *immunityInitiator);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintImplementableEvent)
    void AuthorityForceKillAstro();

    UFUNCTION(BlueprintImplementableEvent)
    float ApplyPowerExternal(int32 Amount);

    UFUNCTION(BlueprintImplementableEvent)
    int32 ApplyOxygenExternal(int32 Amount);

};
