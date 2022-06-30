#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "EHornType.h"
#include "HornComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UHornComponent : public UActorComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    EHornType HornType;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float MinActivationDuration;

    UPROPERTY(BlueprintAssignable)
    FSignal OnOneOffSoundPlayed;

    UPROPERTY(BlueprintAssignable)
    FSignal OnOneOffSoundCompleted;

    UPROPERTY(BlueprintAssignable)
    FSignal OnLoopSoundStarted;

    UPROPERTY(BlueprintAssignable)
    FSignal OnLoopSoundStopped;

public:
    UHornComponent();

protected:
    UFUNCTION(NetMulticast, Reliable)
    void OneOffSoundPlayed();

    UFUNCTION(NetMulticast, Reliable)
    void LoopSoundStopped();

    UFUNCTION(NetMulticast, Reliable)
    void LoopSoundStarted();
};
