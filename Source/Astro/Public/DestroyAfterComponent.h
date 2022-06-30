#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DestroySequenceParticlesStartedDelegate.h"
#include "DestroyAfterComponent.generated.h"

class UParticleSystemComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UDestroyAfterComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint8 bStartTimerOnBeginPlay : 1;

    UPROPERTY(SaveGame)
    uint8 bTimerStarted : 1;

    UPROPERTY(EditAnywhere)
    float MinLife;

    UPROPERTY(EditAnywhere)
    float MaxLife;

    UPROPERTY(Export, Transient)
    UParticleSystemComponent *DestroyParticles;

    UPROPERTY(BlueprintAssignable)
    FDestroySequenceParticlesStarted OnParticlesStarted;

    UDestroyAfterComponent();
    UFUNCTION(BlueprintCallable)
    void StartTimer();

    UFUNCTION(BlueprintCallable)
    void PlayDestroyParticlesAndDelete(UParticleSystemComponent *particles, float playParticlesAfter, float destroyAfter);
};
