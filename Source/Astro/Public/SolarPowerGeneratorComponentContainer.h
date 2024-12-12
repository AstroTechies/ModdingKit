#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "SolarPowerGeneratorComponent.h"
#include "SolarPowerGeneratorComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API USolarPowerGeneratorComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    USolarPowerGeneratorComponentContainer();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSolarPowerGeneratorComponent GetSolarPowerGeneratorComponent(FAstroDatumRef SolarPowerGeneratorComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSolarPowerGeneratorComponent FindSolarPowerGeneratorComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

