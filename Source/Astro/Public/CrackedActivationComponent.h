#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CrackedActivationComponent.generated.h"

class AActor;
class UActivation;
class UCrackedActivationComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UCrackedActivationComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UActivation *Activation;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float CrackedValue;

    UCrackedActivationComponent();

private:
    UFUNCTION()
    void OnCracked();

    UFUNCTION()
    void OnClosed();

public:
    UFUNCTION(BlueprintPure)
    static UCrackedActivationComponent *ActorCrackedActivationComponent(AActor *Actor);
};
