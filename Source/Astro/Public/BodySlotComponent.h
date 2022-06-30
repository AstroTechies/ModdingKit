#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "DropInWorldDelegateDelegate.h"
#include "BodySlotComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UBodySlotComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float HoverHeight;

    UPROPERTY(BlueprintAssignable)
    FSignal OnPlace;

    UPROPERTY(BlueprintAssignable)
    FSignal OnRelease;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FDropInWorldDelegate OnDropInWorld;

    UPROPERTY(BlueprintAssignable)
    FSignal OnStartInWorld;

    UPROPERTY(BlueprintAssignable)
    FSignal OnPickUpFromWorld;

    UBodySlotComponent();
    UFUNCTION(BlueprintCallable)
    void StartInWorld();
};
