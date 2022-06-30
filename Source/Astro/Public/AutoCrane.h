#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "PhysicalItem.h"
#include "AutoCraneStateChangeDelegate.h"
#include "EAutoCraneTransferStage.h"
#include "Engine/EngineTypes.h"
#include "AutoCrane.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;
class UAstroActionComponent;
class UAnimationAsset;
class AActor;
class UPowerComponent;
class UAnimMontage;

UCLASS(Blueprintable, Abstract)
class AAutoCrane : public APhysicalItem
{
    GENERATED_BODY()
public:
    UPROPERTY(Export, Transient)
    UCapsuleComponent *PickupCollider;

    UPROPERTY(Export, Transient)
    UCapsuleComponent *DropoffCollider;

    UPROPERTY(Export, Transient)
    USkeletalMeshComponent *Skeleton;

    UPROPERTY(Transient)
    APhysicalItem *TransferItem;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UAstroActionComponent *ActionComponent;

    UPROPERTY(EditDefaultsOnly)
    float BaseRotationTime;

    UPROPERTY(EditDefaultsOnly)
    float MaxLowPowerRotationTime;

    UPROPERTY(EditDefaultsOnly)
    float ItemSlottingTime;

    UPROPERTY(BlueprintAssignable)
    FAutoCraneStateChange OnClientCraneStateChanged;

    UPROPERTY()
    FAutoCraneStateChange OnClientTransferProgressChanged;

    UPROPERTY()
    FAutoCraneStateChange OnTransferItemSet;

    UPROPERTY()
    FAutoCraneStateChange OnTransferItemReleased;

    UPROPERTY()
    FAutoCraneStateChange OnTransferItemFullyEmplaced;

    UPROPERTY()
    FAutoCraneStateChange OnTransferItemDestroyed;

    UPROPERTY()
    FAutoCraneStateChange OnCranePlacedInSlot;

    UPROPERTY()
    FAutoCraneStateChange OnCraneReleasedFromSlot;

    UPROPERTY(BlueprintAssignable)
    FAutoCraneStateChange OnCranePowerChanged;

    UPROPERTY(BlueprintAssignable)
    FAutoCraneStateChange OnCraneInputUse;

    UPROPERTY(Transient)
    FSlotReference TransferSlotRef;

    UPROPERTY(Export, VisibleAnywhere)
    UPowerComponent *PowerComponent;

    UPROPERTY(EditDefaultsOnly)
    UAnimationAsset *ActivateAnim;

    UPROPERTY(EditDefaultsOnly)
    UAnimationAsset *DeactivateAnim;

    UPROPERTY(EditDefaultsOnly)
    UAnimationAsset *ActivateToHeldAnim;

    UPROPERTY(EditDefaultsOnly)
    UAnimationAsset *ActiveToHeldAnim;

    UPROPERTY(EditDefaultsOnly)
    UAnimationAsset *HeldToInactiveAnim;

    UPROPERTY(EditDefaultsOnly)
    UAnimationAsset *HeldToActiveAnim;

    UPROPERTY(EditDefaultsOnly)
    UAnimationAsset *HeldIdleAnim;

    UPROPERTY(EditDefaultsOnly)
    UAnimationAsset *ActiveIdleAnim;

    UPROPERTY(EditDefaultsOnly)
    UAnimMontage *GrabHighAnim;

    UPROPERTY(EditDefaultsOnly)
    UAnimMontage *GrabMedAnim;

    UPROPERTY(EditDefaultsOnly)
    UAnimMontage *GrabLowAnim;

    UPROPERTY(EditDefaultsOnly)
    UAnimMontage *PlaceHighAnim;

    UPROPERTY(EditDefaultsOnly)
    UAnimMontage *PlaceMedAnim;

    UPROPERTY(EditDefaultsOnly)
    UAnimMontage *PlaceLowAnim;

    UPROPERTY(EditDefaultsOnly)
    FName RotationBoneName;

    UPROPERTY(EditDefaultsOnly)
    float GrabLowHeight;

    UPROPERTY(EditDefaultsOnly)
    float GrabHighHeight;

private:
    UPROPERTY(EditDefaultsOnly)
    FComponentReference PickupColliderReference;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference DropoffColliderReference;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference SkeletonComponentReference;

    UPROPERTY(EditDefaultsOnly)
    FName TransferSlotName;

    UPROPERTY(EditDefaultsOnly)
    FName FilterSlotName;

    UPROPERTY(Transient)
    FSlotReference FilterSlotRef;

public:
    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_TransferProgress)
    float TransferProgress;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    float PowerRatio;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_CraneState, meta = (AllowPrivateAccess = true))
    EAutoCraneTransferStage TransferStage;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_CraneState, meta = (AllowPrivateAccess = true))
    uint8 bIsTurnedOn : 1;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    uint8 bHasPower : 1;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    uint8 bIsSlotted : 1;

    AAutoCrane();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION()
    void OnRep_TransferProgress();

    UFUNCTION()
    void OnRep_CraneState();

    UFUNCTION(NetMulticast, Reliable)
    void MulticastPlayOneOffAnimation(UAnimationAsset *Anim);

private:
    UFUNCTION()
    void HandleSelfOnReleasedFromSlot(bool NewOwner);

    UFUNCTION()
    void HandleSelfOnPlacedInSlot();

    UFUNCTION()
    void HandleOnSetItem(APhysicalItem *Item);

    UFUNCTION()
    void HandleOnReleaseItem(APhysicalItem *Item);

public:
    UFUNCTION()
    void HandleOnReleasedFromSlot(bool NewOwner);

    UFUNCTION()
    void HandleOnItemDestroyed(AActor *DestroyedActor);

private:
    UFUNCTION()
    void HandleOnHasPowerAvailableChanged(bool HasAvailablePower);

public:
    UFUNCTION()
    void HandleOnFullyEmplaced();

private:
    UFUNCTION()
    void HandleOnFilterSlotChanged(APhysicalItem *Item);

    UFUNCTION()
    void HandleChassisSlotEvent(APhysicalItem *Item);
};
