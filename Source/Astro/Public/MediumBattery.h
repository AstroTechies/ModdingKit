#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "Engine/EngineTypes.h"
#include "MediumBattery.generated.h"

class USceneComponent;
class UMaterialInstanceDynamic;
class UPowerComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AMediumBattery : public APhysicalItem
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UMaterialInstanceDynamic *RingMaterial;

private:
    UPROPERTY(Export, Transient)
    UPowerComponent *PowerComponent;

    UPROPERTY(Export, Transient)
    USceneComponent *RingMeshComponent;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference RingMeshReference;

    UPROPERTY(ReplicatedUsing = OnRep)
    float CurrentChargePercent;

public:
    AMediumBattery();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

private:
    UFUNCTION()
    void OnRep();

    UFUNCTION()
    void OnChargeLevelChangedEvent(float NewCharge, float ChargeDelta);
};
