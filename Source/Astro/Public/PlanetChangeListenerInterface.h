#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
#include "PlanetChangeListenerInterface.generated.h"

class AAstroPlanet;

UINTERFACE(Blueprintable, MinimalAPI)
class UPlanetChangeListenerInterface : public UInterface {
    GENERATED_BODY()
};

class IPlanetChangeListenerInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandlePlanetChanged(AAstroPlanet* newPlanet);
    
};

