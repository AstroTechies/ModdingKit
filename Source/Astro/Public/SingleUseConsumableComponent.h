#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "SingleUseConsumableComponent.generated.h"

class UParticleSystem;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API USingleUseConsumableComponent : public UActorComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient, ReplicatedUsing = OnRep_HasBeenConsumed)
    uint8 bHasBeenConsumed : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bSuppressUseAfterConsumption : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bSuppressExamineAfterConsumption : 1;

    UPROPERTY(EditDefaultsOnly)
    UParticleSystem *ConsumptionVFX;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference VFXSpawnComponent;

    UPROPERTY(EditDefaultsOnly)
    FName VFXSpawnSocketName;

    UPROPERTY(EditDefaultsOnly)
    float VFXSpawnScale;

    UPROPERTY(EditDefaultsOnly)
    FString ConsumptionAudioEventName;

public:
    USingleUseConsumableComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void OnRep_HasBeenConsumed(bool bWasConsumed);
};
