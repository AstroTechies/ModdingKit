#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlanetProxyActor.generated.h"

class AAstroPlanet;
class ASolarBody;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API APlanetProxyActor : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    AAstroPlanet *Planet;

    APlanetProxyActor();
    UFUNCTION(BlueprintImplementableEvent)
    void OnSpawn();

    UFUNCTION(BlueprintImplementableEvent)
    void OnLocalPlayerPlanetSelectionEnd();

    UFUNCTION(BlueprintImplementableEvent)
    void OnLocalPlayerPlanetSelectionBegin(ASolarBody *playerHomeBody);
};
