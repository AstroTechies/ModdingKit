#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "PlanetProxyActor.generated.h"

class ASolarBody;
class AAstroPlanet;

UCLASS(Blueprintable)
class ASTRO_API APlanetProxyActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAstroPlanet* Planet;
    
    APlanetProxyActor();
    UFUNCTION(BlueprintImplementableEvent)
    void OnSpawn();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnLocalPlayerPlanetSelectionEnd();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnLocalPlayerPlanetSelectionBegin(ASolarBody* playerHomeBody);
    
};

