#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
#include "PhysicalItem.h"
#include "MediumBattery.generated.h"

class UMaterialInstanceDynamic;
class UPowerComponent;
class USceneComponent;

UCLASS(Blueprintable)
class ASTRO_API AMediumBattery : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* RingMaterial;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* RingMeshComponent;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference RingMeshReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep, meta=(AllowPrivateAccess=true))
    float CurrentChargePercent;
    
public:
    AMediumBattery();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep();
    
    UFUNCTION(BlueprintCallable)
    void OnChargeLevelChangedEvent(float NewCharge, float ChargeDelta);
    
};

