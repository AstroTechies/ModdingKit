#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
#include "EExtractorAnimStage.h"
#include "EExtractorOperationStage.h"
#include "PhysicalItem.h"
#include "Templates/SubclassOf.h"
#include "ResourceExtractor.generated.h"

class UAnimMontage;
class UAnimSequenceBase;
class UAstroAction;
class UAstroActionComponent;
class UItemType;
class UMaterialInstanceDynamic;
class UPowerComponent;
class UPrimitiveComponent;
class UResourceCacheComponent;
class USceneComponent;
class USkeletalMeshComponent;
class UStaticMesh;
class UStorageChassisComponent;

UCLASS(Blueprintable)
class AResourceExtractor : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
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
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 ThumpsPerNugget;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 FullMeterThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroActionComponent* ActionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* VacuumLocationComponent;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference SkeletonComponentReference;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference VacuumLocationComponentReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_NodesInArea, meta=(AllowPrivateAccess=true))
    int32 NodesInArea;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UResourceCacheComponent* ResourceCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
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
    UFUNCTION(BlueprintCallable)
    void OnStorageChassisSlotEventSignal(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnSingleAnimCustomNotifyEvent(FName NotifyName);
    
    UFUNCTION(BlueprintCallable)
    void OnResourceSlotFull(TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintCallable)
    void OnResourceItemReleased(APhysicalItem* Item);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnRep_Stages();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_NodesInArea();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_AnimProgress();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ActivationState();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnMontageEnded(UAstroAction* Action);
    
    UFUNCTION(BlueprintCallable)
    void OnHasPowerAvailableChanged(bool HasAvailablePower);
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastGenerateFlecks(UStaticMesh* StaticMesh, const FVector Location, const float Recipe);
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleOnPickedUpFromWorld(bool PhysicalMovement);
    
    UFUNCTION(BlueprintCallable)
    void HandleOnDroppedInWorld(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal, bool bIsTerrainComponent);
    
};

