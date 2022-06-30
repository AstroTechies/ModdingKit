#pragma once
#include "CoreMinimal.h"
#include "ReplicatedPowerState.h"
#include "Components/ActorComponent.h"
#include "PowerThresholdEvent.h"
#include "SignalDelegate.h"
#include "PowerComponent.generated.h"

class USceneComponent;
class UActivation;
class AActor;
class UPowerComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UPowerComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPowerStateChangeEvent, bool, HasAvailablePower);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FChargeLevelChangedEvent, float, NewCharge, float, ChargeDelta);

    UPROPERTY(BlueprintAssignable)
    FPowerStateChangeEvent OnHasPowerAvailableChanged;

    UPROPERTY(BlueprintAssignable)
    FChargeLevelChangedEvent OnChargeLevelChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnChargeDepleted;

    UPROPERTY(EditAnywhere)
    uint8 bIsGenerator : 1;

    UPROPERTY(EditAnywhere)
    uint8 bIsLoad : 1;

    UPROPERTY(EditAnywhere)
    uint8 ShouldReplicate : 1;

    UPROPERTY(EditAnywhere)
    uint8 SelfDischargeOnly : 1;

    UPROPERTY(EditAnywhere)
    uint8 IsIntegratedBattery : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    uint8 QueryPower : 1;

protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, SaveGame, meta = (AllowPrivateAccess = true))
    uint8 Enabled : 1;

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float StorageCapacity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DischargeRate;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ChargeRate;

    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    float CurrentChargeRate;

    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    float NetActualLoad;

    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    float CurrentAvailablePower;

    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    float CurrentMaximumLoad;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DiscreteDelta;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *UIComponent;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UActivation *WhilePowered;

    UPROPERTY(BlueprintAssignable)
    FSignal OnPowered;

    UPROPERTY(BlueprintAssignable)
    FSignal OnDepowered;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UActivation *WhileGeneratingPower;

    UPROPERTY(BlueprintAssignable)
    FSignal OnStartedGeneratingPower;

    UPROPERTY(BlueprintAssignable)
    FSignal OnStoppedGeneratingPower;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UActivation *WhileDischarging;

    UPROPERTY(BlueprintAssignable)
    FSignal OnDischarging;

    UPROPERTY(BlueprintAssignable)
    FSignal OnEndDischarging;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UActivation *WhileFullCharge;

    UPROPERTY(BlueprintAssignable)
    FSignal OnFullCharge;

    UPROPERTY(BlueprintAssignable)
    FSignal OnEndFullCharge;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UActivation *WhileEmptyCharge;

    UPROPERTY(BlueprintAssignable)
    FSignal OnEmptyCharge;

    UPROPERTY(BlueprintAssignable)
    FSignal OnEndEmptyCharge;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UActivation *WhileFullyPowered;

    UPROPERTY(BlueprintAssignable)
    FSignal OnFullyPowered;

    UPROPERTY(BlueprintAssignable)
    FSignal OnEndFullyPowered;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FPowerThresholdEvent> ThresholdEvents;

    UPROPERTY(ReplicatedUsing = OnRep_ReplicationData)
    FReplicatedPowerState ReplicatedState;

    UPROPERTY()
    FReplicatedPowerState PrevReplicatedState;

    UPROPERTY(VisibleInstanceOnly)
    uint32 PowerID;

protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float NetPowerOutput;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, SaveGame, meta = (AllowPrivateAccess = true))
    float CurrentCharge;

public:
    UPowerComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetSuppliedVisibility(USceneComponent *Component);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetNetPowerOutput(float NewNetPowerOutput);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool SetEnabled(bool NewIsEnabled);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    float SetCurrentCharge(float Charge);

    UFUNCTION(BlueprintPure)
    FText ReportPowerComponent();

    UFUNCTION(BlueprintCallable)
    void PingIndicator(bool Discharging);

    UFUNCTION()
    void OnRep_ReplicationData();

    UFUNCTION(BlueprintPure)
    bool IsSupplied() const;

    UFUNCTION(BlueprintPure)
    bool IsPowered() const;

    UFUNCTION(BlueprintPure)
    bool IsFullySupplied() const;

    UFUNCTION(BlueprintPure)
    bool IsFullyPowered() const;

    UFUNCTION(BlueprintPure)
    bool IsFullyCharged() const;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    float IsEnabled();

    UFUNCTION(BlueprintPure)
    bool IsAnyPowerAvailable() const;

protected:
    UFUNCTION()
    void HandleFreePowerChanged(bool NewFreePowerChanged);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    float GetNetPowerOutput();

    UFUNCTION(BlueprintPure)
    float GetCurrentCharge() const;

    UFUNCTION(BlueprintCallable)
    void DrainBattery(float Speed);

    UFUNCTION(BlueprintPure)
    bool CanPowerFor(float Amount) const;

    UFUNCTION(BlueprintPure)
    bool CanPower() const;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    float AddCharge(float Charge);

    UFUNCTION(BlueprintPure)
    static UPowerComponent *ActorPowerComponent(AActor *Actor);
};
