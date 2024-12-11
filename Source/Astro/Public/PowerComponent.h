#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PowerThresholdEvent.h"
#include "ReplicatedPowerState.h"
#include "SignalDelegate.h"
#include "PowerComponent.generated.h"

class AActor;
class UActivation;
class UPowerComponent;
class USceneComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UPowerComponent : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPowerStateChangeEvent, bool, HasAvailablePower);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FChargeLevelChangedEvent, float, NewCharge, float, ChargeDelta);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPowerStateChangeEvent OnHasPowerAvailableChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FChargeLevelChangedEvent OnChargeLevelChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnChargeDepleted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Should this machine generate power?
    uint8 bIsGenerator: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bIsLoad: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ShouldReplicate: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Unsure, only rovers seem to use this field
    uint8 SelfDischargeOnly: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Is this battery built into the chassis of a machine?
    uint8 IsIntegratedBattery: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    // Does this machine need power to work?
    uint8 QueryPower: 1;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    // Take a guess
    uint8 Enabled: 1;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // The amount of energy that this battery can hold in units
    float StorageCapacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // The number of U/s that this battery can discharge
    float DischargeRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // The number of U/s that this battery can charge
    float ChargeRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentChargeRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NetActualLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentAvailablePower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentMaximumLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Unsure, needs testing
    float DiscreteDelta;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* UIComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* WhilePowered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPowered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDepowered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* WhileGeneratingPower;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnStartedGeneratingPower;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnStoppedGeneratingPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* WhileDischarging;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDischarging;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnEndDischarging;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* WhileFullCharge;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnFullCharge;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnEndFullCharge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* WhileEmptyCharge;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnEmptyCharge;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnEndEmptyCharge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* WhileFullyPowered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnFullyPowered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnEndFullyPowered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPowerThresholdEvent> ThresholdEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ReplicationData, meta=(AllowPrivateAccess=true))
    FReplicatedPowerState ReplicatedState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FReplicatedPowerState PrevReplicatedState;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 PowerID;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // If this number is positive, it is the U/s that this machine will output. If this number is negative, it is the U/s that this machine will draw.
    float NetPowerOutput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float CurrentCharge;
    
public:
    UPowerComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetSuppliedVisibility(USceneComponent* Component);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetNetPowerOutput(float NewNetPowerOutput);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool SetEnabled(bool NewIsEnabled);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    float SetCurrentCharge(float Charge);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText ReportPowerComponent();
    
    UFUNCTION(BlueprintCallable)
    void PingIndicator(bool Discharging);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ReplicationData();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSupplied() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPowered() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFullySupplied() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFullyPowered() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFullyCharged() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    float IsEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnyPowerAvailable() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleFreePowerChanged(bool NewFreePowerChanged);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    float GetNetPowerOutput();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDefaultNetPowerOutput();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentCharge() const;
    
    UFUNCTION(BlueprintCallable)
    void DrainBattery(float Speed);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPowerFor(float Amount) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPower() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    float AddCharge(float Charge);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UPowerComponent* ActorPowerComponent(AActor* Actor);
    
};

