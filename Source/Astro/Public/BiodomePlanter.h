#pragma once
#include "CoreMinimal.h"
#include "BiodomeModule.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "BiodomePlanter.generated.h"

class APhysicalItem;
class ASeed;
class UItemList;
class UItemType;
class UPowerComponent;
class USplineComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ASTRO_API ABiodomePlanter : public ABiodomeModule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ArmMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* MovementSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ClientSeedMesh;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OutputSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName InputSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SeedMovementSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSmoothSeedHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> ItemTypeWhitelist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReloadDelay;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    ASeed* SeedToPlant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> InputItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    APhysicalItem* InputPhysicalItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 DrainedAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_OnEnableStateChanged, meta=(AllowPrivateAccess=true))
    uint8 bIsEnabled: 1;
    
public:
    ABiodomePlanter(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlaySeedFiredEffects();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSeedSetInTargetSeedSlot(APhysicalItem* Item);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_OnEnableStateChanged();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnItemSetInResourceSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnItemSetInOutputSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnItemReleasedFromInputSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void Multicast_SpawnSeedMeshOnSpline(FSlotReference TargetSlot);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void FinishVFX();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityToggleIsEnabled();
    
};

