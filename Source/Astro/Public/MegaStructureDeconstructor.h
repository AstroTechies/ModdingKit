#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "EDeconstructionTargetState.h"
#include "PhysicalItem.h"
#include "Templates/SubclassOf.h"
#include "MegaStructureDeconstructor.generated.h"

class UItemList;
class UMaterialInstanceDynamic;
class UMaterialInterface;

UCLASS(Blueprintable)
class ASTRO_API AMegaStructureDeconstructor : public APhysicalItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnDeconstructorStateChanged, meta=(AllowPrivateAccess=true))
    EDeconstructionTargetState DeconstructorTargetState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> ItemTypeDeconstructionWhitelist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> DeconstructableSlottedItemsList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeconstructionDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MidDeconstructionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* DeconstructionTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* ExoPaletteMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DestructorMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DeconstructorGreyMaterial;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle DeconstructionTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle MidDeconstructionTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> DeconstructionMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_DeconstructableItems, meta=(AllowPrivateAccess=true))
    TArray<APhysicalItem*> DeconstructableItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APhysicalItem*> DeconstrucableSlottedItems;
    
public:
    AMegaStructureDeconstructor(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateTargetMaterialParams(const FName param1Name, const float param1Value, const FName param2Name, const float param2Value);
    
private:
    UFUNCTION(BlueprintCallable)
    void UpdateDeconstructorTarget();
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetTargetMaterials();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_DeconstructableItems();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDeconstructorStateChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeginDeconstruction();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void NetMulticastBeginDeconstruction();
    
    UFUNCTION(BlueprintCallable)
    void DisableTargetCollision();
    
    UFUNCTION(BlueprintCallable)
    void AuthMidDeconstruction();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthEndDeconstruction();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthBeginDeconstruction();
    
};

