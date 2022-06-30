#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "DecoratorInfoComponent.generated.h"

class AAstroPlanet;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UDecoratorInfoComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    AAstroPlanet *Planet;

    UPROPERTY(BlueprintAssignable)
    FSignal OnDecoratorSpawn;

    UDecoratorInfoComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;
};
