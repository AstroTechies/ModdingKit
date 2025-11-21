#pragma once
#include "CoreMinimal.h"
#include "BiodomeModule.h"
#include "EBiodomeHarvesterSFX.h"
#include "EBiodomeHarvesterState.h"
#include "BiodomeHarvester.generated.h"

class APhysicalItem;
class UBiodomePlantComponent;
class UPowerComponent;
class USplineComponent;
class UStaticMeshComponent;
class UStorageChassisComponent;

UCLASS(Blueprintable)
class ASTRO_API ABiodomeHarvester : public ABiodomeModule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* BallMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ClawMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* MovementSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStorageChassisComponent* StorageChassisComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HarvesterHoverHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MovementSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WaitInSectionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateSectionWaitTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PlantsToHarvestPerTrip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ResourceSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName StorageSlotName;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EBiodomeHarvesterState> CurrentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float CurrentSplineLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float CurrentDistanceAlongSpline;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int8 ClosestBiodomeSectionIndex;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int8 TargetBiodomeSectionIndex;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int8 CurrentDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bClientUpdatingMovement: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_OnEnableStateChanged, meta=(AllowPrivateAccess=true))
    uint8 bIsEnabled: 1;
    
public:
    ABiodomeHarvester(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayBiodomeHarvesterSFX(EBiodomeHarvesterSFX harvesterSFX);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnStorageStateChanged(APhysicalItem* movedItem);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_OnEnableStateChanged();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnPlantSpawnedInBiodome();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPlantHarvested(UBiodomePlantComponent* plant, TArray<APhysicalItem*> droppedItems);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnItemAmountChanged();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void Multicast_PlaySFX(EBiodomeHarvesterSFX harvesterSFX);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_MoveDroneToBiodomeSection(int8 SectionIndex);
    
protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityToggleIsEnabled();
    
};

