#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Components/ActorComponent.h"
#include "EAugmentProperty.h"
#include "SignalDelegate.h"
#include "AugmentComponent.generated.h"

UCLASS(Blueprintable, Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UAugmentComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TMap<EAugmentProperty, float> AugmentPropertyMap;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnReplicated_AugmentEquipped, meta = (AllowPrivateAccess = true))
    bool AugmentIsEquipped;

    UPROPERTY(BlueprintAssignable)
    FSignal OnAugmentEquipped;

    UPROPERTY(BlueprintAssignable)
    FSignal OnAugmentUnequipped;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnReplicated_AugmentActive, meta = (AllowPrivateAccess = true))
    bool AugmentIsActive;

    UPROPERTY(BlueprintAssignable)
    FSignal OnAugmentActivated;

    UPROPERTY(BlueprintAssignable)
    FSignal OnAugmentDeactivated;

    UPROPERTY(BlueprintAssignable)
    FSignal OnAugmentEnabled;

    UPROPERTY(BlueprintAssignable)
    FSignal OnAugmentDisabled;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnReplicated_AugmentEnabled, meta = (AllowPrivateAccess = true))
    bool AugmentIsEnabled;

    UPROPERTY(BlueprintAssignable)
    FSignal OnAugmentPropertyChanged;

private:
    UPROPERTY(EditDefaultsOnly)
    bool SuppressClickableWhileDeactivated;

    UPROPERTY()
    FTimerHandle ReactivationTimer;

public:
    UAugmentComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

private:
    UFUNCTION()
    void UnblockReactivation();

public:
    UFUNCTION()
    void SetPowerDrawEnabled(bool drawEnabled);

    UFUNCTION(BlueprintCallable)
    void SetAugmentEquipped(bool equipped);

    UFUNCTION(BlueprintCallable)
    bool SetAugmentEnabled(bool IsEnabled);

    UFUNCTION(BlueprintCallable)
    void SetAugmentActive(bool Active);

private:
    UFUNCTION()
    void PhysicalItemUnslotted(bool NewOwner);

public:
    UFUNCTION()
    void OnReplicated_AugmentEquipped();

    UFUNCTION()
    void OnReplicated_AugmentEnabled();

    UFUNCTION()
    void OnReplicated_AugmentActive();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AugmentUnequipped();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AugmentEquipped();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AugmentEnabled();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AugmentDisabled();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AugmentDeactivated();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AugmentActivated();
};
