#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OnReplicationDataChangedDelegate.h"
#include "GameFramework/Actor.h"
#include "SignalDelegate.h"
#include "EPhysicalItemMotionState.h"
#include "OnSlotReleasedDelegate.h"
#include "ItemDropInWorldDelegateDelegate.h"
#include "ItemDropInWorldTerrainDelegateDelegate.h"
#include "OnPickedUpDelegate.h"
#include "OnMovedDelegate.h"
#include "UObject/NoExportTypes.h"
#include "EmplacementData.h"
#include "Engine/EngineTypes.h"
#include "SlotReference.h"
#include "UObject/NoExportTypes.h"
#include "OnPerformAuxUseOverrideDelegate.h"
#include "PhysicalItemReplicatedState.h"
#include "Engine/NetSerialization.h"
#include "Engine/NetSerialization.h"
#include "PhysicalItem.generated.h"

class UClickableComponent;
class UPhysicalMaterial;
class UProceduralStateComponent;
class UItemComponent;
class UActorEntityLinkComponent;
class UTerrainPhysicsComponent;
class UPrimitiveComponent;
class UStaticMeshComponent;
class UWorldGravity;
class USlotsComponent;
class UTooltipComponent;
class APawn;
class UChildSlotComponent;
class APhysicalItem;
class USceneComponent;
class UItemType;

UCLASS(Blueprintable)
class ASTRO_API APhysicalItem : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnItemUnpacked;
    
    UPROPERTY(BlueprintAssignable)
    FSignal OnPlacedInSlot;
    
    UPROPERTY(BlueprintAssignable)
    FSignal OnSpawnedInSlot;
    
    UPROPERTY(BlueprintAssignable)
    FSignal OnEmplacedInSlot;
    
    UPROPERTY(BlueprintAssignable)
    FSignal OnUnemplacedFromSlot;
    
    UPROPERTY(BlueprintAssignable)
    FSignal OnFullyEmplaced;
    
    UPROPERTY(BlueprintAssignable)
    FOnSlotReleased OnReleasedFromSlot;
    
    UPROPERTY(BlueprintAssignable)
    FSignal OnReleasedFromSlotClientSafe;
    
    UPROPERTY(BlueprintAssignable)
    FItemDropInWorldDelegate OnDroppedInWorld;
    
    UPROPERTY(BlueprintAssignable)
    FItemDropInWorldTerrainDelegate OnDroppedInWorldTerrain;
    
    UPROPERTY(BlueprintAssignable)
    FOnPickedUp OnPickedUpFromWorld;
    
    UPROPERTY(BlueprintAssignable)
    FSignal OnStartInWorld;
    
    UPROPERTY(BlueprintAssignable)
    FOnMoved OnMoved;
    
    UPROPERTY(BlueprintAssignable)
    FSignal OnMotionStateChanged;
    
    UPROPERTY(BlueprintAssignable)
    FSignal OnSetCardinalDirection;
    
    UPROPERTY(BlueprintAssignable)
    FOnReplicationDataChanged OnReplicationDataChanged;
    
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta=(AllowPrivateAccess=true))
    UItemComponent* ItemComponent;
    
    UPROPERTY(BlueprintReadWrite, Export, SaveGame, VisibleAnywhere, meta=(AllowPrivateAccess=true))
    UActorEntityLinkComponent* EntityLinkComponent;
    
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainPhysicsComponent* terrainComponent;
    
    UPROPERTY(BlueprintReadWrite, Export, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* PlaceholderPrimitive;
    
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StaticMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta=(AllowPrivateAccess=true))
    UWorldGravity* GravityComponent;
    
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta=(AllowPrivateAccess=true))
    UClickableComponent* ClickableComponent;
    
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta=(AllowPrivateAccess=true))
    USlotsComponent* SlotsComponent;
    
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta=(AllowPrivateAccess=true))
    UTooltipComponent* TooltipComponent;
    
    UPROPERTY(Export, VisibleAnywhere)
    UProceduralStateComponent* ProceduralState;
    
    UPROPERTY(BlueprintReadWrite, ReplicatedUsing=OnRep_EmplacementData, meta=(AllowPrivateAccess=true))
    FEmplacementData EmplacementData;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FSlotReference CurrentSlot;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FSlotReference PreviousSlot;
    
    UPROPERTY(EditAnywhere)
    FText ItemName;
    
    UPROPERTY(EditAnywhere)
    bool SlotQueryAllowBodyPlacement;
    
    UPROPERTY(EditAnywhere)
    FTransform OddTierBodyOffset;
    
    UPROPERTY(EditAnywhere)
    bool OffsetOddTiers;
    
    UPROPERTY(EditAnywhere)
    FVector HoverAxis;
    
    UPROPERTY(EditAnywhere)
    float HoverHeight;
    
    UPROPERTY(EditAnywhere)
    bool IndicatorUseAnimInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool WeldAsChild;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseHoverForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector HoverForward;
    
    UPROPERTY(EditAnywhere)
    bool IgnoreBodySlotForHover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PrinterHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ToolMoveTier;
    
    UPROPERTY(EditAnywhere)
    float PlacementSnapToGroundHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool IsMovable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AlwaysMovePhysical;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ItemWorldScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlotScale;
    
    UPROPERTY(EditDefaultsOnly)
    uint8 bDestroyWhenDrained: 1;
    
    UPROPERTY(BlueprintAssignable)
    FOnPerformAuxUseOverride AuxUseOverride;
    
    UPROPERTY(BlueprintAssignable)
    FOnPerformAuxUseOverride ActuatorUseOverride;
    
protected:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    APawn* MostRecentNetOwner;
    
    UPROPERTY(EditDefaultsOnly)
    bool IsUnslottable;
    
    UPROPERTY(ReplicatedUsing=OnRep_ItemState)
    FPhysicalItemReplicatedState ReplicatedState;
    
private:
    UPROPERTY(Transient)
    FEmplacementData PreviousEmplacementData;
    
    UPROPERTY(Transient)
    FPhysicalItemReplicatedState PreviousReplicatedState;
    
    UPROPERTY()
    UPhysicalMaterial* DefaultPhysicalMaterial;
    
public:
    APhysicalItem();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void StartItemInWorld();
    
    UFUNCTION(BlueprintImplementableEvent)
    void StartInWorld();
    
    UFUNCTION(BlueprintNativeEvent)
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
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerTakePossession(APawn* controllingPawn, bool PhysicalMovement, bool PartOfSwap);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSlotSetItem(FSlotReference ItemSlot, int32 SubslotIndex, FSlotReference sourceTransitionSlot, bool useSourceTransform, bool FromTool, bool SlottedDuringInitialization, bool PartOfSwap, bool skipBundling);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSlotReleaseItem(bool NewOwner, bool FromTool, float RandomForce, bool PartOfSwap);
    
private:
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerSlotEmplaceItem(FSlotReference Slot, int32 SubslotIndex, bool SnapTo, bool weld);
    
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerSetSlotCardinalDirection(uint8 Direction);
    
public:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerReleasePossession(UPrimitiveComponent* HitComponent, bool NewTerrainComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal);
    
private:
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerMove(FVector_NetQuantize100 clientLoc, float Scale, uint32 clientRot, uint8 clientRoll);
    
public:
    UFUNCTION(BlueprintImplementableEvent)
    void ReleasedFromSlot(bool FromTool, bool NewOwner);
    
    UFUNCTION(BlueprintNativeEvent)
    FTransform PlacementTransform(const FHitResult& Hit);
    
    UFUNCTION(BlueprintImplementableEvent)
    void PlacedInSlot(FSlotReference Slot, bool FromTool, bool SlottedDuringInitialization);
    
    UFUNCTION(BlueprintCallable)
    void PickUpFromWorld(bool PhysicalMovement);
    
    UFUNCTION(BlueprintImplementableEvent)
    void PickedUpFromWorld();
    
private:
    UFUNCTION()
    void OnRep_ItemState();
    
    UFUNCTION()
    void OnRep_EmplacementData();
    
public:
    UFUNCTION()
    void OnPostDrained();
    
    UFUNCTION(NetMulticast, Reliable)
    void MulticastSetFullyEmplaced(FSlotReference Slot, int32 SubslotIndex);
    
    UFUNCTION(NetMulticast, Reliable)
    void MulticastReleasedFromSlot(bool FromTool, bool NewOwner);
    
    UFUNCTION(NetMulticast, Reliable)
    void MulticastPickedUpFromWorld(bool PhysicalMovement);
    
    UFUNCTION(NetMulticast, Reliable)
    void MulticastDroppedInWorld(UPrimitiveComponent* Component, bool NewTerrainComponent, const FVector& Point, const FVector& Normal);
    
    UFUNCTION(BlueprintNativeEvent)
    bool Movable(int32 ToolTier);
    
    UFUNCTION(BlueprintNativeEvent)
    bool IsLarge();
    
    UFUNCTION(BlueprintPure)
    int32 GetSubSlotIndex() const;
    
    UFUNCTION(BlueprintPure)
    TSubclassOf<UItemType> GetStoredSubItemTypeClass() const;
    
    UFUNCTION(BlueprintPure)
    UItemType* GetStoredSubItemTypeCDO() const;
    
    UFUNCTION(BlueprintPure)
    float GetPrinterHeight() const;
    
    UFUNCTION(BlueprintPure)
    int32 GetPickupToolTier();
    
    UFUNCTION(BlueprintPure)
    APhysicalItem* GetPickupItemDefault();
    
    UFUNCTION(BlueprintPure)
    EPhysicalItemMotionState GetMotionState() const;
    
    UFUNCTION(BlueprintPure)
    TSubclassOf<UItemType> GetLiteralItemTypeClass() const;
    
    UFUNCTION(BlueprintPure)
    UItemType* GetLiteralItemTypeCDO() const;
    
    UFUNCTION(BlueprintPure)
    static float GetItemTypeDefaultScale(TSubclassOf<APhysicalItem> Type);
    
    UFUNCTION(BlueprintPure)
    FText GetItemName() const;
    
    UFUNCTION()
    UWorldGravity* GetGravity();
    
    UFUNCTION(BlueprintPure)
    TSubclassOf<UItemType> GetFunctionalItemTypeClass() const;
    
    UFUNCTION(BlueprintPure)
    UItemType* GetFunctionalItemTypeCDO() const;
    
    UFUNCTION(BlueprintNativeEvent)
    UChildSlotComponent* GetBodySlotLegacy() const;
    
    UFUNCTION(BlueprintPure)
    FSlotReference GetBodySlot() const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetBaseLocation();
    
    UFUNCTION(BlueprintImplementableEvent)
    void DroppedInWorld(UPrimitiveComponent* Component, bool NewTerrainComponent, const FVector& Point, const FVector& Normal);
    
    UFUNCTION(BlueprintCallable)
    void DropInWorld(UPrimitiveComponent* Component, bool NewTerrainComponent, const FVector& Point, const FVector& Normal);
    
    UFUNCTION(BlueprintPure)
    bool CanNeverBeSlotted() const;
    
};

