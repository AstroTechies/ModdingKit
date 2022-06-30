#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "HoverDelayComponent.generated.h"

class AActor;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UHoverDelayComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal HoverBegin;

    UPROPERTY(BlueprintAssignable)
    FSignal HoverEnd;

    UPROPERTY(EditAnywhere)
    float HoverBeginDelay;

    UPROPERTY(EditAnywhere)
    float HoverEndDelay;

    UPROPERTY()
    FTimerHandle HoverTimer;

    UPROPERTY()
    bool Hovering;

    UHoverDelayComponent();
    UFUNCTION()
    void OnTimerEnd();

    UFUNCTION()
    void OnHoverEnd(AActor *Actor);

    UFUNCTION()
    void OnHoverBegin(AActor *Actor);
};
