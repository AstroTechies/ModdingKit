#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "ChargeUseComponent.generated.h"

class UPowerComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UChargeUseComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    float DischargeRate;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_State, meta = (AllowPrivateAccess = true))
    bool canUse;

    UPROPERTY(EditAnywhere, SaveGame)
    bool Usable;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_State, meta = (AllowPrivateAccess = true))
    bool Discharging;

    UPROPERTY(Replicated, SaveGame)
    float DischargeProgress;

    UPROPERTY(BlueprintAssignable)
    FSignal OnDischarged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnStateUpdate;

    UPROPERTY(Export)
    UPowerComponent *PowerComponent;

    UChargeUseComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UseCharge();

    UFUNCTION()
    void UpdateCanUse();

    UFUNCTION(BlueprintCallable)
    void SetUsable(bool newUsable);

    UFUNCTION()
    void OnRep_State();
};
