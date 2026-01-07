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
    
    UPROPERTY(AdvancedDisplay, BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPowerStateChangeEvent OnHasPowerAvailableChanged;
    
    UPROPERTY(AdvancedDisplay, BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FChargeLevelChangedEvent OnChargeLevelChanged;
    
    UPROPERTY(AdvancedDisplay, BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnChargeDepleted;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Should this machine generate power?
    uint8 bIsGenerator: 1;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bIsLoad: 1;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ShouldReplicate: 1;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Unsure, only rovers seem to use this field
    uint8 SelfDischargeOnly: 1;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Is this battery built into the chassis of a machine?
    uint8 IsIntegratedBattery: 1;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    // Does this machine need power to work?
    uint8 QueryPower: 1;
    
protected:
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    // Take a guess
    uint8 Enabled: 1;
    
public:
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // The amount of energy that this battery can hold in units
    float StorageCapacity;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // The number of U/s that this battery can discharge
    float DischargeRate;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // The number of U/s that this battery can charge
    float ChargeRate;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentChargeRate;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NetActualLoad;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentAvailablePower;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentMaximumLoad;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Unsure, needs testing
    float DiscreteDelta;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* UIComponent;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* WhilePowered;
    
    UPROPERTY(AdvancedDisplay, BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPowered;
    
    UPROPERTY(AdvancedDisplay, BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDepowered;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* WhileGeneratingPower;
    
    UPROPERTY(AdvancedDisplay, BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnStartedGeneratingPower;
    
    UPROPERTY(AdvancedDisplay, BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnStoppedGeneratingPower;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* WhileDischarging;
    
    UPROPERTY(AdvancedDisplay, BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDischarging;
    
    UPROPERTY(AdvancedDisplay, BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnEndDischarging;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* WhileFullCharge;
    
    UPROPERTY(AdvancedDisplay, BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnFullCharge;
    
    UPROPERTY(AdvancedDisplay, BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnEndFullCharge;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* WhileEmptyCharge;
    
    UPROPERTY(AdvancedDisplay, BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnEmptyCharge;
    
    UPROPERTY(AdvancedDisplay, BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnEndEmptyCharge;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* WhileFullyPowered;
    
    UPROPERTY(AdvancedDisplay, BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnFullyPowered;
    
    UPROPERTY(AdvancedDisplay, BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnEndFullyPowered;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPowerThresholdEvent> ThresholdEvents;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ReplicationData, meta=(AllowPrivateAccess=true))
    FReplicatedPowerState ReplicatedState;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FReplicatedPowerState PrevReplicatedState;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 PowerID;
    
protected:
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // If this number is positive, it is the U/s that this machine will output. If this number is negative, it is the U/s that this machine will draw.
    float NetPowerOutput;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
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

