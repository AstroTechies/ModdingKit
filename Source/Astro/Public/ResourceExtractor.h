#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EExtractorOperationStage.h"
#include "PhysicalItem.h"
#include "Engine/EngineTypes.h"
#include "EExtractorAnimStage.h"
#include "UObject/NoExportTypes.h"
#include "ResourceExtractor.generated.h"

class UResourceCacheComponent;
class USceneComponent;
class UPowerComponent;
class UStorageChassisComponent;
class UItemType;
class UAstroActionComponent;
class USkeletalMeshComponent;
class UAnimSequenceBase;
class UAnimMontage;
class UStaticMesh;
class UMaterialInstanceDynamic;
class UAstroAction;
class UPrimitiveComponent;

UCLASS(Blueprintable, Blueprintable)
class AResourceExtractor : public APhysicalItem
{
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    uint32 ManagerIndex;

    UPROPERTY(EditDefaultsOnly)
    float HammerDroppedHeight;

    UPROPERTY(EditDefaultsOnly)
    float HammerTopHeight;

private:
    UPROPERTY(EditDefaultsOnly)
    float Radius;

    UPROPERTY(EditDefaultsOnly)
    float PostPoundHoldTime;

    UPROPERTY(EditDefaultsOnly)
    float CycleTime;

    UPROPERTY(EditDefaultsOnly)
    float MaxLowPowerCycleTime;

    UPROPERTY(EditDefaultsOnly)
    float ResetTime;

    UPROPERTY(EditDefaultsOnly)
    float NuggetsPerNode;

    UPROPERTY(EditDefaultsOnly)
    uint32 ThumpsPerNugget;

    UPROPERTY(EditDefaultsOnly)
    uint32 FullMeterThreshold;

    UPROPERTY(Export, VisibleAnywhere)
    UPowerComponent *PowerComponent;

    UPROPERTY(Export, VisibleAnywhere)
    UAstroActionComponent *ActionComponent;

    UPROPERTY(Export, Transient)
    USceneComponent *VacuumLocationComponent;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference SkeletonComponentReference;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference VacuumLocationComponentReference;

    UPROPERTY(ReplicatedUsing = OnRep_NodesInArea)
    int32 NodesInArea;

public:
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UResourceCacheComponent *ResourceCache;

    UPROPERTY(Export, Transient)
    USkeletalMeshComponent *SkeletalMesh;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UStorageChassisComponent *StorageChassis;

    UPROPERTY(EditDefaultsOnly)
    UAnimSequenceBase *ActivateAnimation;

    UPROPERTY(EditDefaultsOnly)
    UAnimSequenceBase *DeactivateAnimation;

    UPROPERTY(EditDefaultsOnly)
    UAnimMontage *HammerDropMontage;

    UPROPERTY(BlueprintReadWrite, SkipSerialization, Transient, meta = (AllowPrivateAccess = true))
    UMaterialInstanceDynamic *FillBarMaterial;

    UPROPERTY(EditDefaultsOnly)
    FName HammerBoneName;

    UPROPERTY(ReplicatedUsing = OnRep_AnimProgress)
    float AnimProgress;

    UPROPERTY(Replicated)
    float PowerRatio;

    UPROPERTY(ReplicatedUsing = OnRep_Stages)
    EExtractorAnimStage AnimStage;

    UPROPERTY(ReplicatedUsing = OnRep_Stages)
    EExtractorOperationStage OpStage;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_ActivationState)
    uint8 bIsTurnedOn : 1;

    AResourceExtractor();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

private:
    UFUNCTION()
    void OnStorageChassisSlotEventSignal(APhysicalItem *Item);

    UFUNCTION()
    void OnSingleAnimCustomNotifyEvent(FName NotifyName);

    UFUNCTION()
    void OnResourceSlotFull(TSubclassOf<UItemType> Type);

    UFUNCTION()
    void OnResourceItemReleased(APhysicalItem *Item);

public:
    UFUNCTION()
    void OnRep_Stages();

    UFUNCTION()
    void OnRep_NodesInArea();

    UFUNCTION()
    void OnRep_AnimProgress();

    UFUNCTION()
    void OnRep_ActivationState();

private:
    UFUNCTION()
    void OnMontageEnded(UAstroAction *Action);

    UFUNCTION()
    void OnHasPowerAvailableChanged(bool HasAvailablePower);

public:
    UFUNCTION(NetMulticast, Reliable)
    void MulticastGenerateFlecks(UStaticMesh *StaticMesh, const FVector Location, const float Recipe);

private:
    UFUNCTION()
    void HandleOnPickedUpFromWorld(bool PhysicalMovement);

    UFUNCTION()
    void HandleOnDroppedInWorld(UPrimitiveComponent *Component, const FVector &Point, const FVector &Normal, bool bIsTerrainComponent);
};
