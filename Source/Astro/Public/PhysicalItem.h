#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "GameFramework/Actor.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Vector_NetQuantize100 -FallbackName=Vector_NetQuantize100
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Vector_NetQuantizeNormal -FallbackName=Vector_NetQuantizeNormal
#include "EPhysicalItemMotionState.h"
#include "EmplacementData.h"
#include "ItemDropInWorldDelegateDelegate.h"
#include "ItemDropInWorldTerrainDelegateDelegate.h"
#include "OnMovedDelegate.h"
#include "OnPerformAuxUseOverrideDelegate.h"
#include "OnPickedUpDelegate.h"
#include "OnReplicationDataChangedDelegate.h"
#include "OnSelectionRotationStartOrStopDelegate.h"
#include "OnSlotReleasedDelegate.h"
#include "PhysicalItemReplicatedState.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "PhysicalItem.generated.h"

class APawn;
class APhysicalItem;
class UActorEntityLinkComponent;
class UChildSlotComponent;
class UClickableComponent;
class UItemComponent;
class UItemType;
class UPhysicalMaterial;
class UPrimitiveComponent;
class UProceduralStateComponent;
class USceneComponent;
class USlotsComponent;
class UStaticMeshComponent;
class UTerrainPhysicsComponent;
class UTooltipComponent;
class UWorldGravity;

UCLASS(Blueprintable)
class ASTRO_API APhysicalItem : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnOwnerChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnItemUnpacked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPlacedInSlot;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSpawnedInSlot;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnEmplacedInSlot;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnUnemplacedFromSlot;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnFullyEmplaced;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSlotReleased OnReleasedFromSlot;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnReleasedFromSlotClientSafe;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemDropInWorldDelegate OnDroppedInWorld;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemDropInWorldTerrainDelegate OnDroppedInWorldTerrain;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPickedUp OnPickedUpFromWorld;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnFailedToPickUpFromWorld;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnStartInWorld;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMoved OnMoved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnMotionStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSetCardinalDirection;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnReplicationDataChanged OnReplicationDataChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnIsAttachedToTerrainChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemComponent* ItemComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UActorEntityLinkComponent* EntityLinkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTerrainPhysicsComponent* terrainComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* PlaceholderPrimitive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StaticMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWorldGravity* GravityComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UClickableComponent* ClickableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USlotsComponent* SlotsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTooltipComponent* TooltipComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProceduralStateComponent* ProceduralState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_EmplacementData, meta=(AllowPrivateAccess=true))
    FEmplacementData EmplacementData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference CurrentSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference PreviousSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ItemName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SlotQueryAllowBodyPlacement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform OddTierBodyOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool OffsetOddTiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector HoverAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoverHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IndicatorUseAnimInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool WeldAsChild;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseHoverForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector HoverForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IgnoreBodySlotForHover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PrinterHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ToolMoveTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlacementSnapToGroundHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool IsMovable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AlwaysMovePhysical;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ItemWorldScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlotScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bDestroyWhenDrained: 1;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPerformAuxUseOverride AuxUseOverride;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPerformAuxUseOverride ActuatorUseOverride;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSelectionRotationStartOrStop OnPickedUpRotationStartOrStop;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APawn* MostRecentNetOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsUnslottable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ItemState, meta=(AllowPrivateAccess=true))
    FPhysicalItemReplicatedState ReplicatedState;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEmplacementData PreviousEmplacementData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FPhysicalItemReplicatedState PreviousReplicatedState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhysicalMaterial* DefaultPhysicalMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsAttachedToTerrain: 1;
    
public:
    APhysicalItem();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void StartItemInWorld();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartInWorld();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ShouldPickUp(UPrimitiveComponent* PrimComponent);
    
    UFUNCTION(BlueprintCallable)
    void SetWorldPhysics();
    
    UFUNCTION(BlueprintCallable)
    void SetPuppetPhysics();
    
    UFUNCTION(BlueprintCallable)
    void SetPhysicsState(EPhysicalItemMotionState State, USceneComponent* AttachParent, const FName& SocketName, bool weld);
    
    UFUNCTION(BlueprintCallable)
    void SetNonSimulatingPhysics();
    
    UFUNCTION(BlueprintCallable)
    void SetIndicatorPhysics();
    
    UFUNCTION(BlueprintCallable)
    void SetAttachPhysics(USceneComponent* Component, const FName& SocketName, bool DeWeld);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerTakePossession(APawn* controllingPawn, bool PhysicalMovement, bool PartOfSwap);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSlotSetItem(FSlotReference ItemSlot, int32 SubslotIndex, FSlotReference sourceTransitionSlot, bool useSourceTransform, bool FromTool, bool SlottedDuringInitialization, bool PartOfSwap, bool skipBundling, bool skipTransformUpdate);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSlotReleaseItem(bool NewOwner, bool FromTool, float RandomForce, bool PartOfSwap);
    
private:
    UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation)
    void ServerSlotEmplaceItem(FSlotReference Slot, int32 SubslotIndex, bool SnapTo, bool weld);
    
    UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation)
    void ServerSetSlotCardinalDirection(uint8 Direction);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerReleasePossession(UPrimitiveComponent* HitComponent, bool NewTerrainComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal);
    
private:
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerMove(FVector_NetQuantize100 clientLoc, float Scale, uint32 clientRot, uint8 clientRoll);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReleasedFromSlot(bool FromTool, bool NewOwner);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FTransform PlacementTransform(const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlacedInSlot(FSlotReference Slot, bool FromTool, bool SlottedDuringInitialization);
    
    UFUNCTION(BlueprintCallable)
    void PickUpFromWorld(bool PhysicalMovement);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PickedUpFromWorld();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_ItemState();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_EmplacementData();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnPostDrained();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSetFullyEmplaced(FSlotReference Slot, int32 SubslotIndex);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastReleasedFromSlot(bool FromTool, bool NewOwner);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastPickedUpFromWorld(bool PhysicalMovement);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastDroppedInWorld(UPrimitiveComponent* Component, bool NewTerrainComponent, const FVector& Point, const FVector& Normal);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool Movable(int32 ToolTier);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsLarge();
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleIsBuriedChanged(UTerrainPhysicsComponent* terrainComp);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSubSlotIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UItemType> GetStoredSubItemTypeClass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemType* GetStoredSubItemTypeCDO() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPrinterHeight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetPickupToolTier();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APhysicalItem* GetPickupItemDefault();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EPhysicalItemMotionState GetMotionState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UItemType> GetLiteralItemTypeClass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemType* GetLiteralItemTypeCDO() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetItemTypeDefaultScale(TSubclassOf<APhysicalItem> Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetItemName() const;
    
    UFUNCTION(BlueprintCallable)
    UWorldGravity* GetGravity();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UItemType> GetFunctionalItemTypeClass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemType* GetFunctionalItemTypeCDO() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UChildSlotComponent* GetBodySlotLegacy() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSlotReference GetBodySlot() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetBaseLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DroppedInWorld(UPrimitiveComponent* Component, bool NewTerrainComponent, const FVector& Point, const FVector& Normal);
    
    UFUNCTION(BlueprintCallable)
    void DropInWorld(UPrimitiveComponent* Component, bool NewTerrainComponent, const FVector& Point, const FVector& Normal);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanNeverBeSlotted() const;
    
};

