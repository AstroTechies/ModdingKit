#pragma once
#include "CoreMinimal.h"
#include "PlanetEffectRelevancyChangedDelegate.h"
#include "Components/ActorComponent.h"
#include "PlanetEffect.generated.h"

class AActor;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UPlanetEffect : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float SphereRadius;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    TArray<AActor *> OverlappingPlayers;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    uint8 bSimLocal : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bAutoHandleCriticalComponents : 1;

    UPROPERTY(BlueprintAssignable)
    FPlanetEffectRelevancyChanged OnPlanetEffectRelevancyChanged;

protected:
    UPROPERTY(Export, Transient)
    TArray<UActorComponent *> ManagedComponents;

    UPROPERTY(Export, Transient)
    TArray<UActorComponent *> AutoManagedComponents;

    UPROPERTY(Transient)
    TArray<uint8> AutoManagedComponentFlags;

public:
    UPlanetEffect();
    UFUNCTION(BlueprintCallable)
    void TriggerUpdate();

    UFUNCTION(BlueprintCallable)
    static void SetActorIgnoreForAI(AActor *Actor, bool bSetIgnore);

    UFUNCTION(BlueprintCallable)
    void AddManagedComponent(UActorComponent *Component);
};
