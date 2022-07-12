#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PhysicalItem.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
#include "EExtractorAnimStage.h"
#include "EExtractorOperationStage.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "ResourceExtractor.generated.h"

class UItemType;
class UAstroActionComponent;
class UPowerComponent;
class USkeletalMeshComponent;
class USceneComponent;
class UPrimitiveComponent;
class UResourceCacheComponent;
class UStorageChassisComponent;
class UAnimSequenceBase;
class UAnimMontage;
class UMaterialInstanceDynamic;
class UAstroAction;
class UStaticMesh;

UCLASS(Blueprintable)
class AResourceExtractor : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, SaveGame)
    uint32 ManagerIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HammerDroppedHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HammerTopHeight;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostPoundHoldTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CycleTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxLowPowerCycleTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ResetTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NuggetsPerNode;
    
    UPROPERTY(EditAnywhere)
    uint32 ThumpsPerNugget;
    
    UPROPERTY(EditAnywhere)
    uint32 FullMeterThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UAstroActionComponent* ActionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* VacuumLocationComponent;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference SkeletonComponentReference;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference VacuumLocationComponentReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_NodesInArea, meta=(AllowPrivateAccess=true))
    int32 NodesInArea;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UResourceCacheComponent* ResourceCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStorageChassisComponent* StorageChassis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequenceBase* ActivateAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequenceBase* DeactivateAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* HammerDropMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SkipSerialization, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* FillBarMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HammerBoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_AnimProgress, meta=(AllowPrivateAccess=true))
    float AnimProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float PowerRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Stages, meta=(AllowPrivateAccess=true))
    EExtractorAnimStage AnimStage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Stages, meta=(AllowPrivateAccess=true))
    EExtractorOperationStage OpStage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_ActivationState, meta=(AllowPrivateAccess=true))
    uint8 bIsTurnedOn: 1;
    
    AResourceExtractor();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
private:
    UFUNCTION()
    void OnStorageChassisSlotEventSignal(APhysicalItem* Item);
    
    UFUNCTION()
    void OnSingleAnimCustomNotifyEvent(FName NotifyName);
    
    UFUNCTION()
    void OnResourceSlotFull(TSubclassOf<UItemType> Type);
    
    UFUNCTION()
    void OnResourceItemReleased(APhysicalItem* Item);
    
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
    void OnMontageEnded(UAstroAction* Action);
    
    UFUNCTION()
    void OnHasPowerAvailableChanged(bool HasAvailablePower);
    
public:
    UFUNCTION(NetMulticast, Reliable)
    void MulticastGenerateFlecks(UStaticMesh* StaticMesh, const FVector Location, const float Recipe);
    
private:
    UFUNCTION()
    void HandleOnPickedUpFromWorld(bool PhysicalMovement);
    
    UFUNCTION()
    void HandleOnDroppedInWorld(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal, bool bIsTerrainComponent);
    
};

