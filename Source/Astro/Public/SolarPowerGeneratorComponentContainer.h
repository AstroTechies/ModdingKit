#pragma once
#include "CoreMinimal.h"
#include "SolarPowerGeneratorComponent.h"
#include "AstroEntityComponentContainer.h"
#include "AstroDatumRef.h"
#include "SolarPowerGeneratorComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API USolarPowerGeneratorComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    USolarPowerGeneratorComponentContainer();
    UFUNCTION(BlueprintPure)
    static FSolarPowerGeneratorComponent GetSolarPowerGeneratorComponent(FAstroDatumRef SolarPowerGeneratorComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintPure)
    static FSolarPowerGeneratorComponent FindSolarPowerGeneratorComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

