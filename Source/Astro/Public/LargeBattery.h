#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "LargeBattery.generated.h"

class UMaterialInstanceDynamic;
class UPowerComponent;

UCLASS(Blueprintable)
class ASTRO_API ALargeBattery : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* PowerBarMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PowerBarFillInterpolationRate;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_CurrentChargePercent, meta=(AllowPrivateAccess=true))
    float CurrentChargePercent;
    
public:
    ALargeBattery(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable)
    void UpdateView();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CurrentChargePercent();
    
    UFUNCTION(BlueprintCallable)
    void OnChargeLevelChangedEvent(float NewCharge, float ChargeDelta);
    
};

