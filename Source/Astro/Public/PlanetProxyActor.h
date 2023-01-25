#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlanetProxyActor.generated.h"

class AAstroPlanet;
class ASolarBody;

UCLASS(Blueprintable)
class ASTRO_API APlanetProxyActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAstroPlanet* Planet;
    
    APlanetProxyActor();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpawn();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLocalPlayerPlanetSelectionEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLocalPlayerPlanetSelectionBegin(ASolarBody* playerHomeBody);
    
};

